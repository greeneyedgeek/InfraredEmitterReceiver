#include <Arduino.h>
#include <IRremote.h>

#define IR_RECEIVER 2 //PD2
#define RED_LED 10 //PB2
#define BLUE_LED 9 //PB1
#define GREEN_LED 8 //PB0

// IR Signal constants
class Signal
{
public:
  static const int OFF = 0x00;
  static const int ON = 0x01;
  static const int RED = 0x11;
  static const int GREEN = 0x0F;
  static const int BLUE = 0xFF;
};

// LED status indicator
bool isOn;
bool isInterrupt;
  
Signal signal;

IRrecv receiver(IR_RECEIVER);
decode_results results;

void setRgb(int redValue, int greenValue, int blueValue) 
{
    
	analogWrite(RED_LED, redValue);
	analogWrite(GREEN_LED, greenValue);
	analogWrite(BLUE_LED, blueValue);
	/*
	if (redValue != 0) 
    { 
		// RED LED ON
		PORTB |= (1 << RED_LED);
    }
    else 
    {
		// RED LED OFF
		PORTB &= ~(1 << RED_LED);
    }
    if (greenValue != 0) 
    { 
		// GREEN LED ON
		PORTB |= (1 << GREEN_LED);
    }
    else 
    {
		// GREEN LED OFF
		PORTB &= ~(1 << GREEN_LED);
    } 
    if (blueValue != 0) 
    { 
		// BLUE LED ON
		PORTB |= (1 << BLUE_LED);
    }
    else 
    {
		// BLUE LED OFF
		PORTB &= ~(1 << BLUE_LED);
    }
  */
    if (redValue == 0 && greenValue == 0 && blueValue == 0) { isOn = false ; }
    else { isOn = true; }
}

void receive()
{
   if (receiver.decode(&results))
  {
    long int decCode = results.value;
    //Serial.println(results.value,  HEX);
    switch (results.value)
    {
      // ON/OFF Switch
    case 737444966: 
    case 3622325019:
    isOn ? setRgb(0,0,0) : setRgb(1,1,1);
    isOn = !isOn;
    break;

    case signal.ON:
    setRgb(1,1,1);
    // Red
    case signal.RED:
    setRgb(255,0,0);
    //Serial.println("red\n");
    break;

    // Green
    case signal.GREEN:
    //Serial.println("green\n");
    setRgb(0,255,0);
    break;

    // Blue
    case signal.BLUE:
    setRgb(0,0,255);
    //Serial.println("blue\n");
    break;

    // Defaults to OFF
    case signal.OFF:
    setRgb(0,0,0);
    break;

    default:
    break;
    }
    receiver.resume();
  }
}

void customISR()
{
  static unsigned long previousTime = 0;
  unsigned long currentTime = millis();
  isInterrupt = currentTime - previousTime > 100 ? true : false;
  previousTime = currentTime;
}

void setup()
{

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(IR_RECEIVER, INPUT);

	// Set PORTB as output
	//DDRB = DDRB | 0xFF;

	// Set PORTD as input
	//DDRD = DDRD | 0x00; 

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
    receive();
    isInterrupt = false;
  }
 //_delay_ms(100);
}
