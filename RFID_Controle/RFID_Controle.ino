#include <LiquidCrystal.h> //biblioteca do display LCD 16x2
#include <Servo.h> //biblioteca do servo motor
#include <MFRC522.h> //biblioteca RFID
#include <SPI.h> //biblioteca comunicação serial

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //RS=12, E(ou EN)=11, D4=5, D5=4, D6=3 e D7=2

Servo myservo; //cria o objeto para controle do servo
int pos = 0; //variável para colocar o motor na origem (posição zero)

uint8_t uid_tag[4] = {0xEA, 0x60, 0x19, 0x86}; //UID utilizada para liberar o acesso

#define lvd 32 //led verde
#define lvm 33 //led vermelho

int aces = 0; //variável para liberar acesso

MFRC522 mfrc522(53, 6); //pinos SS e RST no Arduino Mega

void setup() {
  SPI.begin(); //inicia comunicação SPI
  mfrc522.PCD_Init(); //inicia o módulo RFID
  lcd.begin(16, 2); //inicializa o display e informa o seu tamanho em colunas e linhas

  myservo.attach(9); //define o pino 9 para o servo

  myservo.write(0); //inicia o servo na posição 0

  pinMode(lvd, OUTPUT);
  pinMode(lvm, OUTPUT);

  // put your setup code here, to run once:

}

void loop() {
  lcd.clear();
  lcd.print("   Aproxime o");
  lcd.setCursor(5, 1);
  lcd.print("cartao");
  //verifica se existe um cartao presente e começa a leitura
  if ((mfrc522.PICC_IsNewCardPresent()) and (mfrc522.PICC_ReadCardSerial())) {
    aces = 1;
    //verifica os 4 bytes da UID e mostra na tela
    for (byte i = 0; i < 4; i++) {
      if (uid_tag[i] != mfrc522.uid.uidByte[i]) {
        aces = 0;
      }
    }
    if (aces) {
      lcd.clear();
      lcd.print("ACESSO LIBERADO");
      digitalWrite(lvd, HIGH);
      for (pos = 0; pos <= 180; pos++) {
        myservo.write(pos);
        delay(15);
      }
      delay(1000);
      lcd.clear();
      lcd.print(" Seja bem vindo");
      lcd.setCursor(4, 1);
      lcd.print("Tio Davis");
      delay(1000);
      for (pos = 180; pos >= 0; pos--) {
        myservo.write(pos);
        delay(15);
      }
      digitalWrite(lvd, LOW);
    }
    else {
      lcd.clear();
      lcd.print(" ACESSO NEGADO");
      digitalWrite(lvm, HIGH);
      delay(1500);
      lcd.clear();
      lcd.print("    Usuario");
      lcd.setCursor(2, 1);
      lcd.print("desconhecido");
      delay(1500);
      digitalWrite(lvm, LOW);
    }
    delay(500); //aguarda meio segundo para fazer nova leitura
  }
  // put your main code here, to run repeatedly:

}
