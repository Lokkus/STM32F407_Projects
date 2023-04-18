/*
 * u_system.cpp
 *
 *  Created on: 12 kwi 2023
 *      Author: mk
 */


#include "u_system.h"

void USystem::startup()
{
    set_register_bitfield(&RCC->CR, (void*)RCC_CR_HSEON);
    while(!(get_register_bitfield(&RCC->CR, RCC_CR_HSERDY)));

    set_register_bitfield(&RCC->APB1ENR, (void*)RCC_APB1ENR_PWREN);
    set_register_bitfield(&PWR->CR, (void*)PWR_CR_VOS);

    set_register_bitfield(&FLASH->ACR, (void*)(FLASH_ACR_PRFTEN));      // Prefetch enable
    set_register_bitfield(&FLASH->ACR, (void*)(FLASH_ACR_ICEN));        // Instruction cache enable
    set_register_bitfield(&FLASH->ACR, (void*)(FLASH_ACR_DCEN));        // Data cache enable
    set_register_bitfield(&FLASH->ACR, (void*)(FLASH_ACR_LATENCY_5WS));

    clear_register_bitfield(&RCC->CFGR, RCC_CFGR_HPRE_DIV512);    // HPRE: system clock not divided
    set_register_bitfield(&RCC->CFGR, (void*)RCC_CFGR_PPRE2_DIV2);
    set_register_bitfield(&RCC->CFGR, (void*)RCC_CFGR_PPRE1_DIV4);

    clear_register_bitfield(&RCC->PLLCFGR, mask_6_bit);
    set_register_bitfield(&RCC->PLLCFGR, (void*)(PLL_M << PLL_M_OFFSET));
    clear_register_bitfield(&RCC->PLLCFGR, PLL_N_OFFSET, mask_9_bit);
    set_register_bitfield(&RCC->PLLCFGR, (void*)(PLL_N << PLL_N_OFFSET));
    clear_register_bitfield(&RCC->PLLCFGR, PLL_P_OFFSET, mask_2_bit);
    set_register_bitfield(&RCC->PLLCFGR, (void*)(PLL_P << PLL_P_OFFSET));

    set_register_bitfield(&RCC->PLLCFGR, (void*)(RCC_PLLCFGR_PLLSRC));
    set_register_bitfield(&RCC->CR, (void*)RCC_CR_PLLON);
    while(!(get_register_bitfield(&RCC->CR, RCC_CR_PLLRDY)));
    set_register_bitfield(&RCC->CFGR, (void*)RCC_CFGR_SW_1);
    while(!(get_register_bitfield(&RCC->CFGR, RCC_CFGR_SWS_1)));
}
