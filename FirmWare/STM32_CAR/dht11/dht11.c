#include "dht11.h"

extern TIM_HandleTypeDef htim4;

static void DATA_OUTPUT(u8 flg);//DATA���
static u8 DATA_INPUT(void);//DATA����
static u8 DH11_Read_Byte(void);//DH11���ź�

u8 DH11_Read(void);//��ȡDH11�¶Ⱥ�ʪ��

static void Test(void);//���Գ���

DH11_DATA DH11_data;

//void Delay_us(uint16_t us)
//{     //΢����ʱ
//	uint16_t differ = 0xffff-us-5;				
//	__HAL_TIM_SET_COUNTER(&htim4,differ);	//�趨TIM1��������ʼֵ
//	HAL_TIM_Base_Start(&htim4);		//������ʱ��	
//	
//	while(differ < 0xffff-5){	//�ж�
//		differ = __HAL_TIM_GET_COUNTER(&htim4);		//��ѯ�������ļ���ֵ
//	}
//	HAL_TIM_Base_Stop(&htim4);
//}

void Delay_us(u32 nus)
{
    u32 ticks;
    u32 told,tnow,reload,tcnt=0;

    reload = SysTick->LOAD;                     //��ȡ��װ�ؼĴ���ֵ
    ticks = nus * (SystemCoreClock / 1000000);  //����ʱ��ֵ   ������Ĵ���1us����શ�ʱ����value�����½�����ֵ
    told=SysTick->VAL;                          //��ȡ��ǰ��ֵ�Ĵ���ֵ����ʼʱ��ֵ��

    while(1)
    {
          tnow=SysTick->VAL;          //��ȡ��ǰ��ֵ�Ĵ���ֵ
          if(tnow!=told)              //��ǰֵ�����ڿ�ʼֵ˵�����ڼ���
          {         

                 if(tnow<told)             //��ǰֵС�ڿ�ʼ��ֵ��˵��δ�Ƶ�0
                      tcnt+=told-tnow;     //����ֵ=��ʼֵ-��ǰֵ

                 else                  //��ǰֵ���ڿ�ʼ��ֵ��˵���ѼƵ�0�����¼���
                        tcnt+=reload-tnow+told;   //����ֵ=��װ��ֵ-��ǰֵ+��ʼֵ  ����
                                                  //�ӿ�ʼֵ�Ƶ�0�� 
                 told=tnow;                //���¿�ʼֵ
                 if(tcnt>=ticks)break;     //ʱ�䳬��/����Ҫ�ӳٵ�ʱ��,���˳�.
          } 
    }     
}
//void Delay_us()
//{
//	for(char i=10;i>0;i++)
//	{
//	__NOP();
//	__NOP();
//	__NOP();
//	__NOP();
//	__NOP();
//	}

//	
//}

void DATA_OUTPUT(u8 flg)
{
  	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
	GPIO_InitStruct.Pin = DATA_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(DATA_GPIO_Port, &GPIO_InitStruct);

	if(flg==0)
	{
		DATA_RESET();
	}
	else
	{
		DATA_SET();
	}
}

u8 DATA_INPUT(void)
{
  	GPIO_InitTypeDef GPIO_InitStruct = {0};
	u8 flg=0;
	
	GPIO_InitStruct.Pin = DATA_Pin;
  	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  	GPIO_InitStruct.Pull = GPIO_PULLUP;
  	HAL_GPIO_Init(DATA_GPIO_Port, &GPIO_InitStruct);

	if(DATA_READ()==GPIO_PIN_RESET)
	{
		flg=0;
	}
	else 
	{
		flg=1;
	}

	return flg;
}

u8 DH11_Read_Byte(void)
{
    u8 ReadDat=0;
    u8 temp=0;
    u8 retry=0;
    u8 i=0;
    
    for(i=0;i<8;i++)
    {
      while(DATA_READ()==0&&retry<100)//�ȴ�ֱ��DHT11����ߵ�ƽ
      {
        Delay_us(1);
        retry++;
      }
      retry=0;
      Delay_us(40);
      if(DATA_READ()==1)
      {
        temp=1;
      }
      else
      {
        temp=0;
      }
      while(DATA_READ()==1&&retry<100)//�ȴ�ֱ��DHT11����͵�ƽ����ʾ�˳�������1bit�źŽ�����ϡ�
      {
        Delay_us(1);
        retry++;
      }
      retry=0;
      ReadDat<<=1;
      ReadDat|=temp;
    }
    
    return ReadDat;
}

u8 DH11_Read(void)
{
  u8 retry=0;
  u8 i=0;
  
  DATA_OUTPUT(0);//����Ϊ���ģʽMCU��DH11�����ź�
  HAL_Delay(18);
  DATA_SET();
  Delay_us(20);
  
  DATA_INPUT();//����Ϊ����ģʽDH11��MCU�����ź�
  Delay_us(20);
  if(DATA_READ()==0)
  {
    while(DATA_READ()==0&&retry<100)
    {
      Delay_us(1);
      retry=0;
    }
    retry=0;
    while(DATA_READ()==1&&retry<100)
    {
      Delay_us(1);
      retry++;
    }
    retry=0;
    
    for(i=0;i<5;i++)//Data[0]ʪ�ȣ� Data[2]�¶ȡ�Data[1]��Data[3]�ֱ�Ϊ0��2��С��λ��Data[4]����У�顣
    {
      DH11_data.Data[i]=DH11_Read_Byte();
    }
    Delay_us(50);
  }
  u32 sum=DH11_data.Data[0]+DH11_data.Data[1]+DH11_data.Data[2]+DH11_data.Data[3];//У��
  if((sum)==DH11_data.Data[4])
  {
    DH11_data.humidity=DH11_data.Data[0];//��ȡʪ��
    DH11_data.temp=DH11_data.Data[2];//��ȡ�¶�
    return 1;    
  }
  else
  {
    return 0;
  }
}

void Test(void)
{
  if(DH11_Read())
  {
    DH11_data.index++;
    if(DH11_data.index>=128)
    {
      DH11_data.index=0;
    }
  }
   
}


void DH11_Task(void)
{
     Test();
}

