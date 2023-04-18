/*
 * t_gpio.cpp
 *
 *  Created on: 10 kwi 2023
 *      Author: mk
 */

#include "t_gpio.h"
#include "stdint.h"
#include "stm32f4xx.h"
#include "u_gpio.h"
#include <memory>

void GPIO_test::gpio_register_test()
{
    UGPIO gpiod = UGPIO(GPIOD);
    UGPIO gpioa = UGPIO(GPIOA);
//    gpiod.set_moder(Pin::PIN_12 | Pin::PIN_13 | Pin::PIN_14 | Pin::PIN_15, Moder::Alternate);
//    gpiod.set_moder(Pin::PIN_12 | Pin::PIN_13 | Pin::PIN_14 | Pin::PIN_15, Moder::Analog);
//    gpiod.set_moder(Pin::PIN_12 | Pin::PIN_13 | Pin::PIN_14 | Pin::PIN_15, Moder::Input);
//    gpiod.set_moder(Pin::PIN_12 | Pin::PIN_13 | Pin::PIN_14 | Pin::PIN_15, Moder::Output);
//
//    gpiod.set_pull(Pin::PIN_12 | Pin::PIN_13 | Pin::PIN_14 | Pin::PIN_15, PullUp_PullDwn::Pull_Up);
//    gpiod.set_pull(Pin::PIN_12 | Pin::PIN_13 | Pin::PIN_14 | Pin::PIN_15, PullUp_PullDwn::Pull_Down);
//
//    gpiod.set_speed(Pin::PIN_12 | Pin::PIN_13 | Pin::PIN_14 | Pin::PIN_15, Speed::Very_Hihg_Speed);
//    gpiod.set_speed(Pin::PIN_12 | Pin::PIN_13 | Pin::PIN_14 | Pin::PIN_15, Speed::High_Speed);
//    gpiod.set_speed(Pin::PIN_12 | Pin::PIN_13 | Pin::PIN_14 | Pin::PIN_15, Speed::Medium_Speed);
//    gpiod.set_speed(Pin::PIN_12 | Pin::PIN_13 | Pin::PIN_14 | Pin::PIN_15, Speed::Low_Speed);
//
//    gpiod.set_type(Pin::PIN_12 | Pin::PIN_13 | Pin::PIN_14 | Pin::PIN_15, Type::Open_Drain);
//    gpiod.set_type(Pin::PIN_12 | Pin::PIN_13 | Pin::PIN_14 | Pin::PIN_15, Type::Push_Pull);

    gpiod.set_moder(Pin::PIN_11, Moder::Alternate);
    gpiod.set_alternate(Pin::PIN_11, Alternate::AF_12);

    gpiod.set_pins(Pin::PIN_12 | Pin::PIN_13 | Pin::PIN_14 | Pin::PIN_15);
    gpiod.clear_pins(Pin::PIN_12 | Pin::PIN_13 | Pin::PIN_14 | Pin::PIN_15);


}


