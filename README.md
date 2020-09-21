# Hardware-Sync-of-Robosense-and-Xsense-MTI-300
Robosense雷达和Xsense MTI-300的硬件时间同步方案

本项目主要工作是进行了Robosense雷达和Xsense MTI-300的硬件时间同步

首先明确，需要进行硬件同步的原因是：各个传感器的时间坐标不一致且流速有差异（主要是晶振误差带来的）
因此硬件同步的任务是
1. 使得各个传感器的时间坐标的流速一致
2. 得出各个传感器的时间坐标的差

准备工作：
1. MTI-300的硬件接口和时间同步方法

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

2. Robosense激光雷达的时间同步接口
![Robosense GPS同步接口](https://github.com/YangTiankai/Hardware-Sync-of-Robosense-and-Xsense-MTI-300/blob/master/readmefile/LidarGPS.PNG)
该接口是用于将GPS收到的UTC时间同步为雷达内部的时间
PPS引脚检测的是一个1Hz的方波，每当上升沿到来后，应当向Robosense雷达GPS接口的串口接收RXD引脚发送一个串口包，该串口包是模拟GPS设备的GPRMC规范
![GPS设备的GPRMC规范](https://github.com/YangTiankai/Hardware-Sync-of-Robosense-and-Xsense-MTI-300/blob/master/readmefile/GPRMC.PNG)


系统工作流程如下：
1. MTI-300的时钟输出
MTI-300的硬件时间同步方法在官网有说明

https://base.xsens.com/hc/en-us/articles/211592185

在上位机配置SyncIn引脚为StartSample功能，在上电后3秒后，使用stm32的PA6引脚向MTI-300的SyncIn引脚输入一个上升沿脉冲，此时MTI-300将向外输出数据
在上位机配置MTI-300的SyncOut引脚为脉冲输出功能，将其配置为能够输出频率1Hz，脉宽200ms的矩形波

3. 将MTI-300的SyncOut引脚接到Robosense雷达的GPS接口的PPS引脚上

4. 将MTI-300的SyncOut引脚接入stm32单片机的PC4引脚，








