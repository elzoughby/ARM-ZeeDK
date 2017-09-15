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

#define GPIO_BUS_CTL GPIOHBCTL
#define GPIO_CLK_CTL RCGCGPIO
#define GPIO_SLEEP_CLK_CTL SCGCGPIO
#define GPIO_DEEPSLEEP_CLK_CTL DCGCGPIO

/* controls which internal bus is used to access each GPIO port */
#define GPIOHBCTL 0x400FE06C
/* control the clocking for the GPIO modules */
#define RCGCGPIO 0x400FE608
/* GPIO Sleep Mode Clock Gating Control */
#define SCGCGPIO 0x400FE708
/* GPIO Deep-Sleep Mode Clock Gating Control */
#define DCGCGPIO 0x400FE808



#endif /* HW_SYSTEM_H_ */
