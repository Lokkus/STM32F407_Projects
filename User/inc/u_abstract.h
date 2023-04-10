/*
 * u_abstract.h
 *
 *  Created on: 10 kwi 2023
 *      Author: mk
 */

#include "stm32f4xx.h"

#ifndef INC_U_ABSTRACT_H_
#define INC_U_ABSTRACT_H_

class Object
{
    enum mask
    {
        mask_0 = 0,     // this is invalid
        mask_1 = 1,     // 1
        mask_2 = 3,     // 11
        mask_3 = 7,     // 111
        mask_4 = 15,    // 1111
        mask_5 = 31,    // 11111
        mask_6 = 63     // 111111
    };

    mask get_sizeof_value(uint32_t value);
public:
    Object()=default;

    void set_bits_register(__IO uint32_t* reg, uint32_t start_pos, uint32_t value);
    void set_bits_register(__IO uint32_t* reg, uint32_t value);
    void clear_bits_register(__IO uint32_t* reg, uint32_t start_pos, uint32_t value);
    void clear_bits_register(__IO uint32_t* reg, uint32_t value);
};




#endif /* INC_U_ABSTRACT_H_ */
