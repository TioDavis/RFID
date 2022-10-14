# RFID
<h2>Controle de Acesso com RFID</h2>
<h3>Introdução</h3>
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
<h3>MFRC522</h3>
<p align=justify>O módulo MRFC522 permite fazer a leitura de qualquer etiqueta do padrão Mifare que utiliza frequência de 13,56MHz em formato de cartão e tags tipo chaveiro e pulseira. Cada etiqueta possui um Identificador Único, denominado UID. É um código hexadecimal de 4 bytes. A alimentação do módulo é 3,3V e por isso é aconselhável o uso de um conversor de nível de tensão nos pinos de comunicação SPI. O módulo funciona bem quando conectado diretamente ao Arduino, porém no limite.</p>
<p><b>Pinos RC522</b></p>
<table>
  <tr><td>SDA ou SS</td><td>Habilita o módulo para comunicação</td></tr>
  <tr><td>SCK</td><td>Clock para sincronizar os dispositivos</td></tr>
  <tr><td>MOSI</td><td>Saída de dados do Arduino</td></tr>
  <tr><td>MISO</td><td>Entrada de dados do Arduino</td></tr>
  <tr><td>IRQ</td><td>Interrupção quando registra atividade (não conectado ao Arduino)</td></tr>
  <tr><td>GND</td><td>0V</td></tr>
  <tr><td>RST</td><td>Reset</td></tr>
  <tr><td>3.3V</td><td>Alimentação VCC</td></tr>
</table>
<h3>SPI</h3>
<p align=justify>O SPI é um protocolo de comunicação serial síncrona full-duplex para distâncias curtas.</p>
<p><li><b>MOSI (Master Output Slave Input) –</b> o mestre envia informações ao escravo;</li>
  <li><b>MISO (Master Input Slave Output) –</b> o escravo envia informações ao mestre;</li>
  <li><b>SCK (Serial Clock) –</b> sincroniza a transmissão e determina a velocidade e quantidade de bits enviados;</li>
  <li><b>SS (Slave Select) –</b> seleciona o escravo para estabelecer a comunicação.</li></p>
<h3>LCD 16X2</h3>
<p><b>Pinos LCD 16X2</b></p>
<table>
  <tr align=center><td>VSS</td><td>Alimentação 0V (GND)</td></tr>
  <tr align=center><td>VDD</td><td>Alimentação 5V (VCC)</td></tr>
  <tr align=center><td>VO</td><td>Contraste do LCD</td></tr>
  <tr align=center><td>RS</td><td>Seleção de comandos (0) ou dados (1)</td></tr>
  <tr align=center><td>R/W</td><td>Leitura (1) e escrita (0)</td></tr>
  <tr align=center><td>E</td><td>Ativa (1) / desativa (0) o display (Enable)</td></tr>
  <tr align=center><td>DB4</td><td>Data bit 4</td></tr>
  <tr align=center><td>DB5</td><td>Data bit 5</td></tr>
  <tr align=center><td>DB6</td><td>Data bit 6</td></tr>
  <tr align=center><td>DB7</td><td>Data bit 7</td></tr>
  <tr align=center><td>A</td><td>Anodo da iluminação (5V)</td></tr>
  <tr align=center><td>K</td><td>Catodo da iluminação (GND)</td></tr>
</table>



</p>
<p align=justify>


<p align=justify></p>
<p align=justify></p>
<p align=justify></p>
<p align=justify></p>
<p align=justify></p>
<p align=justify></p>
