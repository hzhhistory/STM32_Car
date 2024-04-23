#include"my_menu .h"

u8g2_t u8g2;
short x=10,y=10;
typedef struct
{
    char * str;
}SET_LIST;

SET_LIST list[]={
        {"CAR_SETING"},
        {"TEMP"},
        {"BMP280"},
        {"BEEP"},
};

void my_u8g2_init(void)
{
    u8g2_init(&u8g2);

    u8g2_FirstPage(&u8g2);
    u8g2_ClearBuffer(&u8g2);
    do
    {
        for(int i=20;i>12;i--)
        {
            u8g2_DrawCircle(&u8g2,64,32,i,U8G2_DRAW_ALL);

            u8g2_SendBuffer(&u8g2);
        }

    }while(u8g2_NextPage(&u8g2));

    u8g2_ClearBuffer(&u8g2);
    u8g2_DrawXBMP(&u8g2, 0, 0, wall_e_bmp01_x, wall_e_bmp01_y, wall_e_bmp01);
    u8g2_SendBuffer(&u8g2);

    u8g2_ClearBuffer(&u8g2);
//    u8g2_SetFont(&u8g2,u8g2_font_ncenB10_tr);
//    u8g2_DrawStr(&u8g2,0,30,"HELLO WORLD!!");
//    u8g2_SendBuffer(&u8g2);
}


void menu_init(void)
{
    uint8_t listlen=sizeof (list)/sizeof (SET_LIST);
    u8g2_SetFont(&u8g2,u8g2_font_ncenB08_tr);

    u8g2_ClearBuffer(&u8g2);
    for(int i=0;i<listlen;i++)
    {
        u8g2_DrawStr(&u8g2,x,y*i+16,list[i].str);

    }
    u8g2_DrawStr(&u8g2,110,16,"*");
    u8g2_SendBuffer(&u8g2);

}
void PrintVarFormat(u8g2_t *u8g2, u8g2_uint_t x, u8g2_uint_t y, const uint8_t *font, short var)
{
    uint8_t var_buff[10];             //用来存ASCII码
    u8g2_SetFont(u8g2, font);       //设定字体
    sprintf(var_buff, "%4d", var);  //传递变量（十进制（占四格））
    u8g2_DrawStr(u8g2, x, y, var_buff); //显示
}
