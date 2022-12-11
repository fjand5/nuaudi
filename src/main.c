/***************************************************************************************************************
    This file is part of Library for 8051.

    Library for 8051 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Library for 8051 is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
/**************************************************************************************************************/

/***
**   File       : testlcd.c
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is test code for 8051 LCD driver
***/
#include "env.h"
#include <stdlib.h>
#include "System.h"
// #include "Delay.h"
// #include "lcd/lcd.h" // Include LCD driver
// #include "adc/adc.h" // Include LCD driver

// #define TH1_INIT 0xE0 // 2.5ms@XTAL=12MHz, Period = (5.425/2) ms@XTAL=22.1184MHz
// #define TL1_INIT 0x00
// #define LCD_REFRESH_DELAY 5000 // LCD Refresh rate in milliseconds
#include "sw_button/swButton.h"
#include "mute_out/muteOut.h"
#include "en_out/enOut.h"
#include "mute_in/muteIn.h"
#include "green_led/greenLed.h"
#include "yellow_led/yellowLed.h"
#include "bat/bat.h"

int swHasControl = 0;
int denyOffMute = 1;
void onSwInitFinish(DigitalState state)
{
    switch (state)
    {
    case DigitalState_High:
        denyOffMute = 1;
        setMuteOut(DigitalState_Low);
        setGreenLed(DigitalState_Low);

        break;
    case DigitalState_Low:
        denyOffMute = 0;

        setMuteOut(DigitalState_High);
        setGreenLed(DigitalState_High);
        break;

    default:
        break;
    }
}
void onSwPress(uint32_t time)
{
    if (swHasControl)
        return;
    if (time > 5000)
    {
        setMuteOut(DigitalState_High);
        setGreenLed(DigitalState_High);
        swHasControl = 1;
        denyOffMute = 0;
    }
}
void onSwRelease()
{
    swHasControl = 0;
    denyOffMute = 1;
    setMuteOut(DigitalState_Low);
    setGreenLed(DigitalState_Low);
}
void inMuteInHigh()
{
    setMuteOut(DigitalState_Low);
    setGreenLed(DigitalState_Low);
}
void inMuteInLow()
{
    if (denyOffMute)
    {
        return;
    }
    setMuteOut(DigitalState_High);
    setGreenLed(DigitalState_High);
}

void onBatteryLow(uint32_t time)
{
    if (time > 10000)
    {
        setYellowLedBlink();
        setEnOut(DigitalState_Low);
    }
}
void onBatteryNotLow()
{
    setYellowLedNoBlink();
    setEnOut(DigitalState_High);
}

void main(void)
{
    // Delay_Init();
    // Bind event
    setOnSwPress(onSwPress);
    setOnSwRelease(onSwRelease);
    setOnSwInitFinish(onSwInitFinish);

    setInMuteInHigh(inMuteInHigh);
    setInMuteInLow(inMuteInLow);

    setOnBatteryLow(onBatteryLow);
    setOnBatteryNotLow(onBatteryNotLow);
    // init system
    uptime_init();
    initGreenLed();
    initYellowLed();
    initMuteOut();
    initEnOut();

    initSwButton();
    initMuteIn();
    while (1)
    {
        loopSwButton();
        loopMuteIn();
        loopBat();
        loopYellowLed();
    }
#if 0
    lcdBegin(); // Initiate the LCD

    char string[20];
    char stringn[20];

    uptime_init();
    int number;

    while (1)
    {
        if (get_uptime_ms() > 10000)
        {

            volatile char *pochar = (char *)0;
            *pochar = 0xff;
        }
        lcdSetCursor(1, 0);
        lcdPrint(" adc:");
        lcdWriteint(ADC_read(ADC_CH_6));
        lcdPrint(" ");

        lcdWriteint(ADC_read(ADC_CH_7));

        lcdSetCursor(2, 0);
        lcdPrint(" uptime 2: ");
        lcdWriteint(get_uptime_ms() / 1000);
        // Timer0_Delay1ms(1000);
        delay_ms(222);
        // lcdSetCursor(2, 0);
        // lcdPrint(String2);
        // __delay_ms__(LCD_REFRESH_DELAY);
        lcdClear();
        // __delay_ms__(LCD_REFRESH_DELAY);
    }
#endif
}
