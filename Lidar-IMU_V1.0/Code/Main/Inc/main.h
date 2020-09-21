#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "config.h"
#include "bsp.h"
#include "device.h"
#include "tools.h"
#include "host.h"
#include "control.h"

// #define ROCKER_RANGE                (660.0f)     //摇杆范围为-660 ~ +660
// #define MANUAL_MAX_SPEED_PULSE      10000   //手动速度模式下的编码器最快转速，单位为5ms内的脉冲数

#define UART_DMA_RX_SIZE    (128)

typedef struct
{
    // int64_t cnt_100us;
    int64_t ms;
    int64_t sec;
    int64_t ms_startsample;
    int64_t cycle100ms;
    int64_t cycle1000ms;
} CLOCK;



extern CLOCK clock;


void cycle_100ms_callback(void);
void cycle_1000ms_callback(void);
void MY_UART_Transmit_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */


