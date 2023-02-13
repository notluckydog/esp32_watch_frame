

#include "page_config.h"
#include "my_style.h"
#include "ico.h"

//#include "ico_imgs.h"





static lv_obj_t * list_Screen;
//生成二级页面
void list_page(uint8_t index){

     //显示闹钟图标
    LV_IMG_DECLARE(aralm_ico);
    // //显示时钟图标
    LV_IMG_DECLARE(clock_ico);
    // //显示网络图标
    LV_IMG_DECLARE(net_ico);
    // //显示设定图标
    LV_IMG_DECLARE(setting_ico);
    // //显示番茄钟图标
    LV_IMG_DECLARE(tomato_ico);
    // //显示天气图标
    LV_IMG_DECLARE(weather_ico);

    char* text;//图标下的文字

    list_Screen = lv_obj_create(NULL);
    lv_obj_add_style(list_Screen,&style,0);
    lv_obj_align(list_Screen,LV_ALIGN_CENTER,0,0);

    lv_scr_load_anim(list_Screen,LV_SCR_LOAD_ANIM_MOVE_BOTTOM,300,0,true);



    lv_obj_t * list_icon ;
    list_icon = lv_img_create(list_Screen);
    
    lv_obj_set_size(list_icon, 48, 48);
    lv_obj_align(list_icon, LV_ALIGN_CENTER, 0, -15);

    lv_obj_t * list_text = lv_label_create(list_Screen);
    lv_obj_add_style(list_text,&my_nomal_style1,0);
    lv_obj_align(list_text, LV_ALIGN_CENTER, 0, 30);

        switch (index)
        {
            //番茄图标
        case 1:
            text = "tomato";
            
            lv_img_set_src(list_icon, &tomato_ico);
            lv_label_set_text(list_text,text);
            lv_obj_invalidate(list_icon);
            lv_obj_invalidate(list_text);
            // lv_obj_push_down(list_icon);
            // lv_obj_pop_up(list_text);
            

            break;
            //天气图标
        case 2:
            text = "weather";
            lv_img_set_src(list_icon, &weather_ico);
            lv_label_set_text(list_text,text);
            lv_obj_invalidate(list_icon);
            lv_obj_invalidate(list_text);
            // lv_obj_push_down(list_icon);
            // lv_obj_pop_up(list_text);

            break;
            //闹钟图标
        case 3:
            text = "arlam";
            lv_img_set_src(list_icon, &aralm_ico);
            lv_label_set_text(list_text,text);
            // lv_obj_push_down(list_icon);
            // lv_obj_pop_up(list_text);
            // lv_obj_invalidate(list_icon);
            // lv_obj_invalidate(list_text);

            break;
            //网路图标
        case 4:
            text = "net";
            lv_img_set_src(list_icon, &net_ico);
            lv_label_set_text(list_text,text);
            // lv_obj_push_down(list_icon);
            // lv_obj_pop_up(list_text);
            lv_obj_invalidate(list_icon);
            lv_obj_invalidate(list_text);

            break;

            //设置图标
        case 5:
            text = "setting";
            lv_img_set_src(list_icon, &setting_ico);
            lv_label_set_text(list_text,text);
            //lv_obj_pop_up(list_icon);
            // lv_obj_floating_add(list_text);
            // lv_obj_invalidate(list_icon);
            // lv_obj_invalidate(list_text);

            break;

        default:
            break;
        }

    
        lv_scr_load_anim(list_Screen,LV_SCR_LOAD_ANIM_FADE_ON,100,0,false);

}