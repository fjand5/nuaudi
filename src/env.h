
#ifndef __env_h__
#define __env_h__
#include "N76E003.h"
// input 
#define SW_BUTTON_PORT P1
#define SW_BUTTON_PIN P17
#define SW_BUTTON_DIR1 P1M1
#define SW_BUTTON_DIR2 P1M2
#define SW_BUTTON_BIT (1<<7)

#define MUTE_IN_PORT P0
#define MUTE_IN_PIN P05
#define MUTE_IN_DIR1 P0M1
#define MUTE_IN_DIR2 P0M2
#define MUTE_IN_BIT (1<<5)

// output

// Green LED
#define GREEN_LED_PORT P0
#define GREEN_LED_DIR1  P0M1
#define GREEN_LED_DIR2  P0M2
#define GREEN_LED_BIT (1 << 4)

// Yellow LED
#define YELLOW_LED_PORT P0
#define YELLOW_LED_DIR1  P0M1
#define YELLOW_LED_DIR2  P0M2
#define YELLOW_LED_BIT (1 << 3)

// Mute Out
#define MUTE_OUT_PORT P0
#define MUTE_OUT_DIR1  P0M1
#define MUTE_OUT_DIR2  P0M2
#define MUTE_OUT_BIT (1 << 1)

// EN Out
#define EN_OUT_PORT P0
#define EN_OUT_DIR1  P0M1
#define EN_OUT_DIR2  P0M2
#define EN_OUT_BIT (1 << 7)

// 
#define TIME_SCAN_BUTTON 20 //ms
#define TIME_SCAN_ADC 500 //ms
// battery
#define MAX_BATTERY_VOL 5
#define THRESHOLD_LOW_BATTERY 4 // vol
typedef enum
{
    DigitalState_High,
    DigitalState_Low
} DigitalState;
#endif