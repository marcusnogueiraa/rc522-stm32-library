# RC522 RFID - STM32 Library
## 🚀 Funcionalidades
- [ ] **a) Ler ID de um Cartão (Saída UART):** Função para detectar e ler o identificador único (UID) de um cartão RFID e exibir o resultado via interface UART.
- [ ] **b) Ler Múltiplos IDs de Cartões (Saída UART):** Função para detectar e ler os identificadores únicos de múltiplos cartões RFID consecutivamente, com saída dos resultados através da interface UART.
- [ ] **c) Escrever Conteúdo (String) no Cartão RFID:** Função para gravar uma string específica no armazenamento de um cartão RFID, permitindo a personalização ou uso específico do cartão.
- [ ] **d) Ler Conteúdo (String) do Cartão RFID:** Função para recuperar e ler uma string previamente armazenada em um cartão RFID.
- [ ] **e) Comunicação Ativa - Chat entre Módulos:** Implementação de um sistema de comunicação bidirecional entre vários módulos RFID, permitindo a troca de mensagens em tempo real.
- [ ] **f) Comunicação Ativa: Módulo-para-Smartphone via NFC:** Função que permite a comunicação entre o módulo RFID e um smartphone equipado com NFC, permitindo a leitura e escrita de dados diretamente entre os dispositivos.

## 👥 Colaboradores do Projeto
Ordenados alfabeticamente

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



---
# rc522-stm32-Library

Essa biblioteca foi criada para simplificar a comunicação entre o microcontrolador STM32 (da linha STM32F103xx) e o leitor de RFID RC522 usando a interface SPI. Em vez de lidar com a complexidade de controlar o RC522 diretamente, ela facilita o processo, permitindo que o usuário trabalhe com cartões RFID de maneira prática e eficiente.

**Dependências:**
- Protocolo SPI
- Biblioteca stdint.h
- Biblioteca stm32f1xx.h

**Versão Atual:** 1.0.0
**Licença:** MIT License


## Instalação

1. Clone o repositório:
   ```bash
   git clone https://github.com/marcusnogueiraa/rc522-stm32-library
   ```

2. Adicione os arquivos da biblioteca ao seu projeto STM32CubeIDE.

3. Configure os pinos SPI e GPIO na sua `Main` de acordo com as instruções fornecidas no codigo de exemplo.

## Conexão e Esquemático

### Conexão de Hardware

Para utilizar esta biblioteca com o leitor RFID RC522 em uma placa STM32, será necessário fazer as seguintes conexões entre os pinos do RC522 e os pinos da STM32:

| Pino do RC522 | Função | Pino da STM32 |
| ------------- | ------ | ------------- |
| VCC           | Alimentação 3.3V | 3.3V |
| GND           | Terra                | GND     |
| RST           | Reset do módulo      | PB0     |
| IRQ           | Interrupção (não utilizado) | -     |
| MISO          | SPI Master-In Slave-Out | PA6    |
| MOSI          | SPI Master-Out Slave-In  | PA7    |
| SCK           | SPI Clock               | PA5    |
| SDA (SS)      | Slave Select            | PA4    |

Configure os pinos PA4, PA5, PA6 e PA7 conforme a tabela de conexões dee hardware.

## Esquemático de Conexão

Abaixo está o esquemático para conectar o leitor RC522 ao microcontrolador STM3Ff103xx.

(Imagem do esquemático)



## Estrutura da Biblioteca

- `rc522.c`: Implementa as funções principais para o uso do RC522.
- `rc522.h`: Declaração de funções e definições de macros para o RC522.
- `timer.c`: Funções de inicialização e operação do timer.
- `timer.h`: Declaração de funções e definições de macros para o timer.
- `uart.c`: Implementa a interface UART para a comunicação serial com o dispositivo.
- `uart.h`: Declaração de funções e definições de macros paraa uart.


## Exemplo de Uso

### Inicialização

```c
#include <stdint.h>
#include "stm32f1xx.h"
#include "rc522.h"
#include "uart.h"
#include "string.h"

uint8_t defaultKey[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
uint8_t startBlock = 4;
char myString[] = "Testando 1, 2, 3... ";

void GPIO_Config() {
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;


	//PA4- CE,PA5-SCK,PA7-MOSI,PA6-MISO:

	//PA5 SCK will be set as alternate function output pushpull
	GPIOA->CRL |= GPIO_CRL_MODE5_0 | GPIO_CRL_MODE5_1;      	//Output Mode
	GPIOA->CRL |= GPIO_CRL_CNF5_1;         						//Alternate Function
	GPIOA->CRL &=  ~(GPIO_CRL_CNF5_0);
	//PA7 MOSI will be set as alternate function output pushpull
	GPIOA->CRL |= GPIO_CRL_MODE7_0 | GPIO_CRL_MODE7_1;     		//Output Mode
	GPIOA->CRL |= GPIO_CRL_CNF7_1;         						//Alternate Function
	GPIOA->CRL &=  ~(GPIO_CRL_CNF7_0);
	//PA4 CE will be set as General Purpose Output Mode
	GPIOA->CRL |= GPIO_CRL_MODE4_0 | GPIO_CRL_MODE4_1;     		//Output Mode
	GPIOA->CRL &= ~GPIO_CRL_CNF4_1;         					//General Purpose
	GPIOA->CRL &=  ~(GPIO_CRL_CNF4_0);  						//GPIOA->CRL &=  ~(GPIO_CRL_CNF4_0);
	//PA6 MISO will be set as Floating Input Mode
	GPIOA->CRL &= ~(GPIO_CRL_MODE6_0 | GPIO_CRL_MODE6_1);       //Input Mode
	GPIOA->CRL &= ~GPIO_CRL_CNF6_1;        					    //Floating Input
	GPIOA->CRL |=  (GPIO_CRL_CNF6_0);
	//PC13
	GPIOC->CRH = 0xFF0FFFFF;
	GPIOC->CRH = 0x00200000;
	GPIOC->ODR &= ~(1 << 13);
	//PB0
	GPIOB->CRL = 0xFFFFFFF0;
	GPIOB->CRL = 0x00000002;
	GPIOB->ODR &= ~(1 << 0);
}

void SPI_Init() {
	GPIO_Config();
	RCC->APB2ENR |= (1 << 12);      	// Enable SPI1 CLock
	SPI1->CR1 &= ~(1 << 0) | (1 << 1);  // CPOL=0, CPHA=0
	SPI1->CR1 |= (1 << 2);        		// Master Mode
	SPI1->CR1 |= (2 << 3);        		// BR[2:0] = 010: fPCLK/8, PCLK2 = 72MHz, SPI clk = 9MHz
	SPI1->CR1 &= ~(1 << 7);        		// LSBFIRST = 0, MSB first
	SPI1->CR1 |= (1 << 8) | (1 << 9);   // SSM=1, SSi=1 -> Software Slave Management
	SPI1->CR1 &= ~(1 << 10);        	// RXONLY = 0, full-duplex
	SPI1->CR1 &= ~(1 << 11);       		// DFF=0, 8 bit data
	SPI1->CR1 |= (1 << 6);        		// SPE=1, Peripheral enabled
}

int main() {
    SPI_Init();           // Inicializa SPI
    MFRC522_Init();       // Inicializa o módulo RC522
    USART1_Init();        // Inicializa UART para debug

    uint8_t uid[10];
    if (Read_MFRC522(uid) == MI_OK) {
        uart_write("UID do cartão: %s\n", uid);
    }

    return 0;
} 
```


## Referência da API
### `SPI_TransmitReceive`

**Descrição:**  
Função utilizada para transmitir e receber dados via SPI.

**Parâmetros:**  
- **uint8_t data**: Dado a ser transmitido via SPI.

**Retorno:**  
- **uint8_t**: Dado recebido após a transmissão.

---

### `RC522_SPI_Transfer`

**Descrição:**  
Função wrapper para enviar e receber dados via SPI.

**Parâmetros:**  
- **uint8_t data**: Dado a ser transmitido via SPI.

**Retorno:**  
- **uint8_t**: Dado recebido após a transmissão.

---

### `Write_MFRC522`

**Descrição:**  
Escreve um valor em um determinado endereço do registrador no módulo MFRC522.

**Parâmetros:**  
- **uint8_t addr**: Endereço do registrador no MFRC522.  
- **uint8_t val**: Valor a ser escrito no registrador.

**Retorno:**  
- **void**

---

### `Read_MFRC522`

**Descrição:**  
Lê um valor de um determinado endereço do registrador no módulo MFRC522.

**Parâmetros:**  
- **uint8_t addr**: Endereço do registrador a ser lido.

**Retorno:**  
- **uint8_t**: Valor lido do registrador.

---

### `SetBitMask`

**Descrição:**  
Configura os bits de uma máscara em um registrador específico.

**Parâmetros:**  
- **uint8_t reg**: Endereço do registrador.  
- **uint8_t mask**: Máscara de bits a ser configurada.

**Retorno:**  
- **void**

---

### `ClearBitMask`

**Descrição:**  
Limpa os bits de uma máscara em um registrador específico.

**Parâmetros:**  
- **uint8_t reg**: Endereço do registrador.  
- **uint8_t mask**: Máscara de bits a ser limpa.

**Retorno:**  
- **void**

---

### `AntennaOn`

**Descrição:**  
Ativa a antena do MFRC522.

**Parâmetros:**  
- **Nenhum**

**Retorno:**  
- **void**

---

### `AntennaOff`

**Descrição:**  
Desativa a antena do MFRC522.

**Parâmetros:**  
- **Nenhum**

**Retorno:**  
- **void**

---

### `MFRC522_Reset`

**Descrição:**  
Reinicializa o módulo MFRC522.

**Parâmetros:**  
- **Nenhum**

**Retorno:**  
- **void**

---

### `MFRC522_Init`

**Descrição:**  
Inicializa o módulo MFRC522 e prepara a comunicação SPI.

**Parâmetros:**  
- **Nenhum**

**Retorno:**  
- **void**

---

### `MFRC522_ToCard`

**Descrição:**  
Comunica-se diretamente com o cartão RFID para enviar comandos e receber respostas.

**Parâmetros:**  
- **uint8_t command**: Comando a ser enviado ao cartão.  
- **uint8_t* sendData**: Dados a serem enviados ao cartão.  
- **uint8_t sendLen**: Comprimento dos dados enviados.  
- **uint8_t* backData**: Buffer onde os dados de resposta serão armazenados.  
- **uint16_t* backLen**: Comprimento da resposta recebida.

**Retorno:**  
- **uint8_t**: Código de status da operação.

---

### `MFRC522_Request`

**Descrição:**  
Solicita a identificação de um cartão RFID.

**Parâmetros:**  
- **uint8_t reqMode**: Modo de requisição para identificar o tipo de cartão.

**Retorno:**  
- **uint8_t**: Código de status da operação.

---

### `MFRC522_Anticoll`

**Descrição:**  
Executa o processo de anticolisão para evitar que múltiplos cartões respondam ao mesmo tempo.

**Parâmetros:**  
- **uint8_t* serNum**: Buffer onde o número de série do cartão será armazenado.

**Retorno:**  
- **uint8_t**: Código de status da operação.

---

### `CalulateCRC`

**Descrição:**  
Calcula o CRC de dados para comunicação com o cartão RFID.

**Parâmetros:**  
- **uint8_t* pIndata**: Dados para os quais o CRC será calculado.  
- **uint8_t len**: Comprimento dos dados.  
- **uint8_t* pOutData**: Buffer onde o CRC calculado será armazenado.

**Retorno:**  
- **void**

---

### `MFRC522_Write`

**Descrição:**  
Escreve um bloco de dados no cartão RFID.

**Parâmetros:**  
- **uint8_t blockAddr**: Endereço do bloco onde os dados serão escritos.  
- **uint8_t* writeData**: Dados a serem escritos no cartão.

**Retorno:**  
- **uint8_t**: Código de status da operação.

---

### `MFRC522_Read`

**Descrição:**  
Lê um bloco de dados do cartão RFID.

**Parâmetros:**  
- **uint8_t blockAddr**: Endereço do bloco a ser lido.  
- **uint8_t* recvData**: Buffer onde os dados lidos serão armazenados.

**Retorno:**  
- **uint8_t**: Código de status da operação.

---

### `MFRC522_Auth`

**Descrição:**  
Autentica um bloco do cartão RFID para leitura ou escrita.

**Parâmetros:**  
- **uint8_t authMode**: Modo de autenticação (geralmente `PICC_AUTHENT1A`).  
- **uint8_t blockAddr**: Endereço do bloco a ser autenticado.  
- **uint8_t* key**: Chave de autenticação.  
- **uint8_t* serNum**: Número de série do cartão.

**Retorno:**  
- **uint8_t**: Código de status da operação.

---

### `MFRC522_SelectTag`

**Descrição:**  
Seleciona o cartão RFID com base no número de série.

**Parâmetros:**  
- **uint8_t* serNum**: Número de série do cartão a ser selecionado.

**Retorno:**  
- **uint8_t**: Código de status da operação.

---

### `MFRC522_Halt`

**Descrição:**  
Coloca o cartão RFID no estado de Halt (parada).

**Parâmetros:**  
- **Nenhum**

**Retorno:**  
- **void**

---

### `Read_Single_Card`

**Descrição:**  
Realiza a leitura de um único cartão RFID, autenticando e lendo o bloco de dados.

**Parâmetros:**  
- **uint8_t* serNum**: Buffer onde o número de série do cartão será armazenado.  
- **uint8_t* recvData**: Buffer onde os dados lidos serão armazenados.

**Retorno:**  
- **uint8_t**: Código de status da operação.

---

### `Read_Multiple_Cards`

**Descrição:**  
Lê múltiplos cartões RFID, um por vez, realizando a autenticação e leitura de dados de cada cartão encontrado.

**Parâmetros:**  
- **uint8_t* serNum**: Buffer onde o número de série do cartão será armazenado.  
- **uint8_t* recvData**: Buffer onde os dados lidos de cada cartão serão armazenados.

**Retorno:**  
- **uint8_t**: Código de status da operação.

---

### `Write_Content_Card`

**Descrição:**  
Escreve um conteúdo personalizado em um bloco do cartão RFID após autenticação.

**Parâmetros:**  
- **uint8_t blockAddr**: Endereço do bloco onde os dados serão escritos.  
- **uint8_t* writeData**: Buffer contendo os dados que serão escritos no cartão.  
- **uint8_t* serNum**: Número de série do cartão a ser escrito.  
- **uint8_t* key**: Chave de autenticação.

**Retorno:**  
- **uint8_t**: Código de status da operação.

---

### `Read_Content_Card`

**Descrição:**  
Lê o conteúdo de um bloco de um cartão RFID após autenticação.

**Parâmetros:**  
- **uint8_t blockAddr**: Endereço do bloco a ser lido.  
- **uint8_t* recvData**: Buffer onde os dados lidos serão armazenados.  
- **uint8_t* serNum**: Número de série do cartão a ser lido.  
- **uint8_t* key**: Chave de autenticação.

**Retorno:**  
- **uint8_t**: Código de status da operação.

## Esquemático
![Schematic](schematic.png)

## Tratamento de Erros

### Erros Comuns

- **MI_OK**: Operação concluída com sucesso
- **MI_ERR**: Erro de comunicação com o cartão RFID. Verifique as conexões SPI.
- **MI_NOTAGERR**: Nenhum cartão detectado. Certifique-se de que o cartão esteja no campo de leitura.


## Contribuição

Sinta-se à vontade para enviar pull requests ou abrir issues para melhorias e correções que sejam nescessário para um melhor funcionamento da biblioteca.




