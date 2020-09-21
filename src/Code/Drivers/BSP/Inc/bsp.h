
#ifndef __BSP_H
#define __BSP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"

#include "config.h"

#include "clk.h"
#include "led.h"

#include "can.h"
#include "dma.h"
#include "iwdg.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

#include "stdio.h"
#include "typedef.h"
#include "arm_math.h"

void Error_Handler(char * file, int line);



#ifdef __cplusplus
}
#endif

#endif /* __BSP_H */

