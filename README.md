# Hardware-Sync-of-Robosense-and-Xsense-MTI-300
Robosense雷达和Xsense MTI-300的硬件时间同步方案

本项目主要工作是进行了Robosense雷达和Xsense MTI-300的硬件时间同步

系统工作流程如下：
1. 使用MTI-300的SyncIn引脚的StartSample功能，在上电后3秒后，向MTI-300的SyncIn引脚输入一个上升沿脉冲，此时MTI-300将向外输出数据
2. 使用MTI-300的SyncOut引脚的脉冲输出功能，将其配置为能够输出频率1Hz，脉宽200ms的矩形波
3. 将MTI-300的SyncOut引脚接入Robosense雷达的GPS接口的PPS引脚上
4. 将MTI-300的SyncOut引脚接入stm32单片机，每检测到一个上升沿脉冲，向Robosense雷达的GPS接口的串口接收RXD引脚发送一个串口包，该串口包是模拟GPS设备的GPRMC规范








