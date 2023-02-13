

#include <Arduino.h>
#include "key.h"
#include "lcd.h"
#include "ntp_time.h"
#include "WiFi.h"
#include <Preferences.h>

#include "weather.h"

struct tm timeinfo;
const char *ntpServer = "time1.aliyun.com";
const long gmtOffset_sec = 8 * 3600;
const int daylightOffset_sec = 0;

extern TFT_eSPI tft;
extern TFT_eSprite screen ;

Preferences preferences; 

String now_ssid ,now_pass,now_city_code;

uint8_t WIDTH = 240;
uint8_t HEIGHT = 240;

uint32_t net_update_frequency = 60*60*1000;
uint32_t Backlight_frequency = 1;

bool aralm_bt = false; //是否开启闹钟


unsigned long net_preMillis = 0; //网络更新时间

void (*gui_func)(void);//定义函数指针，指向特定函数



//从FLSAH中获取密码信息
void get_ssid_password(){
    now_ssid = preferences.getString("ssid","UTF-8");
    now_pass = preferences.getString("password","2664856778");

    Serial.printf("the ssid is %s \n!",now_ssid);
    Serial.printf("the password is %s \n!",now_pass);
    Serial.println("connnect wifi preference get infomation success");
}


void connect_wifi(void){
    get_ssid_password();
    char ssid[20];
    char pass[20];
    strcpy(ssid,now_ssid.c_str());
    strcpy(pass,now_pass.c_str());

    WiFi.begin(ssid, pass); //连接网络
    while (WiFi.status() != WL_CONNECTED) //等待网络连接成功
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("WiFi connected!\n");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP()); //打印模块IP
    Serial.println("\n");

}

void disconnect_wifi(void){
    WiFi.disconnect(true);
    WiFi.mode(WIFI_OFF);
    Serial.println("WiFi disconnected!");
}

//获取时间
void get_time(void){
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    
    if (!getLocalTime(&timeinfo))
    {
        //get_sucess_flag =0;
        Serial.println("Failed to obtain time");
        
    }
    Serial.printf("today is %d-%d-%d \n",timeinfo.tm_year,timeinfo.tm_mon,timeinfo.tm_mday);


}

//网络信息更新频率
void net_info_update(void){
    unsigned long net_currentMillis = millis(); // store the current time

    if(net_currentMillis % 3600000 == 0){
        connect_wifi();
        get_time();
      getThreeDayWeather();
      disconnect_wifi();
      Serial.printf("net info update sucess!\n");
    }
}

//硬件初始化函数
void bsp_init(void){

    key_init();
    lcd_init();
    tft.fillScreen(TFT_WHITE);
    show_boot_ani();

    gui_func = show_ui_home;
    connect_wifi();
    get_time();
    getThreeDayWeather();
    disconnect_wifi();
    tft.fillScreen(TFT_WHITE);
    Serial.printf("hardware init sucess!\n");
}
void setup(void){

    Serial.begin(115200);

    bsp_init();
    Serial.printf("tm_year is %d",timeinfo.tm_year);
    Serial.printf("tm_min is %d",timeinfo.tm_mon);
    Serial.printf("tm_mday is %d",timeinfo.tm_mday);
}


void loop(){
    key_update();
    getLocalTime(&timeinfo);
    net_info_update();
    
    gui_func();
  
    delay(10);

}
