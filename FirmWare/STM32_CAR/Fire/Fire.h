#ifndef __FIRE_H__
#define __FIRE_H__
#include"stm32f1xx_hal.h"
#include"gpio.h"
#define Fire_ON 0
#define Fire_OFF 1
/*
 *用于读取火焰传感器的数据
 * @参数 void
 * @返回值Fire_ON(1) or Fire_OFF(0)
 */
uint32_t Fire_Read(void);
void Fire_reback(void);
void beep(void);
#endif