
#ifndef __tim_H
#define __tim_H
#ifdef __cplusplus
 extern "C" {
#endif

#include "bsp.h"


extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim6;

void MX_TIM3_Init(void);
void MX_TIM6_Init(void);

void MY_SYSCLK_Callback(void);

#ifdef __cplusplus
}
#endif
#endif /*__ tim_H */

