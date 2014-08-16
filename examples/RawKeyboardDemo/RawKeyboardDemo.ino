/*
 RawKeyboard Demo
 Copyright (c) 2014 NicoHood.  All right reserved.
 
 This is a simple Demo to show you how to use the RawKeyboard with this library.
 
 Some additional Information:
 *The first input is for modifiers
 *The second input is for the key
 *Make sure to add a proper debounce
 *Make sure to release a button if you use Media.pressRawKeyboard
 *This is just a faster solution for pressing one key + modiers
 *This library also supports Media Keys, see other Demo
 
 Resources:
 https://github.com/aduitsis/ardumultimedia/blob/master/HID.cpp
 https://github.com/aduitsis/ardumultimedia/blob/master/arduremote.ino
 http://stefanjones.ca/blog/arduino-leonardo-remote-multimedia-keys/
 http://eleccelerator.com/tutorial-about-usb-hid-report-descriptors/
 http://www.usb.org/developers/hidpage/
 http://www.usb.org/developers/devclass_docs/Hut1_12v2.pdf
 http://www.usb.org/developers/devclass_docs/HID1_11.pdf
 https://www.silabs.com/Support%20Documents/TechnicalDocs/AN249.pdf
 */

#include "MediaKeys.h"

#define TXLED_BLINK    PORTD ^= (1<<5)
#define RXLED_BLINK    PORTB ^= (1<<0)

const uint8_t buttonPin = 8;

void setup(){
  TX_RX_LED_INIT;
  startup(buttonPin); //a button has to be pressed to continue for safety

  delay(500); //simple debounce

  //while(!Serial); //wait for serial communication
  Serial.begin(9600); //This pipes to the serial monitor
  Serial.println("Ready");
}

void loop(){
  if (digitalRead(buttonPin) == 0)  // if the button goes low
  {
    RXLED1;
    Media.pressRawKeyboard(KEYBOARD_LEFT_CTRL | KEYBOARD_LEFT_ALT , KEYBOARD_DELETE); //modifiers + key
    Keyboard.releaseAll(); //normal function provided by the normal library
    delay(500); //simple debounce
  }
  RXLED0;
}

void startup(uint8_t buttonPin){  
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH); //pullup
  unsigned long previousMillis;

  while(digitalRead(buttonPin)==1){ //wait for buttonpress
    if(millis() - previousMillis > 100) {
      previousMillis = millis();   
      TXLED_BLINK; //blink LED
    }
  }
  TXLED0;
}


/*
 See Hut1_12v2.pdf Chapter 10 (Page 53) for more Keys
 Not every Key is supported (by your pc). Also it's limited to key 101/0x65 by the usb descriptor.
 These are the most common used and working keys.
 
 //Raw Keyboard definitions
 #define KEYBOARD_LEFT_CTRL  	 B00000001
 #define KEYBOARD_LEFT_SHIFT 	 B00000010
 #define KEYBOARD_LEFT_ALT   	 B00000100
 #define KEYBOARD_LEFT_GUI  	 B00001000
 #define KEYBOARD_RIGHT_CTRL	 B00010000
 #define KEYBOARD_RIGHT_SHIFT	 B00100000
 #define KEYBOARD_RIGHT_ALT  	 B01000000
 #define KEYBOARD_RIGHT_GUI 	 B10000000
 
 #define KEYBOARD_UP_ARROW		0x52
 #define KEYBOARD_DOWN_ARROW		0x51
 #define KEYBOARD_LEFT_ARROW		0x50
 #define KEYBOARD_RIGHT_ARROW		0x4F
 #define KEYBOARD_BACKSPACE		0x2A
 #define KEYBOARD_TAB			0x2B
 #define KEYBOARD_RETURN		0x28
 #define KEYBOARD_ESC			0x29
 #define KEYBOARD_INSERT		0x49
 #define KEYBOARD_DELETE		0x4C
 #define KEYBOARD_PAGE_UP		0x4B
 #define KEYBOARD_PAGE_DOWN		0x4E
 #define KEYBOARD_HOME			0x4A
 #define KEYBOARD_END			0x4D
 #define KEYBOARD_CAPS_LOCK		0x39
 #define KEYBOARD_F1			0x3A
 #define KEYBOARD_F2			0x3B
 #define KEYBOARD_F3			0x3C
 #define KEYBOARD_F4			0x3D
 #define KEYBOARD_F5			0x3E
 #define KEYBOARD_F6			0x3F
 #define KEYBOARD_F7			0x40
 #define KEYBOARD_F8			0x41
 #define KEYBOARD_F9			0x42
 #define KEYBOARD_F10			0x43
 #define KEYBOARD_F11			0x44
 #define KEYBOARD_F12			0x45
 #define KEYBOARD_PRINT			0x46
 #define KEYBOARD_SCROLL_LOCK		0x47
 #define KEYBOARD_PAUSE			0x48
 
 //Keyboard fixed/added missing Keys
 #define KEY_PRINT			0xCE
 #define KEY_SCROLL_LOCK		0xCF
 #define KEY_PAUSE			0xD0
 */

