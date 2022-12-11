#include "muteOut.h"
void initMuteOut()
{

    MUTE_OUT_DIR1 &= ~(MUTE_OUT_BIT);
    MUTE_OUT_DIR2 &= ~(MUTE_OUT_BIT);
    setMuteOut(DigitalState_Low);
}
void setMuteOut(DigitalState digitalState)
{
    switch (digitalState)
    {
    case DigitalState_High:
        MUTE_OUT_PORT |= (MUTE_OUT_BIT);
        break;
    case DigitalState_Low:
        MUTE_OUT_PORT &= ~(MUTE_OUT_BIT);
        break;
    default:
        break;
    }
}