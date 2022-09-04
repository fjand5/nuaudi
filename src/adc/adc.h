// #include "ms51.h"
#define ADC_CH_6 6
#define ADC_CH_7 7

#include "../include/Function_Define.h"
#include "../lcd/lcd.h"
// #define P11DIDS 7
// #define ADCEN 0

// #define Enable_ADC_AIN7        \
//     ADCCON0 = 0b11110111;           \
//     P1M1 |= (1 << 1);          \
//     P1M2 &= ~(1 << 1);         \
//     AINDIDS = 0x00;            \
//     AINDIDS &= ~(1 << P11DIDS); \
//     ADCCON1 |= (1 << ADCEN)
// #define Enable_ADC_AIN7  \
//     ADCCON0 &= 0xF0;     \
//     ADCCON0 |= 0x07;     \
//     P11_Input_Mode;      \
//     AINDIDS = 0x00;      \
//     AINDIDS |= SET_BIT7; \
//     ADCCON1 |= SET_BIT0 // P11

// unsigned int ADC_read(void)
// {
//     register unsigned int adc_value = 0x0000;
//     ADCF = 0;
//     ADCS = 1;
//     while (ADCF == 0)
//         ;

//     adc_value = ADCRL;
//     adc_value |= ADCRH<<4;
//     return adc_value;
// }

unsigned int ADC_read(uint8_t channel)
{
    register unsigned int adc_value = 0x0000;

    // CKDIV = 0x02;
    
    switch (channel)
    {
    case ADC_CH_6:
        Enable_ADC_AIN6;
        break;
    case ADC_CH_7:
        Enable_ADC_AIN7;
        break;

    default:
        break;
    }
    clr_ADCF;
    set_ADCS;
    while (ADCF == 0)
        ;
    adc_value = ADCRL;
    adc_value |= ADCRH << 4;
    Disable_ADC;
    return adc_value;
}