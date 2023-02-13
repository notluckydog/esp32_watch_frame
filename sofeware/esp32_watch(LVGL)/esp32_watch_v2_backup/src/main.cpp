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

lv_indev_t* indev_keypad;



#define TFT_GREY 0x5AEB

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

/*Change to your screen resolution*/
static const uint16_t screenWidth  = 240;
static const uint16_t screenHeight = 240;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * 10 ];

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

//TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */

#if LV_USE_LOG != 0
/* Serial debugging */
void my_print(const char * buf)
{
    Serial.printf(buf);
    Serial.flush();
}
#endif

/* Display flushing */
void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p )
{
    uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );

    tft.startWrite();
    tft.setAddrWindow( area->x1, area->y1, w, h );
    tft.pushColors( ( uint16_t * )&color_p->full, w * h, true );
    tft.endWrite();

    lv_disp_flush_ready( disp );
}

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


//LVGL 初始化
void MyDispalyInit(){
    lv_init();

#if LV_USE_LOG != 0
    lv_log_register_print_cb( my_print ); /* register print function for debugging */
#endif

    tft.begin();          /* TFT init */
    tft.setRotation( 0 ); /* Landscape orientation, flipped */
    tft.fillScreen(TFT_BLACK);//清屏

    lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * 10 );

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init( &disp_drv );
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    disp_drv.sw_rotate = 1;
    disp_drv.rotated = LV_DISP_ROT_180;
    lv_disp_drv_register( &disp_drv );

    /*Initialize the (dummy) input device driver*/
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init( &indev_drv );
    //实体按键初始化
    //lv_port_indev_init();
    //indev_drv.type = LV_INDEV_TYPE_POINTER;
    //ndev_drv.read_cb = my_touchpad_read;
    indev_drv.type = LV_INDEV_TYPE_KEYPAD;
    //indev_drv.read_cb = key_read;
    indev_keypad = lv_indev_drv_register( &indev_drv );

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

char time_text1[10];
void loop() {
  
  
  Serial.print("very good !\n\n");
//   delay(1000);

  //SD_TEST();
  //lv_timer_handler(); /* let the GUI do its work */
  //button_task();
  //ui_manage();

  getLocalTime();
  
  strftime(time_text1,sizeof(time_text1),"%H:%M:%S",&timeinfo);
  Serial.printf("time_text will be \n\n");
  Serial.print(time_text1);
  Serial.print("\n");
  delay(1000);
  delay(1000);
  delay(1000);
  delay(1000);
  delay(1000);
  delay( 5 );



  



}