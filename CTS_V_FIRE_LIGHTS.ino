#include <Adafruit_NeoPixel.h>

//Hardware Config
#define LED_PIN 1 //digital PWM output pin
#define LED_COUNT 8 //total number of NeoPixels
#define ANALOG_PIN 3 //analog seed pin used to generate random #'s
#define BRIGHTNESS 127 //led brightness

//Delay perameters 
#define DELAY  10 //delay interval between next loop iteration
#define lowDel 5 //low delay interval in ms
#define highDel 400 //high delay interval in ms
#define RANDLOW 30 //lowest random RGB value
#define RANDHI 256 //highest random RGB value

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int red;
int blue;
int green;

void setup()
{

  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif
  
  strip.begin(); //initiate the strip
  strip.setBrightness(BRIGHTNESS); //set the brightness
  strip.show(); //sets pixels to off
  randomSeed(analogRead(ANALOG_PIN)); //random number seed generation
}
 
void loop()
{ 
    //sets the color of each light
    for (int light = 0; light < LED_COUNT; light ++)
    {
      red = random(RANDLOW, RANDHI); //random red color
      blue = random(RANDLOW, RANDHI); //random blue color
      green = random(RANDLOW, RANDHI); //random green color
      strip.setPixelColor(light, red, blue, green);
      strip.show();
    }
    delay(random(lowDel,highDel)); 
}
