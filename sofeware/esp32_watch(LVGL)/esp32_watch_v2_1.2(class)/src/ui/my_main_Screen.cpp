
#include "my_main_Screen.h"
#include "my_style.h"
#include "./Page/ico_imgs.h"

//extern lv_obj_t * _main_Screen;


//析构函数
main_Screen_UI::~main_Screen_UI(){}

//构造函数
main_Screen_UI::main_Screen_UI(){
    
}

// 初始化,将所有的先绘制一遍
void main_Screen_UI::init(lv_obj_t *main_Screen){

    _main_Screen =main_Screen;
    _main_Screen = lv_obj_create(NULL);
    lv_obj_add_style(_main_Screen,&style,0);
    lv_obj_align(_main_Screen,LV_ALIGN_CENTER,0,0);
    lv_disp_set_rotation(NULL, LV_DISP_ROT_180);


    lv_obj_t *label_time_text = lv_label_create(_main_Screen);
    //lv_label_set_recolor(time_hour_text,true);
    lv_label_set_text(label_time_text,"20:30:10");
    lv_obj_add_style(label_time_text,&my_font_style1,0);
    lv_obj_align(label_time_text, LV_ALIGN_CENTER, 0, 0);


    //日期显示
    lv_obj_t *time_day_text = lv_label_create(_main_Screen);
    lv_label_set_text(time_day_text,"2022-10-22");
    lv_obj_add_style(time_day_text,&my_nomal_style,0);
    lv_obj_align(time_day_text, LV_ALIGN_CENTER, 0, 40);


    //星期显示
    lv_obj_t *time_weekday_text = lv_label_create(_main_Screen);
    lv_label_set_text(time_weekday_text,"sunday");
    lv_obj_add_style(time_weekday_text,&my_nomal_style,0);
    lv_obj_align(time_weekday_text, LV_ALIGN_CENTER, 0, 60);


    //显示最高温度与最低气温
    lv_obj_t *weather_temp_text = lv_label_create(_main_Screen);
    lv_label_set_text(weather_temp_text,"24C~46C");

    lv_obj_add_style(weather_temp_text,&my_nomal_style1,0);

    lv_obj_align(weather_temp_text, LV_ALIGN_CENTER, -50, -40);


    //显示湿度
    lv_obj_t *weather_hum_text = lv_label_create(_main_Screen);
    lv_label_set_text(weather_hum_text,"96%");
    lv_obj_add_style(weather_hum_text,&my_nomal_style1,0);
    lv_obj_align(weather_hum_text, LV_ALIGN_CENTER, -50, -90);


     //显示风向
    lv_obj_t *weather_wind_text = lv_label_create(_main_Screen);
    lv_label_set_text(weather_wind_text,"north 14");

    lv_obj_add_style(weather_wind_text,&my_nomal_style1,0);

    lv_obj_align(weather_wind_text, LV_ALIGN_CENTER, -50, -65);


    //显示天气图标
    LV_IMG_DECLARE(my_logo);
    lv_obj_t * weather_icon = lv_img_create(_main_Screen);
    lv_img_set_src(weather_icon, &my_logo);
    lv_obj_set_size(weather_icon, 44, 44);

     lv_obj_align(weather_icon, LV_ALIGN_CENTER, 40, -75);

     //显示天气文字
    lv_obj_t *weather_value_text = lv_label_create(_main_Screen);
    lv_label_set_text(weather_value_text,"cloudy");

    lv_obj_add_style(weather_value_text,&my_nomal_style1,0);

    lv_obj_align(weather_value_text, LV_ALIGN_CENTER, 40, -40);



}

//绘制时间 例如 20:20:20
void main_Screen_UI::displayTime(char time_text ){

     lv_obj_t *label_time_text_ = lv_label_create(_main_Screen);
    //lv_label_set_recolor(time_hour_text,true);
    lv_label_set_text(label_time_text_,&time_text);
    lv_obj_align(label_time_text_, LV_ALIGN_CENTER, 0, 0);
}

//绘制周几  例如 sunday
void main_Screen_UI::displayWeekday(char time_weekday){

    // time_weekday;
    lv_obj_t *time_weekday_text = lv_label_create(_main_Screen);

    lv_label_set_text(time_weekday_text,&time_weekday);
    lv_obj_add_style(time_weekday_text,&my_nomal_style,0);
    lv_obj_align(time_weekday_text, LV_ALIGN_CENTER, 0, 60);
}

//绘制日期 例如2022-10-10
void main_Screen_UI::displayDay(char time_day){

    lv_obj_t *time_day_text = lv_label_create(_main_Screen);

    lv_label_set_text(time_day_text,&time_day);
    lv_obj_add_style(time_day_text,&my_nomal_style,0);
    lv_obj_align(time_day_text, LV_ALIGN_CENTER, 0, 40);
}

//绘制温度 例如 20C~40C
void main_Screen_UI::displayTemp(char weather_temp){

    lv_obj_t *weather_temp_text = lv_label_create(_main_Screen);

    lv_label_set_text(weather_temp_text,&weather_temp);
    lv_obj_add_style(weather_temp_text,&my_nomal_style1,0);
    lv_obj_align(weather_temp_text, LV_ALIGN_CENTER, -50, -40);
}

//绘制风向，例如northwest
void main_Screen_UI::displayWind(char weather_wind){

    lv_obj_t *weather_wind_text = lv_label_create(_main_Screen);
    lv_label_set_text(weather_wind_text,&weather_wind);

    lv_obj_add_style(weather_wind_text,&my_nomal_style1,0);
    lv_obj_align(weather_wind_text, LV_ALIGN_CENTER, -50, -65);
}

//绘制湿度 例如 80%
void main_Screen_UI::displayHum(char weather_hum){

    lv_obj_t *weather_hum_text = lv_label_create(_main_Screen);
    lv_label_set_text(weather_hum_text,&weather_hum);

    lv_obj_add_style(weather_hum_text,&my_nomal_style1,0);

    lv_obj_align(weather_hum_text, LV_ALIGN_CENTER, -50, -90);

}

//绘制天气图标 例如多云图像
void main_Screen_UI::displayWeatherIco(int index){
    LV_IMG_DECLARE(my_logo);
    lv_obj_t * weather_icon = lv_img_create(_main_Screen);
    lv_img_set_src(weather_icon, &my_logo);
    lv_obj_set_size(weather_icon, 44, 44);
     lv_obj_align(weather_icon, LV_ALIGN_CENTER, 40, -75);
}

//绘制天气文字信息  例如cloudy
void main_Screen_UI::dislplayWeatherText(char weather_text){

    lv_obj_t *weather_value_text = lv_label_create(_main_Screen);
    lv_label_set_text(weather_value_text,&weather_text);

    lv_obj_add_style(weather_value_text,&my_nomal_style1,0);

    lv_obj_align(weather_value_text, LV_ALIGN_CENTER, 40, -40);

}

