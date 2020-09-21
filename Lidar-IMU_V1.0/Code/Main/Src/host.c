#include "main.h"



void table_write(uint16_t offset, uint16_t len, uint8_t wr[], P_MODBUS_TABLE ptable)
{
    uint8_t *arr = (uint8_t*)ptable;
    int i;
    
    if(len >= 1 && offset + len <= TABLE_LEN)
    {
        for(i = 0; i <= len - 1; i++)
        {
            arr[offset + i] = wr[i];
        }
    }
}

int8_t modbus_pack_analize(uint8_t rxdata[], uint32_t rxlen, P_MODBUS_MSG pmsg)
{
    int i;
    uint8_t sum = 0;

    //包头错误
    if((rxdata[0] != 0xAA) || (rxdata[1] != 0xAA) || (rxdata[2] != 0xAA) || (rxdata[3] != 0xAA))
    {
        pmsg->count_error++;
        return -1;
    }
    
    //命令类型错误
    if(rxdata[4] != MODBUS_WRITE && rxdata[4] != MODBUS_READ && rxdata[4] != MODBUS_FEEDBACK)
    {
        pmsg->count_error++;
        return -2;
    }

    //数据长度越界
    if(rxdata[5] + rxdata[6] > TABLE_LEN)
    {
        pmsg->count_error++;
        return -3;
    }

    //数据长度与数据包长度存在矛盾
    if((rxdata[6] + 8) != rxlen)
    {
        pmsg->count_error++;
        return -4;
    }

    sum = 0;
    for(i = 0; i <= rxlen - 2; i++)
    {
        sum ^= rxdata[i];
    }

    //校验错误
    if(sum != rxdata[rxlen - 1])
    {
        pmsg->count_error++;
        return -5;
    }

    pmsg->order = rxdata[4];
    pmsg->offset= rxdata[5];
    pmsg->len= rxdata[6];
    for(i = 0; i <= pmsg->len - 1; i++)
    {
        pmsg->data[i] = rxdata[i + 7];
    }

    pmsg->count_correct++;
    return 0;
}

void modbus_feedback(P_MODBUS_TABLE ptable, uint8_t offset, uint8_t len, uint8_t buff[], uint32_t *bufflen)
{
    uint8_t *table = (uint8_t*)ptable;
		int i;
    if(len >= 1 && offset + len <= TABLE_LEN)
    {
        //生成的数据包总长度
        *bufflen = 8 + len;

        //数据头
        buff[0] = 0xaa;
        buff[1] = 0xaa;
        buff[2] = 0xaa;
        buff[3] = 0xaa;

        //数据类型
        buff[4] = MODBUS_FEEDBACK;

        //数据长度
        buff[5] = offset;

        //数据长度
        buff[6] = len;

        //数据区
        for(i = 0; i <= len - 1; i++)
        {
            buff[i + 7] = table[offset + i];
        }


        //按位异或校验
        buff[7 + len] = 0;
        for(i = 0; i <= 7 + len - 1; i++)
        {
            buff[7 + len] ^= buff[i];
        }
    }
}


// void modbus_write(uint8_t offset, uint8_t len, uint8_t data[], uint8_t buff[], uint32_t *bufflen)
// {
//     if(len >= 1 && address + len <= TABLE_LEN)
//     {
//         //生成的数据包总长度
//         *bufflen = 7 + len;

//         //数据头
//         buff[0] = 0xff;
//         buff[1] = 0xff;
//         buff[2] = 0xff;
//         buff[3] = 0xff;

//         //数据类型
//         buff[4] = MODBUS_WRITE;

//         //数据长度
//         buff[5] = len;

//         //数据区
//         for(i = 0; i <= len - 1; i++)
//         {
//             buff[i + 6] = buff[i];
//         }

//         //按位异或校验
//         buff[6 + len] = buff[0];
//         for(i = 1; i <= 6 + len - 1; i++)
//         {
//             buff[6 + len] ^= buff[i];
//         }
//     }
// }


