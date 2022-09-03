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
#include <stdlib.h>
#include "System.h"
#include "Delay.h"
#include "lcd/lcd.h" // Include LCD driver
#include "adc/adc.h" // Include LCD driver

#define TH1_INIT 0xE0 // 2.5ms@XTAL=12MHz, Period = (5.425/2) ms@XTAL=22.1184MHz
#define TL1_INIT 0x00
#define LCD_REFRESH_DELAY 5000 // LCD Refresh rate in milliseconds

void main(void)
{
    // Delay_Init();

    lcdBegin(); // Initiate the LCD

    char string[20];
    char stringn[20];

    Enable_ADC_AIN7;
    uptime_init();
    int number;
    while (1)
    {

        lcdSetCursor(1, 0);
        lcdPrint(" adc : ");
        // lcdSetCursor(1, 7);
        lcdWriteint(get_uptime_ms()/1000);

        // __uitoa(, string,8);
        lcdSetCursor(2, 5);
        lcdWriteint(ADC_read());
        // Timer0_Delay1ms(1000);
        delay_ms(LCD_REFRESH_DELAY);
        // lcdSetCursor(2, 0);
        // lcdPrint(String2);
        // __delay_ms__(LCD_REFRESH_DELAY);
        lcdClear();
        // __delay_ms__(LCD_REFRESH_DELAY);
    }
}
