

#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "Arduino.h"

class Button
{
    public:
        
        //Button(void){};

        Button(uint8_t button_pin);

        //~Button();

        void init(void);
        uint8_t getStatus(void);//获取当前状态
        

        private:
            uint8_t _button_pin;
            uint8_t _button_status;
        protected:

};


#endif