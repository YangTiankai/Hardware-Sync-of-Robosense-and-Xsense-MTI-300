
#ifndef __gpio_H
#define __gpio_H
#ifdef __cplusplus
 extern "C" {
#endif

#include "bsp.h"

#define WIFI_MD0_Pin            GPIO_PIN_5
#define WIFI_MD0_GPIO_Port      GPIOA

#define WIFI_MD1_Pin            GPIO_PIN_4
#define WIFI_MD1_GPIO_Port      GPIOA


void MX_GPIO_Init(void);


#ifdef __cplusplus
}
#endif
#endif /*__ pinoutConfig_H */
