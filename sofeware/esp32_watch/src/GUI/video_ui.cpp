

#include "lcd.h"
#include "key.h"

extern TFT_eSPI tft ; 
extern void (*gui_func)(void);//定义函数指针，指向特定函数

extern Bounce2::Button menu_botton;
extern  Bounce2::Button ok_botton;
extern Bounce2::Button next_botton;

bool video_first = false;//第一次的时候做一次清屏

void key_video(void){
    if(menu_botton.pressed()){
        
        tft.setCursor(30,100);
        tft.setTextColor(TFT_WHITE,TFT_WHITE);//设置字体颜色 背景色
        tft.setTextSize(2);

        tft.print("Coming soon!\n");
        tft.fillCircle(120,120,120,TFT_WHITE);
        video_first = false;
        gui_func = show_ui_list;
    }
    
}
void show_ui_video(void){
     if(video_first == false){
        tft.fillScreen(TFT_BLACK);
        video_first = true;
    }
    key_video();
    //tft.fillScreen(TFT_BLACK);
    tft.setCursor(30,100);
    tft.setTextColor(TFT_WHITE,TFT_BLACK);//设置字体颜色 背景色
    tft.setTextSize(2);

    tft.print("Coming soon!\n");
    delay(10);
}