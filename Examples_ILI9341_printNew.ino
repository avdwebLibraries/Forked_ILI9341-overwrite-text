#include "Arduino.h"
#include <Wire.h>
#include "Adafruit_ILI9341_Albert.h"
//#include "Adafruit_GFX.h" // https://github.com/adafruit/Adafruit-GFX-Library
//#include "Adafruit_ILI9341.h" // 240x320 https://github.com/adafruit/Adafruit_ILI9341
#include <Fonts/FreeSans12pt7b.h> // https://learn.adafruit.com/adafruit-gfx-graphics-library/using-fonts
#include <Fonts/FreeSans24pt7b.h> 

const byte TFT_DC = A3;
const byte TFT_CS = A1;
const byte TFT_RST = A0;

Adafruit_ILI9341_Albert tft = Adafruit_ILI9341_Albert(TFT_CS, TFT_DC, TFT_RST);

void setup() 
{ Wire.begin();  // join I2C bus
  tft.begin();
  tft.setRotation(3);
}

void loop()
{ tft.fillScreen(ILI9341_BLACK); 
  tft.setTextColor(ILI9341_WHITE, ILI9341_BLACK); 
  // String with standard font
  tft.setCursor(0, 40); 
  tft.setTextSize(2);
  tft.print("Write over standard font");
  delay(1000);
  tft.setCursor(0, 40); 
  tft.printNew("New text", "Write over standard font");
  delay(1000);
  tft.fillScreen(ILI9341_BLACK); 
  tft.setTextSize(0);
  // String with FreeSans12pt7b
  tft.setFont(&FreeSans12pt7b);
  tft.setCursor(0, 40); 
  tft.print("Write over FreeSans12pt7b");
  delay(1000);
  tft.setCursor(0, 40); 
  tft.printNew("New text", "Write over FreeSans12pt7b");
  delay(1000);
  // Number with standard font
  tft.setFont();
  tft.setTextSize(2);
  tft.fillScreen(ILI9341_BLACK); 
  tft.print("standard font");  
  test();
  tft.setTextSize(0);
  // Number with FreeSans12pt7b
  tft.setFont(&FreeSans12pt7b);
  tft.setCursor(0, 40); 
  tft.fillScreen(ILI9341_BLACK); 
  tft.print("FreeSans12pt7b");  
  test();
  // Number with FreeSans24pt7b
  tft.setFont(&FreeSans24pt7b);
  tft.fillScreen(ILI9341_BLACK); 
  tft.setTextColor(ILI9341_WHITE, ILI9341_BLACK); // ILI9341_BLACK needed, else background is white
  tft.setCursor(0, 40); 
  tft.println("FreeSans24");
  test();
  // Number with blue BG
  tft.fillScreen(ILI9341_BLUE); 
  tft.setTextColor(ILI9341_WHITE, ILI9341_BLUE); 
  tft.setCursor(0, 40); 
  tft.println("Blue BG");
  test();
  tft.setFont();
}

void test()
{ for(int i=100; i>=0; i-=50)
  { tft.setCursor(0, 90); 
    delay(500);
    tft.printNew(i, 3); // max number is 100
  }
}


  
