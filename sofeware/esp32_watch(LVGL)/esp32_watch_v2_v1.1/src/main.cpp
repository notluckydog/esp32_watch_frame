#include <Arduino.h>

//#include <FastLED.h>

#include <WiFi.h>

#include "button.h"
#include "beep.h"

#include "SetWiFi.h"

#include "my_weather.h"

#include "ntp_time.h"

//#include "my_SD.h"


#include "ui/ui_init.h"

#include "ui/my_style.h"

#include "ui/ui_manage.h"

#include "my_wifi.h"


//#include "sd_card.h"

// #include "FS.h"
// #include "SD.h"
// #include "SPI.h"

// #include "SD_test.h"

//#include "my_SD.h"
//#include "SD.h"


#define BEEP_PIN 32

uint8_t BT_MENU_PIN=16;
uint8_t BT_OK_PIN=21;
uint8_t BT_NEXT_PIN=25;

uint32_t freq = 5000;
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

struct tm timeinfo;   //当前时间
struct tm aralm_timeinfo;  //设定的闹钟时间

bool setWiFi_Flag = false; // 标识是否需要配网，当第一次开机和ui进入配网页面的时候需要重新配网

time_t last_time;

Beep beep(BEEP_PIN,freq,ledChannel);

/*创建任务句柄   */
static TaskHandle_t AppTaskCreate_Handle = NULL;  // 创建任务 任务句柄
static TaskHandle_t GUI_task_handle = NULL;   // GUI 任务
static TaskHandle_t GUI_time_update_task_handle = NULL;  //LVGL 主页面更新时间 例如20:20:20
static TaskHandle_t GUI_day_update_task_handle = NULL; // LVGL 主页面日期更新 2022-10-10
static TaskHandle_t GUI_weekday_update_task_handle = NULL;  //LVGL 主页面 星期更新
static TaskHandle_t GUI_weather_update_task_handle = NULL;  //LVGL 主页面 天气情况更新
static TaskHandle_t GUI_three_weather_update_task_handle = NULL;  // 次级页面 近三天天气状况更新
static TaskHandle_t GUI_countting_update_task_handle = NULL;  // 次级页面 计时器任务
static TaskHandle_t GUI_aralm_update_task_handle = NULL;   //闹钟任务


//void GUI_time_update_task(void *p);
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

//断开网络
void my_disconnect_wifi(){
    WiFi.disconnect(true);
    WiFi.mode(WIFI_OFF);
    Serial.println("WiFi disconnected!");

}


void GUI_Task(void *p){
  while(1){

    lv_timer_handler(); /* let the GUI do its work */
  //button_task();
  //ui_manage();

  vTaskDelay(5);
    //delay( 5 );
  }
  
  
}

//用来每一个小时更新一次天气、时间等信息
void net_info_update_task(void *p){

      while(1){
        
        double seconds = difftime(mktime(&timeinfo),last_time);
        if(seconds<30){
            my_connect_wifi();
            getLocalTime();
            //getWeatherInfo();
            getThreeDayWeather();
            my_disconnect_wifi();

        };
      }

}

//设置闹钟
void set_aralm(){
      aralm_timeinfo.tm_hour = 10;
      aralm_timeinfo.tm_min  = 20;
      aralm_timeinfo.tm_sec  = 00;
}
//闹钟任务，到了时间就
void aralm_task(void *p){

  while(1){
    if(timeinfo.tm_hour ==aralm_timeinfo.tm_hour&&timeinfo.tm_min==aralm_timeinfo.tm_min){
      beep.setDutyCycle(100);
    }
  }
}


/*   硬件初始化 */
void BSP_init(){
  //beep.setDutyCycle(100);
  pinMode(BT_MENU_PIN,INPUT_PULLUP);
  pinMode(BT_NEXT_PIN,INPUT_PULLUP);
  pinMode(BT_OK_PIN,INPUT_PULLUP);
  // menu_button.init();
  // ok_button.init();
  // next_button.init();
  my_connect_wifi();
  getLocalTime();
  //getWeatherInfo();
  getThreeDayWeather();
  my_disconnect_wifi();

  last_time = time(0);

  MyDispalyInit();
  ui_init();


  Serial.print("hardware init succuss! \n\n");
  //tf.init();
}




void setup() {
  // put your setup code here, to run once:

 
  delay(1000);
  Serial.begin(115200);


  BSP_init();

  xTaskCreate(GUI_Task,"time update",1024*20,NULL,1,NULL);
  xTaskCreate(GUI_time_update_task,"time update",1024*4,NULL,1,NULL);
  //lv_example_btn_1();
  


}

// char time_text1[10];
// strftime(time_text1,sizeof(time_text1),"%H:%M:%S",&timeinfo);
void loop() {
  
  
  // Serial.print("very good !\n\n");
  // delay(1000);

  // //SD_TEST();
  // lv_timer_handler(); /* let the GUI do its work */
  // //button_task();
  // //ui_manage();

  // delay( 5 );



  



}