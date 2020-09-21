
#include "main.h"


uint8_t u5rxdata[UART_DMA_RX_SIZE] = {0};
uint8_t u6rxdata[UART_DMA_RX_SIZE] = {0};
CLOCK clock = {0};
UTC utc = {0};

int rxlen = 0;

int pulse_count = 0;
int sample_us = 0;
int flag_first_sample = 0;
int first_ms = 0;
int first_us = 0;

void MY_UART_IRQHandler(UART_HandleTypeDef *huart)
{
    if(huart->Instance == UART5)
    {
        if(__HAL_UART_GET_FLAG(huart, UART_FLAG_IDLE) != RESET)
        {
            __HAL_UART_CLEAR_IDLEFLAG(huart);
            rxlen = UART_DMA_RX_SIZE - DMA1_Stream0->NDTR;
            HAL_UART_DMAStop(huart);
            HAL_UART_Receive_DMA(huart, u5rxdata, UART_DMA_RX_SIZE);
            if(rxlen == 18)
            {
            }
        }
    }
    else if(huart->Instance == USART6)
    {
        if(__HAL_UART_GET_FLAG(huart, UART_FLAG_IDLE) != RESET)
        {
            __HAL_UART_CLEAR_IDLEFLAG(huart);
   
            HAL_UART_DMAStop(huart);
            HAL_UART_Receive_DMA(huart, u6rxdata, UART_DMA_RX_SIZE);
        }
    }
    
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if(huart->Instance == UART5)
    {

    }
}

 void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
 {
 	if(huart->Instance == USART3)
 	{
        __HAL_UART_CLEAR_OREFLAG(&huart5);
 	}
    else if(huart->Instance == UART5)
 	{
        __HAL_UART_CLEAR_OREFLAG(&huart5);
 	}
 	else if(huart->Instance == USART6)
 	{
        __HAL_UART_CLEAR_OREFLAG(&huart6);
 	}     
 }

inline void MY_SYSCLK_Callback(void)
{

    // clock.cnt_100us++;
    clock.ms++;
    clock.cycle100ms++;
    clock.cycle1000ms++;
    clock.ms_startsample = clock.ms - START_SAMPLE_MS;


}
uint8_t buff[256] = {0};
int len = 0;
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if(GPIO_Pin == GPIO_PIN_4)
    {
        if( (GPIOC->IDR & (1 << 4) ) != 0 ) //如果此时PC3确实是高电平
        {

            if(pulse_count == 0)         
            {
                first_ms = clock.ms;
                first_us = TIM6->CNT;
            }
            pulse_count++;
            inc_sec_utc(&utc);
            genstr_utc(&utc, buff, &len);
            HAL_UART_Transmit(&huart3, buff, len, 0xFFFF);
            // HAL_UART_Transmit(&huart1, buff, len, 0xFFFF);
            // MY_UART_Transmit_DMA(&huart3, buff, len);
        }
    }
}

int main(void)
{    
    init_utc(&utc);

    HAL_Init();
    SystemClock_Config();

    LED_Core_Init();
    MX_GPIO_Init();
    MX_DMA_Init();
    MX_IWDG_Init();
    MX_USART1_UART_Init();  //核心板输出
    // MX_USART2_UART_Init();  //无线串口
    MX_USART3_UART_Init();
    // MX_UART5_Init();        //接收机
    // MX_USART6_UART_Init();  //上位机
    MX_TIM6_Init();
    // MX_TIM3_Init();
    // HAL_UART_Receive_DMA(&huart5, u5rxdata, UART_DMA_RX_SIZE);
    // HAL_UART_Receive_DMA(&huart6, u6rxdata, UART_DMA_RX_SIZE);
    
    while(1)
    {
				
        if (clock.ms == START_SAMPLE_MS)
        {
            if(flag_first_sample == 0)
            {
                GPIOA->BSRR |= 1 << 6;
                sample_us = TIM6->CNT;
                LED_Core_On();
                flag_first_sample = 1;
                printf("a");
            }
        }
        else if (clock.ms == START_SAMPLE_MS + START_SAMPLE_LEN)
        {
            GPIOA->BSRR |= 1 << 22;
        }

        if(clock.cycle100ms >= 100)
        {
            cycle_100ms_callback();
            clock.cycle100ms = 0;            
        }
    }
}



void MY_UART_Transmit_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
{
    if(__HAL_DMA_GET_FLAG(huart->hdmatx, DMA_FLAG_TCIF2_6) == RESET)
    {
        huart->hdmatx->Instance->CR &= (uint32_t)(~DMA_SxCR_DBM);
        huart->hdmatx->Instance->NDTR = Size;
        huart->hdmatx->Instance->M0AR = (uint32_t)pData;        
        huart->hdmatx->Instance->PAR = (uint32_t)(&huart->Instance->DR);        
        __HAL_DMA_ENABLE(huart->hdmatx);
        __HAL_UART_CLEAR_FLAG(huart, UART_FLAG_TC);

    }
    else
    {
        __HAL_DMA_CLEAR_FLAG(huart->hdmatx, DMA_FLAG_TCIF2_6);
        __HAL_DMA_DISABLE(huart->hdmatx);
    }
}


inline void cycle_100ms_callback(void)
{
    // LED_Core_Turn();
    HAL_IWDG_Refresh(&hiwdg);
    return;
}


