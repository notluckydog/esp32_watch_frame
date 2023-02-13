

#ifndef _UI_MANAGE_H_
#define _UI_MANAGE_H_


#include "Arduino.h"
#include <lvgl.h>



extern lv_obj_t * main_Screen;//主页面，home页 pageID 0
extern lv_obj_t * weather_ico_Screen;  //二级选择页面 天气 pageID1
extern lv_obj_t * clock_ico_Screen; // 二级选择页面 闹钟  pageID2
extern lv_obj_t * tomato_ico_Screen;  //二级选择页面 番茄钟 pageID3
extern lv_obj_t * aralm_ico_Screen; //二级选择页面，闹钟
extern lv_obj_t * setting_ico_Screen; //二级选择页面 设置 pageID4
extern lv_obj_t*  net_ico_Screen;  // 二级页面 配网二维码 pageid5

extern lv_obj_t * weather_Screen;    //三级页面  天气 pageid 6
extern lv_obj_t * clock_Screen;   // 三级页面 计时器
extern lv_obj_t * aralm_Screen;  //三级页面 闹钟，暂不提供闹钟设置 pageId7
extern lv_obj_t * tomato_Screen; //三级页面 番茄钟 35min/10min  pageid8
extern lv_obj_t * setting_Screen; // 三级页面 设置 ，暂时只提供选择，不做具体功能9
extern lv_obj_t * net_Screen;//三级页面 配网二维码 pageid 10

extern lv_obj_t * logo_Screen; // 开机时显示logo

typedef struct
{
	uint8_t current ; //当前状态索引号
	uint8_t next; 		//下一个状态
  uint8_t enter; 	    //确定
	uint8_t back; 		//退出
   //void (*current_operation)(void); //当前状态应该执行的操作
   //lv_obj_t* p;				//当前状态应该加载的屏幕
	
	
}Menu_table;

//貌似屏幕太多，导致内存溢出,减少一些屏幕
// static Menu_table table[13] = {
	
// 	    {0,1,1,0,main_Screen},   //主页面，向下一个
// 	    {1,2,7,0,weather_ico_Screen},//显示当天天气
// 		{2,3,8,0,clock_ico_Screen},//秒表计时
// 		{3,4,9,0,tomato_ico_Screen},//番茄钟计时
// 		{4,5,10,0,aralm_ico_Screen},//闹钟
// 		{5,6,11,0,net_ico_Screen},//配网
// 		{6,1,12,0,setting_ico_Screen},//设置
		

// 		{7,7,7,1,weather_Screen},//天气
// 		{8,8,8,2,clock_Screen},//计时器
// 		{9,9,9,3,tomato_Screen},//番茄钟
// 		{10,10,10,4,aralm_Screen},//闹钟
		
// 		{11,11,11,5,net_Screen},//配网
// 		{12,12,12,6,setting_Screen},//设置
	
// };

static Menu_table table[13] = {
	
	    {0,1,1,5},   //主页面，向下一个
		{1,2,6,0},//番茄钟计时
	    {2,3,7,0},//显示当天天气
		{3,4,8,0},//闹钟
		{4,5,9,0},//配网
		{5,1,10,0},//设置
		

		{6,6,6,1},//番茄钟
		{7,7,7,3},//天气
		{8,8,8,4},//闹钟
		{9,9,9,5},//配网
		{10,10,10,6},//设置
	
};





void ui_manage(void);
void ui_init(void);

void GUI_time_update_task(void *p);

#endif