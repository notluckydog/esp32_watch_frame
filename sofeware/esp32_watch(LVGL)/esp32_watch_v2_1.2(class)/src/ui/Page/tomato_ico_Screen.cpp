

#include "tomato_ico_Screen.h"
#include "../my_style.h"
#include "ico_imgs.h"

extern lv_obj_t * tomato_ico_Screen;

void ui_tomato_ico_Screen(void){


    tomato_ico_Screen = lv_obj_create(NULL);
    lv_obj_add_style(tomato_ico_Screen,&style,0);
    lv_obj_align(tomato_ico_Screen,LV_ALIGN_CENTER,0,0);


       //��ʾ����ͼ��
    LV_IMG_DECLARE(tomato_ico);
    lv_obj_t * weather_icon = lv_img_create(tomato_ico_Screen);
    lv_img_set_src(weather_icon, &tomato_ico);
    lv_obj_set_size(weather_icon, 48, 48);

     

     lv_obj_align(weather_icon, LV_ALIGN_CENTER, 0, -15);

     //��ʾ��������
    lv_obj_t *weather_value_text = lv_label_create(tomato_ico_Screen);
    lv_label_set_text(weather_value_text,"tomato");

    lv_obj_add_style(weather_value_text,&my_nomal_style1,0);

    lv_obj_align(weather_value_text, LV_ALIGN_CENTER, 0, 30);



}
