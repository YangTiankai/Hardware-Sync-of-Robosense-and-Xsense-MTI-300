
#include "usart.h"


UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;
UART_HandleTypeDef huart4;
UART_HandleTypeDef huart5;
UART_HandleTypeDef huart6;


DMA_HandleTypeDef hdma_usart1_tx;
DMA_HandleTypeDef hdma_usart2_rx;
DMA_HandleTypeDef hdma_usart2_tx;
DMA_HandleTypeDef hdma_usart3_rx;
DMA_HandleTypeDef hdma_usart3_tx;
DMA_HandleTypeDef hdma_uart4_rx;
DMA_HandleTypeDef hdma_uart5_rx;
DMA_HandleTypeDef hdma_uart5_tx;
DMA_HandleTypeDef hdma_usart6_tx;
DMA_HandleTypeDef hdma_usart6_rx;



__weak void MY_UART_IRQHandler(UART_HandleTypeDef *huart)
{
    return;
}



/* USART1 init function */
void MX_USART1_UART_Init(void)
{

    huart1.Instance = USART1;
    huart1.Init.BaudRate = 115200;
    huart1.Init.WordLength = UART_WORDLENGTH_8B;
    huart1.Init.StopBits = UART_STOPBITS_1;
    huart1.Init.Parity = UART_PARITY_NONE;
    huart1.Init.Mode = UART_MODE_TX_RX;
    huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart1.Init.OverSampling = UART_OVERSAMPLING_16;
    if (HAL_UART_Init(&huart1) != HAL_OK)
    {
        Error_Handler(__FILE__, __LINE__);
    }

}

/* USART2 init function */

void MX_USART2_UART_Init(void)
{

    huart2.Instance = USART2;
    huart2.Init.BaudRate = 115200;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;
    if (HAL_UART_Init(&huart2) != HAL_OK)
    {
        Error_Handler(__FILE__, __LINE__);
    }

}


/* USART3 init function */
void MX_USART3_UART_Init(void)
{

    huart3.Instance = USART3;
    huart3.Init.BaudRate = 9600;
    huart3.Init.WordLength = UART_WORDLENGTH_8B;
    huart3.Init.StopBits = UART_STOPBITS_1;
    huart3.Init.Parity = UART_PARITY_NONE;
    huart3.Init.Mode = UART_MODE_TX_RX;
    huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart3.Init.OverSampling = UART_OVERSAMPLING_16;
    if (HAL_UART_Init(&huart3) != HAL_OK)
    {
        Error_Handler(__FILE__, __LINE__);
    }
}

/* UART4 init function */
void MX_UART4_Init(void)
{

    huart4.Instance = UART4;
    huart4.Init.BaudRate = 100000;
    huart4.Init.WordLength = UART_WORDLENGTH_8B;
    huart4.Init.StopBits = UART_STOPBITS_1;
    huart4.Init.Parity = UART_PARITY_NONE;
    huart4.Init.Mode = UART_MODE_TX_RX;
    huart4.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart4.Init.OverSampling = UART_OVERSAMPLING_16;
    if (HAL_UART_Init(&huart4) != HAL_OK)
    {
        Error_Handler(__FILE__, __LINE__);
    }
}

/* UART5 init function */
void MX_UART5_Init(void)
{

    huart5.Instance = UART5;
    huart5.Init.BaudRate = 100000;
    huart5.Init.WordLength = UART_WORDLENGTH_8B;
    huart5.Init.StopBits = UART_STOPBITS_1;
    huart5.Init.Parity = UART_PARITY_NONE;
    huart5.Init.Mode = UART_MODE_TX_RX;
    huart5.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart5.Init.OverSampling = UART_OVERSAMPLING_16;
    if (HAL_UART_Init(&huart5) != HAL_OK)
    {
        Error_Handler(__FILE__, __LINE__);
    }

    __HAL_DMA_ENABLE(&hdma_uart5_rx);               //使能DMA数据流
    __HAL_UART_ENABLE_IT(&huart5, UART_IT_IDLE);
    __HAL_UART_DISABLE_IT(&huart5, UART_IT_RXNE);
}


/* USART6 init function */
void MX_USART6_UART_Init(void)
{

    huart6.Instance = USART6;
    huart6.Init.BaudRate = 1000000;
    huart6.Init.WordLength = UART_WORDLENGTH_8B;
    huart6.Init.StopBits = UART_STOPBITS_1;
    huart6.Init.Parity = UART_PARITY_NONE;
    huart6.Init.Mode = UART_MODE_TX_RX;
    huart6.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart6.Init.OverSampling = UART_OVERSAMPLING_16;
    if (HAL_UART_Init(&huart6) != HAL_OK)
    {
        Error_Handler(__FILE__, __LINE__);
    }
    __HAL_DMA_ENABLE(&hdma_usart6_rx);               //使能DMA数据流
    __HAL_UART_ENABLE_IT(&huart6, UART_IT_IDLE);
    __HAL_UART_DISABLE_IT(&huart6, UART_IT_RXNE);    
}



void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

    GPIO_InitTypeDef GPIO_InitStruct = {0};

    if(uartHandle->Instance==USART1)
    {
        /* USART1 clock enable */
        __HAL_RCC_USART1_CLK_ENABLE();
    
        __HAL_RCC_GPIOA_CLK_ENABLE();
        /**USART1 GPIO Configuration    
        PB6     ------> USART1_TX
        PB7     ------> USART1_RX 
        */
        GPIO_InitStruct.Pin = GPIO_PIN_9 | GPIO_PIN_10;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

        /* USART1 DMA Init */
        /* USART1_TX Init */
        hdma_usart1_tx.Instance = DMA2_Stream7;
        hdma_usart1_tx.Init.Channel = DMA_CHANNEL_4;
        hdma_usart1_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
        hdma_usart1_tx.Init.PeriphInc = DMA_PINC_DISABLE;
        hdma_usart1_tx.Init.MemInc = DMA_MINC_ENABLE;
        hdma_usart1_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
        hdma_usart1_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
        hdma_usart1_tx.Init.Mode = DMA_NORMAL;
        hdma_usart1_tx.Init.Priority = DMA_PRIORITY_LOW;
        hdma_usart1_tx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
        if (HAL_DMA_Init(&hdma_usart1_tx) != HAL_OK)
        {
            Error_Handler(__FILE__, __LINE__);
        }

        __HAL_LINKDMA(uartHandle, hdmatx, hdma_usart1_tx);

        /* USART1 interrupt Init */
        HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
        HAL_NVIC_EnableIRQ(USART1_IRQn);
    }
    else if(uartHandle->Instance==USART2)
    {
        /* USART2 clock enable */
        __HAL_RCC_USART2_CLK_ENABLE();
    
        __HAL_RCC_GPIOA_CLK_ENABLE();
        /**USART2 GPIO Configuration    
        PA2     ------> USART2_TX
        PA3     ------> USART2_RX 
        */
        GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

        /* USART2 DMA Init */
        /* USART2_RX Init */
        hdma_usart2_rx.Instance = DMA1_Stream5;
        hdma_usart2_rx.Init.Channel = DMA_CHANNEL_4;
        hdma_usart2_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
        hdma_usart2_rx.Init.PeriphInc = DMA_PINC_DISABLE;
        hdma_usart2_rx.Init.MemInc = DMA_MINC_ENABLE;
        hdma_usart2_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
        hdma_usart2_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
        hdma_usart2_rx.Init.Mode = DMA_NORMAL;
        hdma_usart2_rx.Init.Priority = DMA_PRIORITY_LOW;
        hdma_usart2_rx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
        if (HAL_DMA_Init(&hdma_usart2_rx) != HAL_OK)
        {
        Error_Handler(__FILE__, __LINE__);
        }

        __HAL_LINKDMA(uartHandle,hdmarx,hdma_usart2_rx);

        /* USART2_TX Init */
        hdma_usart2_tx.Instance = DMA1_Stream6;
        hdma_usart2_tx.Init.Channel = DMA_CHANNEL_4;
        hdma_usart2_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
        hdma_usart2_tx.Init.PeriphInc = DMA_PINC_DISABLE;
        hdma_usart2_tx.Init.MemInc = DMA_MINC_ENABLE;
        hdma_usart2_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
        hdma_usart2_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
        hdma_usart2_tx.Init.Mode = DMA_NORMAL;
        hdma_usart2_tx.Init.Priority = DMA_PRIORITY_LOW;
        hdma_usart2_tx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
        if (HAL_DMA_Init(&hdma_usart2_tx) != HAL_OK)
        {
            Error_Handler(__FILE__, __LINE__);
        }

        __HAL_LINKDMA(uartHandle,hdmatx,hdma_usart2_tx);

        /* USART2 interrupt Init */
        HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);
        HAL_NVIC_EnableIRQ(USART2_IRQn);
    }
    else if(uartHandle->Instance==USART3)
    {
        /* USART3 clock enable */
        __HAL_RCC_USART3_CLK_ENABLE();
    
        __HAL_RCC_GPIOB_CLK_ENABLE();
        /**USART3 GPIO Configuration    
        PB10     ------> USART3_TX
        PB11     ------> USART3_RX 
        */
        GPIO_InitStruct.Pin = GPIO_PIN_10 | GPIO_PIN_11;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
        HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

        /* USART3 DMA Init */
        /* USART3_RX Init */
        hdma_usart3_rx.Instance = DMA1_Stream1;
        hdma_usart3_rx.Init.Channel = DMA_CHANNEL_4;
        hdma_usart3_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
        hdma_usart3_rx.Init.PeriphInc = DMA_PINC_DISABLE;
        hdma_usart3_rx.Init.MemInc = DMA_MINC_ENABLE;
        hdma_usart3_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
        hdma_usart3_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
        hdma_usart3_rx.Init.Mode = DMA_NORMAL;
        hdma_usart3_rx.Init.Priority = DMA_PRIORITY_LOW;
        hdma_usart3_rx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
        if (HAL_DMA_Init(&hdma_usart3_rx) != HAL_OK)
        {
            Error_Handler(__FILE__, __LINE__);
        }

        __HAL_LINKDMA(uartHandle, hdmarx, hdma_usart3_rx);

        /* USART3_TX Init */
        hdma_usart3_tx.Instance = DMA1_Stream3;
        hdma_usart3_tx.Init.Channel = DMA_CHANNEL_4;
        hdma_usart3_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
        hdma_usart3_tx.Init.PeriphInc = DMA_PINC_DISABLE;
        hdma_usart3_tx.Init.MemInc = DMA_MINC_ENABLE;
        hdma_usart3_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
        hdma_usart3_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
        hdma_usart3_tx.Init.Mode = DMA_NORMAL;
        hdma_usart3_tx.Init.Priority = DMA_PRIORITY_LOW;
        hdma_usart3_tx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
        if (HAL_DMA_Init(&hdma_usart3_tx) != HAL_OK)
        {
            Error_Handler(__FILE__, __LINE__);
        }

        __HAL_LINKDMA(uartHandle,hdmatx,hdma_usart3_tx);

        /* USART3 interrupt Init */
        HAL_NVIC_SetPriority(USART3_IRQn, 0, 0);
        HAL_NVIC_EnableIRQ(USART3_IRQn);
    }
    else if(uartHandle->Instance==UART4)
    {
        /* UART4 clock enable */
        __HAL_RCC_UART4_CLK_ENABLE();
    
        __HAL_RCC_GPIOA_CLK_ENABLE();
        /**UART4 GPIO Configuration    
        PA0-WKUP     ------> UART4_TX
        PA1     ------> UART4_RX 
        */
        GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF8_UART4;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

        /* UART4 DMA Init */
        /* UART4_RX Init */
        hdma_uart4_rx.Instance = DMA1_Stream2;
        hdma_uart4_rx.Init.Channel = DMA_CHANNEL_4;
        hdma_uart4_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
        hdma_uart4_rx.Init.PeriphInc = DMA_PINC_DISABLE;
        hdma_uart4_rx.Init.MemInc = DMA_MINC_ENABLE;
        hdma_uart4_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
        hdma_uart4_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
        hdma_uart4_rx.Init.Mode = DMA_CIRCULAR;
        hdma_uart4_rx.Init.Priority = DMA_PRIORITY_LOW;
        hdma_uart4_rx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
        if (HAL_DMA_Init(&hdma_uart4_rx) != HAL_OK)
        {
        Error_Handler(__FILE__, __LINE__);
        }

        __HAL_LINKDMA(uartHandle, hdmarx, hdma_uart4_rx);

        /* UART4 interrupt Init */
        HAL_NVIC_SetPriority(UART4_IRQn, 0, 0);
        HAL_NVIC_EnableIRQ(UART4_IRQn);
    }
    else if(uartHandle->Instance==UART5)
    {
        /* UART5 clock enable */
        __HAL_RCC_UART5_CLK_ENABLE();
    
        __HAL_RCC_GPIOC_CLK_ENABLE();
        __HAL_RCC_GPIOD_CLK_ENABLE();
        /**UART5 GPIO Configuration    
        PC12     ------> UART5_TX
        PD2     ------> UART5_RX 
        */
        GPIO_InitStruct.Pin = GPIO_PIN_12;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF8_UART5;
        HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = GPIO_PIN_2;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF8_UART5;
        HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

        /* UART5 DMA Init */
        /* UART5_RX Init */
        hdma_uart5_rx.Instance = DMA1_Stream0;
        hdma_uart5_rx.Init.Channel = DMA_CHANNEL_4;
        hdma_uart5_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
        hdma_uart5_rx.Init.PeriphInc = DMA_PINC_DISABLE;
        hdma_uart5_rx.Init.MemInc = DMA_MINC_ENABLE;
        hdma_uart5_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
        hdma_uart5_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
        hdma_uart5_rx.Init.Mode = DMA_NORMAL;
        hdma_uart5_rx.Init.Priority = DMA_PRIORITY_LOW;
        hdma_uart5_rx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
        if (HAL_DMA_Init(&hdma_uart5_rx) != HAL_OK)
        {
            Error_Handler(__FILE__, __LINE__);
        }
        __HAL_LINKDMA(uartHandle,hdmarx,hdma_uart5_rx);

        /* UART5_TX Init */
        hdma_uart5_tx.Instance = DMA1_Stream7;
        hdma_uart5_tx.Init.Channel = DMA_CHANNEL_4;
        hdma_uart5_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
        hdma_uart5_tx.Init.PeriphInc = DMA_PINC_DISABLE;
        hdma_uart5_tx.Init.MemInc = DMA_MINC_ENABLE;
        hdma_uart5_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
        hdma_uart5_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
        hdma_uart5_tx.Init.Mode = DMA_NORMAL;
        hdma_uart5_tx.Init.Priority = DMA_PRIORITY_LOW;
        hdma_uart5_tx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
        if (HAL_DMA_Init(&hdma_uart5_tx) != HAL_OK)
        {
            Error_Handler(__FILE__, __LINE__);
        }
        __HAL_LINKDMA(uartHandle, hdmatx, hdma_uart5_tx);

        /* UART5 interrupt Init */
        HAL_NVIC_SetPriority(UART5_IRQn, 0, 0);
        HAL_NVIC_EnableIRQ(UART5_IRQn);
    }    
    else if(uartHandle->Instance==USART6)
    {
        /* USART6 clock enable */
        __HAL_RCC_USART6_CLK_ENABLE();
    
        __HAL_RCC_GPIOC_CLK_ENABLE();
        /**USART6 GPIO Configuration    
        PC6     ------> USART6_TX
        PC7     ------> USART6_RX 
        */
        GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF8_USART6;
        HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

        /* USART6 DMA Init */
        /* USART6_TX Init */
        hdma_usart6_tx.Instance = DMA2_Stream6;
        hdma_usart6_tx.Init.Channel = DMA_CHANNEL_5;
        hdma_usart6_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
        hdma_usart6_tx.Init.PeriphInc = DMA_PINC_DISABLE;
        hdma_usart6_tx.Init.MemInc = DMA_MINC_ENABLE;
        hdma_usart6_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
        hdma_usart6_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
        hdma_usart6_tx.Init.Mode = DMA_NORMAL;
        hdma_usart6_tx.Init.Priority = DMA_PRIORITY_LOW;
        hdma_usart6_tx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
        if (HAL_DMA_Init(&hdma_usart6_tx) != HAL_OK)
        {
            Error_Handler(__FILE__, __LINE__);
        }
        __HAL_LINKDMA(uartHandle,hdmatx,hdma_usart6_tx);

        /* USART6_RX Init */
        hdma_usart6_rx.Instance = DMA2_Stream1;
        hdma_usart6_rx.Init.Channel = DMA_CHANNEL_5;
        hdma_usart6_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
        hdma_usart6_rx.Init.PeriphInc = DMA_PINC_DISABLE;
        hdma_usart6_rx.Init.MemInc = DMA_MINC_ENABLE;
        hdma_usart6_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
        hdma_usart6_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
        hdma_usart6_rx.Init.Mode = DMA_NORMAL;
        hdma_usart6_rx.Init.Priority = DMA_PRIORITY_LOW;
        hdma_usart6_rx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
        if (HAL_DMA_Init(&hdma_usart6_rx) != HAL_OK)
        {
            Error_Handler(__FILE__, __LINE__);
        }
        __HAL_LINKDMA(uartHandle,hdmarx,hdma_usart6_rx);
        
        /* USART6 interrupt Init */
        HAL_NVIC_SetPriority(USART6_IRQn, 1, 1);
        HAL_NVIC_EnableIRQ(USART6_IRQn);
    }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

    if(uartHandle->Instance==UART4)
    {
        /* Peripheral clock disable */
        __HAL_RCC_UART4_CLK_DISABLE();
    
        /**UART4 GPIO Configuration    
        PA0-WKUP     ------> UART4_TX
        PA1     ------> UART4_RX 
        */
        HAL_GPIO_DeInit(GPIOA, GPIO_PIN_0|GPIO_PIN_1);

        /* UART4 DMA DeInit */
        HAL_DMA_DeInit(uartHandle->hdmarx);

        /* UART4 interrupt Deinit */
        HAL_NVIC_DisableIRQ(UART4_IRQn);
    }
    else if(uartHandle->Instance==UART5)
    {
        /* Peripheral clock disable */
        __HAL_RCC_UART5_CLK_DISABLE();
    
        /**UART5 GPIO Configuration    
        PC12     ------> UART5_TX
        PD2     ------> UART5_RX 
        */
        HAL_GPIO_DeInit(GPIOC, GPIO_PIN_12);

        HAL_GPIO_DeInit(GPIOD, GPIO_PIN_2);

        /* UART5 DMA DeInit */
        HAL_DMA_DeInit(uartHandle->hdmarx);
        HAL_DMA_DeInit(uartHandle->hdmatx);

        /* UART5 interrupt Deinit */
        HAL_NVIC_DisableIRQ(UART5_IRQn);
    }
    else if(uartHandle->Instance==USART1)
    {
        /* Peripheral clock disable */
        __HAL_RCC_USART1_CLK_DISABLE();
    
        /**USART1 GPIO Configuration    
        PB6     ------> USART1_TX
        PB7     ------> USART1_RX 
        */
        HAL_GPIO_DeInit(GPIOB, GPIO_PIN_6|GPIO_PIN_7);

        /* USART1 DMA DeInit */
        HAL_DMA_DeInit(uartHandle->hdmatx);

        /* USART1 interrupt Deinit */
        HAL_NVIC_DisableIRQ(USART1_IRQn);
    }
    else if(uartHandle->Instance==USART2)
    {
        /* Peripheral clock disable */
        __HAL_RCC_USART2_CLK_DISABLE();
    
        /**USART2 GPIO Configuration    
        PA2     ------> USART2_TX
        PA3     ------> USART2_RX 
        */
        HAL_GPIO_DeInit(GPIOA, GPIO_PIN_2|GPIO_PIN_3);

        /* USART2 DMA DeInit */
        HAL_DMA_DeInit(uartHandle->hdmarx);
        HAL_DMA_DeInit(uartHandle->hdmatx);

        /* USART2 interrupt Deinit */
        HAL_NVIC_DisableIRQ(USART2_IRQn);
    }
    else if(uartHandle->Instance==USART3)
    {
        /* Peripheral clock disable */
        __HAL_RCC_USART3_CLK_DISABLE();
    
        /**USART3 GPIO Configuration    
        PC10     ------> USART3_TX
        PC11     ------> USART3_RX 
        */
        HAL_GPIO_DeInit(GPIOC, GPIO_PIN_10|GPIO_PIN_11);

        /* USART3 DMA DeInit */
        HAL_DMA_DeInit(uartHandle->hdmarx);
        HAL_DMA_DeInit(uartHandle->hdmatx);

        /* USART3 interrupt Deinit */
        HAL_NVIC_DisableIRQ(USART3_IRQn);
    }
    else if(uartHandle->Instance==USART6)
    {
        /* Peripheral clock disable */
        __HAL_RCC_USART6_CLK_DISABLE();
    
        /**USART6 GPIO Configuration    
        PC6     ------> USART6_TX
        PC7     ------> USART6_RX 
        */
        HAL_GPIO_DeInit(GPIOC, GPIO_PIN_6|GPIO_PIN_7);

        /* USART6 DMA DeInit */
        HAL_DMA_DeInit(uartHandle->hdmatx);
        HAL_DMA_DeInit(uartHandle->hdmarx);

        /* USART6 interrupt Deinit */
        HAL_NVIC_DisableIRQ(USART6_IRQn);
    }
} 


#ifdef __GNUC__
/* With GCC, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
PUTCHAR_PROTOTYPE
{
    /* Place your implementation of fputc here */
    /* e.g. write a character to the USART1 and Loop until the end of transmission */
    HAL_UART_Transmit(&UART_PRINT_HANDLE, (uint8_t *)&ch, 1, 0xFFFF);

    return ch;
}

