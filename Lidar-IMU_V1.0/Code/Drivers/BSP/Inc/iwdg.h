#ifndef __iwdg_H
#define __iwdg_H
#ifdef __cplusplus
extern "C" {
#endif

#include "bsp.h"


extern IWDG_HandleTypeDef hiwdg;

void MX_IWDG_Init(void);


#ifdef __cplusplus
}
#endif
#endif /*__ iwdg_H */

