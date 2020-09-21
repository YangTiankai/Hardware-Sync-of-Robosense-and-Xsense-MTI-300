#include "utc.h"
#include "string.h"
#include "stdio.h"



void inc_sec_utc(PUTC putc)
{
    putc->sec++;
    while(putc->sec >= 60)
    {
        putc->sec -= 60;
        putc->min++;
    }
    while(putc->min >= 60)
    {
        putc->min -= 60;
        putc->hour++;
    }
    while(putc->hour >= 24)
    {
        putc->hour -= 24;
        putc->day++;
    }
}

void init_utc(PUTC putc)
{
    putc->year = 20;
    putc->month = 1;
    putc->day = 1;
    putc->hour = 0;
    putc->min = 0;
    putc->sec = 0;
}


void genstr_utc(PUTC putc, uint8_t str[], int *plen)
{
    int cnt = 0;
    int i = 0;
    uint8_t check_sum = 0;
    char check_str[16] = {0};

    str[cnt++] = '$';
    str[cnt++] = 'G';
    str[cnt++] = 'P';
    str[cnt++] = 'R';
    str[cnt++] = 'M';
    str[cnt++] = 'C';
    str[cnt++] = ',';

    str[cnt++] = (putc->hour / 10) + '0';
    str[cnt++] = (putc->hour % 10) + '0';
    str[cnt++] = (putc->min / 10) + '0';
    str[cnt++] = (putc->min % 10) + '0';
    str[cnt++] = (putc->sec / 10) + '0';
    str[cnt++] = (putc->sec % 10) + '0';
    str[cnt++] = '.';
    str[cnt++] = '0';
    str[cnt++] = '0';
    str[cnt++] = '0';
    str[cnt++] = ',';

    str[cnt++] = 'A';
    str[cnt++] = ',';

    str[cnt++] = '3';
    str[cnt++] = '0';
    str[cnt++] = '3';
    str[cnt++] = '7';
    str[cnt++] = '.';
    str[cnt++] = '3';
    str[cnt++] = '8';
    str[cnt++] = '9';
    str[cnt++] = '0';
    str[cnt++] = ',';
    
    str[cnt++] = 'N';
    str[cnt++] = ',';

    str[cnt++] = '1';
    str[cnt++] = '0';
    str[cnt++] = '4';
    str[cnt++] = '0';
    str[cnt++] = '2';
    str[cnt++] = '.';
    str[cnt++] = '3';
    str[cnt++] = '5';
    str[cnt++] = '1';
    str[cnt++] = '0';
    str[cnt++] = ',';

    str[cnt++] = 'E';
    str[cnt++] = ',';  

    str[cnt++] = '0';
    str[cnt++] = '.';
    str[cnt++] = '3';
    str[cnt++] = '2';
    str[cnt++] = ',';  

    str[cnt++] = '1';
    str[cnt++] = '6';
    str[cnt++] = '3';
    str[cnt++] = '.';
    str[cnt++] = '2';
    str[cnt++] = '4';
    str[cnt++] = ',';  

    str[cnt++] = (putc->day / 10) + '0';
    str[cnt++] = (putc->day % 10) + '0';
    str[cnt++] = (putc->month / 10) + '0';
    str[cnt++] = (putc->month % 10) + '0';
    str[cnt++] = (putc->year / 10) + '0';
    str[cnt++] = (putc->year % 10) + '0';
    str[cnt++] = ',';


    str[cnt++] = ',';  
    str[cnt++] = ',';

    str[cnt++] = 'A';
    str[cnt++] = '*';

    str[cnt] = 0;

    for(i = 1; i <= cnt - 2; i++)
    {
        check_sum = check_sum ^ str[i];
    }

    sprintf(check_str, "%X", check_sum);
    strcat(str, check_str);
    cnt = strlen(str);

    str[cnt++] = 0X0D;
    str[cnt++] = 0X0A;
    str[cnt] = 0;
    *plen = cnt;

}
