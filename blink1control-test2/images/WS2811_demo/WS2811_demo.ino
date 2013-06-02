/*------------------------------------------------------------------------
  WS2811 demo
------------------------------------------------------------------------*/
#include <Arduino.h>
#include <util/delay.h>
#include "ws2811.h"

/*------------------------------------------------------------------------
  Three LEDs
------------------------------------------------------------------------*/
LED led1,led2,led3;

void sendLEDs()
{
  // Send 60 LEDs
  for (byte i=0; i<20; ++i) {
    led1.send();
    led2.send();
    led3.send();
  }
  // Interrupts back on again (LED::send() turns them off...)
  sei();
}

/*------------------------------------------------------------------------
  Testing...
------------------------------------------------------------------------*/
void setup()
{
  // Initialize ws2811 object
  ws2811.init();

  // Set LED colors
  byte a = 0x00;
  byte b = 0x10;
  led1.setColor(b,b,a);
  led2.setColor(a,a,b);
  led3.setColor(b,a,b);
}

void loop()
{
  // Update LEDs
  sendLEDs();

  // Wait one second
  _delay_ms(1000);

  // Swap the LEDs around
  LED t = led1;
  led1 = led2;
  led2 = led3;
  led3 = t;
}


