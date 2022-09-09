//Opção 1

/*#include <MFRC522.h> //biblioteca RFID
#include <SPI.h> //biblioteca comunicação serial

MFRC522 mfrc522(53, 5); //pinos SS e RST no Arduino Mega

void setup() {
  Serial.begin(9600); //inicia Monitor Serial
  SPI.begin(); //inicia comunicação SPI
  mfrc522.PCD_Init(); //inicia o módulo RFID

  Serial.println("Aproxime o cartão");
  // put your setup code here, to run once:

}

void loop() {
  //verifica se existe um cartao presente e começa a leitura
  if ((mfrc522.PICC_IsNewCardPresent()) && (mfrc522.PICC_ReadCardSerial())) {
    String rfid = ""; //variavel para armazenar o UID
    Serial.print("Tag: ");
    //verifica os 4 bytes da UID
    for (byte i = 0; i < 4; i++) {
      rfid += (mfrc522.uid.uidByte[i] < 0x10 ? "0" : "") + String(mfrc522.uid.uidByte[i], HEX) + (i != 3 ? ":" : "");
      //concatena os bytes lidos dentro da variável, converte em hexadecimal e separa por : (dois pontos)
    }
    rfid.toUpperCase(); //joga as letras para maiúsculas
    Serial.println(rfid); //imprime o UID
    delay(500); //aguarda meio segundo para fazer uma nova leitura
  }
  // put your main code here, to run repeatedly:

}
*/

//Opção 2

/*
#include <MFRC522.h> //biblioteca RFID

#include <SPI.h> //biblioteca comunicação serial

MFRC522 mfrc522(53, 5); //pinos SS e RST no Arduino Mega

void setup() {
  Serial.begin(9600); //inicia Monitor Serial
  SPI.begin(); //inicia comunicação SPI
  mfrc522.PCD_Init(); //inicia o módulo RFID

  Serial.println("Aproxime o cartão");
  // put your setup code here, to run once:

}

void loop() {
  //verifica se existe um cartao presente e começa a leitura
  if ((mfrc522.PICC_IsNewCardPresent()) and (mfrc522.PICC_ReadCardSerial())) {
    Serial.print("Tag: ");
    //verifica os 4 bytes da UID e mostra na tela
    for (byte i = 0; i < 4; i++) {
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "); //vide tabela ASCII
      Serial.print(mfrc522.uid.uidByte[i], HEX); //converte os caracteres para hexadecimal
    }
    Serial.println();
    delay(500); //aguarda meio segundo para fazer nova leitura
  }
  // put your main code here, to run repeatedly:

}
*/
