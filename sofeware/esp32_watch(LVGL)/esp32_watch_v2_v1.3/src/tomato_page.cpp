
#include "page_config.h"

static lv_obj_t *tomato_Screen;
static lv_obj_t * lable_tomato_clock_text;
static lv_obj_t * status_icon;


char tomato_time_text[16];// 整个倒计时 例如 “23:23:10"
int ab = 59 ;
int bc = 35;


// char tomato_time_text[16];// 整个倒计时 例如 “23:23:10"
// volatile uint8_t tomato_time_min =0; // 倒计时 分钟
// volatile uint8_t tomato_time_sec = 0; // 倒计时 秒
// volatile uint8_t tomato_count =0; // 今天共完成了多少个番茄钟，凌晨四点更新一次


void update_tomato_time(int time_min,int time_sec){

    Serial.print("update tomato time \n");

    sprintf(tomato_time_text,"%d:%d",bc,ab);
    
    Serial.print("tomato_time_text");
    Serial.print(tomato_time_text);
   //Serial.printf(tomato_time_text);
    Serial.printf("\n");

    //lv_label_set_text(lable_tomato_clock_text,"35:00");
    
    lv_label_set_text(lable_tomato_clock_text,tomato_time_text);
    //lv_obj_invalidate(lable_tomato_clock_text);


}

//更换开始和停止图标
void update_tomato_ico(bool p){
    //开始图标
    if(p){
        lv_img_set_src(status_icon, &ico_start);
         lv_obj_invalidate(status_icon);
    }else{
        lv_img_set_src(status_icon, &ico_stop);
         lv_obj_invalidate(status_icon);
    }
}

//用来显示番茄钟详情页
void tomato_page(void){

    tomato_Screen = lv_obj_create(NULL);

    lv_obj_add_style(tomato_Screen,&style,0);
    lv_obj_align(tomato_Screen,LV_ALIGN_CENTER,0,0);

    lv_scr_load_anim(tomato_Screen, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 300, 0, true);

    lv_obj_t * lable_tomato_clock_text;

    //sprintf(tomato_time_text,"%2d:%2d",tomato_time_min,tomato_time_sec);

    lable_tomato_clock_text = lv_label_create(tomato_Screen);

    lv_obj_add_style(lable_tomato_clock_text,&my_font_style1,0);
    lv_obj_align(lable_tomato_clock_text, LV_ALIGN_CENTER, 0, -10);

    lv_label_set_text(lable_tomato_clock_text,"35:00");
   
    lv_obj_invalidate(lable_tomato_clock_text);

    


    LV_IMG_DECLARE(ico_start);
    LV_IMG_DECLARE(ico_stop);


    status_icon = lv_img_create(tomato_Screen);

    lv_obj_set_size(status_icon, 32, 32);
     lv_obj_align(status_icon, LV_ALIGN_CENTER, 0, 60);
    
    lv_img_set_src(status_icon, &ico_start);










}