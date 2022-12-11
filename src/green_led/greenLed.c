#include "greenLed.h"
void initGreenLed()
{
    GREEN_LED_DIR1 &= ~(GREEN_LED_BIT);
    GREEN_LED_DIR2 &= ~(GREEN_LED_BIT);
    setGreenLed(DigitalState_Low);
}
void setGreenLed(DigitalState digitalState)
{
    switch (digitalState)
    {
    case DigitalState_High:
        GREEN_LED_PORT |= (GREEN_LED_BIT);
        break;
    case DigitalState_Low:
        GREEN_LED_PORT &= ~(GREEN_LED_BIT);
        break;
    default:
        break;
    }
}