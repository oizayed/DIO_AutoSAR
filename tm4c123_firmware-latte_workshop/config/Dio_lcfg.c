/*
 * Dio_lcfg.c
 *
 *  Created on: Feb 19, 2020
 *      Author: Ghanem, Zayed, Atef & Amayem
 */

#include "../mcal/dio/Dio.h"

#include "Dio_lcfg.h"

const Dio_ChannelGroupType gas_DioChannelArray[7] =
{
 {0b00001110, 1, Dio_Port_F},
 {0b00011111, 0, Dio_Port_F},
 {0b00001110, 0, Dio_Port_F},
 {0b00001110, 0, Dio_Port_F},
 {0b00001110, 0, Dio_Port_F},
 {0b00001110, 0, Dio_Port_F},
 {0b00001110, 0, Dio_Port_F},
};

