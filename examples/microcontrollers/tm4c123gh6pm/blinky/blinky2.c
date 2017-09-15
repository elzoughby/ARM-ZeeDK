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

gpioPin_t redLed = {PORTF, 1, GPIO_MODE_DIGITAL, GPIO_DIR_OUTPUT, GPIO_CURRENT_2MA, 0, OFF};


/***********************************************************************
*                       Function Definitions                           *
***********************************************************************/

int main(void)
{
    GPIOPinInit(&redLed);

    while (1)
    {
        bit_t tmp;
        GPIOPinRead(&redLed, &tmp);
        GPIOPinWrite(&redLed, tmp? LOW:HIGH);

        //some delay time
        int i;
        for(i = 0; i < 500000; i++);
    }
}

#endif

