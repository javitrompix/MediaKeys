/*
 MediaKeys Demo
 Copyright (c) 2014 NicoHood.  All right reserved.
 
 This is a simple Demo to show you how to use the MediaKeys with this library.
 
 Some additional Information:
 *You can use the definitions at the end of the sketch for the special keys
 *You can add your own keys/see notation below
 *Make sure to add a proper debounce
 *Make sure to release a button if you use Media.press
 *This library also supports direct/faster keyinput, see other Demo
 
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
    Media.write(REMOTE_PLAY_PAUSE); //press + release
    //Media.press(REMOTE_PLAY_PAUSE);
    //Media.releaseAll();
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
 See Hut1_12v2.pdf Chapter 15 (Page 75) for more Keys
 Not every Key is supported (by your pc). No limitation by the usb descriptor here!
 These are the most common used and working keys.
 
 //Media Key definitions
 #define BROWSER_HOME 0x223
 #define BROWSER_BACK 0x224
 #define BROWSER_FORWARD 0x225
 #define BROWSER_REFRESH 0x227
 #define BROWSER_BOOKMARKS 0x22A
 
 #define SYSTEM_EMAIL_READER 0x18A
 #define SYSTEM_CALCULATOR 0x192
 #define SYSTEM_EXPLORER 0x194
 
 #define VOLUME_DOWN 0xEA
 #define VOLUME_UP 0xE9
 #define VOLUME_MUTE 0xE2
 
 #define REMOTE_PLAY 0xB0
 #define REMOTE_PAUSE 0xB1
 #define REMOTE_PLAY_PAUSE 0xCD
 #define REMOTE_STOP 0xB7
 #define REMOTE_NEXT 0xB5
 #define REMOTE_PREVIOUS 0xB6
 #define REMOTE_FAST_FORWARD 0xB3
 #define REMOTE_REWIND 0xB2
 */
