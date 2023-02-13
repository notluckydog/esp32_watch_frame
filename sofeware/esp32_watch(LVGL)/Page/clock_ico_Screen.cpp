

#include "clock_ico_Screen.h"
#include "../my_style.h"
#include "ico_imgs.h"

extern lv_obj_t * clock_ico_Screen;


void ui_clock_ico_Screen(void){


     clock_ico_Screen = lv_obj_create(NULL);
    lv_obj_add_style(clock_ico_Screen,&style,0);
    lv_obj_align(clock_ico_Screen,LV_ALIGN_CENTER,0,0);


       //显示天气图标
    LV_IMG_DECLARE(clock_ico);
    lv_obj_t * weather_icon = lv_img_create(clock_ico_Screen);
    lv_img_set_src(weather_icon, &clock_ico);
    lv_obj_set_size(weather_icon, 48, 48);

     /* LV_IMG_DECLARE(my_logo);
    lv_obj_t * weather_icon = lv_img_create(cont);
    lv_img_set_src(weather_icon, &my_logo);
    lv_obj_set_size(weather_icon, 44, 44);*/

     lv_obj_align(weather_icon, LV_ALIGN_CENTER, 0, -15);

     //显示天气文字
    lv_obj_t *weather_value_text = lv_label_create(clock_ico_Screen);
    lv_label_set_text(weather_value_text,"timming");

    lv_obj_add_style(weather_value_text,&my_nomal_style1,0);

    lv_obj_align(weather_value_text, LV_ALIGN_CENTER, 0, 30);



}
