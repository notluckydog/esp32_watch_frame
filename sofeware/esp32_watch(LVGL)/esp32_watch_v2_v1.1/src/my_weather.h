#ifndef MY_WEATHER_H
#define MY_WEATHER_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <WiFi.h>

//龙华有深圳龙华与海南龙华，而且使用城市ID的方式似乎取不到数据，只能够使用拼音或者城市ID的方式来获取市级的天气数据

//Stirng location_code = "WS115H2FNT23";    //深圳龙华城市代码
/*String location_city ;
String weather_private_key ;  //心知天气私钥
String weather_public_key ;   //心知天气公钥

String weather_url ;
String weather_test_url ;*/

//static const char* my_ssid ;  //你的WIFI
//static const char* my_pass ;  //你的WIFI密码


//天气信息结构体，方便后续扩展
typedef struct 
{
    char weather_text;
    char weather_code;
    char weather_tem;
    char weather_hum;
    char weather_wind;

} Weather_Struct;

// Weather_Struct weather_info;

void getWeatherInfo();   //获取天气信息
void getThreeDayWeather(void);//获取包括今天在内的三天的天气信息

#endif