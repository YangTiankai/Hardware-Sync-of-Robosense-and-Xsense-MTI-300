
#ifndef __usart_H
#define __usart_H
#ifdef __cplusplus
 extern "C" {
#endif

#include "bsp.h"

#define UART_PRINT_HANDLE huart1


extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart5;
extern UART_HandleTypeDef huart6;



void MX_USART1_UART_Init(void);
void MX_USART2_UART_Init(void);
void MX_USART3_UART_Init(void);
void MX_UART4_Init(void);
void MX_UART5_Init(void);
void MX_USART6_UART_Init(void);

void MY_UART_IRQHandler(UART_HandleTypeDef *huart);

#ifdef __cplusplus
}
#endif
#endif /*__ usart_H */

