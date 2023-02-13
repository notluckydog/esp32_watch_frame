

#include "page_config.h"
#include "ntp_time.h"
#include "weather.h"

static lv_obj_t * main_Screen;
static lv_obj_t * lable_time_text;

char  weather_temp_range[16];
char weather_wind_dire_scale[20];
char weather_hum_range[10];

extern Ntp_Time ntp_time;
extern Weather weather;
extern struct tm timeinfo;

void updateTime(void){

    lv_label_set_text(lable_time_text,ntp_time.time_text);
   
    lv_obj_invalidate(lable_time_text);

}
void main_page(void){

    Serial.print("main page\n");

    main_Screen = lv_obj_create(NULL);

    lv_obj_add_style(main_Screen,&style,0);
    lv_obj_align(main_Screen,LV_ALIGN_CENTER,0,0);
    

    Serial.print("-2\n");

    //lv_obj_t *lable_time_text;  // 时间标签 例如20:20:20
    lv_obj_t *time_weekday_text;//星期显示
    lv_obj_t *time_day_text;//日期显示
    lv_obj_t *weather_temp_text;//温度显示
    lv_obj_t *weather_hum_text ; //湿度显示
    lv_obj_t *weather_wind_text;//显示风向
    lv_obj_t * logo_icon;
    lv_obj_t *weather_value_text;

    //Serial.print("-3\n");

    lable_time_text = lv_label_create(main_Screen);
    time_weekday_text = lv_label_create(main_Screen);
    time_day_text = lv_label_create(main_Screen);
    weather_temp_text = lv_label_create(main_Screen);
    weather_hum_text = lv_label_create(main_Screen);
    weather_wind_text = lv_label_create(main_Screen);
    logo_icon = lv_img_create(main_Screen);
    weather_value_text = lv_label_create(main_Screen);

    //Serial.print("0");
    //修改时间

    lv_obj_add_style(lable_time_text,&my_font_style1,0);
    lv_obj_align(lable_time_text, LV_ALIGN_CENTER, 0, 0);
   
   
    
    
    updateTime();
    

    //修改星期
    lv_label_set_text(time_weekday_text,ntp_time.weekday_text);
    lv_obj_add_style(time_weekday_text,&my_nomal_style,0);
    lv_obj_align(time_weekday_text, LV_ALIGN_CENTER, 0, 60);
    lv_obj_invalidate(time_weekday_text);

    //Serial.print("1");

    //修改日期
    lv_label_set_text(time_day_text,ntp_time.time_day_text);
    lv_obj_add_style(time_day_text,&my_nomal_style,0);
    lv_obj_align(time_day_text, LV_ALIGN_CENTER, 0, 40);
    lv_obj_invalidate(time_day_text);
    Serial.print("2");

    //修改温度
    sprintf(weather_temp_range,"%s°C~%s°C ",weather.weather_after_temp_hign,weather.weather_today_temp_low);
    lv_label_set_text(weather_temp_text,weather_temp_range);

    lv_obj_add_style(weather_temp_text,&my_nomal_style1,0);
    lv_obj_align(weather_temp_text, LV_ALIGN_CENTER, -50, -60);
    lv_obj_invalidate(weather_temp_text);
    Serial.print("3");

    //修改湿度
    sprintf(weather_hum_range,"%s %% ",weather.weather_today_hum);
    lv_label_set_text(weather_hum_text,weather_hum_range);

    lv_obj_add_style(weather_hum_text,&my_nomal_style1,0);

    lv_obj_align(weather_hum_text, LV_ALIGN_CENTER, -50, -80);
    lv_obj_invalidate(weather_hum_text);
    Serial.print("4");

    //修改风向
     sprintf(weather_wind_dire_scale,"%s level %s ",weather.weather_today_wind_derection,weather.weather_today_wind_scale);
    lv_label_set_text(weather_wind_text,weather_wind_dire_scale);

    lv_obj_add_style(weather_wind_text,&my_nomal_style1,0);

    lv_obj_align(weather_wind_text, LV_ALIGN_CENTER, -50, -40);
    lv_obj_invalidate(weather_wind_text);
    Serial.print("5");

    //显示logo
    LV_IMG_DECLARE(my_logo);
   
    lv_img_set_src(logo_icon, &my_logo);
    lv_obj_set_size(logo_icon, 44, 44);

     lv_obj_align(logo_icon, LV_ALIGN_CENTER, 40, -75);
    lv_obj_invalidate(logo_icon);
    Serial.print("5");

    //显示天气文字
    lv_label_set_text(weather_value_text,weather.weather_today_text_day);
    lv_obj_add_style(weather_value_text,&my_nomal_style1,0);
    lv_obj_align(weather_value_text, LV_ALIGN_CENTER, 40, -40);
    lv_obj_invalidate(weather_value_text);
    Serial.print("6");

    lv_scr_load_anim(main_Screen,LV_SCR_LOAD_ANIM_FADE_ON,100,0,false);




}