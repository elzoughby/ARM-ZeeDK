/***********************************************************************
* NVIC Registers for ARM Microcontrollers GPIO Driver                  *
* @author Ahmed Elzoughby                                              *
* @date July 26, 2017                                                  *
* Purpose: Provide an easy interface to deal with NVIC features        *
***********************************************************************/


#ifndef REG_HW_CORE_H_
#define REG_HW_CORE_H_


/***********************************************************************
*                             Include Files                            *
***********************************************************************/

/* None */


/***********************************************************************
*                            Macros & Typedef                          *
***********************************************************************/

#define BASE_CORE 0xE000E000


/*      Name           Offset    Type Reset       Description                       */
/*----------------------------------------------------------------------------------*/
#define OFFSET_EN0     0x100   /* RW  0x00000000  Interrupt 0-31 Set Enable         */
#define OFFSET_EN1     0x104   /* RW  0x00000000  Interrupt 32-63 Set Enable        */
#define OFFSET_EN2     0x108   /* RW  0x00000000  Interrupt 64-95 Set Enable        */
#define OFFSET_EN3     0x10C   /* RW  0x00000000  Interrupt 96-127 Set Enable       */
#define OFFSET_EN4     0x110   /* RW  0x00000000  Interrupt 128-138 Set Enable      */
#define OFFSET_DIS0    0x180   /* RW  0x00000000  Interrupt 0-31 Clear Enable       */
#define OFFSET_DIS1    0x184   /* RW  0x00000000  Interrupt 32-63 Clear Enable      */
#define OFFSET_DIS2    0x188   /* RW  0x00000000  Interrupt 64-95 Clear Enable      */
#define OFFSET_DIS3    0x18C   /* RW  0x00000000  Interrupt 96-127 Clear Enable     */
#define OFFSET_DIS4    0x190   /* RW  0x00000000  Interrupt 128-138 Clear Enable    */
#define OFFSET_PEND0   0x200   /* RW  0x00000000  Interrupt 0-31 Set Pending        */
#define OFFSET_PEND1   0x204   /* RW  0x00000000  Interrupt 32-63 Set Pending       */
#define OFFSET_PEND2   0x208   /* RW  0x00000000  Interrupt 64-95 Set Pending       */
#define OFFSET_PEND3   0x20C   /* RW  0x00000000  Interrupt 96-127 Set Pending      */
#define OFFSET_PEND4   0x210   /* RW  0x00000000  Interrupt 128-138 Set Pending     */
#define OFFSET_UNPEND0 0x280   /* RW  0x00000000  Interrupt 0-31 Clear Pending      */
#define OFFSET_UNPEND1 0x284   /* RW  0x00000000  Interrupt 32-63 Clear Pending     */
#define OFFSET_UNPEND2 0x288   /* RW  0x00000000  Interrupt 64-95 Clear Pending     */
#define OFFSET_UNPEND3 0x28C   /* RW  0x00000000  Interrupt 96-127 Clear Pending    */
#define OFFSET_UNPEND4 0x290   /* RW  0x00000000  Interrupt 128-138 Clear Pending   */
#define OFFSET_ACTIVE0 0x300   /* RO  0x00000000  Interrupt 0-31 Active Bit         */
#define OFFSET_ACTIVE1 0x304   /* RO  0x00000000  Interrupt 32-63 Active Bit        */
#define OFFSET_ACTIVE2 0x308   /* RO  0x00000000  Interrupt 64-95 Active Bit        */
#define OFFSET_ACTIVE3 0x30C   /* RO  0x00000000  Interrupt 96-127 Active Bit       */
#define OFFSET_ACTIVE4 0x310   /* RO  0x00000000  Interrupt 128-138 Active Bit      */
#define OFFSET_PRI0    0x400   /* RW  0x00000000  Interrupt 0-3 Priority            */
#define OFFSET_PRI1    0x404   /* RW  0x00000000  Interrupt 4-7 Priority            */
#define OFFSET_PRI2    0x408   /* RW  0x00000000  Interrupt 8-11 Priority           */
#define OFFSET_PRI3    0x40C   /* RW  0x00000000  Interrupt 12-15 Priority          */
#define OFFSET_PRI4    0x410   /* RW  0x00000000  Interrupt 16-19 Priority          */
#define OFFSET_PRI5    0x414   /* RW  0x00000000  Interrupt 20-23 Priority          */
#define OFFSET_PRI6    0x418   /* RW  0x00000000  Interrupt 24-27 Priority          */
#define OFFSET_PRI7    0x41C   /* RW  0x00000000  Interrupt 28-31 Priority          */
#define OFFSET_PRI8    0x420   /* RW  0x00000000  Interrupt 32-35 Priority          */
#define OFFSET_PRI9    0x424   /* RW  0x00000000  Interrupt 36-39 Priority          */
#define OFFSET_PRI10   0x428   /* RW  0x00000000  Interrupt 40-43 Priority          */
#define OFFSET_PRI11   0x42C   /* RW  0x00000000  Interrupt 44-47 Priority          */
#define OFFSET_PRI12   0x430   /* RW  0x00000000  Interrupt 48-51 Priority          */
#define OFFSET_PRI13   0x434   /* RW  0x00000000  Interrupt 52-55 Priority          */
#define OFFSET_PRI14   0x438   /* RW  0x00000000  Interrupt 56-59 Priority          */
#define OFFSET_PRI15   0x43C   /* RW  0x00000000  Interrupt 60-63 Priority          */
#define OFFSET_PRI16   0x440   /* RW  0x00000000  Interrupt 64-67 Priority          */
#define OFFSET_PRI17   0x444   /* RW  0x00000000  Interrupt 68-71 Priority          */
#define OFFSET_PRI18   0x448   /* RW  0x00000000  Interrupt 72-75 Priority          */
#define OFFSET_PRI19   0x44C   /* RW  0x00000000  Interrupt 76-79 Priority          */
#define OFFSET_PRI20   0x450   /* RW  0x00000000  Interrupt 80-83 Priority          */
#define OFFSET_PRI21   0x454   /* RW  0x00000000  Interrupt 84-87 Priority          */
#define OFFSET_PRI22   0x458   /* RW  0x00000000  Interrupt 88-91 Priority          */
#define OFFSET_PRI23   0x45C   /* RW  0x00000000  Interrupt 92-95 Priority          */
#define OFFSET_PRI24   0x460   /* RW  0x00000000  Interrupt 96-99 Priority          */
#define OFFSET_PRI25   0x464   /* RW  0x00000000  Interrupt 100-103 Priority        */
#define OFFSET_PRI26   0x468   /* RW  0x00000000  Interrupt 104-107 Priority        */
#define OFFSET_PRI27   0x46C   /* RW  0x00000000  Interrupt 108-111 Priority        */
#define OFFSET_PRI28   0x470   /* RW  0x00000000  Interrupt 112-115 Priority        */
#define OFFSET_PRI29   0x474   /* RW  0x00000000  Interrupt 116-119 Priority        */
#define OFFSET_PRI30   0x478   /* RW  0x00000000  Interrupt 120-123 Priority        */
#define OFFSET_PRI31   0x47C   /* RW  0x00000000  Interrupt 124-127 Priority        */
#define OFFSET_PRI32   0x480   /* RW  0x00000000  Interrupt 128-131 Priority        */
#define OFFSET_PRI33   0x484   /* RW  0x00000000  Interrupt 132-135 Priority        */
#define OFFSET_PRI34   0x488   /* RW  0x00000000  Interrupt 136-138 Priority        */
#define OFFSET_SWTRIG  0xF00   /* WO  0x00000000  Software Trigger Interrupt        */

#define OFFSET_VTABLE  0xD08   /* RW  0x00000000  Vector Table Offset               */



#endif /* REG_HW_CORE_H_ */
