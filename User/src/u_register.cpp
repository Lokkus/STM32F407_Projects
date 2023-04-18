/*
 * u_register.cpp
 *
 *  Created on: 13 kwi 2023
 *      Author: mk
 */

#include "u_register.h"

void URegister::set_register_bitfield(__IO uint32_t* reg, void* value)
{
    *reg |= reinterpret_cast<uint32_t>(value);
}

void URegister::set_register_bitfield(__IO uint32_t* reg, void* value,
        uint32_t offset, Bitfield_Size bitfield_size,
        Bitfield_Mask bitfield_mask)
{
    uint32_t l_offset = static_cast<uint32_t>(bitfield_size) * offset;
    clear_register_bitfield(reg, l_offset, bitfield_mask);
    *reg |= reinterpret_cast<uint32_t>(value) << l_offset;
}

void URegister::clear_register_bitfield(__IO uint32_t* reg, uint32_t offset,
        Bitfield_Mask bitfield_mask)
{
    *reg &=~ (bitfield_mask << offset);
}

void URegister::clear_register_bitfield(__IO uint32_t* reg, uint32_t value)
{
    *reg &=~value;
}

bool URegister::get_register_bitfield(__IO uint32_t* reg, uint32_t bit)
{
    return static_cast<bool>(*reg & bit);
}


