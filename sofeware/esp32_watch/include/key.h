

#ifndef _KEY_H_
#define _KEY_H_

#include <Arduino.h>
#include "Bounce2.h"

const uint8_t BT_MENU_PIN=16;
const uint8_t BT_OK_PIN=21;
const uint8_t BT_NEXT_PIN=25;


void key_init(void);//按键初始化
void key_update(void);//按键状态更新
void key_test(void);//按键测试函数


#endif