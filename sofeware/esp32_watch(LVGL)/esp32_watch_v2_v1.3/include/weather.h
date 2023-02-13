

#ifndef _WEATHER_H_
#define _WEATHER_H_

#include <Arduino.h>
#include <Preferences.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <WiFi.h>



class Weather{
    public:

        Weather();
        ~Weather();
        void init(void);
        void getThreeDay(void);//获取三天的天气预报
        void getToday(void);//获取今天的天气预报
        uint8_t getStatus(void);//获取是否成功获取到信息

        const char * weather_today_date;
        const char * weather_today_temp_hign;
        const char * weather_today_temp_low;
        const char* weather_today_text_day;
        const char* weather_today_code_day;
        const char * weather_today_wind_derection;
        const char * weather_today_wind_scale;
        const char * weather_today_hum;


        const char * weather_tomorrow_date;
        const char * weather_tomorrow_temp_hign;
        const char * weather_tomorrow_temp_low;
        const char* weather_tomorrow_text_day;
        const char* weather_tomorrow_code_day;
        const char * weather_tomorrow_wind_derection;
        const char * weather_tomorrow_wind_scale;
        const char * weather_tomorrow_hum;

        const char * weather_after_date;
        const char * weather_after_temp_hign;
        const char * weather_after_temp_low;
        const char* weather_after_text_day;
        const char* weather_after_code_day;
        const char * weather_after_wind_derection;
        const char * weather_after_wind_scale;
        const char * weather_after_hum;

    private:

        String now_ssid ;
        String  now_pass;
        String now_city_code;
        uint8_t get_sucess_flag ;//标志位，获取成功后设置为1


        

    protected:
};



#endif