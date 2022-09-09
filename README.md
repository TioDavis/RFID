# RFID
<h2>Controle de Acesso com RFID</h2>
<p align=justify>Este projeto consiste em um sistema de controle de acesso eletrônico, por meio de identificação via RFID. O código principal é o RFID_Controle, que dá vida ao sistema. Os demais arquivos são códigos referências, usados como apoio no desenvolvimento do projeto, encontrados em fóruns e tutoriais onlines (o código na pasta RFID_Leitura retorna todas as informações contidas na tag/cartão RFID; RFID_Opcoes_Leitura apresenta duas formas de ler apenas a identificação HEX do cartão; Scroll_Uma_Linha é para rolar o texto em uma linha enquanto que a outra se mantém estática no display LCD).</p>
<p>Bibliotecas utilizadas:</p>
<li>LiquidCrystal - display LCD 16x2</li>
<li>Servo - servo motor (representando uma cancela ou uma fechadura eletrônica)</li>
<li>MFRC522 - módulo RFID RC522</li>
<li>SPI - comunicação serial</li>
<br>
<p>Material:</p>
<li>Arduino Mega;</li>
<li>Display LCD 16x2;</li>
<li>LEDs (verde e vermelho);</li>
<li>Resistor 150R;</li>
<li>Servo motor 9g SG90;</li>
<li>Módulo RFID MFRC522 13,56MHz com tag e cartão;</li>
<br>
<p>O Arduino Mega usa as portas digitais 53 (SDA), 52 (SCK), 51 (MOSI) e 50 (MISO) na comunicação pelo protocolo SPI.</p>
