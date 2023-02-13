
#ifndef  _GUI_H_
#define  _GUI_H_

#include <Arduino.h>
#include <lvgl.h>


#define GUI_ANIM_FLOATING_RANGE 8
#define GUI_ANIM_FLOATING_TIME 1000


typedef struct
{
	uint8_t current ; //当前状态索引号
	uint8_t next; 		//下一个状态
  uint8_t enter; 	    //确定
	uint8_t back; 		//退出
   //void (*current_operation)(void); //当前状态应该执行的操作
   //lv_obj_t* p;				//当前状态应该加载的屏幕
	
}Menu_table;

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




void GUI_Manage(void);//GUI 管理

void tomato_update_time_task(void *p);
void root_animation(void);//实现开机动画

#endif