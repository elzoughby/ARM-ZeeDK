/***********************************************************************
* Timer Registers for ARM Microcontrollers Timer Driver                *
* @author Ahmed Elzoughby                                              *
* @date July 26, 2017                                                  *
* Purpose: Provide an easy interface to deal with Timers               *
***********************************************************************/

#ifndef REG_HW_TIMER_H_
#define REG_HW_TIMER_H_



/***********************************************************************
*                             Include Files                            *
***********************************************************************/

#include "../config.h"


/***********************************************************************
*                            Macros & Typedef                          *
***********************************************************************/

typedef enum {
    BASE_TIMER0  = 0x40030000,
    BASE_TIMER1  = 0x40031000,
    BASE_TIMER2  = 0x40032000,
    BASE_TIMER3  = 0x40033000,
    BASE_TIMER4  = 0x40034000,
    BASE_TIMER5  = 0x40035000,
    BASE_WTIMER0 = 0x40036000,
    BASE_WTIMER1 = 0x40037000,
    BASE_WTIMER2 = 0x4004C000,
    BASE_WTIMER3 = 0x4004D000,
    BASE_WTIMER4 = 0x4004E000,
    BASE_WTIMER5 = 0x4004F000
} timer_base_t;

/*      Name                Offset   Type Reset        Description                     */
/*-------------------------------------------------------------------------------------*/
#define OFFSET_GPTMCFG      0x000  /* RW  0x00000000   GPTM Configuration              */
#define OFFSET_GPTMTAMR     0x004  /* RW  0x00000000   GPTM Timer A Mode               */
#define OFFSET_GPTMTBMR     0x008  /* RW  0x00000000   GPTM Timer B Mode               */
#define OFFSET_GPTMCTL      0x00C  /* RW  0x00000000   GPTM Control                    */
#define OFFSET_GPTMSYNC     0x010  /* RW  0x00000000   GPTM Synchronize                */
#define OFFSET_GPTMIMR      0x018  /* RW  0x00000000   GPTM Interrupt Mask             */
#define OFFSET_GPTMRIS      0x01C  /* RO  0x00000000   GPTM Raw Interrupt Status       */
#define OFFSET_GPTMMIS      0x020  /* RO  0x00000000   GPTM Masked Interrupt Status    */
#define OFFSET_GPTMICR      0x024  /* W1C 0x00000000   GPTM Interrupt Clear            */
#define OFFSET_GPTMTAILR    0x028  /* RW  0xFFFFFFFF   GPTM Timer A Interval Load      */
#define OFFSET_GPTMTBILR    0x02C  /* RW  -            GPTM Timer B Interval Load      */
#define OFFSET_GPTMTAMATCHR 0x030  /* RW  0xFFFFFFFF   GPTM Timer A Match              */
#define OFFSET_GPTMTBMATCHR 0x034  /* RW  -            GPTM Timer B Match              */
#define OFFSET_GPTMTAPR     0x038  /* RW  0x00000000   GPTM Timer A Prescale           */
#define OFFSET_GPTMTBPR     0x03C  /* RW  0x00000000   GPTM Timer B Prescale           */
#define OFFSET_GPTMTAPMR    0x040  /* RW  0x00000000   GPTM TimerA Prescale Match      */
#define OFFSET_GPTMTBPMR    0x044  /* RW  0x00000000   GPTM TimerB Prescale Match      */
#define OFFSET_GPTMTAR      0x048  /* RO  0xFFFFFFFF   GPTM Timer A                    */
#define OFFSET_GPTMTBR      0x04C  /* RO  -            GPTM Timer B                    */
#define OFFSET_GPTMTAV      0x050  /* RW  0xFFFFFFFF   GPTM Timer A Value              */
#define OFFSET_GPTMTBV      0x054  /* RW  -            GPTM Timer B Value              */
#define OFFSET_GPTMRTCPD    0x058  /* RO  0x00007FFF   GPTM RTC Predivide              */
#define OFFSET_GPTMTAPS     0x05C  /* RO  0x00000000   GPTM Timer A Prescale Snapshot  */
#define OFFSET_GPTMTBPS     0x060  /* RO  0x00000000   GPTM Timer B Prescale Snapshot  */
#define OFFSET_GPTMTAPV     0x064  /* RO  0x00000000   GPTM Timer A Prescale Value     */
#define OFFSET_GPTMTBPV     0x068  /* RO  0x00000000   GPTM Timer B Prescale Value     */
#define OFFSET_GPTMPP       0xFC0  /* RO  0x00000000   GPTM Peripheral Properties      */

#define BIT_TAEN 0
#define BIT_TBEN 8


#endif /* REG_HW_TIMER_H_ */
