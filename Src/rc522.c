/*
 * rc522.c
 *
 *  Created on: Sep 22, 2024
 *      Author: guilherme
 */

#include "rc522.h"
#include "stm32f1xx.h"
#include <stdint.h>

void SPI_TransmitReceive(const uint8_t *pTxData, uint8_t *pRxData, uint16_t Size) {
	uint16_t i;
    for(i = 0; i < Size; i++) {
        while (!(SPI1->SR & SPI_SR_TXE));

        SPI1->DR = pTxData[i];

        while (!(SPI1->SR & SPI_SR_RXNE));

        pRxData[i] = SPI1->DR;

        while (SPI1->SR & SPI_SR_BSY);
    }
}

uint8_t RC522_SPI_Transfer(uchar data) {
	uchar rx_data;
	SPI_TransmitReceive(&data, &rx_data, 1);

	return rx_data;
}

void Write_MFRC522(uchar addr, uchar val) {
	/* CS LOW */
	GPIOA->BSRR = (uint32_t)GPIO_PIN_4 << 16;

	RC522_SPI_Transfer((addr<<1)&0x7E);
	RC522_SPI_Transfer(val);

	/* CS HIGH */
	GPIOA->BSRR = GPIO_PIN_4;
}

uchar Read_MFRC522(uchar addr) {
	uchar val;

	/* CS LOW */
	GPIOA->BSRR = (uint32_t)GPIO_PIN_4 << 16;

	RC522_SPI_Transfer(((addr<<1)&0x7E) | 0x80);
	val = RC522_SPI_Transfer(0x00);

	/* CS HIGH */
	GPIOA->BSRR = GPIO_PIN_4;

	return val;
}

void SetBitMask(uchar reg, uchar mask) {
	uchar tmp;
    tmp = Read_MFRC522(reg);
    Write_MFRC522(reg, tmp | mask);  // set bit mask
}

void ClearBitMask(uchar reg, uchar mask) {
    uchar tmp;
    tmp = Read_MFRC522(reg);
    Write_MFRC522(reg, tmp & (~mask));  // clear bit mask
}

void AntennaOn() {
	Read_MFRC522(TxControlReg);
	SetBitMask(TxControlReg, 0x03);
}

void AntennaOff() {
	ClearBitMask(TxControlReg, 0x03);
}

void MFRC522_Reset() {
    Write_MFRC522(CommandReg, PCD_RESETPHASE);
}

void MFRC522_Init() {

	GPIOA->BSRR = GPIO_PIN_4;
	GPIOB->BSRR = GPIO_PIN_0;
	MFRC522_Reset();

	//Timer: TPrescaler*TreloadVal/6.78MHz = 24ms
	Write_MFRC522(TModeReg, 0x8D);    //Tauto=1; f(Timer) = 6.78MHz/TPreScaler
	Write_MFRC522(TPrescalerReg, 0x3E);  //TModeReg[3..0] + TPrescalerReg
	Write_MFRC522(TReloadRegL, 30);
	Write_MFRC522(TReloadRegH, 0);

	Write_MFRC522(TxAutoReg, 0x40);    // force 100% ASK modulation
	Write_MFRC522(ModeReg, 0x3D);    // CRC Initial value 0x6363

	AntennaOn();
}

uchar MFRC522_ToCard(uchar command, uchar *sendData, uchar sendLen, uchar *backData, uint *backLen) {
	uchar status = MI_ERR;
    uchar irqEn = 0x00;
    uchar waitIRq = 0x00;
    uchar lastBits;
    uchar n;
    uint i;

    switch (command)
    {
        case PCD_AUTHENT:    // Certification cards close
    {
      irqEn = 0x12;
      waitIRq = 0x10;
      break;
    }
    case PCD_TRANSCEIVE:  // Transmit FIFO data
    {
      irqEn = 0x77;
      waitIRq = 0x30;
      break;
    }
    default:
      break;
    }

    Write_MFRC522(CommIEnReg, irqEn|0x80);  // Interrupt request
    ClearBitMask(CommIrqReg, 0x80);      // Clear all interrupt request bit
    SetBitMask(FIFOLevelReg, 0x80);      // FlushBuffer=1, FIFO Initialization

    Write_MFRC522(CommandReg, PCD_IDLE);  // NO action; Cancel the current command

    // Writing data to the FIFO
    for (i=0; i<sendLen; i++)
    {
    Write_MFRC522(FIFODataReg, sendData[i]);
  }

    // Execute the command
    Write_MFRC522(CommandReg, command);
    if (command == PCD_TRANSCEIVE)
    {
    SetBitMask(BitFramingReg, 0x80);    // StartSend=1,transmission of data starts
  }

    // Waiting to receive data to complete
  i = 2000;  // i according to the clock frequency adjustment, the operator M1 card maximum waiting time 25ms
    do
    {
    //CommIrqReg[7..0]
    //Set1 TxIRq RxIRq IdleIRq HiAlerIRq LoAlertIRq ErrIRq TimerIRq
        n = Read_MFRC522(CommIrqReg);
        i--;
    }
    while ((i!=0) && !(n&0x01) && !(n&waitIRq));

    ClearBitMask(BitFramingReg, 0x80);      //StartSend=0

    if (i != 0)
    {
        if(!(Read_MFRC522(ErrorReg) & 0x1B))  //BufferOvfl Collerr CRCErr ProtecolErr
        {
            status = MI_OK;
            if (n & irqEn & 0x01)
            {
        status = MI_NOTAGERR;
      }

            if (command == PCD_TRANSCEIVE)
            {
                 n = Read_MFRC522(FIFOLevelReg);
                lastBits = Read_MFRC522(ControlReg) & 0x07;
                if (lastBits)
                {
          *backLen = (n-1)*8 + lastBits;
        }
                else
                {
          *backLen = n*8;
        }

                if (n == 0)
                {
          n = 1;
        }
                if (n > MAX_LEN)
                {
          n = MAX_LEN;
        }

                // Reading the received data in FIFO
                for (i=0; i<n; i++)
                {
          backData[i] = Read_MFRC522(FIFODataReg);
        }
            }
        }
        else
        {
      status = MI_ERR;
    }

    }


    return status;
}

uchar MFRC522_Request(uchar reqMode, uchar *TagType) {
  uchar status;
  uint backBits;       // The received data bits

  Write_MFRC522(BitFramingReg, 0x07);    //TxLastBists = BitFramingReg[2..0]

  TagType[0] = reqMode;
  status = MFRC522_ToCard(PCD_TRANSCEIVE, TagType, 1, TagType, &backBits);

  if ((status != MI_OK) || (backBits != 0x10))
  {
    status = MI_ERR;
  }

  return status;
}

/*
 * Function Name: MFRC522_Anticoll
 * Description: Anti-collision detection, reading selected card serial number card
 * Input parameters: serNum - returns 4 bytes card serial number, the first 5 bytes for the checksum byte
 * Return value: the successful return MI_OK
 */
uchar MFRC522_Anticoll(uchar *serNum) {
    uchar status;
    uchar i;
    uchar serNumCheck=0;
    uint unLen;

    Write_MFRC522(BitFramingReg, 0x00);    //TxLastBists = BitFramingReg[2..0]

    serNum[0] = PICC_ANTICOLL;
    serNum[1] = 0x20;
    status = MFRC522_ToCard(PCD_TRANSCEIVE, serNum, 2, serNum, &unLen);

    if (status == MI_OK) {
        //Check card serial number
		for (i=0; i<4; i++) {
		   serNumCheck ^= serNum[i];
		}
		if (serNumCheck != serNum[i]){
			status = MI_ERR;
		}
    }
    return status;
}
