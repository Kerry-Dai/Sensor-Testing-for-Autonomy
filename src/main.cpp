#include <Arduino.h>
#include <math.h>

#include <SoftwareSerial.h>

#include <ultrasonic.h>
#include <TeleplotWrite.h>
#include <Radar.h>


int RX_us = 11;
int TX_us = 10;

int RX_r = 5;
int TX_r = 4;

float distanceR,distanceUS;

SoftwareSerial mySerialRadar(TX_r, RX_r);
DFRobot_C4001_UART radar(&mySerialRadar, 9600);


void setup() {
  Serial.begin(57600);

  radar_setup(11,1200,10,RX_r,TX_r,mySerialRadar,radar);


}

void loop() {

  valuetimegraph("US Distance",Ultrasonic_Read(RX_us,TX_us));

  //valuetimegraph("Radar Distance",radar_range(RX_r, TX_r, mySerialRadar, radar));







}