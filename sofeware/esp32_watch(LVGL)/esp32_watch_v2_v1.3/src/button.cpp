

#include "button.h"

// Button::~Button(){
    
// }

// Button::Button(void){
//     _button_pin = 12;
//     _button_status = 0;
// };

Button::Button(uint8_t button_pin){

   
    if(button_pin<40&&button_pin>0){
    _button_pin=button_pin;
     _button_status = 0;
     
    }else{
        Serial.print("invalid pin number\n\n");
    }
    
};

void Button::init(){
    pinMode(_button_pin,INPUT_PULLUP);
    Serial.print("button init success \n\n");
};

uint8_t Button::getStatus(void){
    if(digitalRead(_button_pin)==0){
        vTaskDelay(40);
        //delay(100);
        if(digitalRead(_button_pin)==1){
            _button_status = 1;
        return _button_status;
        }else{
            _button_status = 0;
            return _button_status;
        }
        
    }
    
}