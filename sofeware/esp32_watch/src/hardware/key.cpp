

#include "key.h"

#include "Bounce2.h"

Bounce2::Button menu_botton = Bounce2::Button();
Bounce2::Button ok_botton = Bounce2::Button();
Bounce2::Button next_botton = Bounce2::Button();


//@function_name: key_init
//@function_function:  按键初始化
//@Input_variable:      输入变量名及格式
//@output_variable：  输出变量及类型
//@version ：V1.0     版本
//@Last_modification_time:最后修改时间
void key_init(void){

    menu_botton.attach(BT_MENU_PIN,INPUT_PULLUP);
    menu_botton.interval(10);
    menu_botton.setPressedState(LOW);//设置低电平的时候为按下状态


    ok_botton.attach(BT_OK_PIN,INPUT_PULLUP);
    ok_botton.interval(10);
    ok_botton.setPressedState(LOW);//设置低电平的时候为按下状态

    next_botton.attach(BT_NEXT_PIN,INPUT_PULLUP);
    next_botton.interval(10);
    next_botton.setPressedState(LOW);//设置低电平的时候为按下状态

    Serial.printf("key init success!\n");

}

//@function_name: key_update
//@function_function:  按键更新函数
//@Input_variable:      输入变量名及格式
//@output_variable：  输出变量及类型
//@version ：V1.0     版本
//@Last_modification_time:最后修改时间
void key_update(void){
    ok_botton.update();
    next_botton.update();
    menu_botton.update();
}

//@function_name: key_test
//@function_function:  按键测试函数
//@Input_variable:      输入变量名及格式
//@output_variable：  输出变量及类型
//@version ：V1.0     版本
//@Last_modification_time:最后修改时间
void key_test(void){

    if(next_botton.pressed()){
        Serial.printf("next\n");
    }
    if(ok_botton.pressed()){
        Serial.printf("ok\n");
    }
    if(menu_botton.pressed()){
        Serial.printf("menu\n");
    }
}
