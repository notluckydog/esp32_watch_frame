

#include "lcd.h"
#include "key.h"
#include "pic_ico.h"

extern TFT_eSPI tft ;  
extern TFT_eSprite screen ;

uint8_t list_menu_index = 0; // 二级菜单页面位置
uint8_t list_menu_max = 5;

uint8_t left_arrow_x = 20;
uint8_t left_arrow_y = 90;

uint8_t right_arrow_x = 200;
uint8_t right_arrow_y = 90;

extern Bounce2::Button menu_botton;
extern  Bounce2::Button ok_botton;
extern Bounce2::Button next_botton;

extern void (*gui_func)(void);//定义函数指针，指向特定函数

bool list_first = false;
//按键处理函数
void list_ui_key_hander(void){
    if(next_botton.pressed()){
        Serial.printf("the next button is pressed!\n");
        list_menu_index+=1;
        if(list_menu_index >list_menu_max){list_menu_index=0;};
        Serial.printf("ui will be changed to list_ui %d\n",list_menu_index);
        for(right_arrow_x;right_arrow_x<210;right_arrow_x++){
            showImage(right_arrow_x,right_arrow_y,30,60,gImage_right_arrow_ico);
        }

        for(right_arrow_x;right_arrow_x>190;right_arrow_x--){
            showImage(right_arrow_x,right_arrow_y,30,60,gImage_right_arrow_ico);
        }
    }

    if(menu_botton.pressed()){
        Serial.printf("the next button is pressed!\n");
        Serial.print("ui will be changed to main_ui\n");

        tft.fillScreen(TFT_WHITE);
        //tft.fillCircle(120,120,120,TFT_WHITE);
        list_first  = false;
        gui_func = show_ui_home;
        /*list_menu_index-=1;
        if(list_menu_index <=0){list_menu_index=list_menu_max;};

        for(left_arrow_x;left_arrow_x>=10;left_arrow_x--){
            showImage(left_arrow_x,left_arrow_y,30,60,gImage_left_arrow_ico);
        }

         for(left_arrow_x;left_arrow_x<20;left_arrow_x++){
            showImage(left_arrow_x,left_arrow_y,30,60,gImage_left_arrow_ico);
        }
        */
    }
    //ok按键被按下，进入第三级页面
    if(ok_botton.pressed()){
        switch(list_menu_index){
            case 0:
                //天气
                //tft.fillScreen(TFT_BLACK);
                //tft.fillRect(88,88,64,64,TFT_BLACK);
                //showImage(88,88,65,65,gImage_black_ico);
                // tft.fillCircle(120,120,120,TFT_BLACK);
                // tft.drawRect(77,77,100,100,TFT_BLACK);
                // tft.fillScreen(TFT_BLACK);
                delay(10);
                gui_func = show_ui_weather;
                break;
            case 1:
                //计时器
                //tft.fillScreen(TFT_BLACK);
                //tft.fillRect(88,88,64,64,TFT_BLACK);
                //showImage(88,88,65,65,gImage_black_ico);
                // tft.fillCircle(120,120,120,TFT_BLACK);
                // tft.drawRect(77,77,100,100,TFT_BLACK);
                // tft.fillScreen(TFT_BLACK);
                delay(10);
                gui_func = show_ui_clock;
                break;
            case 2:
                //播放视频
                //tft.fillScreen(TFT_BLACK);
                //tft.fillRect(88,88,64,64,TFT_BLACK);
                
                delay(10);
                gui_func = show_ui_video;
                //showImage(88,88,65,65,gImage_black_ico);
                // tft.fillCircle(120,120,120,TFT_BLACK);
                // tft.drawRect(77,77,100,100,TFT_BLACK);
                // tft.fillScreen(TFT_BLACK);
                break;
            case 3:
                //游戏
                //tft.fillScreen(TFT_BLACK);
                //tft.fillRect(88,88,64,64,TFT_BLACK);
                
                delay(10);
                gui_func = show_game_ui;
                //showImage(88,88,65,65,gImage_black_ico);
                // tft.fillCircle(120,120,120,TFT_BLACK);
                // tft.drawRect(77,77,100,100,TFT_BLACK);
                // tft.fillScreen(TFT_BLACK);
                break;
            case 4:
                //配网
                //tft.fillScreen(TFT_BLACK);
                //tft.fillRect(88,88,64,64,TFT_BLACK);
                
                delay(10);
                gui_func = show_net_ui;
                //showImage(88,88,65,65,gImage_black_ico);
                // tft.fillCircle(120,120,120,TFT_BLACK);
                // tft.drawRect(77,77,100,100,TFT_BLACK);
                // tft.fillScreen(TFT_BLACK);
                break;
            case 5:
                //设置页面
                //tft.fillRect(88,88,64,64,TFT_BLACK);
                // tft.fillCircle(120,120,120,TFT_BLACK);
                // tft.drawRect(77,77,100,100,TFT_BLACK);
                //tft.fillScreen(TFT_BLACK);
                //showImage(88,88,65,65,gImage_black_ico);
                
                delay(10);
                gui_func = show_ui_setup;
                break;
        }
        tft.fillScreen(TFT_BLACK);
        showImage(88,88,65,65,gImage_black_ico);
        list_first  = false;
        delay(10);
    }
}
//@function_name: show_ui_list
//@function_function:  展示二级页面，列表选择
//@Input_variable:      输入变量名及格式
//@output_variable：  输出变量及类型
//@version ：V1.0     版本
//@Last_modification_time:最后修改时间
void show_ui_list(void){

    //
    if(list_first == false){
        tft.fillScreen(TFT_WHITE);
        list_first  = true;
    }
    delay(10);
    showImage(right_arrow_x,right_arrow_y,30,60,gImage_right_arrow_ico);
    list_ui_key_hander();
    
    switch (list_menu_index)
    {
    case 0:
        showImage(88,88,64,64,gImage_weather_ico);
        break;
    case 1:
        showImage(88,88,64,64,gImage_clock_ico);
        break;

    case 2:
        showImage(88,88,64,64,gImage_video_ico);
        break;
    
    case 3:
        showImage(88,88,64,64,gImage_game_ico);
        break;
    case 4:
        showImage(88,88,64,64,gImage_net_ico);
        break;

    case 5:
        showImage(88,88,64,64,gImage_setup_ico);
        break;

    
    default:
        break;
    }
}