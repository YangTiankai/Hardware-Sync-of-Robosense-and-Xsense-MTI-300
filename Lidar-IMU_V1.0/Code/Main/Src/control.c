#include "control.h"

void pid_init(P_PID_HANDLE pid)
{
    pidReset(pid);

    pid->enable = 1;
    pid->enable_lim_sum_error = 1;
    pid->enable_lim_output_up = 1;
    pid->enable_lim_output_dn = 1;
    
    pid->kp = 30;
    pid->ki = 4;
    pid->kd = 0;

    pid->lim_sum_error = 1000;
    pid->lim_output_up = 8000;
    pid->lim_output_dn = -8000;
}

