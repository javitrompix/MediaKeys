/*
 MediaKeys.h - library - description
 Copyright (c) 2014 NicoHood.  All right reserved.
 */

// ensure this library description is only included once
#ifndef MediaKeys_h
#define MediaKeys_h

#include "Arduino.h"

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

//Raw Keyboard definitions
#define KEYBOARD_LEFT_CTRL   B00000001
#define KEYBOARD_LEFT_SHIFT  B00000010
#define KEYBOARD_LEFT_ALT    B00000100
#define KEYBOARD_LEFT_GUI  	 B00001000
#define KEYBOARD_RIGHT_CTRL  B00010000
#define KEYBOARD_RIGHT_SHIFT B00100000
#define KEYBOARD_RIGHT_ALT   B01000000
#define KEYBOARD_RIGHT_GUI 	 B10000000

#define KEYBOARD_UP_ARROW		0x52
#define KEYBOARD_DOWN_ARROW		0x51
#define KEYBOARD_LEFT_ARROW		0x50
#define KEYBOARD_RIGHT_ARROW	0x4F
#define KEYBOARD_BACKSPACE		0x2A
#define KEYBOARD_TAB			0x2B
#define KEYBOARD_RETURN			0x28
#define KEYBOARD_ESC			0x29
#define KEYBOARD_INSERT			0x49
#define KEYBOARD_DELETE			0x4C
#define KEYBOARD_PAGE_UP		0x4B
#define KEYBOARD_PAGE_DOWN		0x4E
#define KEYBOARD_HOME			0x4A
#define KEYBOARD_END			0x4D
#define KEYBOARD_CAPS_LOCK		0x39
#define KEYBOARD_F1				0x3A
#define KEYBOARD_F2				0x3B
#define KEYBOARD_F3				0x3C
#define KEYBOARD_F4				0x3D
#define KEYBOARD_F5				0x3E
#define KEYBOARD_F6				0x3F
#define KEYBOARD_F7				0x40
#define KEYBOARD_F8				0x41
#define KEYBOARD_F9				0x42
#define KEYBOARD_F10			0x43
#define KEYBOARD_F11			0x44
#define KEYBOARD_F12			0x45
#define KEYBOARD_PRINT			0x46
#define KEYBOARD_SCROLL_LOCK	0x47
#define KEYBOARD_PAUSE			0x48

//Keyboard fixed/added missing Keys
#define KEY_PRINT				0xCE
#define KEY_SCROLL_LOCK			0xCF
#define KEY_PAUSE				0xD0


class Media_
{
public:
	Media_(void);
	void write(uint16_t command);
	void press(uint16_t command);
	void releaseAll(void);
	void pressRawKeyboard(uint8_t modifiers, uint8_t key);
private:

};
extern Media_ Media;

#endif
