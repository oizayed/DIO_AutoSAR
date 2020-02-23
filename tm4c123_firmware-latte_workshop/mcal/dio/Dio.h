/*
 * Dio.h
 *
 *  Created on: Feb 19, 2020
 *      Author: Ghanem, Zayed, Atef & Amayem
 */

#ifndef TM4C123_FIRMWARE_LATTE_WORKSHOP_MCAL_DIO_DIO_H_
#define TM4C123_FIRMWARE_LATTE_WORKSHOP_MCAL_DIO_DIO_H_

/*===========================================================*
 * Includes.                        *
 *========================================================== */
#include "../../utils/STD_types.h"
#include "Dio_types.h"
#include "../../config/Dio_Cfg.h"
#include "../../config/Dio_lcfg.h"

/*===========================================================*
 * External Functions Prototype.                             *
 *========================================================== */
/**
 * @param ChannelId -> represent the channel id to detect the pin position in the port and also the port itself.
 *
 * @return -> STD_HIGH or STD_LOW depending on the physical level of the corresponding Pin.
 *
 * Description:  Returns the value of the specified DIO channel.
 */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/**
 * @param ChannelId -> represent the channel id to detect the pin position in the port and also the port itself.
 *
 * @param Level -> STD_HIGH or STD_LOW.
 *
 * Description: Service to set a level of a channel.
 */
void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level);

/**
 * @param ChannelId -> represent the channel id to detect the pin position in the port and also the port itself.
 *
 * @return the level of channel after flip action is taken STD_HIGH or STD_LOW.
 *
 * Description:Service to flip (change from 1 to 0 or from 0 to 1) the level of a channel and return
 *   the level of the channel after flip.
 */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);


/**
 *
 * @param PortId -> specify which port to write into.
 * @param Level -> value to be written
 * Description:  Service to set a value of the port.
 */
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level);
/**
 * @param PortId -> specify which port to write into.
 * @return value that in the whole port.
 * Description:  Returns the level of all channels of that port.
 */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);


/**
 * @param ChannelGroupIdPtr -> pointer to channel group.
 *
 * @return the level of group if STD_HIGH or STD_LOW.
 *
 * Description:This Service reads a subset of the adjoining bits of a port.
 */
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr);

/**
 * @param ChannelGroupIdPtr -> pointer to channel group.
 *
 * @param Level -> value to be written STD_HIGH or STD_LOW.
 *
 * Description: Service to set a subset of the adjoining bits of a port to a specified level.
 */
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level);



#endif /* TM4C123_FIRMWARE_LATTE_WORKSHOP_MCAL_DIO_DIO_H_ */



