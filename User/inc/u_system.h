/*
 * u_system.h
 *
 *  Created on: 12 kwi 2023
 *      Author: mk
 */

#ifndef INC_U_SYSTEM_H_
#define INC_U_SYSTEM_H_

#include "stm32f4xx.h"
#include "u_register.h"


class USystem : public URegister
{
    const uint32_t PLL_M = 4;
    const uint32_t PLL_N = 168;
    const uint32_t PLL_P = 2;

    const uint32_t PLL_M_OFFSET = 0;
    const uint32_t PLL_N_OFFSET = 6;
    const uint32_t PLL_P_OFFSET = 16;

    const uint32_t APB1_PERIPH_CLOCK = 42000000;
    const uint32_t APB1_TIMER_CLOCK = 42000000;
    const uint32_t APB2_PERIPH_CLOCK = 84000000;
    const uint32_t APB2_TIMER_CLOCK = 168000000;
    const uint32_t SYSTEM_CLOCK = 168000000;

public:
    /*************>>>>>>> STEPS FOLLOWED <<<<<<<<************

        1. ENABLE HSE and wait for the HSE to become Ready
        2. Set the POWER ENABLE CLOCK and VOLTAGE REGULATOR
        3. Configure the FLASH PREFETCH and the LATENCY Related Settings
        4. Configure the PRESCALARS HCLK, PCLK1, PCLK2
        5. Configure the MAIN PLL
        6. Enable the PLL and wait for it to become ready
        7. Select the Clock Source and wait for it to be set

        ********************************************************/
    void startup();
};



#endif /* INC_U_SYSTEM_H_ */
