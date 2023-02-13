

#include "setting_Screen.h"
#include "../my_style.h"
#include "ico_imgs.h"

extern lv_obj_t * setting_Screen;



static lv_obj_t * voice_slider_label;
static lv_obj_t * blk_slider_label;
static lv_obj_t * sleep_slider_label;
static lv_obj_t * net_slider_label;


static void blk_slider_event_cb(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target(e);
    char buf[8];
    int blk_value;
    lv_snprintf(buf, sizeof(buf), "%d",(int)lv_slider_get_value(slider));
    //lv_snprintf(buf, sizeof(buf), ":%d%",9);

    blk_value = (int)lv_slider_get_value(slider);
    LV_LOG_USER("voice value is %d",blk_value);



    char* text_value1 = "blk:  ";
    char* text_value[8];
    strcpy(text_value,text_value1);
    strcat(text_value,buf);


    lv_label_set_text(blk_slider_label,text_value);
    lv_obj_add_style(voice_slider_label,&my_nomal_style1,0);

     LV_LOG_USER("change voice value is %d",blk_value);
    lv_obj_align_to(blk_slider_label, slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);
}


static void sleep_slider_event_cb(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target(e);
    char buf[8];
    int sleep_time_value;
    sleep_time_value = (int)lv_slider_get_value(slider);

    if(sleep_time_value == 0){
        lv_snprintf(buf, sizeof(buf), "%d s",5);
    }if(sleep_time_value ==1){
        lv_snprintf(buf, sizeof(buf), "%d s",10);
    }if(sleep_time_value ==2){
        lv_snprintf(buf, sizeof(buf), "%d s",20);
    }if(sleep_time_value ==3){
        lv_snprintf(buf, sizeof(buf), "%d s",30);
    }if(sleep_time_value ==4){
        lv_snprintf(buf, sizeof(buf), "%d min",1);
    }if(sleep_time_value ==5){
        lv_snprintf(buf, sizeof(buf), "%d min",2);
    }




    LV_LOG_USER("voice value is %d",sleep_time_value);



    char* text_value1 = "sleep time:  ";
    char* text_value[8];
    strcpy(text_value,text_value1);
    strcat(text_value,buf);


    lv_label_set_text(sleep_slider_label,text_value);
    lv_obj_add_style(sleep_slider_label,&my_nomal_style1,0);

     LV_LOG_USER("change voice value is %d",sleep_time_value);
    lv_obj_align_to(sleep_slider_label, slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);
}

static void net_slider_event_cb(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target(e);
    char buf[8];
    int net_time_update_value;
    net_time_update_value = (int)lv_slider_get_value(slider);

    if(net_time_update_value == 0){
        lv_snprintf(buf, sizeof(buf), "%d min",5);
    }if(net_time_update_value ==1){
        lv_snprintf(buf, sizeof(buf), "%d min",20);
    }if(net_time_update_value ==2){
        lv_snprintf(buf, sizeof(buf), "%d min",30);
    }if(net_time_update_value ==3){
        lv_snprintf(buf, sizeof(buf), "%d hour",2);
    }if(net_time_update_value ==4){
        lv_snprintf(buf, sizeof(buf), "%d hour",6);
    }if(net_time_update_value ==5){
        lv_snprintf(buf, sizeof(buf), "%d hour",12);
    }




    LV_LOG_USER("voice value is %d",net_time_update_value);



    char* text_value1 = "net update interval :  ";
    char* text_value[8];
    strcpy(text_value,text_value1);
    strcat(text_value,buf);


    lv_label_set_text(net_slider_label,text_value);
    lv_obj_add_style(net_slider_label,&my_nomal_style1,0);

     LV_LOG_USER("change voice value is %d",net_time_update_value);
    lv_obj_align_to(net_slider_label, slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);
}


static void voice_slider_event_cb(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target(e);
    char buf[8];
    int voice_value;
    lv_snprintf(buf, sizeof(buf), "%d",(int)lv_slider_get_value(slider));
    //lv_snprintf(buf, sizeof(buf), ":%d%",9);

    voice_value = (int)lv_slider_get_value(slider);
    LV_LOG_USER("voice value is %d",voice_value);



    char* text_value1 = "vioce:  ";
    char* text_value[8];
    strcpy(text_value,text_value1);
    strcat(text_value,buf);


    lv_label_set_text(voice_slider_label,text_value);
    lv_obj_add_style(voice_slider_label,&my_nomal_style1,0);

     LV_LOG_USER("change voice value is %d",voice_value);
    lv_obj_align_to(voice_slider_label, slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);
}

void ui_setting_Screen(void){


    setting_Screen = lv_obj_create(NULL);

    lv_obj_add_style(setting_Screen,&style,0);
    lv_obj_align(setting_Screen,LV_ALIGN_CENTER,0,0);

    //声音调节
     lv_obj_t * voice_slider = lv_slider_create(setting_Screen);
    lv_obj_align(voice_slider,LV_ALIGN_CENTER,0,-75);
    lv_obj_set_size(voice_slider,120,15);
    lv_slider_set_range(voice_slider,0,5);
    lv_obj_add_event_cb(voice_slider, voice_slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);


    /*Create a label below the slider*/
    voice_slider_label = lv_label_create(setting_Screen);
    lv_label_set_text(voice_slider_label, "voice  : 2 ");
    lv_obj_add_style(voice_slider_label,&my_nomal_style1,0);

    lv_obj_align_to(voice_slider_label, voice_slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);

  //天气更新频率调节
     lv_obj_t * net_slider = lv_slider_create(setting_Screen);
    lv_obj_align(net_slider,LV_ALIGN_CENTER,0,-25);
    lv_obj_set_size(net_slider,180,15);
      lv_slider_set_range(net_slider,0,5);
    lv_obj_add_event_cb(net_slider, net_slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);


    /*Create a label below the slider*/
    net_slider_label = lv_label_create(setting_Screen);
    lv_label_set_text(net_slider_label, "net update interval : 30min");
    lv_obj_add_style(net_slider_label,&my_nomal_style1,0);

    lv_obj_align_to(net_slider_label, net_slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);

    //休眠时间调节
     lv_obj_t * sleep_slider = lv_slider_create(setting_Screen);
    lv_obj_align(sleep_slider,LV_ALIGN_CENTER,0,25);
    lv_obj_set_size(sleep_slider,180,15);
    lv_slider_set_range(sleep_slider,0,5);
    lv_obj_add_event_cb(sleep_slider, sleep_slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);


    /*Create a label below the slider*/
    sleep_slider_label = lv_label_create(setting_Screen);
    lv_label_set_text(sleep_slider_label, "sleep time  :5s");
    lv_obj_add_style(sleep_slider_label,&my_nomal_style1,0);
    lv_obj_align_to(sleep_slider_label, sleep_slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);


  //背光调节
     lv_obj_t * blk_slider = lv_slider_create(setting_Screen);
    lv_obj_align(blk_slider,LV_ALIGN_CENTER,0,75);
    lv_obj_set_size(blk_slider,120,15);
    lv_slider_set_range(blk_slider,0,5);
    lv_obj_add_event_cb(blk_slider, blk_slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);


    /*Create a label below the slider*/
    blk_slider_label = lv_label_create(setting_Screen);
    lv_label_set_text(blk_slider_label, "blk  : 2 ");
    lv_obj_add_style(blk_slider_label,&my_nomal_style1,0);
    lv_obj_align_to(blk_slider_label, blk_slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);




}