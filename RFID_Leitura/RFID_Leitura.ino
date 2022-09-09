//Mundo Projetado https://mundoprojetado.com.br/modulo-rfid-rc522/
//Leitura completa de tags

#include <SPI.h>
#include <MFRC522.h>

// Pino para colocar no modo "power-down"
// Não estamos utilizando no circuito proposto
#define PINO_RST  5
// Pino SS (no módulo está escrito SDA neste pino)
#define PINO_SS   53

// Instância do módulo
MFRC522 mfrc522(PINO_SS, PINO_RST);

void setup()
{
  // Inicia a comunicação serial (monitor serial)
  Serial.begin(9600);

  // Inicia a comunicação SPI
  SPI.begin();

  // Inicia o módulo
  mfrc522.PCD_Init();
  // Delay optativo (talvez necessário em algumas placas)
  delay(4);
  // Informa os detalhes do módulo
  mfrc522.PCD_DumpVersionToSerial();

  Serial.println("Passe um cartão no leitor para obter algumas informações dele.");
}

void loop()
{
  // Verifica se existe um cartão presente para leitura
  if (mfrc522.PICC_IsNewCardPresent())
  {
    // Se sim, começa a ler o cartão
    if (mfrc522.PICC_ReadCardSerial())
    {
      // Coloca as informações do cartão no monitor serial
      mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
    }
  }
}
