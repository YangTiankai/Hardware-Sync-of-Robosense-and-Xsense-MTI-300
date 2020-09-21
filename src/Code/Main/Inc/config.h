
#ifndef __CONFIG_H
#define __CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif



#define TIM3_CH2_PA7_Prescaler (8400 - 1) //84MHZ分频为10kHz，周期0.1ms
#define TIM3_CH2_PA7_Period (10000 - 1) //自动重装载值，周期5000ms
#define TIM3_CH2_PA7_Pulse (5000) //高电平时间200ms

#define START_SAMPLE_MS (3000)
#define START_SAMPLE_LEN (100)

#define LIDAR_UTC_START_SEC (5)
#define LIDAR_UTC_OFFSET_SEC (LIDAR_UTC_START_SEC + 1)
#define LIDAR_UTC_PULSE_MS (100)    //必须是100的倍数

#ifdef __cplusplus
}
#endif

#endif


