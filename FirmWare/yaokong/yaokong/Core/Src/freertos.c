/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
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
//#include"debug_com.h"
#include"yaogan.h"
#include"u8g2.h"
#include"oled.h"

#include"my_menu .h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
extern u8g2_t u8g2;
extern int y_task;
extern int x_task;
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
/* Definitions for control */
osThreadId_t controlHandle;
const osThreadAttr_t control_attributes = {
  .name = "control",
  .stack_size = 512 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for OLED */
osThreadId_t OLEDHandle;
const osThreadAttr_t OLED_attributes = {
  .name = "OLED",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void controlTask(void *argument);
void OLEDshow(void *argument);

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
  /* creation of control */
  controlHandle = osThreadNew(controlTask, NULL, &control_attributes);

  /* creation of OLED */
  OLEDHandle = osThreadNew(OLEDshow, NULL, &OLED_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_controlTask */
/**
  * @brief  Function implementing the control thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_controlTask */
void controlTask(void *argument)
{
  /* USER CODE BEGIN controlTask */
    my_u8g2_init();
  /* Infinite loop */
  for(;;)
  {
      switch_print();
    osDelay(20);
  }
  /* USER CODE END controlTask */
}

/* USER CODE BEGIN Header_OLEDshow */
/**
* @brief Function implementing the OLED thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_OLEDshow */
void OLEDshow(void *argument)
{
  /* USER CODE BEGIN OLEDshow */


  /* Infinite loop */
  for(;;)
  {



      u8g2_DrawCircle(&u8g2,64,32,32,U8G2_DRAW_ALL);
      u8g2_SendBuffer(&u8g2);

      u8g2_DrawDisc(&u8g2,64+x_task,32+y_task,10,U8G2_DRAW_ALL);
      u8g2_SendBuffer(&u8g2);
      u8g2_ClearBuffer(&u8g2);


    osDelay(10);
  }
  /* USER CODE END OLEDshow */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
