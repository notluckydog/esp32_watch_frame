



#include "page_config.h"


//用来显示配网显示
void net_page(void){

    lv_obj_t *  net_Screen = lv_obj_create(NULL);
    lv_obj_add_style(net_Screen,&style,0);
    lv_obj_align(net_Screen,LV_ALIGN_CENTER,0,0);

     lv_obj_t * label_text = lv_label_create(net_Screen);
    lv_label_set_long_mode(label_text, LV_LABEL_LONG_WRAP); 
    lv_label_set_recolor(label_text, true);
    
     
    lv_label_set_text(label_text,"#ffff00 please turn on wifi! \n and connect 192.168.4.1. \nthen wathch will restart!!!");
    //"#ffff00 please turn on wifi! and connect 192.168.4.1. then wathch will restart!!!"
    //lv_obj_add_style(label_text,&my_nomal_style,0);
    lv_obj_set_width(label_text,180);

    lv_obj_align(label_text, LV_ALIGN_CENTER, 0, -20);

    lv_scr_load_anim(net_Screen,LV_SCR_LOAD_ANIM_FADE_ON,100,0,false);




}
