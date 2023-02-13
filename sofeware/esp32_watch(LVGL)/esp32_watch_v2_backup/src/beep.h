#ifndef _BEEP_H_
#define _BEEP_H_

#include "Arduino.h"
class Beep{


    public:
        Beep(uint8_t beep_pin,uint8_t freq,uint8_t ledChannel);
        ~Beep();

        void setFreq(uint8_t freq);
        void setResolution(uint8_t resolution);
        void setDutyCycle(uint8_t dutyCycle);
        void on();
        void off();

    private:
        uint8_t  _beep_pin;
        uint8_t  _freq;
        uint8_t _ledChannel;
        uint8_t _resolution = 8;
        uint8_t _dutyCycle;

    protected:
};

#endif