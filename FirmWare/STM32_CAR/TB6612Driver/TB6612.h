#ifndef __TB6612_H__
#define __TB6612_H__
#include"stm32f1xx_hal.h"
#include"gpio.h"
#include"CAR_Dfine.h"

void CAR_STOP(void);
void CAR_FORWARD(void);
void CAR_BACKWARD(void);
void CAR_LEFT(void);
void CAR_RIGHT(void);

#endif