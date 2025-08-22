#include <Arduino.h>
#include <math.h>

#include <SoftwareSerial.h>
#include <ultrasonic.h>

int RX_us = 11;
int TX_us = 10;

float distance;


//--------
SoftwareSerial mySerial(RX_us, TX_us);
unsigned char data[4] = {};


void setup() {
  Serial.begin(57600);
  // Print log
  Serial.println("setup");

  //Set up j graph space
  Serial.println(">j:100:0;0:100|xy");
  
  //--------
  mySerial.begin(9600);

}

float i=0;
int j=0;
void loop() {
  
  do {
      for (int i = 0; i < 4; i++)
      {
        data[i] = mySerial.read();
      }
    } while (mySerial.read() == 0xff);

    mySerial.flush();

    if (data[0] == 0xff)
    {
      int sum;
      sum = (data[0] + data[1] + data[2]) & 0x00FF;

      //Invalid reading - return NULL
      //Reading below lower limit - return NULL
      if (sum == data[3])
      {
        distance = (data[1] << 8) + data[2];
        if (distance > 280)
        {
          Serial.print(">Distance:");
          Serial.println(distance);
        } 
        else 
        {
          Serial.println("US below lower limit");
          Serial.print(">Distance:");
          Serial.println(0);
        }
      
      } else {
          Serial.println("ERROR - ultrasonic reading error");
      }
    }



  //distance = Ultrasonic_Read(RX_us,TX_us);
  //Serial.print(">DistanceUS:"); Serial.println(distance);

  delay(100);
  
  j=j+1;
  Serial.print(">j:");
  Serial.print(j/1.1);
  Serial.print(":");
  Serial.print(j);
  Serial.println("|xy");

  if ( j % 120 == 0) {
    
    Serial.print(">j:");
    Serial.print(j/1.1+100);
    Serial.print(":");
    Serial.print(j/1.0-100);
    Serial.print(";");
    Serial.print(j/1.1-100);
    Serial.print(":");
    Serial.print(j/1.0+100);
    Serial.println("|clr");

    Serial.print(">j:");
    Serial.print(j/1.1+100);
    Serial.print(":");
    Serial.print(j/1.0-100);
    Serial.print(";");
    Serial.print(j/1.1-100);
    Serial.print(":");
    Serial.print(j/1.0+100);
    Serial.println("|xy");
  }

  
}