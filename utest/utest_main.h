#ifndef UTEST_MAIN_H
#define UTEST_MAIN_H

#include <stdio.h>
#include "types.h"

#include "HAL_API.h"
#include "HAL_IPC.h"
#include "tcc_ipc_protocol.h"
#include "uart.h"

#define STD_NULL					0					/*!< Null Value						*/

#define STD_TRUE					1					/*!< Boolean True					*/
#define STD_FALSE					0					/*!< Boolean False					*/

typedef unsigned char				Type_uByte;			/*!< Unsigned 8-Bit Integer			*/
typedef unsigned short int			Type_uHWord;		/*!< Unsigned 16-Bit Integer		*/
typedef unsigned long int			Type_uWord;			/*!< Unsigned 32-Bit Integer		*/
typedef unsigned long long int		Type_uDWord;		/*!< Unsigned 64-Bit Integer		*/

typedef signed char					Type_sByte;			/*!< Signed 8-Bit Integer 			*/
typedef signed short int			Type_sHWord;		/*!< Signed 16-Bit Integer			*/
typedef signed long int				Type_sWord;			/*!< Signed 32-Bit Integer			*/
typedef signed long long int		Type_sDWord;		/*!< Signed 64-Bit Integer			*/

typedef	float						Type_Float;			/*!< 32-Bit Floating Point Number	*/
typedef	double						Type_Double;		/*!< 64-Bit Floating Point Number 	*/

typedef char						Type_Char;			/*! Character 						*/

enum ApiCallResponse {

	RES_OK =						0,					/*!< OK								*/
	RES_NG							,					/*!< NG								*/
	RES_BUSY											/*!< Busy							*/

};

#define ROUTING_DEBUG(fmt, args...)   printf(fmt, ## args)

#define UART_BUFF_SIZE		0x400	// 1024
#define UART_MODE_TX		0
#define UART_MODE_RX		1
#define IPC_BUFF_SIZE		0x200	// 512

#endif // UTEST_MAIN_H
