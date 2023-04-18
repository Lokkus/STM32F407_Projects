/*
 * u_gpio.hpp
 *
 *  Created on: 12 kwi 2023
 *      Author: mk
 */

#ifndef INC_U_GPIO_H_
#define INC_U_GPIO_H_

#include "stm32f4xx.h"
#include "u_register.h"

#include <map>

enum class Pin : uint32_t
{
    PIN_0 = 1<<0,
    PIN_1 = 1<<1,
    PIN_2 = 1<<2,
    PIN_3 = 1<<3,
    PIN_4 = 1<<4,
    PIN_5 = 1<<5,
    PIN_6 = 1<<6,
    PIN_7 = 1<<7,
    PIN_8 = 1<<8,
    PIN_9 = 1<<9,
    PIN_10 = 1<<10,
    PIN_11 = 1<<11,
    PIN_12 = 1<<12,
    PIN_13 = 1<<13,
    PIN_14 = 1<<14,
    PIN_15 = 1<<15
};
enum class Moder
{
    Input = 0,
    Output = 1,
    Alternate = 2,
    Analog = 3
};

enum class Type
{
    Push_Pull = 0,
    Open_Drain = 1
};

enum class Speed
{
    Low_Speed = 0,
    Medium_Speed = 1,
    High_Speed = 2,
    Very_Hihg_Speed = 3
};

enum class PullUp_PullDwn
{
    No_Pull = 0,
    Pull_Up = 1,
    Pull_Down = 2
};

enum class Alternate
{
    AF_0 = 0,
    AF_1 = 1,
    AF_2 = 2,
    AF_3 = 3,
    AF_4 = 4,
    AF_5 = 5,
    AF_6 = 6,
    AF_7 = 7,
    AF_8 = 8,
    AF_9 = 9,
    AF_10 = 10,
    AF_11 = 11,
    AF_12 = 12,
    AF_13 = 13,
    AF_14 = 14,
    AF_15 = 15
};

constexpr Pin operator| (Pin x, Pin y)
{
    return static_cast<Pin>(static_cast<uint32_t>(x) | static_cast<uint32_t>(y));
}

class UGPIO : public URegister
{
    std::map<GPIO_TypeDef*, uint32_t> clocks
    {
        {GPIOA, RCC_AHB1ENR_GPIOAEN},
        {GPIOB, RCC_AHB1ENR_GPIOBEN},
        {GPIOC, RCC_AHB1ENR_GPIOCEN},
        {GPIOD, RCC_AHB1ENR_GPIODEN},
        {GPIOE, RCC_AHB1ENR_GPIOEEN},
        {GPIOF, RCC_AHB1ENR_GPIOFEN},
        {GPIOG, RCC_AHB1ENR_GPIOGEN},
        {GPIOH, RCC_AHB1ENR_GPIOHEN},
        {GPIOI, RCC_AHB1ENR_GPIOIEN},
    };
    GPIO_TypeDef* gpio_;
    void set_gpio(Pin pins, __IO uint32_t*reg, void* value,
            Bitfield_Size bitfield_size, Bitfield_Mask bitfield_mask);

public:
    UGPIO(GPIO_TypeDef* gpio);
    void set_moder(Pin pins, Moder moder);
    void set_type(Pin pins, Type type);
    void set_speed(Pin pins, Speed speed);
    void set_pull(Pin pins, PullUp_PullDwn pupd);
    void set_alternate(Pin pin, Alternate alt);
    void set_pin(Pin pin);
    void set_pins(Pin pins);
    void clear_pin(Pin pin);
    void clear_pins(Pin pins);
    bool get_pin_state(Pin pin);
};



#endif /* INC_U_GPIO_H_ */
