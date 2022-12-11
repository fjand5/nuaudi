#include "System.h"
#include "Adc.h"

#include "../env.h"

void loopBat();
void setOnBatteryLow(void (*onBatLow)(uint32_t lowTime));
void setOnBatteryNotLow(void (*onBatNotLow)());
