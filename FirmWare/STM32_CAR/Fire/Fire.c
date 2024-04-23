#include"Fire.h"
#include"change.h"

uint32_t Fire_Read(void)
{
    if(HAL_GPIO_ReadPin(GPIOA,Fire_Pin)==Fire_ON)
    {
        return Fire_ON;
    }
    else if(HAL_GPIO_ReadPin(GPIOA,Fire_Pin)==Fire_ON)
    {
        return Fire_OFF;
    }


}
void Fire_reback(void)
{
    if(Fire_Read()==Fire_ON)
    {
        HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_RESET);
        CAR_STOP();
    }
    else if(Fire_Read()==Fire_OFF)
    {
        HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,GPIO_PIN_SET);
    }



}