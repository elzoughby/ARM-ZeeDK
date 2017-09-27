/***********************************************************************
* Timer app example for ARM Microcontrollers GPTM Driver               *
* @author Ahmed Elzoughby                                              *
* @date August 17, 2017                                                *
* Purpose: Testing the ARM Microcontrollers GPTM Driver                *
***********************************************************************/


#include "config.h"


#ifdef ADVANCED_MODE


/***********************************************************************
*                             Include Files                            *
***********************************************************************/

#include "lib/HAL/gpio.h"
#include "lib/HAL/timer.h"
#include "lib/SERVICE/interrupt.h"


/***********************************************************************
*                            Macros & Typedef                          *
***********************************************************************/

#define LED_PIN 2


/***********************************************************************
*                   Global Variables Declarations                      *
***********************************************************************/

/* None */


/***********************************************************************
*                        Function Declarations                         *
***********************************************************************/

void handler(void);


/***********************************************************************
*                       Function Definitions                           *
***********************************************************************/

int main(void)
{
    gpio_port_set_clk(PORTF, ON);
    gpio_pin_set_mode(PORTF, LED_PIN, GPIO_MODE_DIGITAL);
    gpio_pin_set_dir(PORTF, LED_PIN, GPIO_DIR_OUTPUT);

    timer_set_clk(BASE_TIMER0, ON);
    timer_dis(BASE_TIMER0, TIMER_UNITAB);
    timer_set_mode(BASE_TIMER0, TIMER_UNITAB, TIMER_MODE_PERIODIC);
    timer_set_count_dir(BASE_TIMER0, TIMER_UNITAB, TIMER_DIR_UP);
    timer_set_load_val(BASE_TIMER0, TIMER_UNITAB, 16000000);
    timer_set_intr_mask(BASE_TIMER0, 0x00000001);
    timer_en(BASE_TIMER0, TIMER_UNITAB);

    intr_init();
    intr_handler_install(INTR_IRQ_TIMER0A, handler);
    intr_irq_en(INTR_IRQ_TIMER0A);
    intr_master_en();

    while(1)
    {

    }
}

void handler(void)
{
    HW_REG32_BIT_SET(BASE_TIMER0 + OFFSET_GPTMICR, 0);
    bit_t tmp;
    gpio_pin_read(PORTF, LED_PIN, &tmp);
    gpio_pin_write(PORTF, LED_PIN, tmp ? LOW : HIGH);
}


#endif
