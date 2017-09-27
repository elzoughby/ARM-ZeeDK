/***********************************************************************
* Timer app example for ARM Microcontrollers GPTM Driver               *
* @author Ahmed Elzoughby                                              *
* @date August 17, 2017                                                *
* Purpose: Testing the ARM Microcontrollers GPTM Driver                *
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

gpioPin_t led = {PORTF, 2, GPIO_MODE_DIGITAL, GPIO_DIR_OUTPUT, GPIO_CURRENT_2MA, 0, OFF};


/***********************************************************************
*                        Function Declarations                         *
***********************************************************************/

void handler(void);


/***********************************************************************
*                       Function Definitions                           *
***********************************************************************/

int main(void)
{
    GPIOPinInit(&led);

    while (1)
    {

    }
}

void handler(void)
{
    bit_t tmp;
    GPIOPinRead(&led, &tmp);
    GPIOPinWrite(&led, tmp? LOW:HIGH);
}

#endif

