/***********************************************************************
* UART Registers for ARM Microcontrollers UART Driver                  *
* @author Ahmed Elzoughby                                              *
* @date July 26, 2017                                                  *
* Purpose: Provide an easy interface to deal with UART                 *
***********************************************************************/


#ifndef REG_HW_UART_H_
#define REG_HW_UART_H_


/***********************************************************************
*                             Include Files                            *
***********************************************************************/

#include "../config.h"


/***********************************************************************
*                            Macros & Typedef                          *
***********************************************************************/

typedef enum {
    BASE_UART0 = 0x4000C000,
    BASE_UART1 = 0x4000D000,
    BASE_UART2 = 0x4000E000,
    BASE_UART3 = 0x4000F000,
    BASE_UART4 = 0x40010000,
    BASE_UART5 = 0x40011000,
    BASE_UART6 = 0x40012000,
    BASE_UART7 = 0x40013000
} uart_base_t;


/*      Name                   Offset    Type Reset       Description                      */
/*-----------------------------------------------------------------------------------------*/
#define OFFSET_UARTDR          0x000   /* RW  0x00000000  UART Data                        */
#define OFFSET_UARTRSR         0x004   /* RW  0x00000000  UART Receive Status              */
#define OFFSET_UARTECR         0x004   /* RW  0x00000000  UART Error Clear                 */
#define OFFSET_UARTFR          0x018   /* RO  0x00000090  UART Flag                        */
#define OFFSET_UARTILPR        0x020   /* RW  0x00000000  UART IrDA Low-Power Register     */
#define OFFSET_UARTIBRD        0x024   /* RW  0x00000000  UART Integer Baud-Rate Divisor   */
#define OFFSET_UARTFBRD        0x028   /* RW  0x00000000  UART Fractional BaudRate Divisor */
#define OFFSET_UARTLCRH        0x02C   /* RW  0x00000000  UART Line Control                */
#define OFFSET_UARTCTL         0x030   /* RW  0x00000300  UART Control                     */
#define OFFSET_UARTIFLS        0x034   /* RW  0x00000012  UART Interrupt FIFO Level Select */
#define OFFSET_UARTIM          0x038   /* RW  0x00000000  UART Interrupt Mask              */
#define OFFSET_UARTRIS         0x03C   /* RO  0x00000000  UART Raw Interrupt Status        */
#define OFFSET_UARTMIS         0x040   /* RO  0x00000000  UART Masked Interrupt Status     */
#define OFFSET_UARTICR         0x044   /* W1C 0x00000000  UART Interrupt Clear             */
#define OFFSET_UARTDMACTL      0x048   /* RW  0x00000000  UART DMA Control                 */
#define OFFSET_UART9BITADDR    0x0A4   /* RW  0x00000000  UART 9-Bit Self Address          */
#define OFFSET_UART9BITAMASK   0x0A8   /* RW  0x000000FF  UART 9-Bit Self Address Mask     */
#define OFFSET_UARTPP          0xFC0   /* RO  0x00000003  UART Peripheral Properties       */
#define OFFSET_UARTCC          0xFC8   /* RW  0x00000000  UART Clock Configuration         */
#define OFFSET_UARTPeriphID4   0xFD0   /* RO  0x00000000  UART Peripheral Id 4             */
#define OFFSET_UARTPeriphID5   0xFD4   /* RO  0x00000000  UART Peripheral Id 5             */
#define OFFSET_UARTPeriphID6   0xFD8   /* RO  0x00000000  UART Peripheral Id 6             */
#define OFFSET_UARTPeriphID7   0xFDC   /* RO  0x00000000  UART Peripheral Id 7             */
#define OFFSET_UARTPeriphID0   0xFE0   /* RO  0x00000060  UART Peripheral Id 0             */
#define OFFSET_UARTPeriphID1   0xFE4   /* RO  0x00000000  UART Peripheral Id 1             */
#define OFFSET_UARTPeriphID2   0xFE8   /* RO  0x00000018  UART Peripheral Id 2             */
#define OFFSET_UARTPeriphID3   0xFEC   /* RO  0x00000001  UART Peripheral Id 3             */
#define OFFSET_UARTPCellID0    0xFF0   /* RO  0x0000000D  UART PrimeCell Id 0              */
#define OFFSET_UARTPCellID1    0xFF4   /* RO  0x000000F0  UART PrimeCell Id 1              */
#define OFFSET_UARTPCellID2    0xFF8   /* RO  0x00000005  UART PrimeCell Id 2              */
#define OFFSET_UARTPCellID3    0xFFC   /* RO  0x000000B1  UART PrimeCell Id 3              */


#endif /* REG_HW_UART_H_ */
