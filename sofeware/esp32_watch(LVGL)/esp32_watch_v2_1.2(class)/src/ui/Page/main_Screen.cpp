//#include "ui_global.h"
#include "main_Screen.h"


#include "../my_style.h"
#include "ico_imgs.h"

extern struct tm timeinfo;


char *time_hour_value = "20";
char *time_min_value = "40";
char *time_sec_value = "60";

char* time_text = "20:22:30";

char *time_day = "2022/11/03";

char *time_lunar_day = "tenoften";

char *time_weekday = "sunday";

char *weather_temp = "24C~46C";

char *weather_hum = "96%";

char *weather_wind = "north 14";

char *weather_text = "cloudy";


typedef struct time_value{
    char time_hour_value ;
    char time_min_value ;
    char time_sec_value ;
}time_val;

time_val my_time = {20,20,20};

extern lv_obj_t * main_Screen;//主页面，home页


/**
 * 主界面显示UI
 *
 */
void ui_main_Screen(void)
{


    //lv_style_set_bg_color(&style,lv_color_hex(0x000000));//如果不设置，则会使用默认颜色蓝色进行填充
    main_Screen = lv_obj_create(NULL);



    lv_obj_add_style(main_Screen,&style,0);
    lv_obj_align(main_Screen,LV_ALIGN_CENTER,0,0);
    lv_disp_set_rotation(NULL, LV_DISP_ROT_180);


    strftime(time_text,sizeof(time_text),"%H:%M:%S",&timeinfo);

    lv_obj_t *label_time_text_ = lv_label_create(main_Screen);
    //lv_label_set_recolor(time_hour_text,true);
    lv_label_set_text(label_time_text_,time_text);

    lv_obj_align(label_time_text_, LV_ALIGN_CENTER, 0, 0);

    // 时钟 小时
    // snprintf(time_hour_value,10,"%02d",timeinfo.tm_hour);
    // lv_obj_t *time_hour_text = lv_label_create(main_Screen);
    // // lv_label_set_recolor(time_hour_text,true);
    // lv_label_set_text(time_hour_text,time_hour_value);

    // lv_obj_align(time_hour_text, LV_ALIGN_CENTER, -20, 0);
    


    // lv_obj_add_style(time_hour_text,&my_font_style1,0);



    // 冒号
    // lv_obj_t *time_maohao1_text = lv_label_create(main_Screen);
    // lv_label_set_recolor(time_maohao1_text, true);
    // lv_label_set_text(time_maohao1_text,":");


    // lv_obj_add_style(time_maohao1_text,&my_font_style4,0);


    // lv_obj_align(time_maohao1_text, LV_ALIGN_CENTER, 10, 0);
    // //lv_obj_set_pos(time_hour_text,120,90);


//
//    // 时间分钟
    //snprintf(time_min_value,10,"%02d",timeinfo.tm_min);
    // strftime(time_min_value,sizeof(time_min_value),"%Y-%m-%d",&timeinfo);
    // lv_obj_t *time_min_text = lv_label_create(main_Screen);
    // lv_label_set_text(time_min_text,time_min_value);

    // lv_obj_add_style(time_min_text,&my_font_style1,0);

    // //lv_obj_align_to(time_hour_text,lv_scr_act(),LV_ALIGN_CENTER,0,-20);

    // lv_obj_align(time_min_text, LV_ALIGN_CENTER, 60, -0);

    //日期显示
    //snprintf(time_day,10,"%04d-%02d-%d",timeinfo.tm_year,timeinfo.tm_mon,timeinfo.tm_mday);
    strftime(time_day,sizeof(time_day),"%Y-%m-%d",&timeinfo);
    lv_obj_t *time_day_text = lv_label_create(main_Screen);

    lv_label_set_text(time_day_text,time_day);

    lv_obj_add_style(time_day_text,&my_nomal_style,0);


    lv_obj_align(time_day_text, LV_ALIGN_CENTER, 0, 40);


    //农历显示
    // lv_obj_t *time_lunar_text = lv_label_create(main_Screen);

    // lv_label_set_text(time_lunar_text,time_lunar_day);

    // lv_obj_add_style(time_lunar_text,&my_nomal_style,0);


    // lv_obj_align(time_lunar_text, LV_ALIGN_CENTER, -40, 60);


    //星期显示
    strftime(time_weekday,sizeof(time_weekday),"%A",&timeinfo);
    //snprintf(time_weekday,10,"%04d-%02d-%d",timeinfo.tm_year,timeinfo.tm_mon,timeinfo.tm_mday);

    lv_obj_t *time_weekday_text = lv_label_create(main_Screen);

    lv_label_set_text(time_weekday_text,time_weekday);

    lv_obj_add_style(time_weekday_text,&my_nomal_style,0);


    lv_obj_align(time_weekday_text, LV_ALIGN_CENTER, 0, 60);


    //显示最高温度与最低气温
    lv_obj_t *weather_temp_text = lv_label_create(main_Screen);
    lv_label_set_text(weather_temp_text,weather_temp);

    lv_obj_add_style(weather_temp_text,&my_nomal_style1,0);

    lv_obj_align(weather_temp_text, LV_ALIGN_CENTER, -50, -40);


    //显示湿度
    lv_obj_t *weather_hum_text = lv_label_create(main_Screen);
    lv_label_set_text(weather_hum_text,weather_hum);

    lv_obj_add_style(weather_hum_text,&my_nomal_style1,0);

    lv_obj_align(weather_hum_text, LV_ALIGN_CENTER, -50, -90);

     //显示风向
    lv_obj_t *weather_wind_text = lv_label_create(main_Screen);
    lv_label_set_text(weather_wind_text,weather_wind);

    lv_obj_add_style(weather_wind_text,&my_nomal_style1,0);

    lv_obj_align(weather_wind_text, LV_ALIGN_CENTER, -50, -65);


    //显示天气图标
    LV_IMG_DECLARE(my_logo);
    lv_obj_t * weather_icon = lv_img_create(main_Screen);
    lv_img_set_src(weather_icon, &my_logo);
    lv_obj_set_size(weather_icon, 44, 44);

     lv_obj_align(weather_icon, LV_ALIGN_CENTER, 40, -75);

     //显示天气文字
    lv_obj_t *weather_value_text = lv_label_create(main_Screen);
    lv_label_set_text(weather_value_text,weather_text);

    lv_obj_add_style(weather_value_text,&my_nomal_style1,0);

    lv_obj_align(weather_value_text, LV_ALIGN_CENTER, 40, -40);


}


