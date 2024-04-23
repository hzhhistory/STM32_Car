/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include"debug_com.h"
#include"change.h"
#include"my_menu .h"
#include"Fire.h"
#include"dht11.h"
#include"stdio.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
extern u8g2_t u8g2;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for Recive_Task */
osThreadId_t Recive_TaskHandle;
const osThreadAttr_t Recive_Task_attributes = {
  .name = "Recive_Task",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void Recive_task(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */

    /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of Recive_Task */
  Recive_TaskHandle = osThreadNew(Recive_task, NULL, &Recive_Task_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_Recive_task */
/**
  * @brief  Function implementing the Recive_Task thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_Recive_task */
void Recive_task(void *argument)
{
  /* USER CODE BEGIN Recive_task */

    my_u8g2_init();

    vTaskDelay(100);
  /* Infinite loop */
  for(;;)
  {

      Car_Control();
      Fire_reback();
      DH11_Task();
      u8g2_SetFont(&u8g2, u8g2_font_helvR12_tf);
      PrintVarFormat(&u8g2,40,20,u8g2_font_sirclivethebold_tr,DH11_data.temp);
      PrintVarFormat(&u8g2,60,40,u8g2_font_sirclivethebold_tr,DH11_data.humidity);
      u8g2_DrawStr(&u8g2,0,20,"temp:");
      u8g2_DrawStr(&u8g2,0,40,"humidity:");
      u8g2_SendBuffer(&u8g2);
//      printf("Temp is %d\r\n", DH11_data.temp);
//      printf("Humi is %d\r\n", DH11_data.humidity);
      osDelay(200);
  }
  /* USER CODE END Recive_task */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
