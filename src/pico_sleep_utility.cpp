#include "pico_sleep_utility.hpp"



PicoSleepUtility::PicoSleepUtility(){}

PicoSleepUtility::~PicoSleepUtility() {}

void PicoSleepUtility::Init(int gpioHighPin, int gpioLowPin){
    _high_pin = gpioHighPin;
    _low_pin = gpioLowPin;
}

void PicoSleepUtility::EnableRosc(void){
    uint32_t tmp = rosc_hw->ctrl;
    tmp &= (~ROSC_CTRL_ENABLE_BITS);
    tmp |= (ROSC_CTRL_ENABLE_VALUE_ENABLE << ROSC_CTRL_ENABLE_LSB);
    rosc_write(&rosc_hw->ctrl, tmp);
    // Wait for stable
    while ((rosc_hw->status & ROSC_STATUS_STABLE_BITS) != ROSC_STATUS_STABLE_BITS);
}


void PicoSleepUtility::GoDormant(void) {
    printf("Go dormant, high: %d, low: %d", _high_pin, _low_pin);
    if (_high_pin != -1) {
        gpio_set_dormant_irq_enabled(_high_pin, IO_BANK0_DORMANT_WAKE_INTE0_GPIO0_EDGE_HIGH_BITS, true);    
    }
    if (_low_pin != -1) {
        gpio_set_dormant_irq_enabled(_low_pin, IO_BANK0_DORMANT_WAKE_INTE0_GPIO0_EDGE_LOW_BITS, true);    
    }
    
    // gpio_set_dormant_irq_enabled(_gpio_button, IO_BANK0_DORMANT_WAKE_INTE0_GPIO0_EDGE_HIGH_BITS, true);

    xosc_dormant();
    // Execution stops here until woken up

    // Clear the irq so we can go back to dormant mode again if we want
    if (_high_pin != -1) {
        gpio_acknowledge_irq(_high_pin, IO_BANK0_DORMANT_WAKE_INTE0_GPIO0_EDGE_HIGH_BITS);
    }
    if (_low_pin != -1) {
        gpio_acknowledge_irq(_low_pin, IO_BANK0_DORMANT_WAKE_INTE0_GPIO0_EDGE_LOW_BITS);
    }
}

void PicoSleepUtility::StartDeepSleep(){
    sleep_run_from_xosc();
    GoDormant();

    EnableRosc();
    clocks_init();
}
