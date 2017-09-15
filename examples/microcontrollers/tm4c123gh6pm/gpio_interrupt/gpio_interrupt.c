/***********************************************************************
* GPIO app example for ARM Microcontrollers GPIO Driver                *
* @author Ahmed Elzoughby                                              *
* @date August 17, 2017                                                *
* Purpose: Testing the ARM Microcontrollers GPIO Driver                *
***********************************************************************/


#include "config.h"


#ifdef ADVANCED_MODE


/***********************************************************************
*                             Include Files                            *
***********************************************************************/

#include "lib/HAL/gpio.h"
#include "lib/SERVICE/interrupt.h"


/***********************************************************************
*                   Global Variables Declarations                      *
***********************************************************************/

/* None */


/***********************************************************************
*                        Function Declarations                         *
***********************************************************************/

void handle(void);
void handle1(void);
void handle2(void);


/***********************************************************************
*                       Function Definitions                           *
***********************************************************************/

int main(void)
{
    gpio_port_set_clk(PORTF, ON);
    gpio_pin_unlock(PORTF, 0, GPIO_UNLOCK_KEY);
    gpio_pin_set_mode(PORTF, 0, GPIO_MODE_DIGITAL);
    gpio_pin_set_dir(PORTF, 0, GPIO_DIR_INPUT_PULLUP);
    gpio_pin_set_intr(PORTF, 0, ON);
    gpio_pin_set_intr_mode(PORTF, 0, GPIO_INTR_RISING_EDGE);
    gpio_pin_set_mode(PORTF, 1, GPIO_MODE_DIGITAL);
    gpio_pin_set_dir(PORTF, 1, GPIO_DIR_OUTPUT);
    gpio_pin_set_mode(PORTF, 3, GPIO_MODE_DIGITAL);
    gpio_pin_set_dir(PORTF, 3, GPIO_DIR_OUTPUT);
    gpio_pin_set_mode(PORTF, 4, GPIO_MODE_DIGITAL);
    gpio_pin_set_dir(PORTF, 4, GPIO_DIR_INPUT_PULLUP);
    gpio_pin_set_intr(PORTF, 4, ON);
    gpio_pin_set_intr_mode(PORTF, 4, GPIO_INTR_RISING_EDGE);

    intr_init();
    intr_handler_install(INTR_IRQ_GPIO_PORTF, handle);
    intr_irq_en(INTR_IRQ_GPIO_PORTF);
    intr_master_en();

    while(1)
    {

    }
}

void handle(void)
{
    uint8_t intr_status;
    gpio_port_get_masked_intr_status(PORTF, &intr_status);

    if (intr_status & 0x01)
        handle2();

    if (intr_status & 0x10)
        handle1();
}

void handle1(void)
{
    intr_irq_dis(INTR_IRQ_GPIO_PORTF);
    int i;
    for(i = 0; i < 250000; i++);
    intr_irq_en(INTR_IRQ_GPIO_PORTF);

    bit_t tmp;
    gpio_pin_read(PORTF, 3, &tmp);

    if(tmp == HIGH)
        gpio_pin_write(PORTF, 3, LOW);
    else
        gpio_pin_write(PORTF, 3, HIGH);

    gpio_port_clear_intr(PORTF);
}

void handle2(void)
{
    intr_irq_dis(INTR_IRQ_GPIO_PORTF);
    int i;
    for(i = 0; i < 250000; i++);
    intr_irq_en(INTR_IRQ_GPIO_PORTF);

    bit_t tmp;
    gpio_pin_read(PORTF, 1, &tmp);

    if(tmp == HIGH)
        gpio_pin_write(PORTF, 1, LOW);
    else
        gpio_pin_write(PORTF, 1, HIGH);

    gpio_port_clear_intr(PORTF);
}


#endif
