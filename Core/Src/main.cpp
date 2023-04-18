/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "u_system.h"
#include "t_gpio.h"

GPIO_test gpio_test;
USystem* usystem = new USystem;

static void init_config()
{
    usystem->startup();
}

static void tests()
{
    gpio_test.gpio_register_test();
}

int main(void)
{
    init_config();
    tests();
    while (1)
    {

    }
    delete usystem;
}


