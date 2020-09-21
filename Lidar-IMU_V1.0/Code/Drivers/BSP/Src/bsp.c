
#include "bsp.h"



void Error_Handler(char * file, int line)
{
    while(1) 
    {
        printf("Wrong parameters value: file %s on line %d\r\n", file, line);
    }
}

#ifdef  USE_FULL_ASSERT
/**
    * @brief  Reports the name of the source file and the source line number
    *         where the assert_param error has occurred.
    * @param  file: pointer to the source file name
    * @param  line: assert_param error line source number
    * @retval None
    */
void assert_failed(uint8_t *file, uint32_t line)
{ 
    while(1)
    {
        printf("Wrong parameters value: file %s on line %d\r\n", file, line);
    }
}
#endif /* USE_FULL_ASSERT */

