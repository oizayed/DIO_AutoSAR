/*
 * Dio_Types.h
 *
 *  Created on: Feb 19, 2020
 *      Author: Ghanem, Zayed, Atef & Amayem
 */

#ifndef TM4C123_FIRMWARE_LATTE_WORKSHOP_MCAL_DIO_DIO_TYPES_H_
#define TM4C123_FIRMWARE_LATTE_WORKSHOP_MCAL_DIO_DIO_TYPES_H_


typedef uint8 Dio_ChannelType;

#define Dio_Channel_A0          (Dio_ChannelType)0
#define Dio_Channel_A1          (Dio_ChannelType)1
#define Dio_Channel_A2          (Dio_ChannelType)2
#define Dio_Channel_A3          (Dio_ChannelType)3
#define Dio_Channel_A4          (Dio_ChannelType)4
#define Dio_Channel_A5          (Dio_ChannelType)5
#define Dio_Channel_A6          (Dio_ChannelType)6
#define Dio_Channel_A7          (Dio_ChannelType)7

#define Dio_Channel_B0          (Dio_ChannelType)8
#define Dio_Channel_B1          (Dio_ChannelType)9
#define Dio_Channel_B2          (Dio_ChannelType)10
#define Dio_Channel_B3          (Dio_ChannelType)11
#define Dio_Channel_B4          (Dio_ChannelType)12
#define Dio_Channel_B5          (Dio_ChannelType)13
#define Dio_Channel_B6          (Dio_ChannelType)14
#define Dio_Channel_B7          (Dio_ChannelType)15

#define Dio_Channel_C0          (Dio_ChannelType)16
#define Dio_Channel_C1          (Dio_ChannelType)17
#define Dio_Channel_C2          (Dio_ChannelType)18
#define Dio_Channel_C3          (Dio_ChannelType)19
#define Dio_Channel_C4          (Dio_ChannelType)20
#define Dio_Channel_C5          (Dio_ChannelType)21
#define Dio_Channel_C6          (Dio_ChannelType)22
#define Dio_Channel_C7          (Dio_ChannelType)23

#define Dio_Channel_D0          (Dio_ChannelType)24
#define Dio_Channel_D1          (Dio_ChannelType)25
#define Dio_Channel_D2          (Dio_ChannelType)26
#define Dio_Channel_D3          (Dio_ChannelType)27
#define Dio_Channel_D4          (Dio_ChannelType)28
#define Dio_Channel_D5          (Dio_ChannelType)29
#define Dio_Channel_D6          (Dio_ChannelType)30
#define Dio_Channel_D7          (Dio_ChannelType)31

#define Dio_Channel_E0          (Dio_ChannelType)32
#define Dio_Channel_E1          (Dio_ChannelType)33
#define Dio_Channel_E2          (Dio_ChannelType)34
#define Dio_Channel_E3          (Dio_ChannelType)35
#define Dio_Channel_E4          (Dio_ChannelType)36
#define Dio_Channel_E5          (Dio_ChannelType)37
#define Dio_Channel_E6_NA       (Dio_ChannelType)38
#define Dio_Channel_E7_NA       (Dio_ChannelType)39

#define Dio_Channel_F0          (Dio_ChannelType)40
#define Dio_Channel_F1          (Dio_ChannelType)41
#define Dio_Channel_F2          (Dio_ChannelType)42
#define Dio_Channel_F3          (Dio_ChannelType)43
#define Dio_Channel_F4          (Dio_ChannelType)44


typedef uint8 Dio_PortType;

#define Dio_Port_A              (Dio_PortType)0
#define Dio_Port_B              (Dio_PortType)1
#define Dio_Port_C              (Dio_PortType)2
#define Dio_Port_D              (Dio_PortType)3
#define Dio_Port_E              (Dio_PortType)4
#define Dio_Port_F              (Dio_PortType)5

typedef struct
{
    uint8 mask;
    uint8 offset;
    Dio_PortType port;
}Dio_ChannelGroupType;

typedef uint8 Dio_LevelType;

#define STD_LOW     (Dio_LevelType)0x00
#define STD_HIGH    (Dio_LevelType)0x01

typedef uint8 Dio_PortLevelType;


#endif /* TM4C123_FIRMWARE_LATTE_WORKSHOP_MCAL_DIO_DIO_TYPES_H_ */
