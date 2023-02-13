#ifndef _MAIN_SCREEN_H_
#define _MAIN_SCREEN_H_


#include "lvgl.h"
#include <Arduino.h>

void ui_main_Screen(void);

void ui_main_Screen_DisplayTime();//修改时间
void ui_main_Screen_DisplayWeekday();//修改星期
void ui_main_Screen_DisplayDay();//修改日期
void ui_main_Screen_DisplayTemp();//修改温度
void ui_main_Screen_DisplayHum();//修改湿度
void ui_main_Screen_DisplayWind();//修改风向
void ui_main_Screen_DisplayWeatherIco();//修改天气图标
void ui_main_Screen_DisplayWeatherText();//修改天气文字




#endif
