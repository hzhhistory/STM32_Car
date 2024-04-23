#ifndef __CAR_DFINE_H__
#define __CAR_DFINE_H__

#define STBY_HIGH() HAL_GPIO_WritePin(GPIOA,STBY_Pin,GPIO_PIN_SET)
#define STBY_LOW()  HAL_GPIO_WritePin(GPIOA,STBY_Pin,GPIO_PIN_RESET)
#define PWMA_HIGH() HAL_GPIO_WritePin(GPIOA,PWMA_Pin,GPIO_PIN_SET)
#define PWMA_LOW()  HAL_GPIO_WritePin(GPIOA,PWMA_Pin,GPIO_PIN_RESET)
#define PWMB_HIGH()  HAL_GPIO_WritePin(GPIOA,PWMB_Pin,GPIO_PIN_SET)
#define PWMB_LOW()  HAL_GPIO_WritePin(GPIOA,PWMB_Pin,GPIO_PIN_RESET)
#define AIN1_HIGH() HAL_GPIO_WritePin(GPIOB,AIN1_Pin,GPIO_PIN_SET)
#define AIN1_LOW()  HAL_GPIO_WritePin(GPIOB,AIN1_Pin,GPIO_PIN_RESET)
#define AIN2_HIGH() HAL_GPIO_WritePin(GPIOB,AIN2_Pin,GPIO_PIN_SET)
#define AIN2_LOW()  HAL_GPIO_WritePin(GPIOB,AIN2_Pin,GPIO_PIN_RESET)
#define BIN1_HIGH() HAL_GPIO_WritePin(GPIOB,BIN1_Pin,GPIO_PIN_SET)
#define BIN1_LOW()  HAL_GPIO_WritePin(GPIOB,BIN1_Pin,GPIO_PIN_RESET)
#define BIN2_HIGH() HAL_GPIO_WritePin(GPIOB,BIN2_Pin,GPIO_PIN_SET)
#define BIN2_LOW()  HAL_GPIO_WritePin(GPIOB,BIN2_Pin,GPIO_PIN_RESET)


#endif