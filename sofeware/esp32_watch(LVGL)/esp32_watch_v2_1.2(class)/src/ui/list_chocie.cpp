

#include "list_choice.h"
#include "my_style.h"
#include "./Page/ico_imgs.h"

list_Screen_UI::list_Screen_UI(){};
list_Screen_UI::~list_Screen_UI(){};



void init(lv_obj_t *Screen,lv_img_dsc_t ico,char text){

    Screen = lv_obj_create(NULL);
    lv_obj_add_style(Screen,&style,0);
    lv_obj_align(Screen,LV_ALIGN_CENTER,0,0);


       //显示图标
    LV_IMG_DECLARE(ico);
    lv_obj_t * icon = lv_img_create(Screen);
    lv_img_set_src(icon, &ico);
    lv_obj_set_size(icon, 48, 48);
     lv_obj_align(icon, LV_ALIGN_CENTER, 0, -15);


     //显示文字
    lv_obj_t *textn = lv_label_create(Screen);
    lv_label_set_text(textn,&text);
    lv_obj_add_style(textn,&my_nomal_style1,0);
    lv_obj_align(textn, LV_ALIGN_CENTER, 0, 30);

}

//显示图片
void displayIco(lv_img_dsc_t ico){

    // LV_IMG_DECLARE(ico);
    // lv_obj_t * icon = lv_img_create(Screen);
    // lv_img_set_src(icon, &ico);
    // lv_obj_set_size(icon, 48, 48);
    //  lv_obj_align(icon, LV_ALIGN_CENTER, 0, -15);

}

//显示文字
void displayText(char text){


}