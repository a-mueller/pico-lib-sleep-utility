/*
  This library is intended to help with the deep sleep in my project when most of the time is spent in sleep on the pico-w
  Written for a very specific use case and is mostly copied together by the samples from raspberry pi and the sdk source code.

  Copyright (c) 2015 Abraham Mueller

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

#ifndef PICO_SLEEP_UTILITY_H
# define PICO_SLEEP_UTILITY_H

#include "hardware/xosc.h"
#include "pico/sleep.h"
#include "hardware/rosc.h"
#include "hardware/clocks.h"
#include "hardware/gpio.h"
#include <iterator>
using namespace std;

class PicoSleepUtility{
    public:
        PicoSleepUtility();
        ~PicoSleepUtility();
        /* gpio high pin will be used to detect a high edge, gpio low pin to detect a low edge, set to -1 if unused */
        void Init(int gpioHighPin, int gpioLowPin);
        void StartDeepSleep();
    private:
        int _low_pin;
        int _high_pin;
        void EnableRosc(void);
        void GoDormant(void);

};




#endif
