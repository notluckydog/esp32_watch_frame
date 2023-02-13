


#include "lcd.h"
#include "key.h"

extern Bounce2::Button menu_botton;
extern  Bounce2::Button ok_botton;
extern Bounce2::Button next_botton;

extern uint32_t net_update_frequency ;
extern uint32_t Backlight_frequency ;

extern  bool aralm_bt ; //是否开启闹钟

extern TFT_eSPI tft ; 

extern void (*gui_func)(void);//定义函数指针，指向特定函数


uint8_t fu_tag_x = 20;
uint8_t fu_tag_y = 30;

//闹钟开关


//网络更新
uint8_t net_freq_count = 0;
uint8_t net_freq_x = 20;  // 进度条的x轴

//背光
uint8_t blk_count = 0;
uint8_t blk_x = 20;  // 进度条的x轴

bool setup_first = false;

uint8_t setup_index = 0; //选择

void setup_key_hander(void){
    if(menu_botton.pressed()){
        tft.fillCircle(120,120,120,TFT_WHITE);
        setup_first = false;
        delay(10);
        gui_func = show_ui_list;
    }
    //切换焦点
    if(next_botton.pressed()){
        setup_index +=1;
        tft.drawRect(20,fu_tag_y,200,60,TFT_BLACK);
        
        if(setup_index >2){
            setup_index = 0;
            fu_tag_y = 30;
        }else{
            fu_tag_y = fu_tag_y +60;
        }
        
        Serial.printf("next bt pressed, fu_tag_y = %d\n",fu_tag_y);
        
    }

    //增加数量
    if(ok_botton.pressed()){
        switch (setup_index)
        {
        case 0:
            //网络更新时间
            net_freq_count +=1;
            if(net_freq_count>4){
                net_freq_count = 0;
                net_freq_x = 20;
            }
            tft.fillRect(net_freq_x,60,10,20,TFT_BLACK);
            tft.fillRect(net_freq_x,75,10,20,TFT_BLACK);

            net_freq_x = net_freq_x +50;
            
            Serial.printf("ok bt pressed, net_freq_x = %d\n",net_freq_x);
            break;

        case 1:
            //背光更新
            blk_count +=1;
            if(blk_count>4){
                blk_count = 0;
                blk_x = 20;
            }
            tft.fillRect(blk_x,120,10,15,TFT_BLACK);
            tft.fillRect(blk_x,135,10,5,TFT_BLACK);
            blk_x = blk_x +50;
            Serial.printf("ok bt pressed, blk_x = %d\n",blk_x);
            
            break;
        case 2:
            //闹钟开关
            aralm_bt = !aralm_bt;
            break;
        
        default:
            break;
        }
    }
}

void show_ui_setup(void){
    
    if(setup_first == false){
        tft.fillScreen(TFT_BLACK);
        setup_first = true;
    }
    setup_key_hander();
    //tft.fillScreen(TFT_BLACK);
    //绘制框，表示焦点
    tft.drawRect(20,fu_tag_y,200,60,TFT_BLUE);

    //网络信息更新频率
    tft.setCursor(70,40);
    tft.setTextColor(TFT_WHITE,TFT_BLACK);//设置字体颜色 背景色
    tft.setTextSize(2);

    tft.print("Net_freq:");

    //进度条绘制
    tft.fillRect(20,70,200,5,TFT_WHITE);
    tft.fillRect(net_freq_x,60,10,20,TFT_WHITE);

    //背光
    tft.setCursor(70,100);
    tft.setTextColor(TFT_WHITE,TFT_BLACK);//设置字体颜色 背景色
    tft.setTextSize(2);

    tft.print("BLKlight:");

    //进度条绘制
    tft.fillRect(20,130,200,5,TFT_WHITE);
    tft.fillRect(blk_x,120,10,20,TFT_WHITE);

    //闹钟开关
    tft.setCursor(70,160);
    tft.setTextColor(TFT_WHITE,TFT_BLACK);//设置字体颜色 背景色
    tft.setTextSize(2);

    tft.print("AlarmSW:");

    if(aralm_bt){
        //开启
        tft.fillRect(110,190,20,20,TFT_GREY);
        tft.fillCircle(110,200,10,TFT_GREY);
        tft.fillCircle(130,200,10,TFT_BLUE);

    }else{
        tft.fillRect(110,190,20,20,TFT_GREY);
        tft.fillCircle(110,200,10,TFT_BLUE);
        tft.fillCircle(130,200,10,TFT_GREY);
    }
    delay(10);

    
    

}