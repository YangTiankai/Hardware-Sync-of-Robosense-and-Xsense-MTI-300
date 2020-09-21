
#ifndef __TYPEDEF_H
#define __TYPEDEF_H

#ifdef __cplusplus
extern "C" {
#endif

#include "bsp.h"

#define PI  3.141592654f     //π值
#define G   9.7944f          //重力加速度


typedef struct 
{
    float x;
    float y;
    float z;
} vector3_f32_t;

typedef struct 
{
    int16_t x;
    int16_t y;
    int16_t z;
} vector3_s16_t;




#ifdef __cplusplus
}
#endif

#endif


