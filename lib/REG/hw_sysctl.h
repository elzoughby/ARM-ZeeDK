/***********************************************************************
* System Registers for ARM Microcontrollers GPIO Driver                *
* @author Ahmed Elzoughby                                              *
* @date July 26, 2017                                                  *
* Purpose: Provide an easy interface to deal with system features      *
***********************************************************************/

#ifndef REG_HW_SYSCTL_H_
#define REG_HW_SYSCTL_H_



/***********************************************************************
*                             Include Files                            *
***********************************************************************/

/* None */


/***********************************************************************
*                            Macros & Typedef                          *
***********************************************************************/

#define BASE_SYSCTL 0x400FE000

/*      Name                Offset   Type   Reset       Description                                 */

#define OFFSET_GPIOHBCTL    0x06C  /* RW    0x00007E00  GPIO High-Performance Bus Control           */

#define OFFSET_RCGCGPIO     0x608  /* RW    0x00000000  GPIO Run Mode Clock Gating Control          */
#define OFFSET_SCGCGPIO     0x708  /* RW    0x00000000  GPIO Sleep Mode Clock Gating Control        */
#define OFFSET_DCGCGPIO     0x808  /* RW    0x00000000  GPIO Deep-Sleep Mode Clock Gating Control   */

#define OFFSET_RCGCTIMER    0x604  /* RW    0x00000000  Timer Run Mode Clock Gating Control         */
#define OFFSET_SCGCTIMER    0x704  /* RW    0x00000000  Timer Sleep Mode Clock Gating Control       */
#define OFFSET_DCGCTIMER    0x804  /* RW    0x00000000  Timer Deep-Sleep Mode Clock Gating Control  */

#define OFFSET_RCGCWTIMER   0x65C  /* RW    0x00000000  WideTimer Run Mode Clock Gating Control     */
#define OFFSET_SCGCWTIMER   0x75C  /* RW    0x00000000  WideTimer Sleep Mode Clock Gating Control   */
#define OFFSET_DCGCWTIMER   0x85C  /* RW    0x00000000  WideTimer Deep-Sleep Mode Clock Gating ctrl */


#endif /* HW_SYSTEM_H_ */
