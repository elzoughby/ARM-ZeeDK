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
#include "lib/HAL/ssi.h"
#include "lib/SERVICE/interrupt.h"


/***********************************************************************
*                            Macros & Typedef                          *
***********************************************************************/

#define SSI0_PORT     PORTA
#define SSI0_CLK_PIN  2
#define SSI0_FSS_PIN  3
#define SSI0_RX_PIN   4
#define SSI0_TX_PIN   5
#define SSI0_ALT_FUN  2


/***********************************************************************
*                   Global Variables Declarations                      *
***********************************************************************/

static const char message[] = "AHMED";


/***********************************************************************
*                        Function Declarations                         *
***********************************************************************/


/***********************************************************************
*                       Function Definitions                           *
***********************************************************************/

int main(void)
{
    gpio_port_set_clk(SSI0_PORT, ON);
    gpio_pin_set_mode(SSI0_PORT, SSI0_CLK_PIN, GPIO_MODE_DIGITAL);
    gpio_pin_set_mode(SSI0_PORT, SSI0_RX_PIN, GPIO_MODE_DIGITAL);
    gpio_pin_set_mode(SSI0_PORT, SSI0_TX_PIN, GPIO_MODE_DIGITAL);

    gpio_pin_set_mode(SSI0_PORT, SSI0_FSS_PIN, GPIO_MODE_DIGITAL);
    gpio_pin_set_dir(SSI0_PORT, SSI0_FSS_PIN, GPIO_DIR_OUTPUT);
    gpio_pin_write(SSI0_PORT, SSI0_FSS_PIN, 1);

    gpio_pin_set_alt_func(SSI0_PORT, SSI0_CLK_PIN, SSI0_ALT_FUN);
    gpio_pin_set_alt_func(SSI0_PORT, SSI0_FSS_PIN, SSI0_ALT_FUN);
    gpio_pin_set_alt_func(SSI0_PORT, SSI0_RX_PIN, SSI0_ALT_FUN);
    gpio_pin_set_alt_func(SSI0_PORT, SSI0_TX_PIN, SSI0_ALT_FUN);


    ssi_enable_clk(BASE_SSI0);
    ssi_disable(BASE_SSI0);
    ssi_set_mode(BASE_SSI0, SSI_MODE_MASTER);
    ssi_set_clk_src(BASE_SSI0, SSI_CLK_PIOSC);
    ssi_set_clk_divider(BASE_SSI0, 4);
    ssi_set_clk_rate(BASE_SSI0, 0);
    ssi_set_spi_mode(BASE_SSI0, SSI_SPI_MODE_0);
    ssi_set_frame(BASE_SSI0, SSI_FRAME_SPI);
    ssi_set_data_size(BASE_SSI0, SSI_DATA_LEN_8BITS);
    ssi_enable(BASE_SSI0);


    gpio_pin_write(SSI0_PORT, SSI0_FSS_PIN, 0);

    uint8_t indx = 0;
    while (message[indx] != '\0' && )
    {
        ssi_write_char(BASE_SSI0,  message[indx++]);
    }

    gpio_pin_write(SSI0_PORT, SSI0_FSS_PIN, 1);



    while(1)
    {

    }
}


#endif
