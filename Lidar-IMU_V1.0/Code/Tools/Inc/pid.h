
#ifndef __PID_H
#define __PID_H

#include "tools.h"


typedef struct
{
    uint32_t enable 					: 1;	//输出使能
    uint32_t enable_lim_sum_error	    : 1;	//积分限幅使能
    uint32_t enable_lim_output_up		: 1;	//输出上限幅使能
    uint32_t enable_lim_output_dn		: 1;	//输出下限幅使能

    float kp;  			//比例参数
    float ki;  			//积分参数
    float kd;  			//微分参数

    float lim_sum_error;    //积分限幅	
    float lim_output_up;    //输出上限幅
    float lim_output_dn;    //输出下限幅

    float sum_error;		//误差积分
    float last_error;		//上一次的误差
    float output;		
} PID_HANDLE, *P_PID_HANDLE;

void pidReset(P_PID_HANDLE phdl);
float pidProcess(P_PID_HANDLE phdl, float input, float measure);



#endif
