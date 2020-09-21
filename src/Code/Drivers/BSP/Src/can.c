
#include "can.h"


CAN_HandleTypeDef hcan1;
CAN_HandleTypeDef hcan2;

/* CAN1 init function */
void MX_CAN1_Init(void)
{

    hcan1.Instance = CAN1;
    hcan1.Init.Prescaler = 3;
    hcan1.Init.Mode = CAN_MODE_NORMAL;
    hcan1.Init.SyncJumpWidth = CAN_SJW_4TQ;
    hcan1.Init.TimeSeg1 = CAN_BS1_7TQ;
    hcan1.Init.TimeSeg2 = CAN_BS2_6TQ;
    hcan1.Init.TimeTriggeredMode = DISABLE;
    hcan1.Init.AutoBusOff = DISABLE;
    hcan1.Init.AutoWakeUp = DISABLE;
    hcan1.Init.AutoRetransmission = ENABLE;
    hcan1.Init.ReceiveFifoLocked = DISABLE;
    hcan1.Init.TransmitFifoPriority = DISABLE;
    if (HAL_CAN_Init(&hcan1) != HAL_OK)
    {
        Error_Handler(__FILE__, __LINE__);
    }

}
/* CAN2 init function */
void MX_CAN2_Init(void)
{

    hcan2.Instance = CAN2;
    hcan2.Init.Prescaler = 3;
    hcan2.Init.Mode = CAN_MODE_NORMAL;
    hcan2.Init.SyncJumpWidth = CAN_SJW_4TQ;
    hcan2.Init.TimeSeg1 = CAN_BS1_7TQ;
    hcan2.Init.TimeSeg2 = CAN_BS2_6TQ;
    hcan2.Init.TimeTriggeredMode = DISABLE;
    hcan2.Init.AutoBusOff = DISABLE;
    hcan2.Init.AutoWakeUp = DISABLE;
    hcan2.Init.AutoRetransmission = ENABLE;
    hcan2.Init.ReceiveFifoLocked = DISABLE;
    hcan2.Init.TransmitFifoPriority = DISABLE;
    if (HAL_CAN_Init(&hcan2) != HAL_OK)
    {
        Error_Handler(__FILE__, __LINE__);
    }

}

static uint32_t HAL_RCC_CAN1_CLK_ENABLED=0;

void HAL_CAN_MspInit(CAN_HandleTypeDef* canHandle)
{

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    if(canHandle->Instance==CAN1)
    {
        /* CAN1 clock enable */
        HAL_RCC_CAN1_CLK_ENABLED++;
        if(HAL_RCC_CAN1_CLK_ENABLED==1){
        __HAL_RCC_CAN1_CLK_ENABLE();
        }
    
        __HAL_RCC_GPIOB_CLK_ENABLE();
        /**CAN1 GPIO Configuration    
        PB8     ------> CAN1_RX
        PB9     ------> CAN1_TX 
        */
        GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF9_CAN1;
        HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

        /* CAN1 interrupt Init */
        HAL_NVIC_SetPriority(CAN1_RX0_IRQn, 0, 0);
        HAL_NVIC_EnableIRQ(CAN1_RX0_IRQn);
        HAL_NVIC_SetPriority(CAN1_RX1_IRQn, 0, 0);
        HAL_NVIC_EnableIRQ(CAN1_RX1_IRQn);
    }
    else if(canHandle->Instance==CAN2)
    {
        /* CAN2 clock enable */
        __HAL_RCC_CAN2_CLK_ENABLE();
        HAL_RCC_CAN1_CLK_ENABLED++;
        if(HAL_RCC_CAN1_CLK_ENABLED==1){
        __HAL_RCC_CAN1_CLK_ENABLE();
        }
    
        __HAL_RCC_GPIOB_CLK_ENABLE();
        /**CAN2 GPIO Configuration    
        PB12     ------> CAN2_RX
        PB13     ------> CAN2_TX 
        */
        GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF9_CAN2;
        HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

        /* CAN2 interrupt Init */
        HAL_NVIC_SetPriority(CAN2_RX0_IRQn, 0, 0);
        HAL_NVIC_EnableIRQ(CAN2_RX0_IRQn);
        HAL_NVIC_SetPriority(CAN2_RX1_IRQn, 0, 0);
        HAL_NVIC_EnableIRQ(CAN2_RX1_IRQn);
    }
}

void HAL_CAN_MspDeInit(CAN_HandleTypeDef* canHandle)
{

    if(canHandle->Instance==CAN1)
    {
        /* Peripheral clock disable */
        HAL_RCC_CAN1_CLK_ENABLED--;
        if(HAL_RCC_CAN1_CLK_ENABLED==0){
        __HAL_RCC_CAN1_CLK_DISABLE();
        }
    
        /**CAN1 GPIO Configuration    
        PB8     ------> CAN1_RX
        PB9     ------> CAN1_TX 
        */
        HAL_GPIO_DeInit(GPIOB, GPIO_PIN_8|GPIO_PIN_9);

        /* CAN1 interrupt Deinit */
        HAL_NVIC_DisableIRQ(CAN1_RX0_IRQn);
        HAL_NVIC_DisableIRQ(CAN1_RX1_IRQn);
    }
    else if(canHandle->Instance==CAN2)
    {
        /* Peripheral clock disable */
        __HAL_RCC_CAN2_CLK_DISABLE();
        HAL_RCC_CAN1_CLK_ENABLED--;
        if(HAL_RCC_CAN1_CLK_ENABLED==0){
        __HAL_RCC_CAN1_CLK_DISABLE();
        }
    
        /**CAN2 GPIO Configuration    
        PB12     ------> CAN2_RX
        PB13     ------> CAN2_TX 
        */
        HAL_GPIO_DeInit(GPIOB, GPIO_PIN_12|GPIO_PIN_13);

        /* CAN2 interrupt Deinit */
        HAL_NVIC_DisableIRQ(CAN2_RX0_IRQn);
        HAL_NVIC_DisableIRQ(CAN2_RX1_IRQn);
    }
} 


void CAN_FilterInit(CAN_TypeDef *CANx, FilterUnit unit[], uint16_t num)
{
    CAN_FilterTypeDef FilterConfig = {0};

    if(num > 14)
    {
        num = 14;
    }

    if(num == 0)    //所有ID均压入FIFO0
    {
        FilterConfig.SlaveStartFilterBank   = 14;                       //过滤器组：CAN1 0-13，CAN2 14-27
        FilterConfig.FilterBank             = CANx == CAN1 ? 0 : 14;    //CAN1用过滤器组0，CAN2用过滤器组14
        FilterConfig.FilterMode             = CAN_FILTERMODE_IDMASK;    //掩码模式
        FilterConfig.FilterScale            = CAN_FILTERSCALE_32BIT;    //32位模式

        FilterConfig.FilterIdHigh           = 0x0000;
        FilterConfig.FilterIdLow            = 0x0000;
        FilterConfig.FilterMaskIdHigh       = 0x0000;
        FilterConfig.FilterMaskIdLow        = 0x0000;
        FilterConfig.FilterFIFOAssignment   = CAN_RX_FIFO0;             //数据压入FIFO0
        FilterConfig.FilterActivation       = ENABLE;                   //过滤器使能

        HAL_CAN_ConfigFilter(&hcan1, &FilterConfig);
    }
    else
    {
        uint16_t i = 0;

        for(i = 0; i <= num - 1; i++)
        {
            FilterConfig.SlaveStartFilterBank   = 14;                     
            FilterConfig.FilterBank             = CANx == CAN1 ? i : i + 14;
            FilterConfig.FilterFIFOAssignment   = unit[i].FilterFIFO;
            FilterConfig.FilterActivation       = ENABLE;                   //过滤器使能

            switch (unit[i].mode)
            {
                case MODE_MASK32:
                    FilterConfig.FilterMode     = CAN_FILTERMODE_IDMASK;
                    FilterConfig.FilterScale    = CAN_FILTERSCALE_32BIT;
                    break;
                case MODE_LIST32:
                    FilterConfig.FilterMode     = CAN_FILTERMODE_IDLIST;
                    FilterConfig.FilterScale    = CAN_FILTERSCALE_32BIT;
                    break;
                case MODE_MASK16:
                    FilterConfig.FilterMode     = CAN_FILTERMODE_IDMASK;
                    FilterConfig.FilterScale    = CAN_FILTERSCALE_16BIT; 
                    break;
                case MODE_LIST16:
                    FilterConfig.FilterMode     = CAN_FILTERMODE_IDLIST;
                    FilterConfig.FilterScale    = CAN_FILTERSCALE_16BIT;
                break;
            
            }

            FilterConfig.FilterIdLow        = unit[i].reg.hal.FilterIdLow;
            FilterConfig.FilterIdHigh       = unit[i].reg.hal.FilterIdHigh;
            FilterConfig.FilterMaskIdLow    = unit[i].reg.hal.FilterMaskIdLow;
            FilterConfig.FilterMaskIdHigh   = unit[i].reg.hal.FilterMaskIdHigh;

            HAL_CAN_ConfigFilter(&hcan1, &FilterConfig);    //这里没写错，就是hcan1
        }
    }
}
