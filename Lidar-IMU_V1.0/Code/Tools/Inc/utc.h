
    
#ifndef __UTC_H
#define __UTC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "tools.h"

typedef struct
{
    int32_t year;
    int32_t month;
    int32_t day;
    int32_t hour;
    int32_t min;
    int32_t sec;
} UTC, *PUTC;


void init_utc(PUTC putc);
void inc_sec_utc(PUTC putc);
void genstr_utc(PUTC putc, uint8_t str[], int *plen);


#ifdef __cplusplus
}
#endif

#endif


