/*********************************************************************
  This is an Arduino library for the Sharp Monochrome Memory Displays.

  It is based off the Adafruit Library for Sharp Memory Displays.

  ********************************************************************
 
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

    Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/1393

  Written by Limor Fried/Ladyada for Adafruit Industries.
  BSD license, check license.txt for more information

 *********************************************************************

  Modified by John Schnurr, Sept 2016. Modified to use the Hardware SPI Pins.
  Faster frames can be achieved using the SPI pins. 
  Verified to work on a Mega, Due, and Zero.

  The Hardware pins required are:
                     MOSI              SCK                SS
  Arduino Mega:     51 (or ICSP 4)    52 (or ICSP 3)     Any Pin
  Arduino Due:      ICSP 4            ICSP 3             Any Pin
  Arduino Mega:     ICSP 4            ICSP 3             Any Pin

  You may need to adjust the SPI Clock Divisor to get the fastest operation.
  Although the Display is rated for 1Mhz, I was able to use a divisor of 8
  on the Due (12 MHz) and a divisor of 6 on the Zero (8 MHz).

  You can change the SHARPMEM_LCDWIDTH and SHARPMEM_LCDHEIGHT in
  Sharp_Mono_LCD.h for the size of display you are using.

*********************************************************************/

#include <Adafruit_GFX.h>
#include <Sharp_Mono_LCD.h>

#define SS 10 // set the Slave Select Pin here.

Sharp_Mono_LCD display(SS);

#define BLACK 0
#define WHITE 1


void setup() {
  // put your setup code here, to run once:
  display.begin();
  display.setRotation(0);

  //fill screen White
  display.fillRect(0, 0, 128, 128, WHITE);
  display.setCursor(20, 20);
  display.setTextColor(BLACK);
  display.print("White");

  //refresh must be called to send the image buffer to the display
  display.refresh();
  delay(1000);

  //fill screen Black
  display.fillRect(0, 0, 128, 128, BLACK);
  display.setCursor(20, 20);
  display.setTextColor(WHITE);
  display.print("Black");

  //refresh must be called to send the image buffer to the display
  display.refresh();
  delay(1000);


  //the clearBuffer command clears the image buffer and is faster than
  //using fillRect for the entire display.
  display.clearBuffer();

  //draw a circle
  display.drawCircle(30, 30, 25, BLACK);

  //draw a square
  display.drawRect(65, 5, 50, 50, BLACK);

  //draw a line
  display.drawLine(10, 65, 55, 120, BLACK);

  //draw a triangle
  display.drawTriangle(65, 65, 120, 65, 93, 120, BLACK);

  //send buffer to display
  display.refresh();
}

void loop() {
  display.fillRect(2, 2, 20, 8, WHITE);
  display.setCursor(3, 3);
  display.setTextColor(BLACK);
  display.print(millis() / 1000);
  display.refresh();
  delay(1000);
}
