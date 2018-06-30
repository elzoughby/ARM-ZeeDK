/***********************************************************************
* UART app example for ARM Microcontrollers UART Driver                *
* @author Ahmed Elzoughby                                              *
* @date August 17, 2017                                                *
* Purpose: Testing the ARM Microcontrollers UART Driver                *
***********************************************************************/


#include "config.h"


#ifdef ADVANCED_MODE


/***********************************************************************
*                             Include Files                            *
***********************************************************************/

#include "lib/HAL/gpio.h"
#include "lib/HAL/uart.h"
#include "lib/SERVICE/interrupt.h"


/***********************************************************************
*                            Macros & Typedef                          *
***********************************************************************/

#define TX 7
#define RX 6


/***********************************************************************
*                   Global Variables Declarations                      *
***********************************************************************/

static char message[] = "AHMED";


/***********************************************************************
*                        Function Declarations                         *
***********************************************************************/

void handler(void);


/***********************************************************************
*                       Function Definitions                           *
***********************************************************************/

int main(void)
{
    gpio_port_set_clk(PORTC, ON);
    gpio_pin_set_mode(PORTC, TX, GPIO_MODE_DIGITAL);
    gpio_pin_set_mode(PORTC, RX, GPIO_MODE_DIGITAL);
    gpio_pin_set_alt_func(PORTC, TX, 1);
    gpio_pin_set_alt_func(PORTC, RX, 1);

    uart_enable_clk(BASE_UART3);
    uart_disable(BASE_UART3);
    uart_disable_high_speed(BASE_UART3);
    uart_set_clk_src(BASE_UART3, UART_CLK_PIOSC);
    uart_set_baudrate(BASE_UART3, 9600);

    uart_set_parity_mode(BASE_UART3, UART_PARITY_MODE_DISABLE);
    uart_set_data_len(BASE_UART3, UART_DATA_LEN_8BITS);
    uart_enable_fifo(BASE_UART3);
    uart_set_tx_fifo_level(BASE_UART3, UART_FIFO_LEVEL_EIGHTH);

    uart_enable_tx(BASE_UART3);
    uart_enable_rx(BASE_UART3);
    //uart_enable_loopback(BASE_UART3);
    //uart_set_intr_mask(BASE_UART3, 0x00000020);
    uart_enable(BASE_UART3);

/*
    intr_init();
    intr_handler_install(INTR_IRQ_UART3, handler);
    intr_irq_enable(INTR_IRQ_UART3);
    intr_master_enable();
*/

    uint8_t indx = 0;
    while (message[indx] != '\0' && )
    {
        uart_write_char(BASE_UART3, message[indx++]);
    }

    while(1)
    {

    }
}

/*
void handler(void)
{
    uart_clear_intr(BASE_UART3, 0x00000020);
    if (indx < 5)
        uart_write_char(BASE_UART3, message[indx++]);
}
*/

#endif
