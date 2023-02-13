

#ifndef _NTP_TIME_H_
#define _NTP_TIME_H_

#include <Arduino.h>

class Ntp_Time{
    public:
        Ntp_Time();
        ~Ntp_Time();
        void init();
        void getLocaTime(void);
        uint8_t getStatus(void);
        char time_text[16];
        char weekday_text[12];
        char time_day_text[12];




    private:
        const char *ntpServer = "time1.aliyun.com";
        const long gmtOffset_sec = 8 * 3600;
        const int daylightOffset_sec = 0;
        uint8_t get_sucess_flag ;//标志位，获取成功后设置为1

        
    protected:
};

#endif
