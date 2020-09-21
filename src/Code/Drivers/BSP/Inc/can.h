
#ifndef __can_H
#define __can_H
#ifdef __cplusplus
 extern "C" {
#endif

#include "bsp.h"




//初始的筛选器结构
typedef struct
{
    uint16_t FilterIdLow;
    uint16_t FilterIdHigh;
    uint16_t FilterMaskIdLow;
    uint16_t FilterMaskIdHigh;
} FilterReg_Hal;

//掩码模式 32位
typedef struct
{
    uint32_t                : 1 ;   // FilterIdLow FilterIdHigh 对应FR1
    uint32_t    RTR         : 1 ;
    uint32_t    IDE         : 1 ;
    uint32_t    ExtID       : 18;
    uint32_t    StdID       : 11;

    uint32_t                : 1 ;   // FilterMaskIdLow FilterMaskIdHigh 对应FR2
    uint32_t    RTR_Mask    : 1 ;
    uint32_t    IDE_Mask    : 1 ;
    uint32_t    ExtID_Mask  : 18;
    uint32_t    StdID_Mask  : 11;
} FilterReg_Mask_32Bit;

//列表模式 32位
typedef struct
{
    uint32_t                : 1 ;   // FilterIdLow FilterIdHigh 对应FR1
    uint32_t    RTR1        : 1 ;
    uint32_t    IDE1        : 1 ;
    uint32_t    ExtID1      : 18;
    uint32_t    StdID1      : 11;

    uint32_t                : 1 ;   // FilterMaskIdLow FilterMaskIdHigh 对应FR2
    uint32_t    RTR2        : 1 ;
    uint32_t    IDE2        : 1 ;
    uint32_t    ExtID2      : 18;
    uint32_t    StdID2      : 11;
} FilterReg_List_32Bit;


//掩码模式 16位
typedef struct
{
    uint16_t                : 3 ;   // FilterIdLow 对应FR1低16位
    uint16_t    IDE1        : 1 ;
    uint16_t    RTR1        : 1 ;
    uint16_t    StdID1      : 11;

    uint16_t                : 3 ;   // FilterIdHigh 对应FR2低16位   
    uint16_t    IDE2        : 1 ;
    uint16_t    RTR2        : 1 ;
    uint16_t    StdID2      : 11;

    uint16_t                : 3 ;   // FilterMaskIdLow 对应FR1高16位
    uint16_t    IDE1_Mask   : 1 ;
    uint16_t    RTR1_Mask   : 1 ;
    uint16_t    StdID1_Mask : 11;

    uint16_t                : 3 ;   //FilterMaskIdHigh  对应FR2高16位 
    uint16_t    IDE2_Mask   : 1 ;
    uint16_t    RTR2_Mask   : 1 ;
    uint16_t    StdID2_Mask : 11;
} FilterReg_Mask_16Bit;

//列表模式 16位
typedef struct
{
    uint16_t                : 3 ;   // FilterIdLow 对应FR1低16位    
    uint16_t    IDE1        : 1 ;
    uint16_t    RTR1        : 1 ;
    uint16_t    StdID1      : 11;

    uint16_t                : 3 ;   // FilterIdHigh 对应FR2低16位    
    uint16_t    IDE2        : 1 ;
    uint16_t    RTR2        : 1 ;
    uint16_t    StdID2      : 11;

    uint16_t                : 3 ;   // FilterMaskIdLow 对应FR1高16位  
    uint16_t    IDE3        : 1 ;
    uint16_t    RTR3        : 1 ;
    uint16_t    StdID3      : 11;

    uint16_t                : 3 ;   //FilterMaskIdHigh  对应FR2高16位   
    uint16_t    IDE4        : 1 ;
    uint16_t    RTR4        : 1 ;
    uint16_t    StdID4      : 11;
} FilterReg_List_16Bit;

typedef union
{
    FilterReg_Hal          hal;     //HAL的参数
    FilterReg_Mask_32Bit   mask32;  //32位掩码模式
    FilterReg_List_32Bit   list32;  //16位列表模式
    FilterReg_Mask_16Bit   mask16;  //32位掩码模式
    FilterReg_List_16Bit   list16;  //16位列表模式
} FilterReg;

typedef enum
{
    MODE_MASK32,
    MODE_LIST32,
    MODE_MASK16,
    MODE_LIST16
} FilterMode;

typedef struct
{
    FilterReg reg;
    FilterMode mode;
    uint32_t FilterFIFO;        //CAN_RX_FIFO0 / CAN_RX_FIFO1
} FilterUnit, *pFilterUnit;


extern CAN_HandleTypeDef hcan1;
extern CAN_HandleTypeDef hcan2;

void MX_CAN1_Init(void);
void MX_CAN2_Init(void);

void CAN_FilterInit(CAN_TypeDef *CANx, FilterUnit unit[], uint16_t num);

#ifdef __cplusplus
}
#endif
#endif /*__ can_H */

