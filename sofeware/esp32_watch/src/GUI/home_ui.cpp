

#include "lcd.h"
#include "astronaut.h"
#include "star.h"
#include "key.h"


extern struct tm timeinfo;

uint8_t current_hour =8;
uint8_t current_min =8;

bool home_first = false;

String week[]={
    "SUN","MON","TUE","WED","THUR","FRI","SAT",
};

//char *day_str = "2022-02-10";//用来保存日期
//String week = "SUN";
//String date = "2023-02-02";

extern TFT_eSPI tft;
extern Bounce2::Button menu_botton;
extern  Bounce2::Button ok_botton;
extern Bounce2::Button next_botton;

extern void (*gui_func)(void);//定义函数指针，指向特定函数
//@function_name: home_ui_key_hander
//@function_function:  主页面按键处理函数
//@Input_variable:      输入变量名及格式
//@output_variable：  输出变量及类型
//@version ：V1.0     版本
//@Last_modification_time:最后修改时间
void home_ui_key_hander(void){
    //有任何一个按键被按下时切换到二级列表选择
    if(ok_botton.pressed()||menu_botton.pressed()||next_botton.pressed()){
        
        tft.fillCircle(120,120,120,TFT_WHITE);
        delay(20);
        home_first = false;
        gui_func =show_ui_list;
        
    }
}
//@function_name: show_ui_home
//@function_function:  展示主页面
//@Input_variable:      输入变量名及格式
//@output_variable：  输出变量及类型
//@version ：V1.0     版本
//@Last_modification_time:最后修改时间
void show_ui_home(void){

    if(home_first ==false){
        home_first = true;
        tft.fillScreen(TFT_WHITE);
    }
    //显示时间
    tft.setCursor(130,70);
    tft.setTextColor(TFT_GREEN,TFT_WHITE);//设置字体颜色 背景色
    //tft.setTextFont(LOAD_FONT4);
    tft.setTextSize(6);

    if(timeinfo.tm_hour<10){
        tft.print(0);
        tft.print(timeinfo.tm_hour); 
    }else{
        tft.print(timeinfo.tm_hour); 
    }
    //tft.print("");

    tft.setCursor(130,120);
    tft.setTextSize(6);
    if(timeinfo.tm_min<10){
        tft.print(0);
        tft.print(timeinfo.tm_min); 
    }else{
        tft.print(timeinfo.tm_min); 
    }

    //显示星期
    tft.setCursor(110,200);
    tft.setTextSize(2);
    tft.setTextColor(TFT_BLACK,TFT_WHITE);
    tft.print(week[timeinfo.tm_wday]);

    //显示日期
    //sprintf(day_str,"%d-%d-%d",timeinfo.tm_year,timeinfo.tm_mon,timeinfo.tm_mday);
    tft.setCursor(80,30);
    tft.setTextSize(2);
    tft.setTextColor(TFT_BLACK,TFT_WHITE);
    tft.printf("%d-%d-%d",timeinfo.tm_year,timeinfo.tm_mon,timeinfo.tm_mday);


    //显示天气图标
    //showImage()

    //画两条线
    //tft.setCursor(30,0);
    
    tft.drawLine(0,60,240,60,TFT_BLACK);
    //tft.drawLine(120,0,120,30,TFT_BLACK);

    tft.drawLine(0,180,240,180,TFT_BLACK);

    showImage(10,70,100,100,gImage_tu_plane_ico);

    home_ui_key_hander();//按键处理函数


}


//绘制太空人动画
void show_astronaut_anim(void){
    showImage(110,110,50,38,gImage_1);
    delay(500);
    showImage(110,110,50,38,gImage_2);
    delay(500);
    showImage(110,110,50,38,gImage_3);
    delay(500);
    showImage(110,110,50,38,gImage_4);
    delay(500);
    showImage(110,110,50,38,gImage_5);
    delay(500);
    showImage(110,110,50,38,gImage_6);
    delay(50);
    showImage(110,110,50,38,gImage_7);
    delay(500);
    showImage(110,110,50,38,gImage_8);
    delay(500);
    showImage(110,110,50,38,gImage_9);
    delay(500);
    showImage(110,110,50,38,gImage_10);
    delay(500);
}