#ifndef __Adc_h__
#define __Adc_h__
#include "System.h"
#define MAX_ADC_VALUE 4096
typedef enum
{
    AdcChanel_0, // P17
    AdcChanel_1, // P30
    AdcChanel_2, // P07
    AdcChanel_3, // P06
    AdcChanel_4, // P05
    AdcChanel_5, // P04
    AdcChanel_6, // P03
    AdcChanel_7, // P11

} AdcChanel;
static unsigned int ADC_read(AdcChanel adcChanel)
{
    register unsigned int adc_value = 0x0000;

    // CKDIV = 0x02;

    switch (adcChanel)
    {
    case AdcChanel_0:
        Enable_ADC_AIN0;
        break;
    case AdcChanel_1:
        Enable_ADC_AIN1;
        break;
    case AdcChanel_2:
        Enable_ADC_AIN2;
        break;
    case AdcChanel_3:
        Enable_ADC_AIN3;
        break;
    case AdcChanel_4:
        Enable_ADC_AIN4;
        break;
    case AdcChanel_5:
        Enable_ADC_AIN5;
        break;
    case AdcChanel_6:
        Enable_ADC_AIN6;
        break;
    case AdcChanel_7:
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
#endif