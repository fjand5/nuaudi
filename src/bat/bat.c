#include "bat.h"
void (*onBatLow)(uint32_t lowTime);
void (*onBatNotLow)();

static uint32_t lastTimeLoop = 0;
static uint32_t lastTimeBatNotLow = 0;

float readBatVol()
{
    float adcValue = ADC_read(AdcChanel_3);
    return adcValue * (float)(MAX_BATTERY_VOL) / (float)(MAX_ADC_VALUE);
}
void setOnBatteryLow(void (*_onBatLow)(uint32_t lowTime))
{
    onBatLow = _onBatLow;
}
void setOnBatteryNotLow(void (*_onBatNotLow)())
{
    onBatNotLow = _onBatNotLow;
}

void loopBat()
{
    if (get_uptime_ms() - lastTimeLoop > TIME_SCAN_ADC)
    {
        lastTimeLoop = get_uptime_ms();
        float currentBatteryVol = readBatVol();
        if (currentBatteryVol < THRESHOLD_LOW_BATTERY)
        {
            if (onBatLow)
                onBatLow(get_uptime_ms() - lastTimeBatNotLow);
        }
        else
        {
            lastTimeBatNotLow = get_uptime_ms();
            if (onBatNotLow)
                onBatNotLow();
        }
    }
}
