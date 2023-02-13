

#include "ntp_time.h"

extern struct tm timeinfo;


Ntp_Time::Ntp_Time(){

}

Ntp_Time::~Ntp_Time(){

}

void Ntp_Time::init(){
    get_sucess_flag =0; // 初始化为0

    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

}


void Ntp_Time::getLocaTime(){

    if (!getLocalTime(&timeinfo))
    {
        get_sucess_flag =0;
        Serial.println("Failed to obtain time");
        
    }
    Serial.println(&timeinfo, "%F %T %A"); // 格式化输出
    strftime(time_text,sizeof(time_text),"%H:%M:%S",&timeinfo);
    strftime(weekday_text,sizeof(weekday_text),"%A",&timeinfo);
    strftime(time_day_text,sizeof(time_day_text),"%Y-%m-%d",&timeinfo);
    get_sucess_flag = 1;

}

uint8_t Ntp_Time::getStatus(void){

    return get_sucess_flag;


}