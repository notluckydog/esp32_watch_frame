

#include "aralm_ico_Screen.h"
#include "../my_style.h"
#include "ico_imgs.h"

extern lv_obj_t * aralm_ico_Screen;

void ui_aralm_ico_Screen(void){


    aralm_ico_Screen = lv_obj_create(NULL);
    lv_obj_add_style(aralm_ico_Screen,&style,0);
    lv_obj_align(aralm_ico_Screen,LV_ALIGN_CENTER,0,0);


       //显示天气图标
    LV_IMG_DECLARE(aralm_ico);
    lv_obj_t * weather_icon = lv_img_create(aralm_ico_Screen);
    lv_img_set_src(weather_icon, &aralm_ico);
    lv_obj_set_size(weather_icon, 48, 48);

     /* LV_IMG_DECLARE(my_logo);
    lv_obj_t * weather_icon = lv_img_create(cont);
    lv_img_set_src(weather_icon, &my_logo);
    lv_obj_set_size(weather_icon, 44, 44);*/

     lv_obj_align(weather_icon, LV_ALIGN_CENTER, 0, -15);

     //显示天气文字
    lv_obj_t *weather_value_text = lv_label_create(aralm_ico_Screen);
    lv_label_set_text(weather_value_text,"aralm");

    lv_obj_add_style(weather_value_text,&my_nomal_style1,0);

    lv_obj_align(weather_value_text, LV_ALIGN_CENTER, 0, 30);



}
