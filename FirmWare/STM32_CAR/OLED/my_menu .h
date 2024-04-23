#ifndef __MY_MENU_H__
#define __MY_MENU_H__
#include"oled.h"
#include"u8g2.h"
#include"WALL_E.h"
#include"stdio.h"
void my_u8g2_init(void);
void menu_init(void);
void PrintVarFormat(u8g2_t *u8g2, u8g2_uint_t x, u8g2_uint_t y, const uint8_t *font, short var);


#endif