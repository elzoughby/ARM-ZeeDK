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
*                       Function Definitions                           *
***********************************************************************/

int main(void)
{
    gpio_port_set_clk(PORTF, ON);
    gpio_pin_set_mode(PORTF, 1, GPIO_MODE_DIGITAL);
    gpio_pin_set_dir(PORTF, 1, GPIO_DIR_OUTPUT);

    while(1)
    {
        bit_t tmp;
        gpio_pin_read(PORTF, 1, &tmp);
        gpio_pin_write(PORTF, 1, tmp? LOW:HIGH);

        //some delay time
        int i;
        for(i = 0; i < 500000; i++);
    }
}


#endif
