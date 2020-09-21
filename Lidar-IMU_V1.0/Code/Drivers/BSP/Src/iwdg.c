
#include "iwdg.h"

IWDG_HandleTypeDef hiwdg;

/* IWDG init function */
void MX_IWDG_Init(void)
{
    hiwdg.Instance = IWDG;
    hiwdg.Init.Prescaler = IWDG_PRESCALER_32;
    hiwdg.Init.Reload = 2000;
    if (HAL_IWDG_Init(&hiwdg) != HAL_OK)
    {
        Error_Handler(__FILE__, __LINE__);
    }
}
