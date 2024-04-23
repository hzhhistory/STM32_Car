#include"TB6612.h"

/******************************
 * 停止命令
******************************/

void APIN_STOP(void)
{
    AIN1_LOW();
    AIN2_LOW();
    PWMA_HIGH();
    STBY_HIGH();
}
void BPIN_STOP(void)
{
    BIN1_LOW();
    BIN2_LOW();
    PWMB_HIGH();
    STBY_HIGH();

}

/******************************
 * 以下为逆时针转
******************************/

void APIN_CCW(void)
{
    AIN1_LOW();
    AIN2_HIGH();
    PWMA_HIGH();
    STBY_HIGH();
}
void BPIN_CCW(void)
{
    BIN1_LOW();
    BIN2_HIGH();
    PWMB_HIGH();
    STBY_HIGH();
}

/******************************
 * 以下为顺时针转
******************************/

void APIN_CW(void)
{
    AIN1_HIGH();
    AIN2_LOW();
    PWMA_HIGH();
    STBY_HIGH();
}
void BPIN_CW(void)
{
    BIN1_HIGH();
    BIN2_LOW();
    PWMB_HIGH();
    STBY_HIGH();
}

/******************************
 * 车辆操作函数
******************************/
void CAR_STOP(void)
{
    APIN_STOP();
    BPIN_STOP();
}
void CAR_FORWARD(void)
{
    APIN_CW();
    BPIN_CW();
}
void CAR_BACKWARD(void)
{
    APIN_CCW();
    BPIN_CCW();
}
void CAR_LEFT(void)
{
    APIN_CCW();
    BPIN_CW();
}
void CAR_RIGHT(void)
{

    APIN_CW();
    BPIN_CCW();
}
