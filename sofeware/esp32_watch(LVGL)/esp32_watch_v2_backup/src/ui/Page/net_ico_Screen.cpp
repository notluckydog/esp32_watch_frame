

#include "net_ico_Screen.h"
#include "../my_style.h"
#include "ico_imgs.h"


extern lv_obj_t * net_ico_Screen;


void ui_net_ico_Screen(void){


    net_ico_Screen = lv_obj_create(NULL);
    lv_obj_add_style(net_ico_Screen,&style,0);
    lv_obj_align(net_ico_Screen,LV_ALIGN_CENTER,0,0);


       //��ʾ����ͼ��
    LV_IMG_DECLARE(net_ico);
    lv_obj_t * weather_icon = lv_img_create(net_ico_Screen);
    lv_img_set_src(weather_icon, &net_ico);
    lv_obj_set_size(weather_icon, 48, 48);

  

     lv_obj_align(weather_icon, LV_ALIGN_CENTER, 0, -15);

     //��ʾ��������
    lv_obj_t *weather_value_text = lv_label_create(net_ico_Screen);
    lv_label_set_text(weather_value_text,"net setup");

    lv_obj_add_style(weather_value_text,&my_nomal_style1,0);

    lv_obj_align(weather_value_text, LV_ALIGN_CENTER, 0, 30);



}
