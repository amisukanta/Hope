/*
 * main-ex1.c
 *
 *  Created on: Feb 20, 2016
 *      Author: sukantakumarghosh
 */
#include "stm32f4xx_hal_conf.h"
#include "stm32f4xx_hal.h"


int main(void){
	GPIO_InitTypeDef GPIO_InitStruct;
	HAL_Init();

	/* GPIO ports enable */
	__GPIOC_CLK_ENABLE();
	__GPIOA_CLK_ENABLE();

	/* Configure GPIO pin : PC13 - USER BUTTON  */
	GPIO_InitStruct.Pin = GPIO_PIN_13;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	/* Configure GPIO pin : PA5 - LD2 LED */

	GPIO_InitStruct.Pin = GPIO_PIN_5;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

	while(1);
}




