#include "ANO.h"



//输入若干int16_t类型的数据，输出适用于匿名四轴上位机的反馈包   
void ANOPrintS16
(
    uint8_t     fun,            //1-10，对应0xA1到0xAA的功能码
    int16_t     data[],         //数据首地址
    uint8_t     data_len,       //数据长度，最大为30
    uint8_t     *print_buff,    //输出数据首地址
    uint16_t    *print_len      //输出数据长度地址
)
{
    if(data_len >= 1 && data_len <= 30)
    {
        int i;

        print_buff[0] = 0x88;
        print_buff[1] = 0xa0 + fun;
        print_buff[2] = 2 * data_len;

        for(i = 0; i <= data_len - 1; i++)
        {
            print_buff[3 + 2 * i + 0] = ((uint8_t*)(&data[i]))[1];
            print_buff[3 + 2 * i + 1] = ((uint8_t*)(&data[i]))[0];
        }
        print_buff[3 + 2 * data_len] = 0;

        for(i = 0; i <= 3 + 2 * data_len - 1; i++)
        {
            print_buff[3 + 2 * data_len] += print_buff[i];
        }

        *print_len = 3 + 2 * data_len + 1;
    }
    else
    {
        *print_len = 0;
    }
    
}


//输入若干float类型的数据，输出适用于匿名四轴上位机的反馈包   
void ANOPrintFloat
(
    uint8_t     fun,            //1-10，对应0xA1到0xAA的功能码
    float       data[],         //数据首地址
    uint8_t     data_len,       //数据长度，最大为30
    uint8_t     *print_buff,    //输出数据首地址
    uint16_t    *print_len      //输出数据长度地址
)
{
    if(data_len >= 1 && data_len <= 30)
    {
        int i;

        print_buff[0] = 0x88;
        print_buff[1] = 0xa0 + fun;
        print_buff[2] = 4 * data_len;

        for(i = 0; i <= data_len - 1; i++)
        {
            print_buff[3 + 4 * i + 0] = ((uint8_t*)(&data[i]))[3];
            print_buff[3 + 4 * i + 1] = ((uint8_t*)(&data[i]))[2];
            print_buff[3 + 4 * i + 2] = ((uint8_t*)(&data[i]))[1];
            print_buff[3 + 4 * i + 3] = ((uint8_t*)(&data[i]))[0];
        }

        print_buff[3 + 4 * data_len] = 0;

        for(i = 0; i <= 3 + 4 * data_len - 1; i++)
        {
            print_buff[3 + 4 * data_len] += print_buff[i];
        }

        *print_len = 3 + 4 * data_len + 1;
    }
    else
    {
        *print_len = 0;
    }
    
}

//输入加速度、角速度、磁场、欧拉角，输出适用于匿名四轴上位机的反馈包
void ANOPrintRPY
(
    vector3_s16_t   *pacc,          //加速度矢量指针
    vector3_s16_t   *pgyro,         //角速度矢量指针
    vector3_s16_t   *pmag,          //磁场矢量指针
    vector3_f32_t   *prpy,          //欧拉角矢量指针
    uint8_t         *print_buff,    //输出数据首地址
    uint16_t        *print_len      //输出数据长度地址
)
{
    int16_t data[14] = {0};

    if(pacc != 0)
    {
        data[0]     = pacc->x;
        data[1]     = pacc->y;
        data[2]     = pacc->z;   
    }
    if(pgyro != 0)
    {
        data[3]     = pgyro->x;
        data[4]     = pgyro->y;
        data[5]     = pgyro->z;   
    }
    if(pmag != 0)
    {
        data[6]     = pmag->x;
        data[7]     = pmag->y;
        data[8]     = pmag->z;   
    }
    if(prpy != 0)
    {
        data[9]     = (int16_t)(prpy->x * 100);
        data[10]    = (int16_t)(prpy->y * 100);
        data[11]    = (int16_t)(prpy->z * 10); 
    }
    data[12] = 0;
    data[13] = 0;
    
    ANOPrintS16(0x0f, data, 14, print_buff, print_len);
}



