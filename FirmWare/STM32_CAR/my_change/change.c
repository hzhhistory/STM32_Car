#include"change.h"


uint8_t pdata[1]={""};
void Car_Control(void)
{
    HAL_UART_Receive(&huart3, (uint8_t *)pdata, sizeof(pdata), 0xFF);
    switch (pdata[0])
    {
        case 'F':
            CAR_FORWARD();break;
        case 'B':
            CAR_BACKWARD();break;
        case 'R':
            CAR_RIGHT();break;
        case 'L':
            CAR_LEFT();break;
        case 'S':
            CAR_STOP();break;
        default:CAR_STOP();break;
    }



}



