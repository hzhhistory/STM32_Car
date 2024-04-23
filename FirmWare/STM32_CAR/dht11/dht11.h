#ifndef _DH11_H_
#define _DH11_H_

#include"main.h"

#define u8 unsigned char 
#define u16 unsigned short
#define u32 unsigned int

//DATA IO�Ķ���
#define DATA_SET() HAL_GPIO_WritePin(DATA_GPIO_Port, DATA_Pin, GPIO_PIN_SET)
#define DATA_RESET() HAL_GPIO_WritePin(DATA_GPIO_Port, DATA_Pin, GPIO_PIN_RESET)

#define DATA_READ() HAL_GPIO_ReadPin(DATA_GPIO_Port,DATA_Pin)

typedef struct
{
  u8 Data[5];//���ݴ������
  u8 index;
  u8 temp;//�¶�
  u8 humidity;//ʪ��
  
}DH11_DATA;

extern DH11_DATA DH11_data;//DH11���Է�װ

void DH11_Task(void);//��̨��ѯ����

#define DATA_Pin GPIO_PIN_9
#define DATA_GPIO_Port GPIOB


#endif


