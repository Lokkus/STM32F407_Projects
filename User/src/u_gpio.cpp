/*
 * u_gpio.cpp
 *
 *  Created on: 12 kwi 2023
 *      Author: mk
 */

#include <u_gpio.h>

UGPIO::UGPIO(GPIO_TypeDef* gpio)
{
    this->gpio_ = gpio;
    // enable clocks
    uint32_t offset = clocks.at(gpio_);
    set_register_bitfield(&RCC->AHB1ENR, (void*)offset);

}


void UGPIO::set_gpio(Pin pins, __IO uint32_t*reg, void* value,
        Bitfield_Size bitfield_size, Bitfield_Mask bitfield_mask)
{
    uint32_t l_pins = static_cast<uint32_t>(pins);
    uint32_t reg_size = sizeof(uint32_t)*8;

    for (uint16_t i = 0; i < reg_size; i++)
    {
        if (l_pins & (1 << i))
        {
            set_register_bitfield(reg, value, (uint32_t)i, bitfield_size, bitfield_mask);
        }
    }
}

void UGPIO::set_moder(Pin pins, Moder moder)
{
    set_gpio(pins, &gpio_->MODER, (void*)moder, Bitfield_Size::size_2_bit,
            Bitfield_Mask::mask_2_bit);
}

void UGPIO::set_type(Pin pins, Type type)
{
    set_gpio(pins, &gpio_->OTYPER, (void*)type, Bitfield_Size::size_1_bit,
            Bitfield_Mask::mask_1_bit);
}

void UGPIO::set_speed(Pin pins, Speed speed)
{
    set_gpio(pins, &gpio_->OSPEEDR, (void*)speed, Bitfield_Size::size_2_bit,
            Bitfield_Mask::mask_2_bit);
}

void UGPIO::set_pull(Pin pins, PullUp_PullDwn pupd)
{
    set_gpio(pins, &gpio_->PUPDR, (void*)pupd, Bitfield_Size::size_2_bit,
                Bitfield_Mask::mask_2_bit);
}

void UGPIO::set_alternate(Pin pin, Alternate alt)
{
    uint16_t pin_position = 0;
    while(!(static_cast<uint16_t>(pin) & (1<<pin_position)))pin_position++;

    set_register_bitfield(&gpio_->AFR[pin_position>>3], (void*)alt,
            static_cast<uint32_t>(pin_position & 0x7), Bitfield_Size::size_4_bit,
            Bitfield_Mask::mask_4_bit);
}

void UGPIO::set_pin(Pin pin)
{
    set_register_bitfield(&gpio_->ODR, (void*)pin);
}

void UGPIO::set_pins(Pin pins)
{
    set_gpio(pins, &gpio_->ODR, (void*)1, Bitfield_Size::size_1_bit,
                Bitfield_Mask::mask_1_bit);
}

void UGPIO::clear_pin(Pin pin)
{
    clear_register_bitfield(&gpio_->ODR, static_cast<uint32_t>(pin));
}

void UGPIO::clear_pins(Pin pins)
{
    for (uint16_t i = 0; i<sizeof(uint32_t)*8; i++)
    {
        if (static_cast<uint32_t>(pins) & 1<<i)
        {
            clear_register_bitfield(&gpio_->ODR, static_cast<uint32_t>(1<<i));
        }
    }
}

bool UGPIO::get_pin_state(Pin pin)
{
    return gpio_->IDR & static_cast<uint32_t>(pin);
}

