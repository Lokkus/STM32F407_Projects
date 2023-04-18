/*
 * u_register.h
 *
 *  Created on: 13 kwi 2023
 *      Author: mk
 */

#ifndef INC_U_REGISTER_H_
#define INC_U_REGISTER_H_

#include "stm32f4xx.h"

class URegister
{
protected:
    enum Bitfield_Mask
    {
        mask_1_bit = 0x1,
        mask_2_bit = 0x3,
        mask_3_bit = 0x7,
        mask_4_bit = 0xF,
        mask_5_bit = 0x1F,
        mask_6_bit = 0x3F,
        mask_7_bit = 0x7F,
        mask_8_bit = 0xFF,
        mask_9_bit = 0x1FF
    };

    enum Bitfield_Size
    {
        size_1_bit = 1,
        size_2_bit = 2,
        size_3_bit = 3,
        size_4_bit = 4,
        size_5_bit = 5
    };

public:
    URegister()=default;

    void set_register_bitfield(__IO uint32_t* reg, void* value);
    void set_register_bitfield(__IO uint32_t* reg, void* value, uint32_t offset,
            Bitfield_Size bitfield_size, Bitfield_Mask bitfiled_mask);
    void clear_register_bitfield(__IO uint32_t* reg, uint32_t offset,
            Bitfield_Mask bitfield_mask);
    void clear_register_bitfield(__IO uint32_t* reg, uint32_t value);
    bool get_register_bitfield(__IO uint32_t* reg, uint32_t bit);
};




#endif /* INC_U_REGISTER_H_ */
