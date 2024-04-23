#include "yaogan.h"
#include"adc.h"
#include"../Src/debug_com.h"
int y_task=0;
int x_task=0;
uint32_t value1 ,value2;
uint32_t scn_switch(void)
{
    HAL_ADC_Start(&hadc1);
    HAL_ADC_Start(&hadc2);
    value1=HAL_ADC_GetValue(&hadc1);
    value2=HAL_ADC_GetValue(&hadc2);
    HAL_ADC_Stop(&hadc1);
    HAL_ADC_Stop(&hadc2);
    if(value2<=500)
    {
        return CAR_LEFT;
    }
    else if(value2>=3500)
    {
        return CAR_RIGHT;
    }
    else if(value1<=500)
    {
        return CAR_BACKWARD;
    }
    else if(value1>=3500)
    {
        return CAR_FORWARD;
    }
    else{
        return CAR_STOP;
    }




}


void switch_print(void) {
    switch (scn_switch()) {
        case CAR_STOP:
            printf("Stop\r\n");
            y_task=0;
            x_task=0;
            break;
        case CAR_FORWARD:
            printf("Forward\r\n");
            y_task=-20;
            break;
        case CAR_BACKWARD:
            printf("BACKWARD\r\n");
            y_task=20;
            break;
        case CAR_LEFT:
            printf("LEFT\r\n");
            x_task=-20;
            break;
        case CAR_RIGHT:
            printf("RIGHT\r\n");
            x_task=20;
            break;
        default:
            break;
    }
}