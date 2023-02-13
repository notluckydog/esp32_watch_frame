

#include "lcd.h"
#include "key.h"
#include "pic_ico.h"

extern TFT_eSPI tft ; 
extern Bounce2::Button menu_botton;
extern  Bounce2::Button ok_botton;
extern Bounce2::Button next_botton;

extern void (*gui_func)(void);//定义函数指针，指向特定函数

bool clock_run_flag = false;//ture 表示开始计时，反之则是停止计时

uint32_t clock_hour = 0;
uint32_t clock_min = 0;
uint32_t clock_sec = 0;

bool clock_first = false;//第一次的时候做一次清屏

unsigned long key_previousMilis =0;//使用mills函数来实现精准计时，定时器功能
unsigned long gui_previousMilis =0;
//按键处理函数
void clock_ui_key_hander(void){
    

    //当按键被按下时，暂停或者开始计时
    if(ok_botton.pressed()){
        clock_run_flag = !clock_run_flag;
        Serial.print("ok button is pressed!\n");
        if(clock_run_flag){
            Serial.print("count will start!\n");
        }else{
            Serial.print("count will stop!\n");
        }
    }
    //重新开始计时
    if(next_botton.pressed()){
        clock_hour =0;
        clock_min = 0;
        clock_sec = 0;
        clock_run_flag = false;
        Serial.print("count will be reseted!\n");
    }
    //返回二级菜单选择页面
    if(menu_botton.pressed()){
        clock_first = false;
        tft.fillCircle(120,120,120,TFT_WHITE);
        gui_func = show_ui_list;
    }

}

void colck_time_update(void){
    if(clock_run_flag){
        
        if(++clock_sec ==60){
            clock_sec =0;
            clock_min =clock_min+1;
            if(clock_min==60){
                clock_min=0;
                clock_hour +=1;
                if(clock_hour ==24){
                    clock_hour =0;
                }
            }
        }
    }
    
}

void show_ui_clock(void){

    if(clock_first == false){
        tft.fillScreen(TFT_BLACK);
        clock_first = true;
    }
    unsigned long currentMillis = millis(); // store the current time

    //20ms更新一次按键状态
    if(currentMillis-key_previousMilis >=10){
        clock_ui_key_hander();
        key_previousMilis = currentMillis;
    }
    if(currentMillis-gui_previousMilis >=1000){
        //tft.fillScreen(TFT_BLACK);
        colck_time_update();
        gui_previousMilis = currentMillis;


        tft.setCursor(30,100);
        tft.setTextColor(TFT_WHITE,TFT_BLACK);//设置字体颜色 背景色
        tft.setTextSize(4);

        if(clock_hour<10){
            tft.print("0");
            tft.print(clock_hour);
        }else{
            tft.print(clock_hour);
        }
        tft.print(":");
        if(clock_min<10){
            tft.print("0");
            tft.print(clock_min);
        }else{
            tft.print(clock_min);
        }
        tft.print(":");
        if(clock_sec<10){
            tft.print("0");
            tft.print(clock_sec);
        }else{
            tft.print(clock_sec);
        }
        

        if(clock_run_flag){
            //32X32
            showImage(104,180,32,32,gImage_start_ico);
        }else{
            showImage(104,180,32,32,gImage_stop_ico);
        }
    }
    

    
    
    
}