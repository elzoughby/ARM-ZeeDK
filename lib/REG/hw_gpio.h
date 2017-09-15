/***********************************************************************
* GPIO Registers for ARM Microcontrollers GPIO Driver                  *
* @author Ahmed Elzoughby                                              *
* @date July 26, 2017                                                  *
* Purpose: Provide an easy interface to deal with digital I/O devices  *
***********************************************************************/

#ifndef MCAL_HW_GPIO_H_
#define MCAL_HW_GPIO_H_



/***********************************************************************
*                             Include Files                            *
***********************************************************************/

#include "../config.h"


/***********************************************************************
*                            Macros & Typedef                          *
***********************************************************************/

#define BASEA   BASE_A
#define BASEB   BASE_B
#define BASEC   BASE_C
#define BASED   BASE_D
#define BASEE   BASE_E
#define BASEF   BASE_F

#define PORTA   BASE_A
#define PORTB   BASE_B
#define PORTC   BASE_C
#define PORTD   BASE_D
#define PORTE   BASE_E
#define PORTF   BASE_F

#define PORT_A  BASE_A
#define PORT_B  BASE_B
#define PORT_C  BASE_C
#define PORT_D  BASE_D
#define PORT_E  BASE_E
#define PORT_F  BASE_F


#ifdef APB

/* When using Advanced Peripheral Bus */
#define BASE_A 0x40004000
#define BASE_B 0x40005000
#define BASE_C 0x40006000
#define BASE_D 0x40007000
#define BASE_E 0x40024000
#define BASE_F 0x40025000

#else

/* When using Advanced High-Performance Bus */
#define BASE_A 0x40058000
#define BASE_B 0x40059000
#define BASE_C 0x4005A000
#define BASE_D 0x4005B000
#define BASE_E 0x4005C000
#define BASE_F 0x4005D000

#endif

/*      Name                    Offset    Type  Reset       Description                         */

#define OFFSET_GPIODATA         0x000   /* RW   0x00000000  GPIO Data                           */
#define OFFSET_GPIODATA_NM      0x3FC   /* RW   0x00000000  GPIO Data Not Masked                */
#define OFFSET_GPIODIR          0x400   /* RW   0x00000000  GPIO Direction                      */
#define OFFSET_GPIOIS           0x404   /* RW   0x00000000  GPIO Interrupt Sense                */
#define OFFSET_GPIOIBE          0x408   /* RW   0x00000000  GPIO Interrupt Both Edges           */
#define OFFSET_GPIOIEV          0x40C   /* RW   0x00000000  GPIO Interrupt Event                */
#define OFFSET_GPIOIM           0x410   /* RW   0x00000000  GPIO Interrupt Mask                 */
#define OFFSET_GPIORIS          0x414   /* RO   0x00000000  GPIO Raw Interrupt Status           */
#define OFFSET_GPIOMIS          0x418   /* RO   0x00000000  GPIO Masked Interrupt Status        */
#define OFFSET_GPIOICR          0x41C   /* W1C  0x00000000  GPIO Interrupt Clear                */
#define OFFSET_GPIOAFSEL        0x420   /* RW   -           GPIO Alternate Function Select      */

#define OFFSET_GPIODR2R         0x500   /* RW   0x000000FF  GPIO 2-mA Drive Select              */
#define OFFSET_GPIODR4R         0x504   /* RW   0x00000000  GPIO 4-mA Drive Select              */
#define OFFSET_GPIODR8R         0x508   /* RW   0x00000000  GPIO 8-mA Drive Select              */
#define OFFSET_GPIOODR          0x50C   /* RW   0x00000000  GPIO Open Drain Select              */
#define OFFSET_GPIOPUR          0x510   /* RW   -           GPIO Pull-Up Select                 */
#define OFFSET_GPIOPDR          0x514   /* RW   0x00000000  GPIO Pull-Down Select               */
#define OFFSET_GPIOSLR          0x518   /* RW   0x00000000  GPIO Slew Rate Control Select       */
#define OFFSET_GPIODEN          0x51C   /* RW   -           GPIO Digital Enable                 */
#define OFFSET_GPIOLOCK         0x520   /* RW   0x00000001  GPIO Lock                           */
#define OFFSET_GPIOCR           0x524   /* -    -           GPIO Commit                         */
#define OFFSET_GPIOAMSEL        0x528   /* RW   0x00000000  GPIO Analog Mode Select             */
#define OFFSET_GPIOPCTL         0x52C   /* RW   -           GPIO Port Control                   */
#define OFFSET_GPIOADCCTL       0x530   /* RW   0x00000000  GPIO ADC Control                    */
#define OFFSET_GPIODMACTL       0x534   /* RW   0x00000000  GPIO DMA Control                    */

#define OFFSET_GPIOPeriphID4    0xFD0   /* RO   0x00000000  GPIO Peripheral Identification 4    */
#define OFFSET_GPIOPeriphID5    0xFD4   /* RO   0x00000000  GPIO Peripheral Identification 5    */
#define OFFSET_GPIOPeriphID6    0xFD8   /* RO   0x00000000  GPIO Peripheral Identification 6    */
#define OFFSET_GPIOPeriphID7    0xFDC   /* RO   0x00000000  GPIO Peripheral Identification 7    */
#define OFFSET_GPIOPeriphID0    0xFE0   /* RO   0x00000061  GPIO Peripheral Identification 0    */
#define OFFSET_GPIOPeriphID1    0xFE4   /* RO   0x00000000  GPIO Peripheral Identification 1    */
#define OFFSET_GPIOPeriphID2    0xFE8   /* RO   0x00000018  GPIO Peripheral Identification 2    */
#define OFFSET_GPIOPeriphID3    0xFEC   /* RO   0x00000001  GPIO Peripheral Identification 3    */
#define OFFSET_GPIOPCellID0     0xFF0   /* RO   0x0000000D  GPIO PrimeCell Identification 0     */
#define OFFSET_GPIOPCellID1     0xFF4   /* RO   0x000000F0  GPIO PrimeCell Identification 1     */
#define OFFSET_GPIOPCellID2     0xFF8   /* RO   0x00000005  GPIO PrimeCell Identification 2     */
#define OFFSET_GPIOPCellID3     0xFFC   /* RO   0x000000B1  GPIO PrimeCell Identification 3     */


#endif /* HW_GPIO_H_ */
