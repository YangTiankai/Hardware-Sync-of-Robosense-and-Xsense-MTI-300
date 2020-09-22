# Hardware-Sync-of-Robosense-and-Xsense-MTI-300
  Robosense雷达和Xsense MTI-300的硬件时间同步方案

  本项目主要工作是进行了Robosense雷达和Xsense MTI-300的硬件时间同步

  首先明确，需要进行硬件同步的原因是：各个传感器的时间坐标不一致且流速有差异（主要是晶振误差带来的）
  因此硬件同步的任务是
  1. 使得各个传感器的时间坐标的流速一致
  2. 得出各个传感器的时间坐标的差

  我们的工作是将IMU和Lidar的时间轴都向IMU对齐

## 传感器的硬件同步方法
### MTI-300的硬件接口和时间同步方法

  MTI-300的接口如下图，其中GND、USB-DP、USB-DM、Vin应当转为USB2.0接口接入电脑，RS232两个引脚不使用，ClockSync、SyncOut、SyncIn为硬件时间同步引脚
  ![MTI-300接口线序](https://github.com/YangTiankai/Hardware-Sync-of-Robosense-and-Xsense-MTI-300/blob/master/readmefile/MTI-300.PNG)

  MTI-300官网上的硬件时间同步方法，我们只需要使用其中的部分功能  
  https://base.xsens.com/hc/en-us/sections/201296842-Algorithms-Data

  MTI-300的StartSample功能的官网说明如下
  https://base.xsens.com/hc/en-us/articles/208595729-ClockSync-and-StartSampling

  当在上位机中将SyncIn配置为StartSample功能后，MTI-300上电后不会输出数据，直到在SyncIn上检测到一个上升沿
  我们的项目只需要加速度和角速度数据，根据文档和我们实际实验测试，StartSample后大约3ms后会有第一个数据包

  MTI-300的SyncOut功能的官网说明如下，可以将其配置为特定频率的脉冲输出
  https://base.xsens.com/hc/en-us/articles/211592185-Synchronization-with-the-MTi

### Robosense激光雷达的时间同步接口
![Robosense GPS同步接口](https://github.com/YangTiankai/Hardware-Sync-of-Robosense-and-Xsense-MTI-300/blob/master/readmefile/LidarGPS.PNG)

  该接口是用于将GPS收到的UTC时间同步为雷达内部的时间
  PPS引脚检测的是一个1Hz的方波，每当上升沿到来后，应当向Robosense雷达GPS接口的串口接收RXD引脚发送一个串口包，该串口包是模拟GPS设备的GPRMC规范

![GPS设备的GPRMC规范](https://github.com/YangTiankai/Hardware-Sync-of-Robosense-and-Xsense-MTI-300/blob/master/readmefile/GPRMC.PNG)

## 系统构成
![PCB原理图](https://github.com/YangTiankai/Hardware-Sync-of-Robosense-and-Xsense-MTI-300/blob/master/readmefile/PCB.PNG)

  将MTI-300的USB信号转为标准USB接口接入PC
  将MTI300的SyncIn引脚接入stm32的PA引脚
  将MTI-300的SyncOut引脚接入stm32单片机的PC4引脚和雷达GPS接口的PPS引脚
  将stm32的串口发送引脚PB10/USART3_TX接到雷达GPS接口的串口接收引脚TXD

## 上位机配置
  在上位机配置SyncIn引脚为StartSample功能
  在上位机配置MTI-300的SyncOut引脚为脉冲输出功能，将其配置为能够输出频率1Hz，脉宽200ms的矩形波

## 运行时流程
  上电后3秒，stm32向SyncIn发出一个StartSapmle脉冲
  将PC引脚配置为上升沿触发的外部中断，当上升沿到来时，将UTC时间通过串口发出，每次自加1秒，第一个数据的时间约定为2020年1月1日0分0秒

## 计算硬件时间差
  经过上述的过程，我们已经将雷达的硬件时间流速同步为和IMU一致，现在我们需要推算两者硬件时间戳的差

  记stm32的时间轴为t_32，雷达的时间轴为t_li，IMU的时间轴为t_imu

  当stm32发出第一个脉冲时，设此时
  t_32 = T0
  t_imu = T1

  SyncOut上出现第一个上升沿时，设此时
  t_32 = T2
  t_li = T3

  可得
  t_li - t_32 = T3 - T2
  t_imu - t_32 = T1 - T0

  可得
  t_li - t_imu = T3 - T1 - (T2 - T0)

  T3为约定量，为2020年1月1日0分0秒，直接在Lidar回传的时间戳扣除即可
  T1的测量方法为，当PC收到第一个IMU数据包时，将其减去2.69ms即为T1
  根据实验和手册，(T2 - T0)为1000.19ms




