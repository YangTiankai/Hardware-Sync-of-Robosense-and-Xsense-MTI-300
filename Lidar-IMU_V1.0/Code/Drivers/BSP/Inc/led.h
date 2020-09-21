
#ifndef __led_H
#define __led_H
#ifdef __cplusplus
 extern "C" {
#endif

#include "bsp.h"


#define LED_CORE_GPIO_Port  GPIOB
#define LED_CORE_Pin        (GPIO_PIN_2 | GPIO_PIN_7)

void LED_Core_Init(void);
void LED_Core_On(void);
void LED_Core_Off(void);
void LED_Core_Turn(void);



#ifdef __cplusplus
}
#endif
#endif /*__ led _H */
