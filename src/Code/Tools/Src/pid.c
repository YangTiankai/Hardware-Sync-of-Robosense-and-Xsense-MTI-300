
#include "pid.h"


void pidReset(P_PID_HANDLE phdl)
{
    phdl->sum_error     = 0;
    phdl->last_error    = 0;
}


float pidProcess(P_PID_HANDLE phdl, float input, float measure)
{
    float output = 0;
    float error = input - measure;         //计算误差

    phdl->sum_error += error;
    //误差积分限幅
    if(phdl->enable_lim_sum_error == 1 && fabs(phdl->sum_error) > phdl->lim_sum_error)
    {
        if(phdl->sum_error > 0)
            phdl->sum_error = phdl->lim_sum_error;
        else
            phdl->sum_error = -phdl->lim_sum_error;
    }

    output =        phdl->kp * error
                +   phdl->ki * phdl->sum_error
                +   phdl->kd * (error - phdl->last_error);

		
    //输出限幅
    if(phdl->enable_lim_output_up == 1 && output > phdl->lim_output_up)
    {
        output = phdl->lim_output_up;
    }
    if(phdl->enable_lim_output_dn == 1 && output < phdl->lim_output_dn)
    {
        output = phdl->lim_output_dn;
    }

    //更新误差值
    phdl->last_error = error;

    //是否使能输出
    if(phdl->enable == 1)
    {
        phdl->output = output;
        return output;
    }   
    else
        return 0;
}




