

#include "weather.h"
#include <ArduinoJson.h>
#include <HTTPClient.h>

String location_city = "Shenzhen";
String weather_private_key = "SLJ1zuypKt_M1URPh";  //心知天气私钥
String weather_public_key = "PCPNJ-fF1VnBX9wLO";   //心知天气公钥


String weather_new_url = "https://api.seniverse.com/v3/weather/now.json?key="+ weather_private_key +"&location="+location_city+"&language=en";
String weather_url = "https://api.seniverse.com/v3/weather/now.json?key=SLJ1zuypKt_M1URPh&location=ip&language=en";

String weather_three_day = "https://api.seniverse.com/v3/weather/daily.json?key=SLJ1zuypKt_M1URPh&location=ip&language=en&unit=c&start=0&days=5";


weatherInfo todayWeather;
weatherInfo nextdayWeather;
weatherInfo afterdayWeather;

//@function_name: getThreeDay
//@function_function:  获取三天天气详情
//@Input_variable:      输入变量名及格式
//@output_variable：  输出变量及类型
//@version ：V1.0     版本
//@Last_modification_time:最后修改时间
void getThreeDayWeather(void){
    DynamicJsonDocument doc(1024*4);
    HTTPClient https;
    https.begin(weather_three_day);
    int http_code = https.GET();

    if(http_code>0){
        String playload = https.getString();
        deserializeJson(doc,playload);
        JsonObject results_0 = doc["results"][0];
        JsonObject results_0_daily = results_0["daily"][0];
        JsonObject results_1_daily  = results_0["daily"][1];
        JsonObject results_2_daily  = results_0["daily"][2];

        //今天的天气状态获取
        todayWeather.code_day=results_0_daily["date"];
        todayWeather.temp_hign = results_0_daily["high"];
        todayWeather.temp_low = results_0_daily["low"];
        todayWeather.text_day = results_0_daily["text_day"];
        todayWeather.wind_derection = results_0_daily["wind_direction"];
        todayWeather.wind_scale = results_0_daily["wind_scale"];
        todayWeather.hum = results_0_daily["humidity"];
        
         //打印今天的天气信息
        Serial.print("today weather info\n");
        Serial.printf("weather_today_date is %s  \n",todayWeather.code_day); 
        Serial.printf("weather_today_temp_hign is %s  \n",todayWeather.temp_hign); 
        Serial.printf("weather_today_temp_low is %s \n",todayWeather.temp_low);
        Serial.printf("weather_today_text_day is %s \n",todayWeather.text_day);
        Serial.printf("weather_today_wind_derection is %s \n",todayWeather.wind_derection);
        Serial.printf("weather_today_wind_scale is %s \n",todayWeather.wind_scale);
        Serial.printf("weather_today_hum is %s \n\n",todayWeather.hum);

        //明天的天气状态获取
        nextdayWeather.date=results_1_daily["date"];
        nextdayWeather.temp_hign = results_1_daily["high"];
        nextdayWeather.temp_low = results_1_daily["low"];
        nextdayWeather.text_day = results_1_daily["text_day"];
        nextdayWeather.wind_derection = results_1_daily["wind_direction"];
        nextdayWeather.wind_scale = results_1_daily["wind_scale"];
        nextdayWeather.hum = results_1_daily["humidity"];

        //打印明天天的天气信息
        Serial.print("tomorrow weather info\n");
        Serial.printf("weather_tomorrow_date is %s  \n",nextdayWeather.date); 
        Serial.printf("weather_tomorrow_temp_hign is %s  \n",nextdayWeather.temp_hign); 
        Serial.printf("weather_tomorrow_temp_low is %s \n",nextdayWeather.temp_low);
        Serial.printf("weather_tomorrow_text_day is %s \n",nextdayWeather.text_day);
        Serial.printf("weather_tomorrow_wind_derection is %s \n",nextdayWeather.wind_derection);
        Serial.printf("weather_tomorrow_wind_scale is %s \n",nextdayWeather.wind_scale);
        Serial.printf("weather_tomorrow_hum is %s \n\n",nextdayWeather.hum);

        //后天的天气状态的获取
        afterdayWeather.date=results_2_daily["date"];
        afterdayWeather.temp_hign = results_2_daily["high"];
        afterdayWeather.temp_low = results_2_daily["low"];
        afterdayWeather.text_day = results_2_daily["text_day"];
        afterdayWeather.wind_derection = results_2_daily["wind_direction"];
        afterdayWeather.wind_scale = results_2_daily["wind_scale"];
        afterdayWeather.hum = results_2_daily["humidity"];

        //打印后天的天气信息
        Serial.print("after weather info\n");
        Serial.printf("weather_after_date is %s  \n",afterdayWeather.date); 
        Serial.printf("weather_after_temp_hign is %s  \n",afterdayWeather.temp_hign); 
        Serial.printf("weather_after_temp_low is %s \n",afterdayWeather.temp_low);
        Serial.printf("weather_after_text_day is %s \n",afterdayWeather.text_day);
        Serial.printf("weather_after_wind_derection is %s \n",afterdayWeather.wind_derection);
        Serial.printf("weather_after_wind_scale is %s \n",afterdayWeather.wind_scale);
        Serial.printf("weather_after_hum is %s \n\n",afterdayWeather.hum);

         }else{
        Serial.println("get weather failed\n\n");
        
    }

}


//@function_name: getThreeDay
//@function_function:  获取1天天气详情
//@Input_variable:      输入变量名及格式
//@output_variable：  输出变量及类型
//@version ：V1.0     版本
//@Last_modification_time:最后修改时间
/*
void getOneDayWeather(){
    DynamicJsonDocument doc(2048);
    HTTPClient https;
    https.begin(weather_url);
    int http_code = https.GET();

    if(http_code>0){
        String playload = https.getString();
        deserializeJson(doc,playload);
        JsonObject results_0 = doc["results"][0];
        JsonObject results_0_now = results_0["now"];

        weather_today_text_day = results_0_now["text"];
        weather_today_code_day = results_0_now["code"];
        weather_today_temp_hign = results_0_now["temperature"];
        //weather_hum = "None";
        //weather_wind = "None";

        Serial.print("weather info\n");
        //Serial.println(playload);
        
        Serial.printf("\ntoday weather is %c  \n\n",weather_today_text_day); 
        
        Serial.printf("\ntoday weather code  is %c  \n\n",weather_today_code_day); 
        

        Serial.printf("\ntoday weather tem is %c \n\n",weather_today_temp_hign);

        
    }else{
        
        Serial.println("get weather failed\n\n");

    }
}*/