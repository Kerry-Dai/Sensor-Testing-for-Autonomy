#include <Arduino.h>
#include <math.h>

#include <SoftwareSerial.h>
#include <ultrasonic.h>

int RX_us = 11;
int TX_us = 10;

float distance;


//--------
//SoftwareSerial mySerial(RX_us, TX_us);
unsigned char data[4] = {};


void setup() {
  Serial.begin(57600);
  // Print log
  Serial.println("setup");

  
  //-------- 
  //mySerial.begin(9600);

}

float i=0;

void loop() {
  

  distance = Ultrasonic_Read(RX_us,TX_us);
  Serial.print(">DistanceUS:"); Serial.println(distance);

  
}