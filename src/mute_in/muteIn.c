#include "muteIn.h"
void (*inHigh)();
void (*inLow)();

static uint32_t lastTimePress = 0;
static uint32_t lastTimeLoop = 0;
static DigitalState lastState = DigitalState_High;
void initMuteIn()
{
    MUTE_IN_PORT |= MUTE_IN_BIT;
    
    MUTE_IN_DIR1 &= ~MUTE_IN_BIT;
    MUTE_IN_DIR2 &= ~MUTE_IN_BIT;

}

void setInMuteInHigh(void (*_inHigh)())
{
    inHigh = _inHigh;
}
void setInMuteInLow(void (*_inLow)())
{
    inLow = _inLow;
}
void loopMuteIn()
{
    if (get_uptime_ms() - lastTimeLoop > TIME_SCAN_BUTTON)
    {
        lastTimeLoop = get_uptime_ms();
        DigitalState curentState = getMuteInState();
        if (
            // lastState == DigitalState_Low &&
            curentState == DigitalState_High)
        {
            if (inHigh)
                inHigh();
        }
        else if (
            // lastState == DigitalState_High &&
            curentState == DigitalState_Low)
        {
            if (inLow)
                inLow();
        }
        // lastState = curentState;
    }
}

DigitalState getMuteInState()
{
    if (MUTE_IN_PIN)
        return DigitalState_High;
    else
        return DigitalState_Low;
}
