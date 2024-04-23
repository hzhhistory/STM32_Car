#ifndef __YAOGAN_H__
#define __YAOGAN_H__
#include"stm32f1xx_hal.h"
#define CAR_STOP 0x01
#define CAR_LEFT 0x02
#define CAR_RIGHT 0x03
#define CAR_FORWARD 0x04
#define CAR_BACKWARD 0x05

uint32_t scn_switch(void);
void switch_print(void);
#endif