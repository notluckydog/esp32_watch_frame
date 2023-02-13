

#include "weather.h"

extern Preferences preferences; 
//String now_ssid ,now_pass,now_city_code;

String location_city = "Shenzhen";
String weather_private_key = "SLJ1zuypKt_M1URPh";  //心知天气私钥
String weather_public_key = "PCPNJ-fF1VnBX9wLO";   //心知天气公钥


String weather_new_url = "https://api.seniverse.com/v3/weather/now.json?key="+ weather_private_key +"&location="+location_city+"&language=en";
String weather_url = "https://api.seniverse.com/v3/weather/now.json?key=SLJ1zuypKt_M1URPh&location=ip&language=en";

String weather_three_day = "https://api.seniverse.com/v3/weather/daily.json?key=SLJ1zuypKt_M1URPh&location=ip&language=en&unit=c&start=0&days=5";



Weather::Weather(){

}

Weather::~Weather(){


}

void Weather::init(){
    Preferences preferences; 

    now_ssid = preferences.getString("ssid","UTF-8");
    now_pass = preferences.getString("password","2664856778");
    now_city_code = preferences.getString("citycode","Shenzhen");


    get_sucess_flag = 0  ;//初始化为0

    Serial.println("preference get infomation success");


}
void Weather::getToday(){
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

        get_sucess_flag = 1 ;
    }else{
        get_sucess_flag = 0  ;
        Serial.println("get weather failed\n\n");

    }

}

void Weather::getThreeDay(){

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
        weather_today_date=results_0_daily["date"];
        weather_today_temp_hign = results_0_daily["high"];
        weather_today_temp_low = results_0_daily["low"];
        weather_today_text_day = results_0_daily["text_day"];
        weather_today_wind_derection = results_0_daily["wind_direction"];
        weather_today_wind_scale = results_0_daily["wind_scale"];
        weather_today_hum = results_0_daily["humidity"];
        
        
        //明天的天气状态获取
        weather_tomorrow_date=results_1_daily["date"];
        weather_tomorrow_temp_hign = results_1_daily["high"];
        weather_tomorrow_temp_low = results_1_daily["low"];
        weather_tomorrow_text_day = results_1_daily["text_day"];
        weather_tomorrow_wind_derection = results_1_daily["wind_direction"];
        weather_tomorrow_wind_scale = results_1_daily["wind_scale"];
        weather_tomorrow_hum = results_1_daily["humidity"];

        //后天的天气状态的获取
         weather_after_date=results_2_daily["date"];
        weather_after_temp_hign = results_2_daily["high"];
        weather_after_temp_low = results_2_daily["low"];
        weather_after_text_day = results_2_daily["text_day"];
        weather_after_wind_derection = results_2_daily["wind_direction"];
        weather_after_wind_scale = results_2_daily["wind_scale"];
        weather_after_hum = results_2_daily["humidity"];

         //打印今天的天气信息
        Serial.print("today weather info\n");
        Serial.printf("weather_today_date is %s  \n",weather_today_date); 
        Serial.printf("weather_today_temp_hign is %s  \n",weather_today_temp_hign); 
        Serial.printf("weather_today_temp_low is %s \n",weather_today_temp_low);
        Serial.printf("weather_today_text_day is %s \n",weather_today_text_day);
        Serial.printf("weather_today_wind_derection is %s \n",weather_today_wind_derection);
        Serial.printf("weather_today_wind_scale is %s \n",weather_today_wind_scale);
        Serial.printf("weather_today_hum is %s \n\n",weather_today_hum);


        //打印明天天的天气信息
        Serial.print("tomorrow weather info\n");
        Serial.printf("weather_tomorrow_date is %s  \n",weather_tomorrow_date); 
        Serial.printf("weather_tomorrow_temp_hign is %s  \n",weather_tomorrow_temp_hign); 
        Serial.printf("weather_tomorrow_temp_low is %s \n",weather_tomorrow_temp_low);
        Serial.printf("weather_tomorrow_text_day is %s \n",weather_tomorrow_text_day);
        Serial.printf("weather_tomorrow_wind_derection is %s \n",weather_tomorrow_wind_derection);
        Serial.printf("weather_tomorrow_wind_scale is %s \n",weather_tomorrow_wind_scale);
        Serial.printf("weather_tomorrow_hum is %s \n\n",weather_tomorrow_hum);

        //打印后天的天气信息
        Serial.print("after weather info\n");
        Serial.printf("weather_after_date is %s  \n",weather_after_date); 
        Serial.printf("weather_after_temp_hign is %s  \n",weather_after_temp_hign); 
        Serial.printf("weather_after_temp_low is %s \n",weather_after_temp_low);
        Serial.printf("weather_after_text_day is %s \n",weather_after_text_day);
        Serial.printf("weather_after_wind_derection is %s \n",weather_after_wind_derection);
        Serial.printf("weather_after_wind_scale is %s \n",weather_after_wind_scale);
        Serial.printf("weather_after_hum is %s \n\n",weather_after_hum);

       get_sucess_flag = 1  ;

    }else{

        get_sucess_flag = 0  ;
        Serial.println("get weather failed\n\n");
        
    }

}

//获取是否成功获取到信息
uint8_t Weather::getStatus(void){
    return get_sucess_flag;
}