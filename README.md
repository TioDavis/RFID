<h1>Controle de Acesso com RFID</h1>
<h3>Introdução</h3>
<p align=justify>Este projeto consiste em um sistema de controle de acesso eletrônico, por meio de identificação via RFID. O código principal é o RFID_Controle, que dá vida ao sistema. Os demais arquivos são códigos referências, usados como apoio no desenvolvimento do projeto, encontrados em fóruns e tutoriais onlines (o código na pasta RFID_Leitura retorna todas as informações contidas na tag/cartão RFID; RFID_Opcoes_Leitura apresenta duas formas de ler apenas a identificação HEX do cartão; Scroll_Uma_Linha é para rolar o texto em uma linha enquanto que a outra se mantém estática no display LCD).</p>
<h4>Bibliotecas utilizadas:</h4>
<li>LiquidCrystal - display LCD 16x2</li>
<li>Servo - servo motor (representando uma cancela ou uma fechadura eletrônica)</li>
<li>MFRC522 - módulo RFID RC522</li>
<li>SPI - comunicação serial</li>
<h4>Material:</h4>
<li>Arduino Mega;</li>
<li>Display LCD 16x2;</li>
<li>LEDs (verde e vermelho);</li>
<li>Resistor 150R;</li>
<li>Servo motor 9g SG90;</li>
<li>Módulo RFID MFRC522 13,56MHz com tag e cartão;</li>
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
<h3>LCD 16x2</h3>
<p><b>Pinos LCD 16x2</b></p>
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
<h3>O Projeto</h3>
<p align=justify>Quando se aproxima a etiqueta com o UID cadastrado o servo é acionado, como se fosse uma cancela, girando 180° para um lado e depois de um segundo retorna para a posição original. Ainda é apresentado uma mensagem no display, dando as boas-vindas ao usuário, e acende o LED verde, indicando que está liberado o acesso. Quando é aproximado a etiqueta com o UID não cadastrado o servo motor não é acionado, o display apresenta a mensagem de usuário desconhecido e o LED vermelho acende, indicando que o acesso não foi liberado.</p>
<p align=justify>O circuito com os esquemas de ligação é mostrado abaixo. A única diferença está no potenciômetro para ajuste do contraste do display. No meu circuito joguei o pino VO diretamente no GND para ter maior visibilidade, mas caso necessário a inclusão do potenciômetro ele deve ser conectado conforme o circuito abaixo.</p>
<p><b>Circuito do Projeto</b></p>
<img src="l1nq.com/7Z8Fp">
<p>Há diferença na pinagem SPI dos Arduinos, dependendo da placa utilizada. A tabela abaixo possui os pinos das placas MEGA e UNO</p>
<table>
  <tr><td><b>RC522</b></td><td><b>MEGA</b></td><td><b>UNO</b></td></tr>
  <tr><td>MISO</td><td>50</td><td>12</td></tr>
  <tr><td>MOSI</td><td>51</td><td>11</td></tr>
  <tr><td>SCK</td><td>52</td><td>13</td></tr>
  <tr><td>SDA</td><td>53</td><td>10</td></tr>
</table>
