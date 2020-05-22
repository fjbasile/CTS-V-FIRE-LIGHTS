#include <Adafruit_CircuitPlayground.h>

int red;
int blue;
int green;

const int DELAY = 10;
const int lowDel = 5;
const int highDel = 400;

const int RANDLOW = 30;
const int RANDHI = 256;

void setup()
{
  CircuitPlayground.begin(); 
  randomSeed(analogRead(0));
}
 
void loop()
{ 
    red = random(RANDLOW, RANDHI);
    blue = random(RANDLOW, RANDHI);
    green = random(RANDLOW, RANDHI);
    //for (int light = 0; light < 10; light ++)
    //{
      CircuitPlayground.setPixelColor(0, red, blue, green);
    //}
    delay(random(lowDel,highDel)); 
}
