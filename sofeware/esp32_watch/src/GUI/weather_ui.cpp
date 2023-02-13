


#include "lcd.h"
#include "key.h"
#include "weather.h"
#include "weather_pic.h"
#include "pic_ico.h"


extern TFT_eSPI tft;
extern TFT_eSprite screen ;

extern Bounce2::Button menu_botton;
extern  Bounce2::Button ok_botton;
extern Bounce2::Button next_botton;

extern weatherInfo todayWeather;
extern weatherInfo nextdayWeather;
extern weatherInfo afterdayWeather;

extern void (*gui_func)(void);//定义函数指针，指向特定函数

char temp_today_range[16];
char temp_tomorrow_range[16];
char temp_after_range[16];

uint8_t weather_ui_update_flag = 0;//解决刷屏问题，1表示需要刷新

weatherInfo *showWeather_Info = &todayWeather;//结构体指针，用来保存显示在画面画面上内容

uint8_t weather_ui_index =0;//天气详情页 今天、明天、后天
uint8_t weather_ui_last_index = 1;//上一次天气页面，不一致是为了第一次进来的时候刷新一次

//按键处理函数
void weather_ui_key_hander(void){
    if(next_botton.pressed()){
        weather_ui_index++;
        //weather_ui_update_flag = !weather_ui_update_flag;
        Serial.print("next bt is pressed!\n");
        
        if(weather_ui_index>2){weather_ui_index=0;}
        Serial.printf("ui will be changed to %d\n",weather_ui_index);

        uint8_t down_arrow_y =190;
        for(down_arrow_y;down_arrow_y<210;down_arrow_y++){
            showImage(90,down_arrow_y,60,30,gImage_down_arrow_ico);
        }

         for(down_arrow_y;down_arrow_y>190;down_arrow_y--){
            showImage(90,down_arrow_y,60,30,gImage_down_arrow_ico);
        }
    }
    //返回二级菜单选择界面
    if(menu_botton.pressed()){
       //tft.fillScreen(TFT_BLACK);
        tft.fillCircle(120,120,120,TFT_WHITE);
        delay(10);
        gui_func = show_ui_list;
    }

}

//@function_name: show_ui_weather
//@function_function:  显示天气详情页
//@Input_variable:      输入变量名及格式
//@output_variable：  输出变量及类型
//@version ：V1.0     版本
//@Last_modification_time:最后修改时间
void show_ui_weather(void){

    //tft.fillScreen(TFT_BLACK);
    //当按下下一个按键的时候，就开始显示不同的内容
    if(weather_ui_index!=weather_ui_last_index){
        tft.fillScreen(TFT_BLACK);
        weather_ui_last_index=weather_ui_index;
        switch (weather_ui_index)
            {
                case 0:
                    //显示今天的天气详情
                    showWeather_Info = &todayWeather;
                    Serial.print("show today weather!\n");
                    /* code */
                    break;
                case 1:
                    //显示明天的天气详情
                    showWeather_Info = &nextdayWeather;
                    Serial.print("show nextday weather!\n");
                    break;
                case 2:
                    //显示后天的天气详情
                    showWeather_Info = &afterdayWeather;
                    Serial.print("show afterday weather!\n");
                default:
                    showWeather_Info = &todayWeather;
                    Serial.print("show today weather!\n");
                    break;
            }
            //显示向下箭头
            showImage(90,190,60,30,gImage_down_arrow_ico);
            //显示城市
            tft.setCursor(100,20);
            tft.setTextColor(TFT_WHITE,TFT_BLACK);//设置字体颜色 背景色
            tft.setTextSize(1);
            tft.print("Shenzhen");
            Serial.print("1");

            //显示时间
            tft.setCursor(60,40);
            tft.setTextColor(TFT_WHITE,TFT_BLACK);//设置字体颜色 背景色
            tft.setTextSize(2);
            tft.print(showWeather_Info->date);
            Serial.print("2");


            //显示天气图片
            showImage(36,110,48,48,gImage_weather_test_ico);
            Serial.print("3");


            //显示最高温度与最低温度
            tft.setCursor(140,100);
            tft.setTextColor(TFT_WHITE,TFT_BLACK);//设置字体颜色 背景色
            tft.setTextSize(2);
            tft.printf("%sC~%sC", showWeather_Info->temp_hign,showWeather_Info->temp_low);
            Serial.print("4");

            //显示湿度
            tft.setCursor(140,120);
            tft.setTextColor(TFT_WHITE,TFT_BLACK);//设置字体颜色 背景色
            tft.setTextSize(2);
            tft.printf("%s%%", showWeather_Info->hum);
            Serial.print("5");


            //显示风向
            tft.setCursor(140,140);
            tft.setTextColor(TFT_WHITE,TFT_BLACK);//设置字体颜色 背景色
            tft.setTextSize(2);
            tft.printf("%s %s", showWeather_Info->hum,showWeather_Info->wind_scale);
            Serial.print("6");

            
            delay(100);
    }
            weather_ui_key_hander();
            delay(10);
            

            
}
        //tft.pushSprite(0,0);
    
        /*
        tft.fillScreen(TFT_BLACK);
        screen.setTextDatum(MC_DATUM);
        screen.drawString("Sprite", 140, 120, 2);
        screen.pushSprite(-40, -40);

        screen.pushSprite(0, 0);

        screen.pushSprite(100, 30);

        screen.pushSprite(20, 1200);*/







/*




*/

