#include "swButton.h"
void (*onInitFinish)(DigitalState state);
void (*onPress)(uint32_t presssTime);
void (*onRelease)();

static uint32_t lastTimePress = 0;
static uint32_t lastTimeLoop = 0;
static DigitalState lastState = DigitalState_Low;
void initSwButton()
{
    SW_BUTTON_PORT |= SW_BUTTON_BIT;

    SW_BUTTON_DIR1 &= ~SW_BUTTON_BIT;
    SW_BUTTON_DIR2 &= ~SW_BUTTON_BIT;
    lastState = getSwState();
    if (onInitFinish)
        onInitFinish(lastState);
}
void setOnSwInitFinish(void (*_onInitFinish)(DigitalState state))
{
    onInitFinish = _onInitFinish;
}
void setOnSwPress(void (*_onPress)(uint32_t presssTime))
{
    onPress = _onPress;
}
void setOnSwRelease(void (*_onRelease)())
{
    onRelease = _onRelease;
}

void loopSwButton()
{
    if (get_uptime_ms() - lastTimeLoop > TIME_SCAN_BUTTON)
    {
        lastTimeLoop = get_uptime_ms();
        DigitalState curentState = getSwState();
        if (lastState == DigitalState_Low &&
            curentState == DigitalState_Low)
        {
            if (onPress)

                onPress(get_uptime_ms() - lastTimePress);
        }
        else
        {
            lastTimePress = get_uptime_ms();
        }

        if (curentState == DigitalState_High)
        {
            if (onRelease)
                onRelease();
        }
        lastState = curentState;
    }
}

DigitalState getSwState()
{
    if (SW_BUTTON_PIN)
        return DigitalState_High;
    else
        return DigitalState_Low;
}
