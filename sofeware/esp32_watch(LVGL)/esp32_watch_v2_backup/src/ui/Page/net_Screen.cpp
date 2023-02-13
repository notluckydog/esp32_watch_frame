
#include "net_Screen.h"
#include "../my_style.h"
#include "ico_imgs.h"

extern lv_obj_t * net_Screen;


void ui_net_Screen(void){

    net_Screen = lv_obj_create(NULL);

    lv_obj_add_style(net_Screen,&style,0);
    lv_obj_align(net_Screen,LV_ALIGN_CENTER,0,0);


       //显示天气图标
    // LV_IMG_DECLARE(netcode1);
    // lv_obj_t * weather_icon = lv_img_create(net_Screen);
    // lv_img_set_src(weather_icon, &netcode1);
    // lv_obj_set_size(weather_icon, 100, 100);

    // lv_obj_align(weather_icon, LV_ALIGN_CENTER, 0, -10);


    //显示天气文字
    lv_obj_t *weather_value_text = lv_label_create(net_Screen);
    lv_label_set_long_mode(weather_value_text, LV_LABEL_LONG_WRAP); 
    lv_label_set_recolor(weather_value_text, true);
     
    lv_label_set_text(weather_value_text,"#ffff00 please turn on wifi!\n and connect 192.168.4.1\n then wathch will restart!!!");

    lv_obj_add_style(weather_value_text,&my_nomal_style,0);

    lv_obj_align(weather_value_text, LV_ALIGN_CENTER, 0, 0);

}






