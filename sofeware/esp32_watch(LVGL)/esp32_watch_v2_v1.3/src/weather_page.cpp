

#include "page_config.h"
#include "ntp_time.h"
#include "weather.h"


extern Ntp_Time ntp_time;
extern Weather weather;


static lv_obj_t * weather_Screen;


char temp_today_range[16];
char temp_tomorrow_range[16];
char temp_after_range[16];


//用来显示天气页面
void weather_page(void){

    weather_Screen = lv_obj_create(NULL);

    lv_obj_add_style(weather_Screen,&style,0);
    lv_obj_align(weather_Screen,LV_ALIGN_CENTER,0,0);

    lv_scr_load_anim(weather_Screen, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 300, 0, true);
   
     LV_IMG_DECLARE(weather01);

     //天气图标
     lv_obj_t * weather_icon = lv_img_create(weather_Screen);
    lv_img_set_src(weather_icon, &weather01);
    lv_obj_set_size(weather_icon, 51, 52);

    lv_obj_align(weather_icon, LV_ALIGN_CENTER,-40, -60);

    //今天温度，大字体
    lv_obj_t *weather_today_value_text = lv_label_create(weather_Screen);
    lv_label_set_text(weather_today_value_text,weather.weather_today_temp_hign);

     lv_obj_add_style(weather_today_value_text,&my_font_style1,0);
    lv_obj_align(weather_today_value_text, LV_ALIGN_CENTER, 60, -60);

    //今天温度范围
    sprintf(temp_today_range,"%s°C~%s°C ",weather.weather_today_temp_hign,weather.weather_today_temp_low);
    // lv_obj_t *weather_today_temp_range_text = lv_label_create(weather_Screen);
    // lv_label_set_text(weather_today_temp_range_text,temp_today_range);

    //  lv_obj_add_style(weather_today_temp_range_text,&my_nomal_style,0);
    // lv_obj_align(weather_today_temp_range_text, LV_ALIGN_CENTER, 5, -10);

    //今天日期

     lv_obj_t *weather_tomoro_text = lv_label_create(weather_Screen);
    lv_label_set_text(weather_tomoro_text,weather.weather_today_date);

     lv_obj_add_style(weather_tomoro_text,&my_nomal_style1,0);
    lv_obj_align(weather_tomoro_text, LV_ALIGN_CENTER, -40, 0);

    //今天气温范围
     lv_obj_t *weather_tomoro_temp_text = lv_label_create(weather_Screen);
    lv_label_set_text(weather_tomoro_temp_text,temp_today_range);

     lv_obj_add_style(weather_tomoro_temp_text,&my_nomal_style1,0);
    lv_obj_align(weather_tomoro_temp_text, LV_ALIGN_CENTER, 40, -10);

    //今天天气信息
    lv_obj_t *weather_tomoro_code_text = lv_label_create(weather_Screen);
    lv_label_set_text(weather_tomoro_code_text,weather.weather_today_text_day);

     lv_obj_add_style(weather_tomoro_code_text,&my_nomal_style1,0);
    lv_obj_align(weather_tomoro_code_text, LV_ALIGN_CENTER, 40, 10);

    //明天日期
     lv_obj_t *weather_after_text = lv_label_create(weather_Screen);
    lv_label_set_text(weather_after_text,weather.weather_tomorrow_date);

     lv_obj_add_style(weather_after_text,&my_nomal_style1,0);
    lv_obj_align(weather_after_text, LV_ALIGN_CENTER, -40, 40);

    //明天温度范围
    sprintf(temp_tomorrow_range,"%s°C~%s°C ",weather.weather_tomorrow_temp_hign,weather.weather_tomorrow_temp_low);
    lv_obj_t *weather_after_temp_text = lv_label_create(weather_Screen);
    lv_label_set_text(weather_after_temp_text,temp_tomorrow_range);

     lv_obj_add_style(weather_after_temp_text,&my_nomal_style1,0);
    lv_obj_align(weather_after_temp_text, LV_ALIGN_CENTER, 40, 30);

    //明天天气信息
     lv_obj_t *weather_after_code_text = lv_label_create(weather_Screen);
    lv_label_set_text(weather_after_code_text,weather.weather_tomorrow_text_day);

     lv_obj_add_style(weather_after_code_text,&my_nomal_style1,0);
    lv_obj_align(weather_after_code_text, LV_ALIGN_CENTER,  40, 50);


    //后天日期
     lv_obj_t *weather_after_after_text = lv_label_create(weather_Screen);
    lv_label_set_text(weather_after_after_text,weather.weather_after_date);

     lv_obj_add_style(weather_after_after_text,&my_nomal_style1,0);
    lv_obj_align(weather_after_after_text, LV_ALIGN_CENTER, -40, 80);

    //后天 温度范围
    sprintf(temp_after_range,"%s°C~%s°C ",weather.weather_after_temp_hign,weather.weather_after_temp_low);
    lv_obj_t *weather_after_after_temp_text = lv_label_create(weather_Screen);
    lv_label_set_text(weather_after_after_temp_text,temp_after_range);

     lv_obj_add_style(weather_after_after_temp_text,&my_nomal_style1,0);
    lv_obj_align(weather_after_after_temp_text, LV_ALIGN_CENTER, 40, 70);

    //第三天 天气信息
     lv_obj_t *weather_after_after_code_text = lv_label_create(weather_Screen);
    lv_label_set_text(weather_after_after_code_text,weather.weather_after_text_day);

     lv_obj_add_style(weather_after_after_code_text,&my_nomal_style1,0);
    lv_obj_align(weather_after_after_code_text, LV_ALIGN_CENTER,40, 90);




}