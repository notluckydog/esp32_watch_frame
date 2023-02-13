

#ifndef _MY_WIFI_H_
#define _MY_WIFI_H_

#include <Arduino.h>
#include <Preferences.h>
#include <WiFi.h>


String pre_ssid ,pre_pass,pre_city_code;


//从preferences 中读取wifi的名称与密码
void connectWifi(){
    Preferences preferences; 

    pre_ssid = preferences.getString("ssid","UTF-8");
    pre_pass = preferences.getString("password","2664856778");
    pre_city_code = preferences.getString("citycode","Shenzhen");

    Serial.println("preference get infomation success");

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
void disconnect_wifi(){
    WiFi.disconnect(true);
    WiFi.mode(WIFI_OFF);
    Serial.println("WiFi disconnected!");

}

#endif