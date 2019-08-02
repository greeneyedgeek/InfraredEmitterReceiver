/*
  Project:  InfraredEmitterReceiver
  File:   	IR_Receiver.cpp
  Created:  2019-07-27
  Modified: 2019-08-02
  Author:   Gabriel Fontaine-Escobar

  This code is in the public domain.
  https://github.com/greeneyedgeek/InfraredEmitterReceiver
  
  The circuit:
  * IR RECEIVER to digital pin 2
  * IR RECEIVER POS to +5V
  * IR RECEIVER GND PIN to GROUND
  * RGB LED GREEN PIN to digital pin 8
  * RGB LED BLUE PIN to digital pin 9
  * RGB LED RED PIN to digital pin 10
  * RGB LED GND pin to GROUND
*/

#include <Arduino.h>
#include <IRremote.h>

#define IR_RECEIVER 2 // PD2
#define RED_LED 10 // PB2
#define BLUE_LED 9 // PB1
#define GREEN_LED 8 // PB0

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
};

// LED status indicator
bool isOn;
bool isInterrupt;
  
Signal signal;

IRrecv receiver(IR_RECEIVER);
decode_results results;

// Sets the LED colour
void setRgb(int redValue, int greenValue, int blueValue) 
{
    
  analogWrite(RED_LED, redValue);
  analogWrite(GREEN_LED, greenValue);
  analogWrite(BLUE_LED, blueValue);
 
  if (redValue == 0 && greenValue == 0 && blueValue == 0) { isOn = false ; }
  else { isOn = true; }
}

// Receives and processes the IR signal
void receive()
{
  if (receiver.decode(&results))
  {
    switch (results.value)
    {
      case signal.RED:
      setRgb(255,0,0);
      break;
  
      case signal.YELLOW:
      setRgb(200,200,0);
      break;
  
      case signal.GREEN:
      setRgb(0,255,0);
      break;
  
      case signal.CYAN:
      setRgb(0,200,200);
      break;
  
      case signal.BLUE:
      setRgb(0,0,255);
      break;
      
      case signal.MAGENTA:
      setRgb(200,0,200);
      break;
  
      case signal.WHITE:
      setRgb(200,200,200);
      break;
  
      default:
      // Do nothing
      break;
    }
    receiver.resume();
  }
}

// Called when IR signal is received
void customISR()
{
  static unsigned long previousTime {0};
  unsigned long currentTime = millis();
  isInterrupt = currentTime - previousTime > 100 ? true : false;
  previousTime = currentTime;
}

void setup()
{
  // Set Pin 2 (PD2) as input
  DDRD |= (1 << PD2);
  
  // Set LED Pins as output
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

	// Initialize variables
	isOn = false;
	isInterrupt = false;
	
	//Serial.begin(9600); 
	receiver.enableIRIn(); 
	attachInterrupt(digitalPinToInterrupt(IR_RECEIVER), customISR, RISING);
}

void loop()
{
  if (isInterrupt)
  {
	// Receive and process the signal
    receive();
    isInterrupt = false;
  }
}
