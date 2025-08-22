#include <Arduino.h>
#include <TeleplotWrite.h>
#include <math.h>


void valuetimegraph(const char * graph_title, float value)
//print the data in default value-time format
{
    Serial.print(">");
    Serial.print(graph_title);
    Serial.print(":");
    Serial.println(value);

}

void xygraph(char graph_title, float x, float y)
//print the data in xy format (no time axis)
{

    Serial.print(">");
    Serial.print(graph_title);
    Serial.print(":");
    Serial.print(x);
    Serial.print(":");
    Serial.print(y);
    Serial.println("|xy");

}


void xysetscale(char graph_title, float xcentre, float ycentre, float xwidth, float ywidth)
//print four corners on the graph - make sure the data does not exceed the corners or the formatting will look weird
{
    Serial.print(">");
    Serial.print(graph_title);
    Serial.print(":");
    Serial.print(xcentre+xwidth/2);
    Serial.print(":");
    Serial.print(ycentre+ywidth/2);
    Serial.print(";");
    Serial.print(xcentre-xwidth/2);
    Serial.print(":");
    Serial.print(ycentre-ywidth/2);
    Serial.println("|xy");

}