#include <Arduino.h>
#include <SoftwareSerial.h>


float Ultrasonic_Read(int RX_us, int TX_us) 
//input the RX and TX pin numbers, returns distance reading from ultrasonic sensor
{
    unsigned char data[4] = {};
    float distance;

    //This should only happen once but i dont know how to implement that with function notation
    SoftwareSerial mySerial(RX_us, TX_us); // RX, TX

    //should be in setup loop but idk how to implement
    mySerial.begin(9600);

    //Without this delay, the US would not have enough time to "start up" and would give no correct readings
    delay(100);

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

    //Invalid reading - return 0
    //Reading below lower limit - return 0
    if (sum == data[3])
    {
      distance = (data[1] << 8) + data[2];
      if (distance > 280)
      {
        return distance/1000;
      } 
      else 
      {
        Serial.println("US below lower limit");
        return 0.;
      }
    
    } else {
        Serial.println("ERROR - ultrasonic reading error");
        return 0.;
    }
  }


}




















