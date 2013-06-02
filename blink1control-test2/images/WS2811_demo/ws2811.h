/*------------------------------------------------------------------------
  Some pin mappings for different chips
------------------------------------------------------------------------*/

// PB4 on Tiny85
#if defined (__AVR_ATtiny85__)
#define LED_DDR DDRB
#define LED_PORT PORTB
#define LED_PIN PINB
#define LED_BIT _BV(3)

// PA0 on Tiny84
#elif defined (__AVR_ATtiny84__)
#define LED_DDR DDRA
#define LED_PORT PORTA
#define LED_PIN PINA
#define LED_BIT _BV(0)

#else
// Assume Arduino Uno, digital pin 8 (ie. port B, pin 0)
// See http://arduino.cc/en/Hacking/PinMapping168 for pin mappings

#define LED_DDR DDRB
#define LED_PORT PORTB
#define LED_PIN PINB
#define LED_BIT _BV(0)

#endif

#define NOP __asm__("nop\n\t")

/*------------------------------------------------------------------------
  WS2811 control functions
------------------------------------------------------------------------*/
class WS2811 {
public:
  static void init() {
    LED_PORT &= ~LED_BIT;
    LED_DDR |= LED_BIT;
  }

  static void sendByte(byte b) {
    byte i=8;
    do {
      if ((b&0x80)==0) {
        // Send a '0'
        if (F_CPU==16000000L) {
          LED_PIN=LED_BIT;NOP;// Hi (start)
          NOP;NOP;            // Hi
          LED_PIN=LED_BIT;NOP;// Lo (250ns)
          NOP;NOP;            // Lo
          NOP;NOP;            // Lo (500ns)
        }
        else if (F_CPU==8000000L) {
          LED_PIN = LED_BIT;  // Hi (start)
          NOP;                // Hi
          LED_PIN = LED_BIT;  // Lo (250ns)
          NOP;                // Lo
          NOP;                // Lo (500ns)
          NOP;                // Lo (data bit here!)  
          NOP;                // Lo (750ns)
        }
      }
      else {
        // Send a '1'
        if (F_CPU==16000000L) {
          LED_PIN=LED_BIT;NOP;// Hi (start)
          NOP;NOP;            // Hi
          NOP;NOP;            // Hi (250ns)
          NOP;NOP;            // Hi
          NOP;NOP;            // Hi (500ns)
          LED_PIN=LED_BIT;    // Lo (625ns)
        }
        else if (F_CPU==8000000L) {
          LED_PIN = LED_BIT;  // Hi (start)
          NOP;                // Hi
          NOP;                // Hi (250ns)
          NOP;                // Hi
          NOP;                // Hi (500ns)
          NOP;                // Hi (data bit here!)
          LED_PIN = LED_BIT;  // Lo (750ns)
        }
      }
      b = b+b;
    } while (--i!=0);
  }
};
WS2811 ws2811;

/*------------------------------------------------------------------------
  LED object
------------------------------------------------------------------------*/
class LED {
  byte r_,g_,b_;
public:
  LED& setColor(byte r, byte g, byte b) {
    r_ = r;
    g_ = g;
    b_ = b;
  }
  // nb. Interrupts must be disabled when you use this
  void send() const {
    cli();      // Lest we forget...
    ws2811.sendByte(g_);
    ws2811.sendByte(r_);
    ws2811.sendByte(b_);
  }
};


