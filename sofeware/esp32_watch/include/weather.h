

#ifndef _WEATHER_H_
#define _WEATHER_H_

#include <Arduino.h>


// String location_city = "Shenzhen";
// String weather_private_key = "SLJ1zuypKt_M1URPh";  //心知天气私钥
// String weather_public_key = "PCPNJ-fF1VnBX9wLO";   //心知天气公钥


// String weather_new_url = "https://api.seniverse.com/v3/weather/now.json?key="+ weather_private_key +"&location="+location_city+"&language=en";
// String weather_url = "https://api.seniverse.com/v3/weather/now.json?key=SLJ1zuypKt_M1URPh&location=ip&language=en";

// String weather_three_day = "https://api.seniverse.com/v3/weather/daily.json?key=SLJ1zuypKt_M1URPh&location=ip&language=en&unit=c&start=0&days=5";

//天气信息结构体
struct weatherInfo {
    const char * date = "2022-02-12";
    const char * temp_hign = "99";
    const char * temp_low = "99";
    const char* text_day  = "none";
    const char* code_day  = "12";
    const char * wind_derection = "NW";
    const char * wind_scale = "10";
    const char * hum = "100";
};

void getThreeDayWeather();//获取三天的天气详情
void getOneDayWeather();//获取一天的天气详情


#endif