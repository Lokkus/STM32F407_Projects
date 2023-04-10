/*
 * u_abstract.cpp
 *
 *  Created on: 10 kwi 2023
 *      Author: mk
 */

#include <u_abstract.h>

Object::mask Object::get_sizeof_value(uint32_t value)
{
    Object::mask m;
    if (value == 1)
    {
        m = Object::mask_1;
    }
    else if (value > 1 and value < 4)
    {
        m = Object::mask_2;
    }
    else if (value > 3 and value < 8)
    {
        m = Object::mask_3;
    }
    else if (value > 7 and value < 16)
    {
        m = Object::mask_4;
    }
    else if (value > 15 and value < 32)
    {
        m = Object::mask_5;
    }
    else if (value > 31 and value < 64)
    {
        m = Object::mask_6;
    }
    else
    {
        m = Object::mask_0;
    }
    return m;
}

void Object::set_bits_register(__IO uint32_t* reg, uint32_t start_pos, uint32_t value)
{
    clear_bits_register(reg, start_pos, value);
    *reg |= value << start_pos;

}
void Object::set_bits_register(__IO uint32_t* reg, uint32_t value)
{

}
void Object::clear_bits_register(__IO uint32_t* reg, uint32_t start_pos, uint32_t value)
{
    uint32_t mask = static_cast<uint32_t>(get_sizeof_value(value));
    *reg &= ~(mask << start_pos);
}
void Object::clear_bits_register(__IO uint32_t* reg, uint32_t value)
{

}


