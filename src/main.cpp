#include <Arduino.h>
#include <math.h>

#include <SoftwareSerial.h>

#include <ultrasonic.h>
#include <TeleplotWrite.h>

int RX_us = 11;
int TX_us = 10;

float distance;


//--------
//SoftwareSerial mySerial(RX_us, TX_us);
unsigned char data[4] = {};


void setup() {
  Serial.begin(57600);

}

float i=0;

void loop() {
  

  distance = Ultrasonic_Read(RX_us,TX_us);
  Serial.println(distance);


  //fdfdf

  
}

