/*
 *                        _oo0oo_
 *                       o8888888o
 *                       88" . "88
 *                       (| -_- |)
 *                       0\  =  /0
 *                     ___/`---'\___
 *                   .' \\|     |// '.
 *                  / \\|||  :  |||// \
 *                 / _||||| -:- |||||- \
 *                |   | \\\  - /// |   |
 *                | \_|  ''\---/''  |_/ |
 *                \  .-\__  '-'  ___/-. /
 *              ___'. .'  /--.--\  `. .'___
 *           ."" '<  `.___\_<|>_/___.' >' "".
 *          | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *          \  \ `_.   \_ __\ /__ _/   .-` /  /
 *      =====`-.____`.___ \_____/___.-`___.-'=====
 *                        `=---='
 * 
 * 
 *      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 
 *            佛祖保佑      永不宕机      永无BUG
 */


#include <Arduino.h>

#include <WiFi.h>
#include <Preferences.h>

#include "watch.h"
#include "gui.h"
#include <lvgl.h>
#include "my_style.h"

#include "button.h"
#include "ntp_time.h"
#include "weather.h"
#include "connect_wifi.h"

lv_obj_t * Screen;

/*   全局变量  */
//按键相关
uint8_t BT_MENU_PIN=16;
uint8_t BT_OK_PIN=21;
uint8_t BT_NEXT_PIN=25;

Button ok_button(BT_OK_PIN);
Button menu_button(BT_MENU_PIN);
Button next_button(BT_NEXT_PIN);

//蜂鸣器相关
#define BEEP_PIN 32

uint32_t freq = 5000;
uint8_t ledChannel =0;
uint8_t resolution = 8;
uint8_t dutyCycle = 100;

//手表相关
Watch watch;


//获取网络信息相关
struct tm timeinfo;
Ntp_Time ntp_time;
Weather weather;
Preferences preferences; 
bool net_info_get_success; //开机时会获取一遍网络信息，若失败，则会再获取一次


/*    任务句柄  */
static TaskHandle_t AppTaskCreate_Handle = NULL;//创建任务句柄
//LVGL 工作任务句柄
static TaskHandle_t GUI_task_handle = NULL;   //番茄钟更换图标
//开机任务句柄，执行一次后删除
static TaskHandle_t reboot_task_handle =NULL;
//闹钟任务句柄，暂时仅创建执行，
static TaskHandle_t aralm_task_handle= NULL;

static portMUX_TYPE my_mutex = portMUX_INITIALIZER_UNLOCKED;

/*  函数声明 */
static void AppTaskCreate(void* p);//用于创建任务，所有任务都在这里创建
static void reboot_task(void* p);//开机动画任务
static void aralm_task(void* p);//闹钟任务


/*   
@ 函数名  ：GUI_Task
@ 功能说明：LVGL库的任务函数，用以维持LVGL的运转
@ 参数    ：NULL
@ 返回值  ：NULL
*/
static void GUI_Task(void *p){

  while(1){
    lv_timer_handler(); /* let the GUI do its work */
    vTaskDelay(5);
  }
}

/*   
@ 函数名  ：reboot_task
@ 功能说明：开机动画任务，并且在此时完成网络信息的获取
@ 参数    ：NULL
@ 返回值  ：NULL
*/
static void reboot_task(void *p){
  uint8_t get_net_info_count = 0;//尝试获取信息次数，三次后就不再重新获取
  uint8_t ntp_time_status =0;//
  uint8_t weather_status =0;
  net_info_get_success = false;
  connect_wifi();
  ntp_time.getLocaTime();
  vTaskDelay(50);
  weather.getThreeDay();
  Serial.print("reboot task start work\n");
    while(1){

        //root_animation();

        ntp_time_status = ntp_time.getStatus();
        weather_status = weather.getStatus();
        if(get_net_info_count<4&&net_info_get_success){

          if(ntp_time_status==1&&weather_status==1){
              net_info_get_success = true;
              disconnect_wifi();
              Serial.print("reboot task will be del\n");
              vTaskDelete(NULL);//执行完成之后，任务自己删除自己
    
        }
        }
        else{

          get_net_info_count++;
          ntp_time.getLocaTime();
          weather.getThreeDay();
          vTaskDelay(200);

        }

        }

}

/*   
@ 函数名  ：aralm_task
@ 功能说明：闹钟任务，时间到了开始响铃
@ 参数    ：NULL
@ 返回值  ：NULL
*/
static void aralm_task(void* p){

  while(1){

  }
}

/*   
@ 函数名  ：AppTaskCreate
@ 功能说明：创建任务入口，创建完后删除
@ 参数    ：NULL
@ 返回值  ：NULL
*/
static void AppTaskCreate(void *p){

    BaseType_t xReturn =pdPASS ;//定义一个信息返回值，默认为pdPass

    Serial.print("apptask start \n");
    taskENTER_CRITICAL(&my_mutex); //进入临界区

     xReturn =  xTaskCreate(reboot_task,"reboot_task",1024*3,NULL,1,&reboot_task_handle);
    if(xReturn == xReturn){
      Serial.print("开机动画 任务创建成功");
    }

    xReturn =  xTaskCreate(GUI_Task,"gui task",1024*10,NULL,3,&GUI_task_handle);
    if(xReturn == xReturn){
      Serial.print("创建GUI manage 任务成功");
    }

    // xReturn =  xTaskCreate(aralm_task,"reboot_task",1024*3,NULL,1,&aralm_task_handle);
    // if(xReturn == xReturn){
    //   Serial.print("闹钟任务创建成功");
    // }

    // xReturn = xTaskCreate(tomato_update_time_task,"tomato update",1024*4,NULL,1,NULL);
    // if(xReturn == xReturn){
    //   Serial.print("番茄钟任务创建成功");
    // }




    vTaskDelete(AppTaskCreate_Handle); //删除 AppTaskCreate 任务
 
    taskEXIT_CRITICAL(&my_mutex); //退出临界区




}

/*   硬件初始化 */
void BSP_init(){

  delay(100);
  Serial.begin(115200);

  watch.init();

  ok_button.init();
  next_button.init();
  menu_button.init();

  ntp_time.init();
  weather.init();

  //GUI_Manage(); 
  Serial.print("hardware init succuss! \n\n");
  
}




void setup() {
  // put your setup code here, to run once:



  BSP_init();
  Serial.print("1\n");

  watch.begin();

  Serial.print("2\n");

  GUI_Manage();

  // BaseType_t xReturn =pdPASS ;//定义一个信息返回值，默认为pdPass

  // xReturn = xTaskCreate(AppTaskCreate, "AppTaskCreate",512, NULL,1, &AppTaskCreate_Handle);
  // /* 启动任务调度 */
  // if (pdPASS == xReturn){
  //   vTaskStartScheduler(); /* 启动任务，开启调度 */
  // }
  
  // else{
    
  // }
  
  // BaseType_t xReturn =pdPASS ;//定义一个信息返回值，默认为pdPass

  //   Serial.print("apptask start \n");
  //   //taskENTER_CRITICAL(&my_mutex); //进入临界区

  //    xReturn =  xTaskCreate(reboot_task,"reboot_task",1024*3,NULL,1,&reboot_task_handle);
  //   if(xReturn == xReturn){
  //     Serial.print("reboot task start!\n");
  //   }


}

int a=35;
int b = 1;
char c_text[16];

void loop() {

  lv_timer_handler(); /* let the GUI do its work */
  vTaskDelay(5);
  // if(b=0){
  //   b=59;
  // }
//   if(--b<=0){
//             b = 59;

//                 if(--a<=0){
//                     a=34; 
                    
//                 }
// }
//   delay(800);
//   sprintf(c_text,"%2d:%2d",a,b);
  
//   Serial.print("tomato_time_text");
//   Serial.printf(c_text);
//   Serial.printf("\n");
}