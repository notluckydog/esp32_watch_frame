#include "my_weather.h"
#include <Preferences.h>



const char* my_pass = "2664856778";  //你的WIFI密码
const char* my_ssid = "UTF-8";  //你的WIFI

String now_ssid ,now_pass,now_city_code;

String location_city = "Shenzhen";
String weather_private_key = "SLJ1zuypKt_M1URPh";  //心知天气私钥
String weather_public_key = "PCPNJ-fF1VnBX9wLO";   //心知天气公钥

String weather_url = "https://api.seniverse.com/v3/weather/now.json?key="+ weather_private_key +"&location="+location_city+"&language=en";
String weather_test_url = "https://api.seniverse.com/v3/weather/now.json?key=SLJ1zuypKt_M1URPh&location=ip&language=en";


//从preferences 中读取wifi的名称与密码
void get_wifi_info(){
    Preferences preferences; 

    now_ssid = preferences.getString("ssid","UTF-8");
    now_pass = preferences.getString("password","2664856778");
    now_city_code = preferences.getString("citycode","Shenzhen");

    Serial.println("preference get infomation success");

}
//获取天气信息
void getWeatherInfo(){

    // Serial.printf("WIFI :Connecting to %s ",my_ssid );
    // WiFi.begin(my_ssid, my_ssid);
    // while (WiFi.status() != WL_CONNECTED) {
    //     delay(500);
    //     Serial.print(".");
    // }
    // Serial.println("WIFI CONNECTED");
    // Serial.println("IP address: ");
    // Serial.println(WiFi.localIP()); //打印模块IP

    DynamicJsonDocument doc(2048);
    HTTPClient https;
    https.begin(weather_test_url);
    int http_code = https.GET();

    if(http_code>0){
        String playload = https.getString();
        deserializeJson(doc,playload);
        JsonObject results_0 = doc["results"][0];
        JsonObject results_0_now = results_0["now"];


        //JsonObject results_text = results_now["text"];
        weather_struct.weather_text = results_0_now["text"];
        weather_struct.weather_code = results_0_now["code"];
        weather_struct.weather_tem = results_0_now["temperature"];

        //Serial.println(playload);

        Serial.printf("today weather is %c  \n\n",weather_struct.weather_text); 
        Serial.println(weather_struct.weather_text);
        Serial.println("\n\n");
        Serial.printf("today weather code  is %d  \n\n",weather_struct.weather_code); 
        Serial.printf("today weather tem is %d \n\n",weather_struct.weather_tem);
    }else{
        Serial.println("get weather failed\n\n");
    }

}
