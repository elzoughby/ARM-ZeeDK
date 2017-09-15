/***********************************************************************
* GPIO app example for ARM Microcontrollers GPIO Driver                *
* @author Ahmed Elzoughby                                              *
* @date August 17, 2017                                                *
* Purpose: Testing the ARM Microcontrollers GPIO Driver                *
***********************************************************************/


#include "config.h"


#ifdef EASY_MODE


/***********************************************************************
*                            Include Files                             *
***********************************************************************/

#include "lib/HAL/gpio.h"
#include "lib/SERVICE/interrupt.h"


/***********************************************************************
*                   Global Variables Declarations                      *
***********************************************************************/

gpioPin_t greenLed = {PORTF, 3, GPIO_MODE_DIGITAL, GPIO_DIR_OUTPUT, GPIO_CURRENT_2MA, 0, OFF};
gpioPin_t redLed = {PORTF, 1, GPIO_MODE_DIGITAL, GPIO_DIR_OUTPUT, GPIO_CURRENT_2MA, 0, OFF};
gpioPin_t switch1 = {PORTF, 4, GPIO_MODE_DIGITAL, GPIO_DIR_INPUT_PULLUP, GPIO_CURRENT_2MA, 0, OFF};
gpioPin_t switch2 = {PORTF, 0, GPIO_MODE_DIGITAL, GPIO_DIR_INPUT_PULLUP, GPIO_CURRENT_2MA, 0, ON};


/***********************************************************************
*                        Function Declarations                         *
***********************************************************************/

void Handle1(void);
void Handle2(void);


/***********************************************************************
*                       Function Definitions                           *
***********************************************************************/

int main(void)
{
    GPIOPinInit(&greenLed);
    GPIOPinInit(&redLed);
    GPIOPinInit(&switch1);
    GPIOPinInit(&switch2);
    IntrInit();
    gpioIntr_t swtch1Intr = {GPIO_INTR_RISING_EDGE, Handle1};
    gpioIntr_t swtch2Intr = {GPIO_INTR_RISING_EDGE, Handle2};
    GPIOPinAttachIntr(&switch1, &swtch1Intr);
    GPIOPinAttachIntr(&switch2, &swtch2Intr);

    while (1)
    {

    }
}

void Handle1(void)
{
    intr_irq_dis(INTR_IRQ_GPIO_PORTF);
    int i;
    for(i = 0; i < 250000; i++);
    intr_irq_en(INTR_IRQ_GPIO_PORTF);

    bit_t tmp;
    GPIOPinRead(&greenLed, &tmp);

    if(tmp == HIGH)
        GPIOPinWrite(&greenLed, LOW);
    else
        GPIOPinWrite(&greenLed, HIGH);

    gpio_port_clear_intr(PORTF);
}

void Handle2(void)
{
    intr_irq_dis(INTR_IRQ_GPIO_PORTF);
    int i;
    for(i = 0; i < 250000; i++);
    intr_irq_en(INTR_IRQ_GPIO_PORTF);

    bit_t tmp;
    GPIOPinRead(&redLed, &tmp);

    if(tmp == HIGH)
        GPIOPinWrite(&redLed, LOW);
    else
        GPIOPinWrite(&redLed, HIGH);

    gpio_port_clear_intr(PORTF);
}


#endif

