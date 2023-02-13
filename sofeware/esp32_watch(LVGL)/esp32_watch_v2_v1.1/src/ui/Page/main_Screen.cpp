//#include "ui_global.h"
#include "main_Screen.h"

#include "ntp_time.h"
#include "my_weather.h"
#include "../my_style.h"
#include "ico_imgs.h"

extern struct tm timeinfo;


lv_obj_t *label_time_text;  // 时间标签 例如20:20:20
lv_obj_t *time_weekday_text;//星期显示
lv_obj_t *time_day_text;//日期显示
lv_obj_t *weather_temp_text;//温度显示
lv_obj_t *weather_hum_text ; //湿度显示
lv_obj_t *weather_wind_text;//显示风向
lv_obj_t * weather_icon;
lv_obj_t *weather_value_text;


typedef struct time_value{
    char time_hour_value ;
    char time_min_value ;
    char time_sec_value ;
}time_val;

time_val my_time = {20,20,20};

extern Time_Str time_str;
extern Weather_Struct weather_info;

extern lv_obj_t * main_Screen;//主页面，home页
typedef struct{
    char *time_text;//时间字符串 例如 20:20:20
    char *weekday_text;//星期字符串 例如 sunday
    char *time_day_text;  //日期字符串 例如2022-10-20
    char weather_temp;//最高气温与最低气温 例如 20C~40C
    char weather_hum;//湿度信息 例如 96%
    char weather_wind;//风向信息 例如norther 14
    char weather_ico_index;//天气图标 例如说2 其表示晴天
    char weather_text;//天气文字信息 例如说 cloudy

}Main_Screen_Data;



volatile Main_Screen_Data main_screen_data = {
};

char temp[8];
char hum;
char wind;
char ico_id;
char weather;


extern const char* weather_text;
extern int weather_code;
extern int weather_tem;
extern char* weather_hum;
extern char* weather_wind;


extern const char * weather_today_date;
extern const char * weather_today_temp_hign;
extern const char * weather_today_temp_low;
extern const char* weather_today_text_day;
extern const char * weather_today_wind_derection;
extern const char * weather_today_wind_scale;
extern const char * weather_today_hum;

char  weather_temp_hign_low[16];
char weather_wind_dire_scale[20];
char weather_hum_range[10];
//修改时间
void ui_main_Screen_DisplayTime(){
    //绘制时间
    main_screen_data.time_text = time_str.time_text;
    
    //lv_label_set_recolor(time_hour_text,true);
    lv_label_set_text(label_time_text,main_screen_data.time_text);
    lv_obj_add_style(label_time_text,&my_font_style1,0);
    lv_obj_align(label_time_text, LV_ALIGN_CENTER, 0, 0);
    lv_obj_invalidate(label_time_text);
}


//修改星期
void ui_main_Screen_DisplayWeekday(){

    main_screen_data.weekday_text = time_str.weekday_text;
    //星期显示
    

    lv_label_set_text(time_weekday_text,main_screen_data.weekday_text);
    lv_obj_add_style(time_weekday_text,&my_nomal_style,0);
    lv_obj_align(time_weekday_text, LV_ALIGN_CENTER, 0, 60);
    lv_obj_invalidate(time_weekday_text);
}
//修改日期
void ui_main_Screen_DisplayDay(){

    main_screen_data.time_day_text = time_str.time_day_text;
    
    lv_label_set_text(time_day_text,main_screen_data.time_day_text);
    lv_obj_add_style(time_day_text,&my_nomal_style,0);
    lv_obj_align(time_day_text, LV_ALIGN_CENTER, 0, 40);
    lv_obj_invalidate(time_day_text);
}

//修改温度
void ui_main_Screen_DisplayTemp(){
    //main_screen_data.weather_temp =  weather_info.weather_tem;
    //显示最高温度与最低气温

    sprintf(weather_temp_hign_low,"%s°C~%s°C ",weather_today_temp_hign,weather_today_temp_low);
    lv_label_set_text(weather_temp_text,temp);

    lv_obj_add_style(weather_temp_text,&my_nomal_style1,0);
    lv_obj_align(weather_temp_text, LV_ALIGN_CENTER, -50, -40);
    lv_obj_invalidate(weather_temp_text);
}
//修改湿度
void ui_main_Screen_DisplayHum(){

    //main_screen_data.weather_hum = weather_info.weather_hum;
     //显示湿度

    //hum = main_screen_data.weather_hum;

    sprintf(weather_hum_range,"%s % ",weather_today_hum);
    lv_label_set_text(weather_hum_text,weather_hum_range);

    lv_obj_add_style(weather_hum_text,&my_nomal_style1,0);

    lv_obj_align(weather_hum_text, LV_ALIGN_CENTER, -50, -80);
    lv_obj_invalidate(weather_hum_text);
}
//修改风向
void ui_main_Screen_DisplayWind(){

    //main_screen_data.weather_wind = weather_info.weather_wind;
    //显示风向
    
    //wind = main_screen_data.weather_wind;
    
     sprintf(weather_wind_dire_scale,"%s level %s ",weather_today_wind_derection,weather_today_wind_scale);
    lv_label_set_text(weather_wind_text,weather_wind_dire_scale);

    lv_obj_add_style(weather_wind_text,&my_nomal_style1,0);

    lv_obj_align(weather_wind_text, LV_ALIGN_CENTER, -50, -40);
    lv_obj_invalidate(weather_wind_text);
}

//显示logo
void ui_main_Screen_DisplayWeatherIco(){
    //
    LV_IMG_DECLARE(my_logo);
   
    lv_img_set_src(weather_icon, &my_logo);
    lv_obj_set_size(weather_icon, 44, 44);

     lv_obj_align(weather_icon, LV_ALIGN_CENTER, 40, -75);
    lv_obj_invalidate(weather_icon);

}
//修改天气文字
void ui_main_Screen_DisplayWeatherText(){

    //main_screen_data.weather_text = weather_info.weather_text;
     //显示天气文字
    
    //weather = main_screen_data.weather_text;
    lv_label_set_text(weather_value_text,weather_today_text_day);
    lv_obj_add_style(weather_value_text,&my_nomal_style1,0);
    lv_obj_align(weather_value_text, LV_ALIGN_CENTER, 40, -40);
    lv_obj_invalidate(weather_value_text);
}


/**
 * 主界面显示UI
 *
 */
void ui_main_Screen(void)
{

    main_screen_data.time_text = time_str.time_text;
    main_screen_data.weekday_text = time_str.weekday_text;
    main_screen_data.time_day_text = time_str.time_day_text;
    main_Screen = lv_obj_create(NULL);


    lv_obj_add_style(main_Screen,&style,0);
    lv_obj_align(main_Screen,LV_ALIGN_CENTER,0,0);
    lv_disp_set_rotation(NULL, LV_DISP_ROT_180);

    label_time_text = lv_label_create(main_Screen);
    time_weekday_text = lv_label_create(main_Screen);
    time_day_text = lv_label_create(main_Screen);
    weather_temp_text = lv_label_create(main_Screen);
    weather_hum_text = lv_label_create(main_Screen);
    weather_wind_text = lv_label_create(main_Screen);
    weather_icon = lv_img_create(main_Screen);
    weather_value_text = lv_label_create(main_Screen);

    ui_main_Screen_DisplayTime();
    ui_main_Screen_DisplayWeekday();
    ui_main_Screen_DisplayDay();
    ui_main_Screen_DisplayTemp();
    ui_main_Screen_DisplayHum();
    ui_main_Screen_DisplayWind();
    ui_main_Screen_DisplayWeatherIco();
    ui_main_Screen_DisplayWeatherText();
    
}


