# Pico sleep utility

I use this in some of my projects where the pico should sleep most of the time and only do periodic work.

## Warning

I have really no idea what I am doing both on the electronics and with C / C++. This code is most likely stupid, but I do those projects
very infrequently so whenever it works it is good enough. You have been warned.

I also assume this will become obsolete once they include the sleep stuff into the SDK.

## What does it do

It allows you to go to deep sleep where the pico needs next to no power and wake up when either of two GPIOs trigger a wakeup.
I use this because I have an external RTC with a battery and interrupt plus a button I can press.


## Pico SDK

You need both, the standard `include(pico_sdk_import.cmake)` and extras `include(pico_extras_import.cmake)`


## How to use it

```
int main() {
    stdio_init_all();
    
    // setup your stuff

    PicoSleepUtility sleepUtility;
    sleepUtility.Init(4, 5);

    while(true) {
        printf("Going to sleep\n");
        uart_default_tx_wait_blocking();
        sleepUtility.StartDeepSleep();

        // check if the RTC or the button woke you up and do some stuff, go to sleep again
    }
}
```
