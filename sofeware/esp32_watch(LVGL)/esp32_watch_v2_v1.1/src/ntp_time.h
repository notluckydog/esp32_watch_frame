

#ifndef _NTP_TIME_H_
#define _NTP_TIME_H_

#include <Arduino.h>


// const char *ntpServer = "pool.ntp.org";
// const long gmtOffset_sec = 8 * 3600;
// const int daylightOffset_sec = 0;

typedef struct{
    char time_text[16];
    char weekday_text[12];
    char time_day_text[12];

}Time_Str;

// Time_Str time_str;


void getLocalTime(void);
void getTime(void);


#endif