

#include "weather_Screen.h"
#include "../my_style.h"
#include "ico_imgs.h"

char * weather_today_value = "26 C";
char * weather_today_temp_range= "25~32 C";
char* weather_today_code = "cloudy";

char * weather_tomoro = "08-22";
char * weather_tomoro_temp = "25~32 C";
char * weather_tomoro_code = "windy";

char * weather_after = "08-23";
char * weather_after_temp = "25~32 C";
char * weather_after_code = "cloudy";

char * weather_after_after = "08-24";
char * weather_after_after_temp = "25~32 C";
char * weather_after_after_code = "windy";


extern const char * weather_today_date;
extern const char * weather_today_temp_hign;
extern const char * weather_today_temp_low;
extern const char* weather_today_text_day;
extern const char * weather_today_wind_derection;
extern const char * weather_today_wind_scale;
extern const char * weather_today_hum;

extern const char * weather_tomorrow_date;
extern const char * weather_tomorrow_temp_hign;
extern const char * weather_tomorrow_temp_low;
extern const char* weather_tomorrow_text_day;
extern const char * weather_tomorrow_wind_derection;
extern const char * weather_tomorrow_wind_scale;
extern const char * weather_tomorrow_hum;

extern const char * weather_after_date;
extern const char * weather_after_temp_hign;
extern const char * weather_after_temp_low;
extern const char* weather_after_text_day;
extern const char * weather_after_wind_derection;
extern const char * weather_after_wind_scale;
extern const char * weather_after_hum;

char temp_today_range[16];
char temp_tomorrow_range[16];
char temp_after_range[16];

extern lv_obj_t * weather_Screen;    //三级页面  天气


void ui_weather_Screen(void)
{
    //lv_style_set_bg_color(&style,lv_color_hex(0x000000));//��������ã����ʹ��Ĭ����ɫ��ɫ�������
    weather_Screen = lv_obj_create(NULL);

    
    lv_obj_add_style(weather_Screen,&style,0);
    lv_obj_align(weather_Screen,LV_ALIGN_CENTER,0,0);


     LV_IMG_DECLARE(weather01);

    //天气图标
     lv_obj_t * weather_icon = lv_img_create(weather_Screen);
    lv_img_set_src(weather_icon, &weather01);
    lv_obj_set_size(weather_icon, 51, 52);

    lv_obj_align(weather_icon, LV_ALIGN_CENTER,-40, -60);

    //今天温度，大字体
    lv_obj_t *weather_today_value_text = lv_label_create(weather_Screen);
    lv_label_set_text(weather_today_value_text,weather_today_temp_hign);

     lv_obj_add_style(weather_today_value_text,&my_font_style1,0);
    lv_obj_align(weather_today_value_text, LV_ALIGN_CENTER, 60, -60);

    //今天温度范围
    sprintf(temp_today_range,"%s°C~%s°C ",weather_today_temp_hign,weather_today_temp_low);
    // lv_obj_t *weather_today_temp_range_text = lv_label_create(weather_Screen);
    // lv_label_set_text(weather_today_temp_range_text,temp_today_range);

    //  lv_obj_add_style(weather_today_temp_range_text,&my_nomal_style,0);
    // lv_obj_align(weather_today_temp_range_text, LV_ALIGN_CENTER, 5, -10);

    //今天日期

     lv_obj_t *weather_tomoro_text = lv_label_create(weather_Screen);
    lv_label_set_text(weather_tomoro_text,weather_today_date);

     lv_obj_add_style(weather_tomoro_text,&my_nomal_style1,0);
    lv_obj_align(weather_tomoro_text, LV_ALIGN_CENTER, -40, 0);

    //今天气温范围
     lv_obj_t *weather_tomoro_temp_text = lv_label_create(weather_Screen);
    lv_label_set_text(weather_tomoro_temp_text,temp_today_range);

     lv_obj_add_style(weather_tomoro_temp_text,&my_nomal_style1,0);
    lv_obj_align(weather_tomoro_temp_text, LV_ALIGN_CENTER, 40, -10);

    //今天天气信息
    lv_obj_t *weather_tomoro_code_text = lv_label_create(weather_Screen);
    lv_label_set_text(weather_tomoro_code_text,weather_today_text_day);

     lv_obj_add_style(weather_tomoro_code_text,&my_nomal_style1,0);
    lv_obj_align(weather_tomoro_code_text, LV_ALIGN_CENTER, 40, 10);

    //明天日期
     lv_obj_t *weather_after_text = lv_label_create(weather_Screen);
    lv_label_set_text(weather_after_text,weather_tomorrow_date);

     lv_obj_add_style(weather_after_text,&my_nomal_style1,0);
    lv_obj_align(weather_after_text, LV_ALIGN_CENTER, -40, 40);

    //明天温度范围
    sprintf(temp_tomorrow_range,"%s°C~%s°C ",weather_tomorrow_temp_hign,weather_tomorrow_temp_low);
    lv_obj_t *weather_after_temp_text = lv_label_create(weather_Screen);
    lv_label_set_text(weather_after_temp_text,weather_after_temp);

     lv_obj_add_style(weather_after_temp_text,&my_nomal_style1,0);
    lv_obj_align(weather_after_temp_text, LV_ALIGN_CENTER, 40, 30);

    //明天天气信息
     lv_obj_t *weather_after_code_text = lv_label_create(weather_Screen);
    lv_label_set_text(weather_after_code_text,weather_tomorrow_text_day);

     lv_obj_add_style(weather_after_code_text,&my_nomal_style1,0);
    lv_obj_align(weather_after_code_text, LV_ALIGN_CENTER,  40, 50);


    //后天日期
     lv_obj_t *weather_after_after_text = lv_label_create(weather_Screen);
    lv_label_set_text(weather_after_after_text,weather_after_date);

     lv_obj_add_style(weather_after_after_text,&my_nomal_style1,0);
    lv_obj_align(weather_after_after_text, LV_ALIGN_CENTER, -40, 80);

    //后天 温度范围
    sprintf(temp_after_range,"%s°C~%s°C ",weather_after_temp_hign,weather_after_temp_low);
    lv_obj_t *weather_after_after_temp_text = lv_label_create(weather_Screen);
    lv_label_set_text(weather_after_after_temp_text,temp_after_range);

     lv_obj_add_style(weather_after_after_temp_text,&my_nomal_style1,0);
    lv_obj_align(weather_after_after_temp_text, LV_ALIGN_CENTER, 40, 70);

    //第三天 天气信息
     lv_obj_t *weather_after_after_code_text = lv_label_create(weather_Screen);
    lv_label_set_text(weather_after_after_code_text,weather_after_text_day);

     lv_obj_add_style(weather_after_after_code_text,&my_nomal_style1,0);
    lv_obj_align(weather_after_after_code_text, LV_ALIGN_CENTER,40, 90);
}


extern lv_obj_t * weather_ico_Screen;

void ui_weather_ico_Screen(void){


    weather_ico_Screen = lv_obj_create(NULL);
    lv_obj_add_style(weather_ico_Screen,&style,0);
    lv_obj_align(weather_ico_Screen,LV_ALIGN_CENTER,0,0);


       //显示天气图标
    LV_IMG_DECLARE(weather_ico);
    lv_obj_t * weather_icon = lv_img_create(weather_ico_Screen);
    lv_img_set_src(weather_icon, &weather_ico);
    lv_obj_set_size(weather_icon, 48, 48);



     lv_obj_align(weather_icon, LV_ALIGN_CENTER, 0, -15);

     //显示天气文字
    lv_obj_t *weather_value_text = lv_label_create(weather_ico_Screen);
    lv_label_set_text(weather_value_text,"weather");

    lv_obj_add_style(weather_value_text,&my_nomal_style1,0);

    lv_obj_align(weather_value_text, LV_ALIGN_CENTER, 0, 30);



}