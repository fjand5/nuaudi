
#ifndef __mute_in_h__
#define __mute_in_h__

#include "System.h"

#include "../env.h"

void initMuteIn();
void loopMuteIn();
void setInMuteInHigh(void (*inHigh)());
void setInMuteInLow(void (*inLow)());

#endif