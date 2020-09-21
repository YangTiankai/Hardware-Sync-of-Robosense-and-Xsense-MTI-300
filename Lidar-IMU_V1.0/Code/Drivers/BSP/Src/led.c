#include "led.h"

void LED_Core_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOB_CLK_ENABLE();
    
    HAL_GPIO_WritePin(LED_CORE_GPIO_Port, LED_CORE_Pin, GPIO_PIN_SET);

    GPIO_InitStruct.Pin = LED_CORE_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(LED_CORE_GPIO_Port, &GPIO_InitStruct);
}

void LED_Core_On(void)
{
    HAL_GPIO_WritePin(LED_CORE_GPIO_Port, LED_CORE_Pin, GPIO_PIN_RESET);
}

void LED_Core_Off(void)
{
    HAL_GPIO_WritePin(LED_CORE_GPIO_Port, LED_CORE_Pin, GPIO_PIN_SET);
}

void LED_Core_Turn(void)
{
    HAL_GPIO_TogglePin(LED_CORE_GPIO_Port, LED_CORE_Pin);
}

