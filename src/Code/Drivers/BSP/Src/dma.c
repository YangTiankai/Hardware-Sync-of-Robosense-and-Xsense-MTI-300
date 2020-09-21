
#include "dma.h"


/*----------------------------------------------------------------------------*/
/* Configure DMA                                                              */
/*----------------------------------------------------------------------------*/


/** 
  * Enable DMA controller clock
  */
void MX_DMA_Init(void) 
{
    __HAL_RCC_DMA1_CLK_ENABLE();
    __HAL_RCC_DMA2_CLK_ENABLE();

    //USART5_RX
    HAL_NVIC_SetPriority(DMA1_Stream0_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(DMA1_Stream0_IRQn);

    //USART3_RX
    // HAL_NVIC_SetPriority(DMA1_Stream1_IRQn, 0, 0);
    // HAL_NVIC_EnableIRQ(DMA1_Stream1_IRQn);

    // HAL_NVIC_SetPriority(DMA1_Stream2_IRQn, 0, 0);
    // HAL_NVIC_EnableIRQ(DMA1_Stream2_IRQn);

    //USART3_TX
    // HAL_NVIC_SetPriority(DMA1_Stream3_IRQn, 0, 0);
    // HAL_NVIC_EnableIRQ(DMA1_Stream3_IRQn);

    //USART2_RX
    // HAL_NVIC_SetPriority(DMA1_Stream5_IRQn, 0, 0);
    // HAL_NVIC_EnableIRQ(DMA1_Stream5_IRQn);

    //USART2_TX
    HAL_NVIC_SetPriority(DMA1_Stream6_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(DMA1_Stream6_IRQn);

    //USART5_TX
    // HAL_NVIC_SetPriority(DMA1_Stream7_IRQn, 0, 0);
    // HAL_NVIC_EnableIRQ(DMA1_Stream7_IRQn);

    //USART6_RX
    HAL_NVIC_SetPriority(DMA2_Stream1_IRQn, 1, 1);
    HAL_NVIC_EnableIRQ(DMA2_Stream1_IRQn);

    //USART6_TX
    HAL_NVIC_SetPriority(DMA2_Stream6_IRQn, 2, 2);
    HAL_NVIC_EnableIRQ(DMA2_Stream6_IRQn);

    //USART1_TX
    HAL_NVIC_SetPriority(DMA2_Stream7_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(DMA2_Stream7_IRQn);
}

