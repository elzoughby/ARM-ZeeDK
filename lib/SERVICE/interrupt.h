/***********************************************************************
* Interrupt operations for ARM Microcontrollers                        *
* @author Ahmed Elzoughby                                              *
* @date August 17, 2017                                                *
* Purpose: Provide an easy interface to deal with interrupts           *
***********************************************************************/


#ifndef SERVICE_INTERRUPT_H_
#define SERVICE_INTERRUPT_H_



/***********************************************************************
*                             Include Files                            *
***********************************************************************/

#include "../REG/hw_nvic.h"
#include "../HAL/gpio.h"


/***********************************************************************
*                            Macros & Typedef                          *
***********************************************************************/

#ifdef EASY_MODE

#define intrIRQ_t    intr_irq_t
#define intrError_t  intr_error_t

#endif


/***********************************************************************
*                         Structures & Enums                           *
***********************************************************************/

typedef enum {
    INTR_IRQ_STACK_POINTER,
    INTR_IRQ_RESET,
    INTR_IRQ_NMI,
    INTR_IRQ_HARD_FAULT,
    INTR_IRQ_MPU_FAULT,
    INTR_IRQ_BUS_FAULT,
    INTR_IRQ_USAGE_FAULT,
    INTR_IRQ_RESERVED0,
    INTR_IRQ_RESERVED1,
    INTR_IRQ_RESERVED2,
    INTR_IRQ_RESERVED3,
    INTR_IRQ_SVCALL,
    INTR_IRQ_DEBUG_MONITOR,
    INTR_IRQ_RESERVED4,
    INTR_IRQ_PENDSV,
    INTR_IRQ_SYSTICK,
    /*================*/
    INTR_IRQ_GPIO_PORTA,
    INTR_IRQ_GPIO_PORTB,
    INTR_IRQ_GPIO_PORTC,
    INTR_IRQ_GPIO_PORTD,
    INTR_IRQ_GPIO_PORTE,
    INTR_IRQ_UART0,
    INTR_IRQ_UART1,
    INTR_IRQ_SSI0,
    INTR_IRQ_I2C0,
    INTR_IRQ_PWM_FAULT,
    INTR_IRQ_PWM_GEN0,
    INTR_IRQ_PWM_GEN1,
    INTR_IRQ_PWM_GEN2,
    INTR_IRQ_QUAD_ENC0,
    INTR_IRQ_ADC_SEQ0,
    INTR_IRQ_ADC_SEQ1,
    INTR_IRQ_ADC_SEQ2,
    INTR_IRQ_ADC_SEQ3,
    INTR_IRQ_WATCHDOG,
    INTR_IRQ_TIMER0_A,
    INTR_IRQ_TIMER0_B,
    INTR_IRQ_TIMER1_A,
    INTR_IRQ_TIMER1_B,
    INTR_IRQ_TIMER2_A,
    INTR_IRQ_TIMER2_B,
    INTR_IRQ_ANALOG_COMP0,
    INTR_IRQ_ANALOG_COMP1,
    INTR_IRQ_ANALOG_COMP2,
    INTR_IRQ_SYSTEM_CTRL,
    INTR_IRQ_FLASH_CTRL,
    INTR_IRQ_GPIO_PORTF,
    INTR_IRQ_GPIO_PORTG,
    INTR_IRQ_GPIO_PORTH,
    INTR_IRQ_UART2,
    INTR_IRQ_SSI1,
    INTR_IRQ_TIMER3_A,
    INTR_IRQ_TIMER3_B,
    INTR_IRQ_I2C1,
    INTR_IRQ_QUAD_ENC1,
    INTR_IRQ_CAN0,
    INTR_IRQ_CAN1,
    INTR_IRQ_RESERVED5,
    INTR_IRQ_RESERVED6,
    INTR_IRQ_HIBERNATE,
    INTR_IRQ_USB0,
    INTR_IRQ_PWM_GEN3,
    INTR_IRQ_UDMA_TRANS,
    INTR_IRQ_UDMA_ERROR,
    INTR_IRQ_ADC1_SEQ0,
    INTR_IRQ_ADC1_SEQ1,
    INTR_IRQ_ADC1_SEQ2,
    INTR_IRQ_ADC1_SEQ3,
    INTR_IRQ_RESERVED7,
    INTR_IRQ_RESERVED8,
    INTR_IRQ_GPIO_PORTJ,
    INTR_IRQ_GPIO_PORTK,
    INTR_IRQ_GPIO_PORTL,
    INTR_IRQ_SSI2,
    INTR_IRQ_SSI3,
    INTR_IRQ_UART3,
    INTR_IRQ_UART4,
    INTR_IRQ_UART5,
    INTR_IRQ_UART6,
    INTR_IRQ_UART7,
    INTR_IRQ_RESERVED9,
    INTR_IRQ_RESERVED10,
    INTR_IRQ_RESERVED11,
    INTR_IRQ_RESERVED12,
    INTR_IRQ_I2C2,
    INTR_IRQ_I2C3,
    INTR_IRQ_TIMER4_A,
    INTR_IRQ_TIMER4_B,
    INTR_IRQ_RESERVED13,
    INTR_IRQ_RESERVED14,
    INTR_IRQ_RESERVED15,
    INTR_IRQ_RESERVED16,
    INTR_IRQ_RESERVED17,
    INTR_IRQ_RESERVED18,
    INTR_IRQ_RESERVED19,
    INTR_IRQ_RESERVED20,
    INTR_IRQ_RESERVED21,
    INTR_IRQ_RESERVED22,
    INTR_IRQ_RESERVED23,
    INTR_IRQ_RESERVED24,
    INTR_IRQ_RESERVED25,
    INTR_IRQ_RESERVED26,
    INTR_IRQ_RESERVED27,
    INTR_IRQ_RESERVED28,
    INTR_IRQ_RESERVED29,
    INTR_IRQ_RESERVED30,
    INTR_IRQ_RESERVED31,
    INTR_IRQ_RESERVED32,
    INTR_IRQ_TIMER5_A,
    INTR_IRQ_TIMER5_B,
    INTR_IRQ_WIDE_TIMER0_A,
    INTR_IRQ_WIDE_TIMER0_B,
    INTR_IRQ_WIDE_TIMER1_A,
    INTR_IRQ_WIDE_TIMER1_B,
    INTR_IRQ_WIDE_TIMER2_A,
    INTR_IRQ_WIDE_TIMER2_B,
    INTR_IRQ_WIDE_TIMER3_A,
    INTR_IRQ_WIDE_TIMER3_B,
    INTR_IRQ_WIDE_TIMER4_A,
    INTR_IRQ_WIDE_TIMER4_B,
    INTR_IRQ_WIDE_TIMER5_A,
    INTR_IRQ_WIDE_TIMER5_B,
    INTR_IRQ_FPU,
    INTR_IRQ_RESERVED33,
    INTR_IRQ_RESERVED34,
    INTR_IRQ_I2C4,
    INTR_IRQ_I2C5,
    INTR_IRQ_GPIO_PORTN,
    INTR_IRQ_QUAD_ENC2,
    INTR_IRQ_RESERVED35,
    INTR_IRQ_RESERVED36,
    INTR_IRQ_GPIO_PORTP,
    INTR_IRQ_GPIO_PORTP1,
    INTR_IRQ_GPIO_PORTP2,
    INTR_IRQ_GPIO_PORTP3,
    INTR_IRQ_GPIO_PORTP4,
    INTR_IRQ_GPIO_PORTP5,
    INTR_IRQ_GPIO_PORTP6,
    INTR_IRQ_GPIO_PORTP7,
    INTR_IRQ_GPIO_PORTQ,
    INTR_IRQ_GPIO_PORTQ1,
    INTR_IRQ_GPIO_PORTQ2,
    INTR_IRQ_GPIO_PORTQ3,
    INTR_IRQ_GPIO_PORTQ4,
    INTR_IRQ_GPIO_PORTQ5,
    INTR_IRQ_GPIO_PORTQ6,
    INTR_IRQ_GPIO_PORTQ7,
    INTR_IRQ_GPIO_PORTR,
    INTR_IRQ_GPIO_PORTS,
    INTR_IRQ_PWM1_GEN0,
    INTR_IRQ_PWM1_GEN1,
    INTR_IRQ_PWM1_GEN2,
    INTR_IRQ_PWM1_GEN3,
    INTR_IRQ_PWM1_FAULT
} intr_irq_t;

typedef enum {
    INTR_STATE_SUCCESS,
    INTR_STATE_IRQ_ERROR,
    INTR_STATE_MODE_ERROR,
    INTR_STATE_MASK_ERROR
} intr_error_t;

#ifdef EASY_MODE

typedef struct {
    gpioIntrMode_t mode;
    fptr_t handler;
} gpioIntr_t;

#endif


/***********************************************************************
*                   Global Variables Declarations                      *
***********************************************************************/

/* None */


/***********************************************************************
*                        Function Declarations                         *
***********************************************************************/

intr_error_t intr_init();

intr_error_t intr_set_default_handler(fptr_t handler);

intr_error_t intr_irq_en(intr_irq_t irq);

intr_error_t intr_irq_dis(intr_irq_t irq);

intr_error_t intr_handler_install(intr_irq_t irq, fptr_t handler);

intr_error_t intr_handler_uninstall(intr_irq_t irq);

intr_error_t intr_handler_get(intr_irq_t irq, fptr_t* dest);

intr_error_t intr_vect_install(volatile fptr_t (*new_vect)[154]);

intr_error_t intr_vect_uninstall();

intr_error_t intr_master_en();

intr_error_t intr_master_dis();

#ifdef EASY_MODE

intrError_t IntrInit();

intrError_t GPIOPinAttachIntr(gpioPin_t* pinObj, gpioIntr_t* intrObj);

intrError_t GPIOPortAttachIntr(gpioPort_t* portObj, gpioIntr_t* intrObj);

#endif

#endif /* SERVICE_INTERRUPT_H_ */
