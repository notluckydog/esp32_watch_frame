#include <Arduino.h>

//#include <FastLED.h>

#include <WiFi.h>

#include "button.h"
#include "beep.h"

#include "SetWiFi.h"

#include "my_weather.h"

#include "ntp_time.h"

//#include "my_SD.h"

#include <lvgl.h>
//#include "lv_examples.h"
#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>

#include "ui/my_style.h"

#include "ui/ui_manage.h"

#include "my_wifi.h"


//#include "sd_card.h"

// #include "FS.h"
// #include "SD.h"
// #include "SPI.h"

// #include "SD_test.h"

#include "my_SD.h"
//#include "SD.h"


#define BEEP_PIN 32

uint8_t BT_MENU_PIN=16;
uint8_t BT_OK_PIN=21;
uint8_t BT_NEXT_PIN=25;


uint8_t freq = 5000;
uint8_t ledChannel =0;
uint8_t resolution = 8;
uint8_t dutyCycle = 100;







lv_obj_t * a_ui;
lv_obj_t * main_Screen;//主页面，home页
lv_obj_t * list_Screen;//二级菜单选择页面，
lv_obj_t * weather_ico_Screen;  //二级选择页面 天气
lv_obj_t * clock_ico_Screen; // 二级选择页面 计时器、
lv_obj_t * tomato_ico_Screen;  //二级选择页面 番茄钟
lv_obj_t * aralm_ico_Screen; //二级选择页面，闹钟
lv_obj_t * setting_ico_Screen; //二级选择页面 设置
lv_obj_t*  net_ico_Screen;  // 二级页面 配网二维码
lv_obj_t * weather_Screen;    //三级页面  天气
lv_obj_t * clock_Screen;   // 三级页面 计时器
lv_obj_t * aralm_Screen;  //三级页面 闹钟，暂不提供闹钟设置
lv_obj_t * tomato_Screen; //三级页面 番茄钟 35min/10min
lv_obj_t * setting_Screen; // 三级页面 设置 ，暂时只提供选择，不做具体功能
lv_obj_t * net_Screen;//三级页面 配网二维码
lv_obj_t * logo_Screen;

//SdCard tf;

struct tm timeinfo;


bool setWiFi_Flag = false;

// uint8_t ui_index = 0;// 用来记录当前UI所在的位置
// uint8_t ui_index_last =0; // 用来记录上一次UI所在的位置
// extern  Menu_table table[10] ;

Button menu_button(BT_MENU_PIN);
Button ok_button(BT_NEXT_PIN);
Button next_button(BT_OK_PIN);


Beep beep(BEEP_PIN,freq,ledChannel);



//按键扫描函数
uint8_t key_scan(){
  //menu按键被按下
    if(menu_button.getStatus()==1){
      return 1;
    }

  //ok按键被按下
  if(ok_button.getStatus()==1){
      return 2;
    }

  //next按键被按下
  if(menu_button.getStatus()==1){
      return 3;
    }

    return 0;

}
//按键状态更新函数
static void key_read(lv_indev_drv_t * indev_driver, lv_indev_data_t * data){
    static uint32_t last_key = 0;
	  uint32_t act_key = key_scan();

    if(act_key != 0) {
      data->state = LV_INDEV_STATE_PR;
	    switch(act_key) {
	        case 1:
              //menu按键
	            //act_key = LV_KEY_PREV;
	            //data->state = LV_INDEV_STATE_PRESSED;	
	            break;
              //OK 按键
	        case 2:
	            act_key = LV_KEY_NEXT;
	            //data->state = LV_INDEV_STATE_RELEASED;
	            //data->enc_diff++;
	            break;
              //next按键
	        case 3:
	            act_key = LV_KEY_ENTER;
	            //data->state = LV_INDEV_STATE_RELEASED;
	            //data->enc_diff--;
	            break;
	    }
	    last_key = act_key;
	}else{
    data->state = LV_INDEV_STATE_REL;
  }
	data->key = last_key;

  //return false;


}




//连接wifi
void my_connect_wifi(){
     WiFi.begin("UTF-8", "2664856778"); //连接网络
  while (WiFi.status() != WL_CONNECTED) //等待网络连接成功
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected!");

  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); //打印模块IP


}

/*   硬件初始化 */
void BSP_init(){
  //beep.setDutyCycle(100);
  menu_button.init();
  ok_button.init();
  next_button.init();
  my_connect_wifi();
  //getLocalTime();

  MyDispalyInit();
  ui_init();

  Serial.print("hardware init succuss! \n\n");
  //tf.init();
}

//配网
void setWifi(){
    initBasic();
    initSoftAP();
    initWebServer();
    initDNS();

    while(setWiFi_Flag == true) {
    server.handleClient();
    dnsServer.processNextRequest();
    if(WiFi.status() == WL_CONNECTED) {
      server.stop();
      setWiFi_Flag = true;
    }
  }
}







void setup() {
  // put your setup code here, to run once:

 
  delay(1000);
  Serial.begin(115200);


  BSP_init();
  //lv_example_btn_1();
  


}

// char time_text1[10];
// strftime(time_text1,sizeof(time_text1),"%H:%M:%S",&timeinfo);
void loop() {
  
  
  Serial.print("very good !\n\n");
  delay(1000);

  //SD_TEST();
  lv_timer_handler(); /* let the GUI do its work */
  //button_task();
  //ui_manage();

  // if(digitalRead(BT_NEXT_PIN)==0){
  //       delay(30);
  //           if(digitalRead(BT_NEXT_PIN)==1){
  //               //delay(1000);
                 
  //               Serial.print("bt next is pressed!\n\n");
  //               lv_scr_load_anim(tomato_ico_Screen,LV_SCR_LOAD_ANIM_FADE_ON,100,0,false);
                
  //           }
  //       }

  
  delay( 5 );



  



}