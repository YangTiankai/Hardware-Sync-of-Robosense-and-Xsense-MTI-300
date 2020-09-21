
#ifndef __ANO_H
#define __ANO_H

#ifdef __cplusplus
extern "C" {
#endif


#include "tools.h"


//输入若干int16_t类型的数据，输出适用于匿名四轴上位机的反馈包   
void ANOPrintS16
(
    uint8_t         fun,            //1-10，对应0xA1到0xAA的功能码
    int16_t         data[],         //数据首地址
    uint8_t         data_len,       //数据长度，最大为30
    uint8_t         *print_buff,    //输出数据首地址
    uint16_t        *print_len      //输出数据长度地址
);


//输入若干float类型的数据，输出适用于匿名四轴上位机的反馈包   
void ANOPrintFloat
(
    uint8_t     fun,            //1-10，对应0xA1到0xAA的功能码
    float       data[],         //数据首地址
    uint8_t     data_len,       //数据长度，最大为30
    uint8_t     *print_buff,    //输出数据首地址
    uint16_t    *print_len      //输出数据长度地址
);


//输入加速度、角速度、磁场、欧拉角，输出适用于匿名四轴上位机的反馈包
void ANOPrintRPY
(
    vector3_s16_t   *pacc,          //加速度矢量指针
    vector3_s16_t   *pgyro,         //角速度矢量指针
    vector3_s16_t   *pmag,          //磁场矢量指针
    vector3_f32_t 	*prpy,          //欧拉角矢量指针
    uint8_t         *print_buff,    //输出数据首地址
    uint16_t        *print_len      //输出数据长度地址
);




#ifdef __cplusplus
}
#endif

#endif


