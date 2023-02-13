
#include "ntp_time.h"
//#include "my_wifi.h"


const char *ntpServer = "time1.aliyun.com";
const long gmtOffset_sec = 8 * 3600;
const int daylightOffset_sec = 0;

extern struct tm timeinfo;

Time_Str time_str;

//获取当前时间
void getTime(void){

    //struct tm timeinfo;
    if (!getLocalTime(&timeinfo))
    {
        Serial.println("Failed to obtain time");
        return;
    }
    Serial.println(&timeinfo, "%F %T %A"); // 格式化输出
    strftime(time_str.time_text,sizeof(time_str.time_text),"%H:%M:%S",&timeinfo);
    strftime(time_str.weekday_text,sizeof(time_str.weekday_text),"%A",&timeinfo);
    strftime(time_str.time_day_text,sizeof(time_str.time_day_text),"%Y-%m-%d",&timeinfo);

}

//获取当前时间
void getLocalTime(){

    //connectWifi();

    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

    getTime();

    // WiFi.disconnect(true);
    // WiFi.mode(WIFI_OFF);
    // Serial.println("WiFi disconnected!");



}