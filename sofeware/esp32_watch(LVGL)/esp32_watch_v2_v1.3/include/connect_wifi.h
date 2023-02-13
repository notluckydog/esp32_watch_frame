
#ifndef _CONNECT_WIFI_H_
#define _CONNECT_WIFI_H_

#include <Arduino.h> 
#include <WiFi.h>
#include <Preferences.h>

extern Preferences preferences; 

String now_ssid ,now_pass,now_city_code;

void get_ssid_password(){



    now_ssid = preferences.getString("ssid","UTF-8");
    now_pass = preferences.getString("password","2664856778");

    Serial.printf("the ssid is %s \n!",now_ssid);
    Serial.printf("the ssid is %s \n!",now_ssid);

    
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
    Serial.println("WiFi connected!");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP()); //打印模块IP

}



void disconnect_wifi(void){
    WiFi.disconnect(true);
    WiFi.mode(WIFI_OFF);
    Serial.println("WiFi disconnected!");
}


#endif