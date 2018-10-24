#include <SPI.h>        
#include <Ethernet.h>
#include <EthernetUdp.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 10);
unsigned int localPort = 8888;

String machineIP = "192.168.1.2";
int machinePort = 3040;


EthernetUDP Udp;

void setup() {
  // put your setup code here, to run once:
  Ethernet.begin(mac,ip);
  Udp.begin(localPort);
  pinMode(0, INPUT_PULLUP);  

}

void loop() {
  // put your main code here, to run repeatedly:

  int sensorValue = digitalRead(0);

  if (sensorValue == HIGH) {
    Udp.beginPacket(machineIP, machinePort);
    Udp.write("gotoControlCue show\r\n");
    Udp.write("run\r\n");
    Udp.endPacket();
    delay(2000);
  }

}
