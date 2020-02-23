/*
 * lab_03_spi.c
 *
 *  Created on: Aug 20, 2019
 *      Author: Muhammad.Elzeiny
 */
#include <tm4c123_firmware-latte_workshop/mcal/dio/Dio.h>
#include <tm4c123_firmware-latte_workshop/mcal/PortDriver/port.h>
#include <tm4c123_firmware-latte_workshop/mcal/SysCtr/SysCtr.h>

void lab_00_dio(void)
{
    /*TODO: write simple code to test System control clock */
    uint8 Var = 0;

    SysCtr_init();
    SysCtr_prepheralClkEnable(SYSCTL_PERIPH_GPIOA);
    SysCtr_prepheralClkEnable(SYSCTL_PERIPH_GPIOB);
    SysCtr_prepheralClkEnable(SYSCTL_PERIPH_GPIOC);
    SysCtr_prepheralClkEnable(SYSCTL_PERIPH_GPIOD);
    SysCtr_prepheralClkEnable(SYSCTL_PERIPH_GPIOE);
    SysCtr_prepheralClkEnable(SYSCTL_PERIPH_GPIOF);
    PORT_init();


    Dio_WriteChannelGroup(LEDS_Group, 0b00000111);
    Dio_WriteChannelGroup(ALL_Group, 0b00011111);
    Var = Dio_ReadChannelGroup(LEDS_Group);
    Dio_WriteChannelGroup(LEDS_Group, 0b00000000);
    Var = Dio_ReadChannelGroup(LEDS_Group);
    Dio_WriteChannel(Dio_Channel_F1, STD_high);
    Var = Dio_ReadChannel(Dio_Channel_F1);
    Dio_FlipChannel(Dio_Channel_F1);
    Dio_WritePort(Dio_Port_F, 0b00011111);
    Var = Dio_ReadPort(Dio_Port_F);
    //Dio_WriteChannel(Dio_Channel_F0, STD_high);
    //Dio_WriteChannel(Dio_Channel_F1, STD_high);
    //Dio_WriteChannel(Dio_Channel_F2, STD_high);

    while(1)
    {

    }
}


