/***********************************************************************
* Interrupt operations for ARM Microcontrollers                        *
* @author Ahmed Elzoughby                                              *
* @date August 17, 2017                                                *
* Purpose: Provide an easy interface to deal with interrupts           *
***********************************************************************/



/***********************************************************************
*                             Include Files                            *
***********************************************************************/

#include "interrupt.h"


/***********************************************************************
*                            Macros & Typedef                          *
***********************************************************************/

/* None */


/***********************************************************************
*                         Structures & Enums                           *
***********************************************************************/

/* None */


/***********************************************************************
*                    Static Function Declarations                      *
***********************************************************************/

extern void ResetISR(void);

static void Stuck(void);

static void intr_isr_reset(void);

static void intr_isr_default(void);


#ifdef EASY_MODE

static void intr_isr_gpio_porta(void);

static void intr_isr_gpio_portb(void);

static void intr_isr_gpio_portc(void);

static void intr_isr_gpio_portd(void);

static void intr_isr_gpio_porte(void);

static void intr_isr_gpio_portf(void);

#endif


/***********************************************************************
*                   Global Variables Declarations                      *
***********************************************************************/

volatile static fptr_t INTR_ISR_RESET = ResetISR;
volatile static fptr_t INTR_ISR_DEFAULT = Stuck;

volatile static fptr_t vector_table[] = {
    0,                                  // The stack pointer
    intr_isr_reset,                     // The reset handler
    intr_isr_default,                   // The NMI handler
    intr_isr_default,                   // The hard fault handler
    intr_isr_default,                   // The MPU fault handler
    intr_isr_default,                   // The bus fault handler
    intr_isr_default,                   // The usage fault handler
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    intr_isr_default,                   // SVCall handler
    intr_isr_default,                   // Debug monitor handler
    0,                                  // Reserved
    intr_isr_default,                   // The PendSV handler
    intr_isr_default,                   // The SysTick handler

    intr_isr_default,                   // GPIO Port A
    intr_isr_default,                   // GPIO Port B
    intr_isr_default,                   // GPIO Port C
    intr_isr_default,                   // GPIO Port D
    intr_isr_default,                   // GPIO Port E
    intr_isr_default,                   // UART0 Rx and Tx
    intr_isr_default,                   // UART1 Rx and Tx
    intr_isr_default,                   // SSI0 Rx and Tx
    intr_isr_default,                   // I2C0 Master and Slave
    intr_isr_default,                   // PWM Fault
    intr_isr_default,                   // PWM Generator 0
    intr_isr_default,                   // PWM Generator 1
    intr_isr_default,                   // PWM Generator 2
    intr_isr_default,                   // Quadrature Encoder 0
    intr_isr_default,                   // ADC Sequence 0
    intr_isr_default,                   // ADC Sequence 1
    intr_isr_default,                   // ADC Sequence 2
    intr_isr_default,                   // ADC Sequence 3
    intr_isr_default,                   // Watchdog timer
    intr_isr_default,                   // Timer 0 subtimer A
    intr_isr_default,                   // Timer 0 subtimer B
    intr_isr_default,                   // Timer 1 subtimer A
    intr_isr_default,                   // Timer 1 subtimer B
    intr_isr_default,                   // Timer 2 subtimer A
    intr_isr_default,                   // Timer 2 subtimer B
    intr_isr_default,                   // Analog Comparator 0
    intr_isr_default,                   // Analog Comparator 1
    intr_isr_default,                   // Analog Comparator 2
    intr_isr_default,                   // System Control (PLL, OSC, BO)
    intr_isr_default,                   // FLASH Control
    intr_isr_default,                   // GPIO Port F
    intr_isr_default,                   // GPIO Port G
    intr_isr_default,                   // GPIO Port H
    intr_isr_default,                   // UART2 Rx and Tx
    intr_isr_default,                   // SSI1 Rx and Tx
    intr_isr_default,                   // Timer 3 subtimer A
    intr_isr_default,                   // Timer 3 subtimer B
    intr_isr_default,                   // I2C1 Master and Slave
    intr_isr_default,                   // Quadrature Encoder 1
    intr_isr_default,                   // CAN0
    intr_isr_default,                   // CAN1
    0,                                  // Reserved
    0,                                  // Reserved
    intr_isr_default,                   // Hibernate
    intr_isr_default,                   // USB0
    intr_isr_default,                   // PWM Generator 3
    intr_isr_default,                   // uDMA Software Transfer
    intr_isr_default,                   // uDMA Error
    intr_isr_default,                   // ADC1 Sequence 0
    intr_isr_default,                   // ADC1 Sequence 1
    intr_isr_default,                   // ADC1 Sequence 2
    intr_isr_default,                   // ADC1 Sequence 3
    0,                                  // Reserved
    0,                                  // Reserved
    intr_isr_default,                   // GPIO Port J
    intr_isr_default,                   // GPIO Port K
    intr_isr_default,                   // GPIO Port L
    intr_isr_default,                   // SSI2 Rx and Tx
    intr_isr_default,                   // SSI3 Rx and Tx
    intr_isr_default,                   // UART3 Rx and Tx
    intr_isr_default,                   // UART4 Rx and Tx
    intr_isr_default,                   // UART5 Rx and Tx
    intr_isr_default,                   // UART6 Rx and Tx
    intr_isr_default,                   // UART7 Rx and Tx
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    intr_isr_default,                   // I2C2 Master and Slave
    intr_isr_default,                   // I2C3 Master and Slave
    intr_isr_default,                   // Timer 4 subtimer A
    intr_isr_default,                   // Timer 4 subtimer B
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    0,                                  // Reserved
    intr_isr_default,                   // Timer 5 subtimer A
    intr_isr_default,                   // Timer 5 subtimer B
    intr_isr_default,                   // Wide Timer 0 subtimer A
    intr_isr_default,                   // Wide Timer 0 subtimer B
    intr_isr_default,                   // Wide Timer 1 subtimer A
    intr_isr_default,                   // Wide Timer 1 subtimer B
    intr_isr_default,                   // Wide Timer 2 subtimer A
    intr_isr_default,                   // Wide Timer 2 subtimer B
    intr_isr_default,                   // Wide Timer 3 subtimer A
    intr_isr_default,                   // Wide Timer 3 subtimer B
    intr_isr_default,                   // Wide Timer 4 subtimer A
    intr_isr_default,                   // Wide Timer 4 subtimer B
    intr_isr_default,                   // Wide Timer 5 subtimer A
    intr_isr_default,                   // Wide Timer 5 subtimer B
    intr_isr_default,                   // FPU
    0,                                  // Reserved
    0,                                  // Reserved
    intr_isr_default,                   // I2C4 Master and Slave
    intr_isr_default,                   // I2C5 Master and Slave
    intr_isr_default,                   // GPIO Port N
    intr_isr_default,                   // Quadrature Encoder 2
    0,                                  // Reserved
    0,                                  // Reserved
    intr_isr_default,                   // GPIO Port P (Summary or P0)
    intr_isr_default,                   // GPIO Port P1
    intr_isr_default,                   // GPIO Port P2
    intr_isr_default,                   // GPIO Port P3
    intr_isr_default,                   // GPIO Port P4
    intr_isr_default,                   // GPIO Port P5
    intr_isr_default,                   // GPIO Port P6
    intr_isr_default,                   // GPIO Port P7
    intr_isr_default,                   // GPIO Port Q (Summary or Q0)
    intr_isr_default,                   // GPIO Port Q1
    intr_isr_default,                   // GPIO Port Q2
    intr_isr_default,                   // GPIO Port Q3
    intr_isr_default,                   // GPIO Port Q4
    intr_isr_default,                   // GPIO Port Q5
    intr_isr_default,                   // GPIO Port Q6
    intr_isr_default,                   // GPIO Port Q7
    intr_isr_default,                   // GPIO Port R
    intr_isr_default,                   // GPIO Port S
    intr_isr_default,                   // PWM 1 Generator 0
    intr_isr_default,                   // PWM 1 Generator 1
    intr_isr_default,                   // PWM 1 Generator 2
    intr_isr_default,                   // PWM 1 Generator 3
    intr_isr_default                    // PWM 1 Fault
};

#ifdef EASY_MODE

static fptr_t intr_isr_gpio_porta_vect[] = { intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default
};

static fptr_t intr_isr_gpio_portb_vect[] = { intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default
};

static fptr_t intr_isr_gpio_portc_vect[] = { intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default
};

static fptr_t intr_isr_gpio_portd_vect[] = { intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default
};

static fptr_t intr_isr_gpio_porte_vect[] = { intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default
};

static fptr_t intr_isr_gpio_portf_vect[] = { intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default,
                                             intr_isr_default
};

#endif


/***********************************************************************
*                    Static Function Definitions                       *
***********************************************************************/

static void Stuck(void)
{
    // Go into an infinite loop.
    while(1);
}

static void intr_isr_reset(void)
{
    INTR_ISR_RESET();
}

static void intr_isr_default(void)
{
    INTR_ISR_DEFAULT();
}


#ifdef EASY_MODE

static void intr_isr_gpio_porta(void)
{
    uint8_t intr_status;
    gpio_port_get_masked_intr_status(PORTA, &intr_status);

    if (intr_status & 0x01)
        intr_isr_gpio_porta_vect[0]();

    if (intr_status & 0x02)
        intr_isr_gpio_porta_vect[1]();

    if (intr_status & 0x04)
        intr_isr_gpio_porta_vect[2]();

    if (intr_status & 0x08)
        intr_isr_gpio_porta_vect[3]();

    if (intr_status & 0x10)
        intr_isr_gpio_porta_vect[4]();

    if (intr_status & 0x20)
        intr_isr_gpio_porta_vect[5]();

    if (intr_status & 0x40)
        intr_isr_gpio_porta_vect[6]();

    if (intr_status & 0x80)
        intr_isr_gpio_porta_vect[7]();
}

static void intr_isr_gpio_portb(void)
{
    uint8_t intr_status;
    gpio_port_get_masked_intr_status(PORTB, &intr_status);

    if (intr_status & 0x01)
        intr_isr_gpio_portb_vect[0]();

    if (intr_status & 0x02)
        intr_isr_gpio_portb_vect[1]();

    if (intr_status & 0x04)
        intr_isr_gpio_portb_vect[2]();

    if (intr_status & 0x08)
        intr_isr_gpio_portb_vect[3]();

    if (intr_status & 0x10)
        intr_isr_gpio_portb_vect[4]();

    if (intr_status & 0x20)
        intr_isr_gpio_portb_vect[5]();

    if (intr_status & 0x40)
        intr_isr_gpio_portb_vect[6]();

    if (intr_status & 0x80)
        intr_isr_gpio_portb_vect[7]();
}

static void intr_isr_gpio_portc(void)
{
    uint8_t intr_status;
    gpio_port_get_masked_intr_status(PORTC, &intr_status);

    if (intr_status & 0x01)
        intr_isr_gpio_portc_vect[0]();

    if (intr_status & 0x02)
        intr_isr_gpio_portc_vect[1]();

    if (intr_status & 0x04)
        intr_isr_gpio_portc_vect[2]();

    if (intr_status & 0x08)
        intr_isr_gpio_portc_vect[3]();

    if (intr_status & 0x10)
        intr_isr_gpio_portc_vect[4]();

    if (intr_status & 0x20)
        intr_isr_gpio_portc_vect[5]();

    if (intr_status & 0x40)
        intr_isr_gpio_portc_vect[6]();

    if (intr_status & 0x80)
        intr_isr_gpio_portc_vect[7]();
}

static void intr_isr_gpio_portd(void)
{
    uint8_t intr_status;
    gpio_port_get_masked_intr_status(PORTD, &intr_status);

    if (intr_status & 0x01)
        intr_isr_gpio_portd_vect[0]();

    if (intr_status & 0x02)
        intr_isr_gpio_portd_vect[1]();

    if (intr_status & 0x04)
        intr_isr_gpio_portd_vect[2]();

    if (intr_status & 0x08)
        intr_isr_gpio_portd_vect[3]();

    if (intr_status & 0x10)
        intr_isr_gpio_portd_vect[4]();

    if (intr_status & 0x20)
        intr_isr_gpio_portd_vect[5]();

    if (intr_status & 0x40)
        intr_isr_gpio_portd_vect[6]();

    if (intr_status & 0x80)
        intr_isr_gpio_portd_vect[7]();
}

static void intr_isr_gpio_porte(void)
{
    uint8_t intr_status;
    gpio_port_get_masked_intr_status(PORTE, &intr_status);

    if (intr_status & 0x01)
        intr_isr_gpio_porte_vect[0]();

    if (intr_status & 0x02)
        intr_isr_gpio_porte_vect[1]();

    if (intr_status & 0x04)
        intr_isr_gpio_porte_vect[2]();

    if (intr_status & 0x08)
        intr_isr_gpio_porte_vect[3]();

    if (intr_status & 0x10)
        intr_isr_gpio_porte_vect[4]();

    if (intr_status & 0x20)
        intr_isr_gpio_porte_vect[5]();

    if (intr_status & 0x40)
        intr_isr_gpio_porte_vect[6]();

    if (intr_status & 0x80)
        intr_isr_gpio_porte_vect[7]();
}

static void intr_isr_gpio_portf(void)
{
    uint8_t intr_status;
    gpio_port_get_masked_intr_status(PORTF, &intr_status);

    if (intr_status & 0x01)
        intr_isr_gpio_portf_vect[0]();

    if (intr_status & 0x02)
        intr_isr_gpio_portf_vect[1]();

    if (intr_status & 0x04)
        intr_isr_gpio_portf_vect[2]();

    if (intr_status & 0x08)
        intr_isr_gpio_portf_vect[3]();

    if (intr_status & 0x10)
        intr_isr_gpio_portf_vect[4]();

    if (intr_status & 0x20)
        intr_isr_gpio_portf_vect[5]();

    if (intr_status & 0x40)
        intr_isr_gpio_portf_vect[6]();

    if (intr_status & 0x80)
        intr_isr_gpio_portf_vect[7]();
}

#endif


/***********************************************************************
*                        Function Definitions                          *
***********************************************************************/

intr_error_t intr_init()
{
    intr_vect_install(&vector_table);
    vector_table[0] = (fptr_t) HW_REG32_READ(0x00000000);
    return INTR_STATE_SUCCESS;
}

intr_error_t intr_set_default_handler(fptr_t handler)
{
    INTR_ISR_DEFAULT = handler;
    return INTR_STATE_SUCCESS;
}

intr_error_t intr_irq_en(intr_irq_t irq)
{
    intr_error_t result = INTR_STATE_SUCCESS;

    if(irq < 16 || irq == 43 || irq == 47 || irq == 48 || irq == 57 || irq == 58
            || (irq > 67 && irq < 73) || (irq > 79 && irq < 84) || (irq > 87 && irq < 108)
            || (irq > 122 && irq < 150) || irq > 153)
    {
        result = INTR_STATE_IRQ_ERROR;
    }
    else
    {
        if(irq < 48)
            HW_REG32_BIT_SET(BASE_CORE + OFFSET_EN0, irq - 16);
        else if(irq < 80)
            HW_REG32_BIT_SET(BASE_CORE + OFFSET_EN1, irq - 48);
        else if(irq < 112)
            HW_REG32_BIT_SET(BASE_CORE + OFFSET_EN2, irq - 80);
        else if(irq < 144)
            HW_REG32_BIT_SET(BASE_CORE + OFFSET_EN3, irq - 112);
        else
            HW_REG32_BIT_SET(BASE_CORE + OFFSET_EN4, irq - 144);
    }

    return result;
}

intr_error_t intr_irq_dis(intr_irq_t irq)
{
    intr_error_t result = INTR_STATE_SUCCESS;

    if(irq < 16 || irq == 43 || irq == 47 || irq == 48 || irq == 57 || irq == 58
            || (irq > 67 && irq < 73) || (irq > 79 && irq < 84) || (irq > 87 && irq < 108)
            || (irq > 122 && irq < 150) || irq > 153)
    {
        result = INTR_STATE_IRQ_ERROR;
    }
    else
    {
        if(irq < 48)
            HW_REG32_BIT_SET(BASE_CORE + OFFSET_DIS0, irq - 16);
        else if(irq < 80)
            HW_REG32_BIT_SET(BASE_CORE + OFFSET_DIS1, irq - 48);
        else if(irq < 112)
            HW_REG32_BIT_SET(BASE_CORE + OFFSET_DIS2, irq - 80);
        else if(irq < 144)
            HW_REG32_BIT_SET(BASE_CORE + OFFSET_DIS3, irq - 112);
        else
            HW_REG32_BIT_SET(BASE_CORE + OFFSET_DIS4, irq - 144);
    }

    return result;
}

intr_error_t intr_handler_install(intr_irq_t irq, fptr_t handler)
{
    intr_error_t result = INTR_STATE_SUCCESS;

    if(irq < 16 || irq == 43 || irq == 47 || irq == 48 || irq == 57 || irq == 58
            || (irq > 67 && irq < 73) || (irq > 79 && irq < 84) || (irq > 87 && irq < 108)
            || (irq > 122 && irq < 150) || irq > 153)
        result = INTR_STATE_IRQ_ERROR;
    else
        vector_table[irq] = handler;

    return result;
}

intr_error_t intr_handler_uninstall(intr_irq_t irq)
{
    intr_error_t result = INTR_STATE_SUCCESS;

    if(irq < 16 || irq == 43 || irq == 47 || irq == 48 || irq == 57 || irq == 58
            || (irq > 67 && irq < 73) || (irq > 79 && irq < 84) || (irq > 87 && irq < 108)
            || (irq > 122 && irq < 150) || irq > 153)
        result = INTR_STATE_IRQ_ERROR;
    else
        vector_table[irq] = INTR_ISR_DEFAULT;

    return result;
}

intr_error_t intr_handler_get(intr_irq_t irq, fptr_t* dest)
{
    intr_error_t result = INTR_STATE_SUCCESS;

    if(irq < 16 || irq == 43 || irq == 47 || irq == 48 || irq == 57 || irq == 58
            || (irq > 67 && irq < 73) || (irq > 79 && irq < 84) || (irq > 87 && irq < 108)
            || (irq > 122 && irq < 150) || irq > 153)
        result = INTR_STATE_IRQ_ERROR;
    else
        *dest = vector_table[irq];

    return result;
}

intr_error_t intr_vect_install(volatile fptr_t (*new_vect)[154])
{
    HW_REG32_WRITE(BASE_CORE + OFFSET_VTABLE, (uint32_t)new_vect);
    return INTR_STATE_SUCCESS;
}

intr_error_t intr_vect_uninstall()
{
    HW_REG32_WRITE(BASE_CORE + OFFSET_VTABLE, (uint32_t)(&vector_table));
    return INTR_STATE_SUCCESS;
}

intr_error_t intr_master_en()
{
    __asm("    CPSIE I \n");
    return INTR_STATE_SUCCESS;
}

intr_error_t intr_master_dis()
{
    __asm("    CPSID I \n");
    return INTR_STATE_SUCCESS;
}

#ifdef EASY_MODE

intrError_t IntrInit()
{
    intr_init();
    return INTR_STATE_SUCCESS;
}

intrError_t GPIOPinAttachIntr(gpioPin_t* pinObj, gpioIntr_t* intrObj)
{
    intr_error_t result = INTR_STATE_SUCCESS;
    gpio_error_t gpioResult = GPIO_STATE_SUCCESS;
    intr_irq_t theIRQ;

    if (pinObj->base == PORTA)
    {
        theIRQ = INTR_IRQ_GPIO_PORTA;
        intr_isr_gpio_porta_vect[pinObj->pinNum] = intrObj->handler;
        result = intr_handler_install(theIRQ, intr_isr_gpio_porta);
    }
    else if (pinObj->base == PORTB)
    {
        theIRQ = INTR_IRQ_GPIO_PORTB;
        intr_isr_gpio_porta_vect[pinObj->pinNum] = intrObj->handler;
        result = intr_handler_install(theIRQ, intr_isr_gpio_portb);
    }
    else if (pinObj->base == PORTC)
    {
        theIRQ = INTR_IRQ_GPIO_PORTC;
        intr_isr_gpio_portc_vect[pinObj->pinNum] = intrObj->handler;
        result = intr_handler_install(theIRQ, intr_isr_gpio_portc);
    }
    else if (pinObj->base == PORTD)
    {
        theIRQ = INTR_IRQ_GPIO_PORTD;
        intr_isr_gpio_portd_vect[pinObj->pinNum] = intrObj->handler;
        result = intr_handler_install(theIRQ, intr_isr_gpio_portd);
    }
    else if (pinObj->base == PORTE)
    {
        theIRQ = INTR_IRQ_GPIO_PORTE;
        intr_isr_gpio_porte_vect[pinObj->pinNum] = intrObj->handler;
        result = intr_handler_install(theIRQ, intr_isr_gpio_porte);
    }
    else if (pinObj->base == PORTF)
    {
        theIRQ = INTR_IRQ_GPIO_PORTF;
        intr_isr_gpio_portf_vect[pinObj->pinNum] = intrObj->handler;
        result = intr_handler_install(theIRQ, intr_isr_gpio_portf);
    }
    else
    {
        gpioResult = GPIO_STATE_PORT_ERROR;
    }

    if (gpioResult == GPIO_STATE_SUCCESS && result == INTR_STATE_SUCCESS)
    {
        result = intr_irq_dis(theIRQ);
        if (result == INTR_STATE_SUCCESS)
        {
            gpioResult = gpio_pin_set_intr(pinObj->base,
                                            pinObj->pinNum, ON);
            if (gpioResult == GPIO_STATE_SUCCESS)
            {
                gpioResult = gpio_pin_set_intr_mode(pinObj->base,
                                                     pinObj->pinNum,
                                                     intrObj->mode);
                if (gpioResult == GPIO_STATE_SUCCESS)
                {
                    result = intr_irq_en(theIRQ);
                    if (result == INTR_STATE_SUCCESS)
                    {
                        result = intr_master_en();
                    }
                }
                else
                {
                    result = INTR_STATE_MODE_ERROR;
                }
            }
            else
            {
                result = INTR_STATE_MASK_ERROR;
            }
        }
    }
    else
    {
        result = INTR_STATE_IRQ_ERROR;
    }

    return result;
}

intrError_t GPIOPortAttachIntr(gpioPort_t* portObj, gpioIntr_t* intrObj)
{
    intr_error_t result = INTR_STATE_SUCCESS;
    gpio_error_t gpioResult = GPIO_STATE_SUCCESS;
    intr_irq_t theIRQ;

    if (portObj->base == PORTA)
        theIRQ = INTR_IRQ_GPIO_PORTA;
    else if (portObj->base == PORTB)
        theIRQ = INTR_IRQ_GPIO_PORTB;
    else if (portObj->base == PORTC)
        theIRQ = INTR_IRQ_GPIO_PORTC;
    else if (portObj->base == PORTD)
        theIRQ = INTR_IRQ_GPIO_PORTD;
    else if (portObj->base == PORTE)
        theIRQ = INTR_IRQ_GPIO_PORTE;
    else if (portObj->base == PORTF)
        theIRQ = INTR_IRQ_GPIO_PORTF;
    else
        gpioResult = GPIO_STATE_PORT_ERROR;

    if (gpioResult == GPIO_STATE_SUCCESS)
    {
        result = intr_irq_dis(theIRQ);
        if (result == INTR_STATE_SUCCESS)
        {
            gpioResult = gpio_port_set_intr(portObj->base, ON);
            if (gpioResult == GPIO_STATE_SUCCESS)
            {
                gpioResult = gpio_port_set_intr_mode(portObj->base,
                                                     intrObj->mode);
                if (gpioResult == GPIO_STATE_SUCCESS)
                {
                    result = intr_handler_install(theIRQ, intrObj->handler);
                    if (result == INTR_STATE_SUCCESS)
                    {
                        result = intr_irq_en(theIRQ);
                        if (result == INTR_STATE_SUCCESS)
                        {
                            result = intr_master_en();
                        }
                    }
                }
                else
                {
                    result = INTR_STATE_MODE_ERROR;
                }
            }
            else
            {
                result = INTR_STATE_MASK_ERROR;
            }
        }
    }
    else
    {
        result = INTR_STATE_IRQ_ERROR;
    }

    return result;
}

#endif

