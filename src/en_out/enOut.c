#include "enOut.h"
void initEnOut()
{

    EN_OUT_DIR1 &= ~(EN_OUT_BIT);
    EN_OUT_DIR2 &= ~(EN_OUT_BIT);
    setEnOut(DigitalState_Low);
}
void setEnOut(DigitalState digitalState)
{
    switch (digitalState)
    {
    case DigitalState_High:
        EN_OUT_PORT |= (EN_OUT_BIT);
        break;
    case DigitalState_Low:
        EN_OUT_PORT &= ~(EN_OUT_BIT);
        break;
    default:
        break;
    }
}