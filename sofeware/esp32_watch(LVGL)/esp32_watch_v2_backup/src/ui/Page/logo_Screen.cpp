
#include "logo_Screen.h"
#include "../my_style.h"
#include "ico_imgs.h"


extern lv_obj_t * logo_Screen;


void ui_logo_Screen(void){

    logo_Screen = lv_obj_create(NULL);

    lv_obj_add_style(logo_Screen,&style,0);
    lv_obj_align(logo_Screen,LV_ALIGN_CENTER,0,0);


       //显示天气图标
    LV_IMG_DECLARE(logo);
    lv_obj_t * weather_icon = lv_img_create(logo_Screen);
    lv_img_set_src(weather_icon, &logo);
    lv_obj_set_size(weather_icon, 92, 64);

    lv_obj_align(weather_icon, LV_ALIGN_CENTER, 0, 0);


 

}


