

#ifndef __MY_MAIN_SCREEN_H_
#define __MY_MAIN_SCREEN_H_

#include <Arduino.h>
#include <lvgl.h>

class main_Screen_UI{
    public:
        main_Screen_UI();
        ~main_Screen_UI();

        void init(lv_obj_t *_main_Screen);// 初始化,将所有的先绘制一遍
        void displayTime(char time_text );//绘制时间 例如 20:20:20
        void displayWeekday(char time_weekday);//绘制周几  例如 sunday
        void displayDay(char time_day);//绘制日期 例如2022-10-10
        void displayTemp(char weather_temp);//绘制温度 例如 20C~40C
        void displayWind(char weather_wind);//绘制风向，例如northwest
        void displayHum(char weather_hum);//绘制湿度 例如 80%
        void displayWeatherIco(int index);//绘制天气图标 例如多云图像
        void dislplayWeatherText(char weather_text);//绘制天气文字信息  例如cloudy

    private:
        // char _time_text = "20:22:30";
        // char _time_day = "2022-11-03";
        // char _time_weekday= "sunday";
        // char _weather_temp = "24C~46C";
        // char _weather_hum = "96%";
        // char _weather_wind = "north 14";
        // int _index = 1;
        // char _weather_text = "cloudy";
        lv_obj_t *_main_Screen;
    protected:

};

#endif