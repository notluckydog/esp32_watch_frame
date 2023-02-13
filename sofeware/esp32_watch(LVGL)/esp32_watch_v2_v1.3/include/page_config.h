

#ifndef _PAGE_CONFIG_H_
#define _PAGE_CONFIG_H_

#include <Arduino.h>
#include <lvgl.h>
#include "my_style.h"
#include "ico.h"

void net_page(void);//用来显示配网显示
void main_page(void);//用来显示主页面
void updateTime(void);//主页面，更新时钟

void alarm_page(void);//用来显示闹钟页面

void tomato_page(void);//用来显示番茄钟详情页
void update_tomato_ico(bool p);//用来更换开始和暂停的图标
void update_tomato_time(int time_min,int time_sec);//用来更新番茄钟的时间

void setting_page(void);//用来显示设置页面
void weather_page(void);//用来显示天气页面
void list_page(uint8_t index);//用来显示二级页面，显示天气等选项

void reboot_page(void);//用来实现开机动画

/**
 * @brief 向下弹出动画
 * @param obj lvgl对象指针
 * @param distance 动画移动距离
 * @param time 动画持续时长
 * @param delay 动画开始前延时
 */
//void lv_obj_push_down(lv_obj_t *obj, uint16_t distance = 24,uint16_t time = 300, uint16_t waitBeforeStart = 0);


/**
 * @brief 向上弹出动画
 * @param obj lvgl对象指针
 * @param distance 动画移动距离
 * @param time 动画持续时长
 * @param delay 动画开始前延时
 */
//void lv_obj_pop_up(lv_obj_t *obj, uint16_t distance = 24,uint16_t time = 300, uint16_t waitBeforeStart = 0);

//void lv_obj_fall_down(lv_obj_t *obj, uint16_t distance = 24,uint16_t time = 300, uint16_t waitBeforeStart = 0);


/**
 * @brief 浮动动画
 * @param obj lvgl对象指针
 * @param waitBeforeStart 动画开始前延时
 */                      
//void lv_obj_floating_add(lv_obj_t *obj, uint16_t waitBeforeStart = 0);

/**
 * @brief 移动到指定位置，渐慢动画
 * @param obj lvgl对象指针
 * @param x 目标位置x坐标
 * @param y 目标位置y坐标
 * @param time 动画持续时长
 * @param delay 动画开始前延时
 */
//void lv_obj_move_anim(lv_obj_t *obj, int16_t x, int16_t y,uint16_t time = 500, uint16_t waitBeforeStart = 0);




#endif