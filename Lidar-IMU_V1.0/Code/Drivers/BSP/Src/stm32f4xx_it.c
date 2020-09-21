/* USER CODE BEGIN Header */
/**
    ******************************************************************************
    * @file    stm32f4xx_it.c
    * @brief   Interrupt Service Routines.
    ******************************************************************************
    *
    * COPYRIGHT(c) 2019 STMicroelectronics
    *
    * Redistribution and use in source and binary forms, with or without modification,
    * are permitted provided that the following conditions are met:
    *   1. Redistributions of source code must retain the above copyright notice,
    *      this list of conditions and the following disclaimer.
    *   2. Redistributions in binary form must reproduce the above copyright notice,
    *      this list of conditions and the following disclaimer in the documentation
    *      and/or other materials provided with the distribution.
    *   3. Neither the name of STMicroelectronics nor the names of its contributors
    *      may be used to endorse or promote products derived from this software
    *      without specific prior written permission.
    *
    * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
    * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
    * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
    * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
    *
    ******************************************************************************
    */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_it.h"


/* External variables --------------------------------------------------------*/
extern CAN_HandleTypeDef hcan1;
extern CAN_HandleTypeDef hcan2;
extern TIM_HandleTypeDef htim6;
extern DMA_HandleTypeDef hdma_uart4_rx;
extern DMA_HandleTypeDef hdma_uart5_rx;
extern DMA_HandleTypeDef hdma_uart5_tx;
extern DMA_HandleTypeDef hdma_usart1_tx;
extern DMA_HandleTypeDef hdma_usart2_rx;
extern DMA_HandleTypeDef hdma_usart2_tx;
extern DMA_HandleTypeDef hdma_usart3_rx;
extern DMA_HandleTypeDef hdma_usart3_tx;
extern DMA_HandleTypeDef hdma_usart6_rx;
extern DMA_HandleTypeDef hdma_usart6_tx;
extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart5;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart6;

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */ 
/******************************************************************************/
/**
    * @brief This function handles Non maskable interrupt.
    */
void NMI_Handler(void)
{

}

/**
    * @brief This function handles Hard fault interrupt.
    */
void HardFault_Handler(void)
{
    while (1)
    {

    }
}

/**
    * @brief This function handles Memory management fault.
    */
void MemManage_Handler(void)
{
    while (1)
    {

    }
}

/**
    * @brief This function handles Pre-fetch fault, memory access fault.
    */
void BusFault_Handler(void)
{
    while (1)
    {

    }
}

/**
    * @brief This function handles Undefined instruction or illegal state.
    */
void UsageFault_Handler(void)
{
    while (1)
    {

    }
}

/**
    * @brief This function handles System service call via SWI instruction.
    */
void SVC_Handler(void)
{

}

/**
    * @brief This function handles Debug monitor.
    */
void DebugMon_Handler(void)
{

}

/**
    * @brief This function handles Pendable request for system service.
    */
void PendSV_Handler(void)
{

}

/**
* @brief This function handles System tick timer.
*/
void SysTick_Handler(void)
{
    HAL_IncTick();
    HAL_SYSTICK_IRQHandler();
}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/



/**
    * @brief This function handles CAN1 RX0 interrupts.
    */
void CAN1_RX0_IRQHandler(void)
{
    HAL_CAN_IRQHandler(&hcan1);
}

/**
    * @brief This function handles CAN1 RX1 interrupt.
    */
void CAN1_RX1_IRQHandler(void)
{
    HAL_CAN_IRQHandler(&hcan1);
}


/**
    * @brief This function handles USART1 global interrupt.
    */
void USART1_IRQHandler(void)
{
    HAL_UART_IRQHandler(&huart1);
}

/**
    * @brief This function handles USART2 global interrupt.
    */
void USART2_IRQHandler(void)
{
    HAL_UART_IRQHandler(&huart2);
}

/**
    * @brief This function handles USART3 global interrupt.
    */
void USART3_IRQHandler(void)
{
    HAL_UART_IRQHandler(&huart3);
}


/**
    * @brief This function handles UART4 global interrupt.
    */
void UART4_IRQHandler(void)
{
    HAL_UART_IRQHandler(&huart4);
}

/**
    * @brief This function handles UART5 global interrupt.
    */
void UART5_IRQHandler(void)
{
    // HAL_UART_IRQHandler(&huart5);
    MY_UART_IRQHandler(&huart5);
}

/**
    * @brief This function handles USART6 global interrupt.
    */
void USART6_IRQHandler(void)
{
    MY_UART_IRQHandler(&huart6);
    // HAL_UART_IRQHandler(&huart6);

}


/**
    * @brief This function handles CAN2 RX0 interrupts.
    */
void CAN2_RX0_IRQHandler(void)
{
    HAL_CAN_IRQHandler(&hcan2);
}

/**
    * @brief This function handles CAN2 RX1 interrupt.
    */
void CAN2_RX1_IRQHandler(void)
{
    HAL_CAN_IRQHandler(&hcan2);
}

/**
    * @brief This function handles DMA1 stream0 global interrupt.
    */
void DMA1_Stream0_IRQHandler(void)
{
    HAL_DMA_IRQHandler(&hdma_uart5_rx);
}

/**
    * @brief This function handles DMA1 stream1 global interrupt.
    */
void DMA1_Stream1_IRQHandler(void)
{
    HAL_DMA_IRQHandler(&hdma_usart3_rx);
}

/**
    * @brief This function handles DMA1 stream2 global interrupt.
    */
void DMA1_Stream2_IRQHandler(void)
{
    HAL_DMA_IRQHandler(&hdma_uart4_rx);
}

/**
    * @brief This function handles DMA1 stream3 global interrupt.
    */
void DMA1_Stream3_IRQHandler(void)
{
    HAL_DMA_IRQHandler(&hdma_usart3_tx);
}

/**
    * @brief This function handles DMA1 stream5 global interrupt.
    */
void DMA1_Stream5_IRQHandler(void)
{
    HAL_DMA_IRQHandler(&hdma_usart2_rx);
}

/**
    * @brief This function handles DMA1 stream6 global interrupt.
    */
void DMA1_Stream6_IRQHandler(void)
{
    HAL_DMA_IRQHandler(&hdma_usart2_tx);
}

/**
    * @brief This function handles DMA1 stream7 global interrupt.
    */
void DMA1_Stream7_IRQHandler(void)
{
    HAL_DMA_IRQHandler(&hdma_uart5_tx);
}


// void DMA2_Stream1_IRQHandler(void)
// {
//   HAL_DMA_IRQHandler(&hdma_usart6_rx);
// }

/**
    * @brief This function handles DMA2 stream6 global interrupt.
    */
void DMA2_Stream6_IRQHandler(void)
{
    HAL_DMA_IRQHandler(&hdma_usart6_tx);
}

/**
    * @brief This function handles DMA2 stream7 global interrupt.
    */
void DMA2_Stream7_IRQHandler(void)
{
    HAL_DMA_IRQHandler(&hdma_usart1_tx);
}

void EXTI4_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);

}

void EXTI9_5_IRQHandler(void)
{
    // HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_5);
    // HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_6);
    // HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_7);
    // HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_8);
    // HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_9);
}



void TIM6_DAC_IRQHandler(void)
{
    if (__HAL_TIM_GET_FLAG(&htim6, TIM_FLAG_UPDATE) != RESET)
    {
        if (__HAL_TIM_GET_IT_SOURCE(&htim6, TIM_IT_UPDATE) != RESET)
        {
            __HAL_TIM_CLEAR_IT(&htim6, TIM_IT_UPDATE);
            MY_SYSCLK_Callback();
        }
    }
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
