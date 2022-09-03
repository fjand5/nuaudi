#include "Delay.h"
void Timer0_Delay1ms(UINT32 u32CNT)
{
    clr_T0M;      // T0M=0, Timer0 Clock = Fsys/12
    TMOD |= 0x01; // Timer0 is 16-bit mode
    set_TR0;      // Start Timer0
    while (u32CNT != 0)
    {
        TL0 = LOBYTE(TIMER_DIV12_VALUE_1ms); // Find  define in "Function_define.h" "TIMER VALUE"
        TH0 = HIBYTE(TIMER_DIV12_VALUE_1ms);
        while (TF0 != 1)
            ; // Check Timer0 Time-Out Flag
        clr_TF0;
        u32CNT--;
    }
    clr_TR0; // Stop Timer0
}
void Timer0_Delay100us(UINT32 u32CNT)
{
    clr_T0M;                                		//T0M=0, Timer0 Clock = Fsys/12
    TMOD |= 0x01;                         		  //Timer0 is 16-bit mode
    set_TR0;                            		    //Start Timer0
    while (u32CNT != 0)
    {
        TL0 = LOBYTE(TIMER_DIV12_VALUE_100us);	//Find  define in "Function_define.h" "TIMER VALUE"
        TH0 = HIBYTE(TIMER_DIV12_VALUE_100us);
        while (TF0 != 1);       		            //Check Timer0 Time-Out Flag
        clr_TF0;
        u32CNT --;
    }
    clr_TR0;                       			        //Stop Timer0
}