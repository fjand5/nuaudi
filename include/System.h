#ifndef __System_h__
#define __System_h__
#include "Function_Define.h"
#include "SFR_Macro.h"
#include "N76E003.h"
// Dùng timer0 để chạy uptime rồi
void uptime_init();
void Timer0_ISR(void) __interrupt(1);
uint32_t get_uptime_ms();
uint32_t get_uptime_us();
void delay_ms(uint32_t time);
void delay_us(uint32_t time);
#endif

// ==========
