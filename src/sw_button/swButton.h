
#ifndef __sw_button_h__
#define __sw_button_h__

#include "System.h"

#include "../env.h"

void initSwButton();
void loopSwButton();
void setOnSwInitFinish(void (*onInitFinish)(DigitalState state));

void setOnSwPress(void (*onPress)(uint32_t presssTime));
void setOnSwRelease(void (*onRelease)());

#endif