# RC522 RFID - STM32 Library
Collaborative project among students of the Microcontrollers course, aiming to create a library that abstracts the use of the RFID reader module RC522 on STM32 Blue Pill microcontrollers.

See documentation in Portuguese (Brazil) [here](README-PT.md).

## 🚀 Features
- [x] **a) Read Single Card ID (UART Output):** Function to detect and read the unique identifier (UID) of an RFID card and output the result via UART interface.
- [x] **b) Read Multiple Card IDs (UART Output):** Function to detect and read the unique identifiers of multiple RFID cards consecutively, with output of results through the UART interface.
- [x] **c) Write Content (String) to RFID Card:** Function to write a specific string to the storage of an RFID card, allowing for customization or specific use of the card.
- [x] **d) Read Content (String) from RFID Card:** Function to retrieve and read a previously stored string from an RFID card.
- [ ] **e) Active Communication - Module-to-Module Chat:** Implementation of a bidirectional communication system between multiple RFID modules, enabling real-time message exchange.
- [ ] **f) Active Communication: Module-to-Smartphone NFC:** Function that allows communication between the RFID module and an NFC-equipped smartphone, enabling direct reading and writing of data between the devices.

## 👥 Project Collaborators
Sorted alphabetically

<table>
  <tr>
    <td align="center">
      <a href="https://github.com/AndreAlves-18" title="André Alves">
        <img src="https://github.com/AndreAlves-18.png" width="100px;" alt="André Alves"/>
        <br>
        <sub>
          <b>André Alves</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/Arthursnoww" title="Arthur Roberto">
        <img src="https://github.com/Arthursnoww.png" width="100px;" alt="Arthur Roberto"/>
        <br>
        <sub>
          <b>Arthur Roberto</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/CaioJ0rdan" title="Caio Jordan">
        <img src="https://github.com/CaioJ0rdan.png" width="100px;" alt="Caio Jordan"/>
        <br>
        <sub>
          <b>Caio Jordan</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/calebe-sucupira" title="Calebe Sucupira">
        <img src="https://github.com/calebe-sucupira.png" width="100px;" alt="Calebe Sucupira"/>
        <br>
        <sub>
          <b>Calebe Sucupira</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/elitonnmelo" title="Éliton Melo">
        <img src="https://github.com/elitonnmelo.png" width="100px;" alt="Éliton Melo"/>
        <br>
        <sub>
          <b>Éliton Melo</b>
        </sub>
      </a>
    </td>
  </tr>
  <tr>
    <td align="center">
      <a href="https://github.com/guiaf04" title="Guilherme Araújo">
        <img src="https://github.com/guiaf04.png" width="100px;" alt="Guilherme Araújo"/>
        <br>
        <sub>
          <b>Guilherme Araújo</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="#" title="Jefferson Matheus">
        <img src="https://github.com/example.png" width="100px;" alt="Jefferson Matheus"/>
        <br>
        <sub>
          <b>Jefferson Matheus</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/JosueSucupira" title="Josué Sucupira">
        <img src="https://github.com/JosueSucupira.png" width="100px;" alt="Josué Sucupira"/>
        <br>
        <sub>
          <b>Josué Sucupira</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="#" title="Marcos Nascimento">
        <img src="https://github.com/example.png" width="100px;" alt="Marcos Nascimento"/>
        <br>
        <sub>
          <b>Marcos Nascimento</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/marcusnogueiraa" title="Marcus Nogueira">
        <img src="https://github.com/marcusnogueiraa.png" width="100px;" alt="Marcus Nogueira"/>
        <br>
        <sub>
          <b>Marcus Nogueira</b>
        </sub>
      </a>
    </td>
  </tr>
  <tr>
    <td align="center">
      <a href="https://github.com/pedronobredmc" title="Pedro Nobrega">
        <img src="https://github.com/pedronobredmc.png" width="100px;" alt="Pedro Nobrega"/>
        <br>
        <sub>
          <b>Pedro Nobrega</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/ryanguilherme" title="Ryan Guilherme">
        <img src="https://github.com/ryanguilherme.png" width="100px;" alt="Ryan Guilherme"/>
        <br>
        <sub>
          <b>Ryan Guilherme</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/wl11lm" title="William Marreiro">
        <img src="https://github.com/wl11lm.png" width="100px;" alt="William Marreiro"/>
        <br>
        <sub>
          <b>William Marreiro</b>
        </sub>
      </a>
    </td>
  </tr>
</table>


----
# rc522-stm32-Library

This library was created to simplify communication between the STM32 microcontroller (from the STM32F103xx family) and the RC522 RFID reader using the SPI interface. Instead of handling the complexity of directly controlling the RC522, it streamlines the process, allowing the user to work with RFID cards in a practical and efficient way.

**Dependencies:**
- SPI protocol
- stdint.h library
- stm32f1xx.h library

**Current Version:** 1.0.0  
**License:** MIT License

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/marcusnogueiraa/rc522-stm32-library
   ```

2. Add the library files to your STM32CubeIDE project.

3. Configure the SPI and GPIO pins in your `Main` according to the instructions provided in the example code.

## Connection and Schematic

### Hardware Connection

To use this library with the RC522 RFID reader on an STM32 board, you will need to make the following connections between the RC522 pins and the STM32 pins:

| RC522 Pin | Function              | STM32 Pin |
| --------- | --------------------- | --------- |
| VCC       | Power Supply 3.3V      | 3.3V      |
| GND       | Ground                 | GND       |
| RST       | Module Reset           | PB0       |
| IRQ       | Interrupt (not used)   | -         |
| MISO      | SPI Master-In Slave-Out | PA6       |
| MOSI      | SPI Master-Out Slave-In | PA7       |
| SCK       | SPI Clock              | PA5       |
| SDA (SS)  | Slave Select           | PA4       |

Configure the PA4, PA5, PA6, and PA7 pins according to the hardware connection table.

## Connection Schematic

Below is the schematic for connecting the RC522 reader to the STM32F103xx microcontroller.

![Schematic](schematic.png)

## Library Structure

- `rc522.c`: Implements the main functions for using the RC522.
- `rc522.h`: Function declarations and macro definitions for the RC522.
- `timer.c`: Timer initialization and operation functions.
- `timer.h`: Timer function declarations and macro definitions.
- `uart.c`: Implements the UART interface for serial communication with the device.
- `uart.h`: UART function declarations and macro definitions.

## Usage Example

### Initialization

```c
#include <stdint.h>
#include "stm32f1xx.h"
#include "rc522.h"
#include "uart.h"
#include "string.h"

void GPIO_Config() {
  //Clock SPI, GPIOA and GPIOB enable
  RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
  RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;

  //PA5 SCK
  GPIOA->CRL |= GPIO_CRL_MODE5_0 | GPIO_CRL_MODE5_1;        //Output Mode
  GPIOA->CRL |= GPIO_CRL_CNF5_1;                             //Alternate Function
  GPIOA->CRL &=  ~(GPIO_CRL_CNF5_0);
  //PA7 MOSI
  GPIOA->CRL |= GPIO_CRL_MODE7_0 | GPIO_CRL_MODE7_1;         //Output Mode
  GPIOA->CRL |= GPIO_CRL_CNF7_1;                             //Alternate Function
  GPIOA->CRL &=  ~(GPIO_CRL_CNF7_0);
  //PA4 NSS
  GPIOA->CRL |= GPIO_CRL_MODE4_0 | GPIO_CRL_MODE4_1;         //Output Mode
  GPIOA->CRL &= ~GPIO_CRL_CNF4_1;                           //General Purpose
  GPIOA->CRL &=  ~(GPIO_CRL_CNF4_0);
  //PA6 MISO
  GPIOA->CRL &= ~(GPIO_CRL_MODE6_0 | GPIO_CRL_MODE6_1);     //Input Mode
  GPIOA->CRL &= ~GPIO_CRL_CNF6_1;                            //Floating Input
  GPIOA->CRL |=  (GPIO_CRL_CNF6_0);
  //PB0 RST
  GPIOB->CRL |= GPIO_CRL_MODE0_0 | GPIO_CRL_MODE0_1;         //Output Mode
  GPIOB->CRL &= ~GPIO_CRL_CNF0_1;                           //General Purpose
  GPIOB->CRL &=  ~(GPIO_CRL_CNF0_0);
}

void SPI_Init() {
  GPIO_Config();
  RCC->APB2ENR |= (1 << 12);          // Enable SPI1 CLock
  SPI1->CR1 &= ~(1 << 0) | (1 << 1);  // CPOL=0, CPHA=0
  SPI1->CR1 |= (1 << 2);              // Master Mode
  SPI1->CR1 |= (2 << 3);              // BR[2:0] = 010: fPCLK/8, PCLK2 = 72MHz, SPI clk = 9MHz
  SPI1->CR1 &= ~(1 << 7);              // LSBFIRST = 0, MSB first
  SPI1->CR1 |= (1 << 8) | (1 << 9);   // SSM=1, SSi=1 -> Software Slave Management
  SPI1->CR1 &= ~(1 << 10);            // RXONLY = 0, full-duplex
  SPI1->CR1 &= ~(1 << 11);             // DFF=0, 8 bit data
  SPI1->CR1 |= (1 << 6);              // SPE=1, Peripheral enabled
}

int main()
{
  SPI_Init();    
  MFRC522_Init(); 
  USART1_Init();  

  uint8_t str[MAX_LEN];
  uint8_t sNum[150];
  uint8_t ch[] = "\n\r";

  while (1)
  {
    uchar requestStatus, anticollStatus;
    requestStatus = MFRC522_Request(PICC_REQIDL, str);
    if (requestStatus == MI_OK)
    {
      anticollStatus = MFRC522_Anticoll(str);
      if (anticollStatus == MI_OK)
      {
        MFRC522_SelectTag(str);
        int_to_string(str, 5, sNum);
        uart_write(sNum);
        delay_ms(50);
        uart_write(ch);
        MFRC522_Halt();
      }
    }
  }
  return 0;
}
```

## API Reference
### `SPI_TransmitReceive`

**Description:**  
Function used to transmit and receive data via SPI.

**Parameters:**  
- **pTxData**: Pointer for data to be transmitted via SPI.
- **pRxData**: Pointer for data to be received via SPI.
- **size**: Size of the amount of data to be sent and received.  
**Return:**  
- **none**
---

### `RC522_SPI_Transfer`

**Description:**  
Transfer data to MFRC522.

**Parameters:**  
- **data**: Value to be written.

**Return:**  
- **uint8_t**: One byte of data read from the module.

---

### `Write_MFRC522`

**Description:**  
Writes a byte of data to a specific register of the MFRC522.

**Parameters:**  
- **addr**: Address of the register.
- **val**: Value to be written.

**Return:**  
- **none**

---

### `Read_MFRC522`

**Description:**  
Reads a byte from a data register of the MFRC522 module.

**Parameters:**  
- **addr**: Address of the register.

**Return:**  
- **uint8_t**: A byte of data read from the module.

---

### `SetBitMask`

**Description:**  
Sets a bit of the MFRC522 register.

**Parameters:**  
- **reg**: Address of the register.  
- **mask**: Value to be set.

**Return:**  
- **none**

---

### `ClearBitMask`

**Description:**  
Clears bits of a specific register in the MFRC522 module according to the provided mask.

**Parameters:**  
- **reg**: Address of the register to be modified.  
- **mask**: Mask that defines which bits will be cleared.

**Return:**  
- **none**

---

### `AntennaOn`

**Description:**  
Activates the MFRC522 antenna.

**Parameters:**  
- **none**

**Return:**  
- **none**

---

### `AntennaOff`

**Description:**  
Deactivates the MFRC522 antenna.

**Parameters:**  
- **none**

**Return:**  
- **none**

---

### `MFRC522_Reset`

**Description:**  
Clears the registers of the MFRC522 module.

**Parameters:**  
- **none**

**Return:**  
- **none**

---

### `MFRC522_Init`

**Description:**  
Initializes the MFRC522 module and prepares SPI communication.

**Parameters:**  
- **none**

**Return:**  
- **none**

---

### `MFRC522_ToCard`

**Description:**  
Establishes communication between the RC522 module and a card, sending and receiving data according to the specified command.

**Parameters:**  
- **command**: Command word of the MF522 to be sent.  
- **sendData**: Data to be sent by the RC522 to the card.  
- **sendLen**: Length of the data to be sent.  
- **backData**: Data received from the card after communication.  
- **backLen**: Length of the received data.

**Return:**  
- **uchar**: Status code of the operation.

---

### `MFRC522_Request`

**Description:**  
Locates cards and reads the card type number.

**Parameters:**  
- **reqMode**: Request mode to identify the card type.

**Return:**  
- **uint8_t**: Status code of the operation.

---

### `MFRC522_Anticoll`

**Description:**  
Collision detection, reading the serial number of the selected card.

**Parameters:**  
- **uint8_t* serNum**: Buffer where the serial number of the card will be stored.

**Return:**  
- **uint8_t**: Status code of the operation.

---

### `CalulateCRC`

**Description:**  
Performs CRC (Cyclic Redundancy Check) calculation using the MFRC522 module, ensuring data integrity.

**Parameters:**  
- **pIndata**: Input data for which the CRC will be calculated.  
- **len**: Length of the input data.  
- **pOutData**: Results of the CRC calculation to be stored.

**Return:**  
- **None**

---

### `MFRC522_Write`

**Description:**  
Writes a block of data to the RFID card.

**Parameters:**  
- **blockAddr**: Address of the block where the data will be written.  
- **writeData**: Data to be written to the card.

**Return:**  
- **uint8_t**: Status code of the operation.

---

### `MFRC522_Read`

**Description:**  
Reads a block of data from the RFID card.

**Parameters:**  
- **blockAddr**: Address of the block to be read.  
- **recvData**: Buffer where the read data will be stored.

**Return:**  
- **uint8_t**: Status code of the operation.

---

### `MFRC522_Auth`

**Description:**  
Authenticates a block of the RFID card for reading or writing.

**Parameters:**  
- **uint8_t authMode**: Authentication mode (usually `PICC_AUTHENT1A`).  
- **uint8_t blockAddr**: Address of the block to be authenticated.  
- **uint8_t* key**: Authentication key.  
- **uint8_t* serNum**: Serial number of the card.

**Return:**  
- **uint8_t**: Status code of the operation.

---

### `MFRC522_SelectTag`
**Description:**  
Selects the RFID card based on the serial number.

**Parameters:**  
- **serNum**: Serial number of the card to be selected.

**Return:**  
- **uint8_t**: Status code of the operation.

---

### `MFRC522_Halt`

**Description:**  
Puts the RFID card into the Halt (stop) state.

**Parameters:**  
- **none**

**Return:**  
- **none**

---

### `Read_Single_Card`

**Description:**  
Reads a single RFID card, authenticating and reading the data block.

**Parameters:**  
- **none**

**Return:**  
- **none**

---

### `Read_Multiple_Cards`

**Description:**  
Reads multiple RFID cards.

**Parameters:**  
- **none**

**Return:**  
- **none**

---

### `Write_Content_Card`

**Description:**  
**Parameters:**  
- **authMode**: Authentication mode (usually `PICC_AUTHENT1A`).  
- **myString**: Buffer containing the data to be written to the card.  
- **block**: Block to be written to the card.  
- **Sectorkey**: Authentication key.

**Return:**  
- **none**

---

### `Read_Content_Card`

**Description:**  
Reads the content of a block of an RFID card after authentication.

**Parameters:**  
- **authMode**: Authentication mode (usually `PICC_AUTHENT1A`).   
- **block**: Block to be read from the card.  
- **Sectorkey**: Authentication key.

**Return:**  
- **none**:


## Error Handling

### Common Errors

- **MI_OK**: Operation completed successfully.
- **MI_ERR**: Communication error with the RFID card. Check the SPI connections.
- **MI_NOTAGERR**: No card detected. Ensure the card is within the reading range.

## Contribution

Feel free to submit pull requests or open issues for any improvements or fixes needed for better library functionality.


