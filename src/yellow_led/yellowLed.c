#include "yellowLed.h"
int enBlink = 0;
DigitalState state = DigitalState_Low;
static uint32_t lastTimeLoop = 0;

void setYellowLed(DigitalState digitalState)
{
    switch (digitalState)
    {
    case DigitalState_High:
        YELLOW_LED_PORT |= (YELLOW_LED_BIT);
        break;
    case DigitalState_Low:
        YELLOW_LED_PORT &= ~(YELLOW_LED_BIT);
        break;
    default:
        break;
    }
}
void initYellowLed()
{
    YELLOW_LED_DIR1 &= ~(YELLOW_LED_BIT);
    YELLOW_LED_DIR2 &= ~(YELLOW_LED_BIT);
    setYellowLed(state);
}
void setYellowLedBlink()
{
    enBlink = 1;
}
void setYellowLedNoBlink()
{
    enBlink = 0;
}
void loopYellowLed()
{
    if (enBlink)
    {
        if (get_uptime_ms() - lastTimeLoop > YELLOW_LED_BLINK_CYCLE)
        {
            lastTimeLoop = get_uptime_ms();
            setYellowLed(state);
            if (state == DigitalState_High)
            {
                state = DigitalState_Low;
            }
            else
            {
                state = DigitalState_High;
            }
        }
    }
}
