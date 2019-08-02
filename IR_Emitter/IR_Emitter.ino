/*
  Project:  InfraredEmitterReceiver
  File:	    IR_Emitter.cpp
  Created:  2019-07-27
  Modified: 2019-08-02
  Author:   Gabriel Fontaine-Escobar

  This code is in the public domain.
  https://github.com/greeneyedgeek/InfraredEmitterReceiver
  
  The circuit:
  * IR LED to digital pin 3
  * IR LED POS to +5V
  * IR LED GND PIN to GROUND
*/

#include <Arduino.h>
#include <IRremote.h>

#define IR_LED 3

class Signal
{
public:
  // IR Signal constants
  static const int OFF = 0x00;
  static const int ON = 0x01;
  static const int RANDOM = 0x02;  
  static const int RED = 0x11;
  static const int YELLOW = 0x55;
  static const int GREEN = 0x0F;
  static const int CYAN = 0xF0;
  static const int BLUE = 0xFF;
  static const int MAGENTA = 0x1F;
  static const int WHITE = 0x99;

  int VALUES[7] { RED, YELLOW, GREEN, CYAN, BLUE, MAGENTA, WHITE }; 
};

IRsend emitter;
Signal signal;

void setup()
{
	// Set IR LED Pin as output
	pinMode(IR_LED, OUTPUT); 
}

void loop() 
{
  // Send a random colour signal every 250ms
  emitter.sendNEC(signal.VALUES[random(7)], 32);
  _delay_ms(250);  
}
