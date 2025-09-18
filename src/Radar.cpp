#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Radar.h>

void radar_setup(uint16_t min, uint16_t max, uint16_t thres, int RX_r, int TX_r, SoftwareSerial mySerialRadar, DFRobot_C4001_UART radar) 
//include this in setup, after Serial.begin()
{

/*
SoftwareSerial mySerial(RX_r, TX_r);
DFRobot_C4001_UART radar(&mySerial, 9600); 
*/


while (!Serial)
    ;
while (!radar.begin()) {
    Serial.println("NO Radar Deivces !");
    delay(500);
  }
  Serial.println("Radar Device connected!");

  // speed Mode
  radar.setSensorMode(eSpeedMode);

  /*
   * min Detection range Minimum distance, unit cm, range 0.3~20m (30~2500), not exceeding max, otherwise the function is abnormal.
   * max Detection range Maximum distance, unit cm, range 2.4~20m (240~2500)
   * thres Target detection threshold, dimensionless unit 0.1, range 0~6553.5 (0~65535)
   */
  if (radar.setDetectThres(/*min*/ min, /*max*/ max, /*thres*/ thres)) {
    Serial.println("set detect threshold successfully");
  }

  // set Fretting Detection
  radar.setFrettingDetection(eON);


}




//Is there a better way without using delays?
//I have to redefine the variables upon every reading - how do i avoid this?

float radar_speed(int RX_r, int TX_r, SoftwareSerial mySerialRadar, DFRobot_C4001_UART radar)
//speed
{
    radar.getTargetNumber();
    
    //delay(100);
    return radar.getTargetSpeed();
}


float radar_range(int RX_r, int TX_r, SoftwareSerial mySerialRadar, DFRobot_C4001_UART radar)
//distance
{
    radar.getTargetNumber();
    //delay(100);
    return radar.getTargetRange();  
}


uint32_t radar_energy(int RX_r, int TX_r, SoftwareSerial mySerialRadar, DFRobot_C4001_UART radar)
//not sure what this is yet
{
    radar.getTargetNumber();

    //delay(100);
    return radar.getTargetEnergy();
}


