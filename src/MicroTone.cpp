#include "Arduino.h"
#include "MicroTone.h"
#ifndef __AVR_ATtiny13__
#error this library ONLY supports Attiny13
#endif     //thanks to FastLED library
uint8_t prescale;

void MicroToneClass::begin (void)
{
  prescale = 3;
  TIMSK0 = (0 << OCIE0B) | (0 << OCIE0A) | (0 << TOIE0);
  DDRB |=(1 << DDB0);
}

void MicroToneClass::begin(uint8_t myPrescale)
{
	//default = 3
	TIMSK0 = (0 << OCIE0B) | (0 << OCIE0A) | (0 << TOIE0);
    DDRB |=(1 << DDB0);
	if(myPrescale > 5)myPrescale = 5;
    prescale = myPrescale;
}

void MicroToneClass::setPrescaler (uint8_t myAnotherPrescale)
{
    if(myAnotherPrescale > 5)myAnotherPrescale = 5;
    prescale = myAnotherPrescale;
}

void MicroToneClass::write(uint8_t valOfOCR0A)
{
  if(TCCR0B != prescale)
  {
    TCCR0A = 0b01000010;
    TCCR0B = prescale;
  }
  OCR0A = valOfOCR0A;
}


void MicroToneClass::stop(void)
{
	TCCR0A = 0x00;
	TCCR0B = 0x00;
}

MicroToneClass MicroTone;
