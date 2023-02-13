
#include "gui.h"
#include "page_config.h"
#include "my_style.h"
#include "button.h"

uint8_t ui_index ;  // 用来记录当前UI界面位置
uint8_t ui_index_last;//上一次ui的位置

// char tomato_time_text[16];// 整个倒计时 例如 “23:23:10"
volatile int tomato_time_min =35; // 倒计时 分钟
volatile int tomato_time_sec = 0; // 倒计时 秒
volatile bool tomato_process = false;  // 番茄钟状态 工作中和休息中
volatile bool tomato_status = false;  //番茄钟工作状态 暂停 和开始

volatile uint8_t tomato_count =0; // 今天共完成了多少个番茄钟，凌晨四点更新一次

extern Button ok_button;


//GUI 管理
void GUI_Manage(void){

    //reboot_page();

    //alarm_page();
    list_page(2);
    // list_page(2);
    // delay(1000);
    //     delay(1000);
    //     delay(1000);
    //     delay(1000);
    //     delay(1000);
    // list_page(5);
    // delay(1000);
    //     delay(1000);
    //     delay(1000);
    //     delay(1000);

        //weather_page();
        tomato_page();

    // for(int i = 0; i<6; i++){
    //     list_page(i);
    //     delay(1000);
    //     delay(1000);
    //     delay(1000);
    //     delay(1000);
    //     delay(1000);
    // }
    Serial.print("GUI mange\n");
    //main_page();
    //net_page();

    // lv_obj_t *clock_ico_Screen = lv_obj_create(NULL);
    // lv_obj_add_style(clock_ico_Screen,&style,0);
    // lv_obj_align(clock_ico_Screen,LV_ALIGN_CENTER,0,0);

    // lv_obj_t *weather_value_text = lv_label_create(clock_ico_Screen);
    // lv_label_set_text(weather_value_text,"aralm");
    // lv_obj_add_style(weather_value_text,&my_nomal_style1,0);
    // lv_obj_align(weather_value_text, LV_ALIGN_CENTER, 0, 30);

    
    // lv_scr_load_anim(clock_ico_Screen,LV_SCR_LOAD_ANIM_FADE_ON,100,0,false);

}


void tomato_update_time_task(void *p){

    //sprintf(tomato_time_text,"%2d:%2d",tomato_time_min,tomato_time_sec);
     //update_tomato_time(tomato_time_text);
    while(1){
        
        if(--tomato_time_sec<=0){
            tomato_time_sec = 59;

            if(--tomato_time_min<=0){
                tomato_time_min=34;
                }

    }
    //sprintf(tomato_time_text,"%2d:%2d",tomato_time_min,tomato_time_sec);
    //Serial.print("tomato_time_text");
   //Serial.printf(tomato_time_text);
    //Serial.printf("\n");
    update_tomato_time(tomato_time_min,tomato_time_sec);
    vTaskDelay(800);

    if(ok_button.getStatus()==0){
        tomato_status = !tomato_status;
        vTaskDelay(100);
    }
    update_tomato_ico(tomato_status);
        
    }
}


void update_time(void){

    if(--tomato_time_sec<=0){
        tomato_time_sec = 59;
        if(--tomato_time_min<=0){
            tomato_time_min=34;
            //sprintf(tomato_time_text,"%2d:%2d",tomato_time_min,tomato_time_sec);

        }
    }
}
/*
TickType_t xLastWakeTime = xTaskGetTickCount();
        // 如果开启番茄钟
        if(tomato_status){
            // 如果是处于工作中的状态，开始35min的倒计时
            if(tomato_process){
                if(tomato_time_sec<=0){
                    tomato_time_min--;
                    tomato_time_sec =60;
                }
                if(tomato_time_min <=0){
                    //分钟变为0后，就开始休息了，此时
                    tomato_time_min =35;
                    tomato_time_sec = 60;
                    tomato_process =false;
                }else{
                    tomato_time_sec--;
                }
            }else(!tomato_process){
                tomato_time_min =5;
                tomato_time_sec = 60;


            }
        }

*/

//实现开机动画
void root_animation(void){
    reboot_page();
}