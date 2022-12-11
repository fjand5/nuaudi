
#ifndef __yellow_led_h__
#define __yellow_led_h__
#define YELLOW_LED_BLINK_CYCLE 250
#include "System.h"

#include "../env.h"
void initYellowLed();
void loopYellowLed();
void setYellowLedBlink();
void setYellowLedNoBlink();

#endif