

#include "lcd.h"
#include "SetWiFi.h"
#include "key.h"

extern TFT_eSPI tft ;  
bool setWiFi_Flag = false; // 标识是否需要配网
extern Bounce2::Button menu_botton;
extern  Bounce2::Button ok_botton;
extern Bounce2::Button next_botton;

extern void (*gui_func)(void);//定义函数指针，指向特定函数

bool net_first = false;

//按键处理函数
void net_ui_key_hander(void){
    if(menu_botton.pressed()){
        tft.fillCircle(120,120,120,TFT_WHITE);
        delay(10);
        net_first = false;
        gui_func = show_ui_list;
    }
}

//配网界面，配网完成后自动重启
void show_net_ui(void){
    if(net_first == false){
        tft.fillScreen(TFT_BLACK);
        net_first = true;
    }
    net_ui_key_hander();
    //tft.fillScreen(TFT_BLACK);
    tft.setCursor(20,100);

    tft.setTextColor(TFT_WHITE,TFT_BLACK);//设置字体颜色 背景色
    tft.setTextSize(2);
    tft.print("please connected WIFi");

    tft.setCursor(30,120);
    tft.print("HERWATCH");
    setWiFi_Flag = true;
    setWifi();

}