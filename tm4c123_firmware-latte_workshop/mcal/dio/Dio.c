/*
 * Dio.c
 *
 *  Created on: Feb 19, 2020
 *      Author: Ghanem, Zayed, Atef & Amayem
 */

/*===========================================================*
 * INCLUDES                                                  *
 *========================================================== */

#include "Dio.h"
#include "../mcu_hw.h"


/*===========================================================*
 * DEFINES                                                   *
 *========================================================== */
#define BIT_MASK_ADDR(BIT_NUM)          ((1<<BIT_NUM))
#define ALL_PINS                            (0xff)
#define MAX_NUM_OF_PORTS                    6


/*===========================================================*
 *GLOBAL VARIABLES                                           *
 *========================================================== */
static volatile PORT_RegType* BaseAddrArr[MAX_NUM_OF_PORTS] = {PORTA_BaseAddr,PORTB_BaseAddr,
                                                               PORTC_BaseAddr,PORTD_BaseAddr,
                                                               PORTE_BaseAddr,PORTF_BaseAddr};


/*===========================================================*
 * External Functions Implementation.                        *
 *========================================================== */
/**
 * @param ChannelId -> represent the channel id to detect the pin position in the port and also the port itself.
 *
 * @return -> STD_HIGH or STD_LOW depending on the physical level of the corresponding Pin.
 *
 * Description:  Returns the value of the specified DIO channel.
 */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    /* Initialization local variables */
    Dio_LevelType channelStatus;
    Dio_PortType Dio_ReadChannel_PortId = (Dio_PortType) (ChannelId / (Dio_PortType) (8));
    Dio_ChannelType Dio_ReadChannel_ChannelPos = (Dio_ChannelType) (ChannelId % (Dio_ChannelType) (8));
    uint8 u8_bitMaskOffset = BIT_MASK_ADDR(Dio_ReadChannel_ChannelPos);

    /* get the level of given Channel */
    channelStatus = (Dio_LevelType)(((BaseAddrArr[Dio_ReadChannel_PortId]))->GPIODATA[u8_bitMaskOffset]);

    /* Dio_LevelType take only one of two levels STD_low or STD_high*/
    if(channelStatus != STD_low)
    {
        channelStatus = STD_high;
    }
    else
    {
    }
    return channelStatus;
}

/**
 * @param ChannelId -> represent the channel id to detect the pin position in the port and also the port itself.
 *
 * @param Level -> STD_HIGH or STD_LOW.
 *
 * Description: Service to set a level of a channel.
 */
void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level)
{
    /* Initialization local variables */
     Dio_PortType Dio_WriteChannel_PortId = (Dio_PortType) (ChannelId / (Dio_PortType) (8));
     Dio_ChannelType Dio_WriteChannel_ChannelPos = (Dio_ChannelType) (ChannelId % (Dio_ChannelType) (8));
     uint8 u8_bitMaskOffset = BIT_MASK_ADDR(Dio_WriteChannel_ChannelPos);

     /* Assign the level value to the required Channel */
     (((BaseAddrArr[Dio_WriteChannel_PortId]))->GPIODATA[u8_bitMaskOffset]) = BIT_MASK_ADDR(Level);
}

/**
 * @param ChannelId -> represent the channel id to detect the pin position in the port and also the port itself.
 *
 * @return the level of channel after flip action is taken STD_HIGH or STD_LOW.
 *
 * Description:Service to flip (change from 1 to 0 or from 0 to 1) the level of a channel and return
 *   the level of the channel after flip.
 */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
    /* Initialization local variables */
    Dio_LevelType Dio_channelStatus;
    Dio_PortType Dio_ChannelPortId = (Dio_PortType) (ChannelId / (Dio_PortType) (8));
    Dio_ChannelType Dio_ChannelPos = (Dio_ChannelType) (ChannelId % (Dio_ChannelType) (8));
    uint8 u8_bitMaskOffset = BIT_MASK_ADDR(Dio_ChannelPos);
    Std_levelType Dio_pinDirection = STD_low;
    PORT_RegType *pstr_portBaseAddr = (PORT_RegType *)BaseAddrArr[Dio_ChannelPortId];


    /* specify the current bit direction */
    Dio_pinDirection = BIT_BAND_ACCESS((uint32*)(&pstr_portBaseAddr->GPIODIR),(uint8)Dio_ChannelPos);
    /* get the current level of the selected bit */
    Dio_channelStatus = BIT_BAND_ACCESS((uint32*)(&pstr_portBaseAddr->GPIODATA[u8_bitMaskOffset]),(uint8)Dio_ChannelPos);

    /* output pin */
    if(Dio_pinDirection != STD_low)
    {
        /* toggle the pin if it's output pin */
        Dio_channelStatus ^= 0xff;
        BIT_BAND_ACCESS((uint32*)(&pstr_portBaseAddr->GPIODATA[u8_bitMaskOffset]),(uint8)Dio_ChannelPos) = Dio_channelStatus;
    }
    /* input pin */
    else
    {
        /* return current pin value without toggle */
    }
    return Dio_channelStatus;
}
/**
 *
 * @param PortId -> specify which port to write into.
 * @param Level -> value to be written
 * Description:  Service to set a value of the port.
 */
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level)
{
    BaseAddrArr[PortId]->GPIODATA[ALL_PINS] = Level;
}

/**
 *
 * @param PortId -> specify which port to write into.
 * @return value that in the whole port.
 * Description:  Returns the level of all channels of that port.
 */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
   return BaseAddrArr[PortId]->GPIODATA[ALL_PINS];
}



/**
 * @param ChannelGroupIdPtr -> pointer to channel group.
 *
 * @param Level -> value to be written STD_HIGH or STD_LOW.
 *
 * Description: Service to set a subset of the adjoining bits of a port to a specified level.
 */
void Dio_WriteChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level )
{
    BaseAddrArr[ChannelGroupIdPtr->port]->GPIODATA[ChannelGroupIdPtr->mask] = (Level << ChannelGroupIdPtr->offset);
}


/**
 * @param ChannelGroupIdPtr -> pointer to channel group.
 *
 * @return the level of group if STD_HIGH or STD_LOW.
 *
 * Description:This Service reads a subset of the adjoining bits of a port.
 */
Dio_PortLevelType Dio_ReadChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr )
{
    return ((BaseAddrArr[ChannelGroupIdPtr->port]->GPIODATA[ChannelGroupIdPtr->mask]) >> (ChannelGroupIdPtr->offset));
}





