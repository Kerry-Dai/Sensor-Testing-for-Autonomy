#ifndef RADAR_H
#define RADAR_H
#include "DFRobot_C4001.h"

void radar_setup(uint16_t min, uint16_t max, uint16_t thres, int RX_r, int TX_r, SoftwareSerial mySerialRadar, DFRobot_C4001_UART radar);

float radar_range(int RX_r, int TX_r, SoftwareSerial mySerialRadar, DFRobot_C4001_UART radar);

float radar_speed(int RX_r, int TX_r, DFRobot_C4001_UART radar);

uint32_t radar_energy(int RX_r, int TX_r, DFRobot_C4001_UART radar);



//These lines need to be above void setup in main
/*

int RX_r = 5;   //set the rx and tx pins
int TX_r = 4;

SoftwareSerial mySerial(4, 5);  //define the variables
DFRobot_C4001_UART radar(&mySerial, 9600);

*/

//These lines need to be in setup in main
/*

  radar_setup(11,1200,10,RX_r,TX_r,mySerial,radar);

*/



#endif