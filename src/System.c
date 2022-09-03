#include "System.h"
register uint32_t uptime_4ms = 0;

void uptime_init()
{
    // Timer 0 will clock when TR0 is 1 regardless of INT0 ̅̅̅̅̅̅̅ logic level.
    clr_GATE_T0;
    // Timer 0 is incremented by internal system clock.
    clr_CT_T0;
    // Mode 1: 16 bit
    set_M0_T0;
    clr_M1_T0;
    // The clock source of Timer 0 is direct the system clock. 
    set_T0M;

    set_ET0;
    set_EA; // enable interrupts

    TH1 = 0x06;
    TL1 = 0x0A;
    set_TR0; // Timer0 run
}
void Timer0_ISR(void) __interrupt(1) // interrupt address is 0x001B
{
    // Start at 65536-64000 + 10= 1546;
    TH1 = 0x06;   // 2 cycle
    TL1 = 0x0A;   // 2 cycle
    uptime_4ms++; // 6 cycle
    // P03 = ~P03;															// GPIO toggle when interrupt
}
uint32_t get_uptime_ms()
{
    return uptime_4ms * 4;
}
uint32_t get_uptime_us()
{
    return uptime_4ms * 4000;
}

void delay_ms(uint32_t time){
    uint32_t volatile lastTime = get_uptime_ms();
    while ((get_uptime_ms() - lastTime) <= time);
}

void delay_us(uint32_t time){
    uint32_t volatile lastTime = get_uptime_us();
    while ((get_uptime_us() - lastTime) <= time);
}

