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
//defining softwareserial twice will cause issues as only the second instance will work, but since the definition for the US is within its own looped code, it will always be the second instance in US mode
//for radar, it is defined here in the global scope so it will always be the latest instance in radar mode


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int read_data = 1 ;
  // 0 = Ultrasonic
  // 1 = Radar

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void setup() {
  Serial.begin(57600);

  if (read_data == 1) {
  radar_setup(11,1200,10,RX_r,TX_r,mySerialRadar,radar);
  }

}

void loop() { 


  //depending on read data mode, print and read data accordingly
  if (read_data == 0) {

    valuetimegraph("US Distance",Ultrasonic_Read(RX_us,TX_us));

  } else if (read_data == 1) {

    valuetimegraph("Target Distance (radar)",radar_range(RX_r, TX_r, mySerialRadar, radar));
    valuetimegraph("Target Speed (radar)",radar_speed(RX_r, TX_r, mySerialRadar, radar));
    valuetimegraph("Target Energy (radar)",radar_energy(RX_r, TX_r, mySerialRadar, radar));

  } else {
    Serial.println("Select appropriate sensor to read");
  }


}