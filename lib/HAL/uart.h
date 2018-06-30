/***********************************************************************
* UART operations for ARM Microcontrollers UART Driver                 *
* @author Ahmed Elzoughby                                              *
* @date August 8, 2017                                                 *
* Purpose: Provide an easy interface to deal with UART                 *
***********************************************************************/


#ifndef HAL_UART_H_
#define HAL_UART_H_


/***********************************************************************
*                             Include Files                            *
***********************************************************************/

#include "../types.h"
#include "../REG/hw_types.h"
#include "../REG/hw_sysctl.h"
#include "../REG/hw_uart.h"


/***********************************************************************
*                            Macros & Typedef                          *
***********************************************************************/

/* None */


/***********************************************************************
*                         Structures & Enums                           *
***********************************************************************/

typedef enum {
    UART_DATA_LEN_5BITS,
    UART_DATA_LEN_6BITS,
    UART_DATA_LEN_7BITS,
    UART_DATA_LEN_8BITS
} uart_data_len_t;

typedef enum {
    UART_PARITY_MODE_EVEN,
    UART_PARITY_MODE_ODD,
    UART_PARITY_MODE_STICK_EVEN,
    UART_PARITY_MODE_STICK_ODD,
    UART_PARITY_MODE_DISABLE
} uart_parity_mode_t;

typedef enum {
    UART_CLK_SYS = 0,
    UART_CLK_PIOSC = 5
} uart_clk_t;

typedef enum {
    UART_FIFO_LEVEL_EIGHTH,
    UART_FIFO_LEVEL_QUARTER,
    UART_FIFO_LEVEL_HALF,
    UART_FIFO_LEVEL_THREE_QUARTERS,
    UART_FIFO_LEVEL_SEVEN_EIGHTHS
} uart_fifo_level_t;

typedef enum {
    UART_STATE_SUCCESS,
    UART_STATE_CLK_ERROR,
    UART_STATE_BASE_ERROR,
    UART_STATE_DATA_LEN_ERROR,
    UART_STATE_PARITY_MODE_ERROR,
} uart_error_t;


/***********************************************************************
*                   Global Variables Declarations                      *
***********************************************************************/

/* None */


/***********************************************************************
*                        Function Declarations                         *
***********************************************************************/

uart_error_t uart_enable_clk(uart_base_t base);

uart_error_t uart_disable_clk(uart_base_t base);

uart_error_t uart_enable_sleep_clk(uart_base_t base);

uart_error_t uart_disable_sleep_clk(uart_base_t base);

uart_error_t uart_enable_deepsleep_clk(uart_base_t base);

uart_error_t uart_disable_deepsleep_clk(uart_base_t base);

uart_error_t uart_enable(uart_base_t base);

uart_error_t uart_disable(uart_base_t base);

uart_error_t uart_enable_high_speed(uart_base_t base);

uart_error_t uart_disable_high_speed(uart_base_t base);

uart_error_t uart_set_clk_src(uart_base_t base, uart_clk_t clk);

uart_error_t uart_set_baudrate(uart_base_t base, uint32_t baudrate);


uart_error_t uart_set_parity_mode(uart_base_t base, uart_parity_mode_t mode);

uart_error_t uart_set_data_len(uart_base_t base, uart_data_len_t len);

uart_error_t uart_enable_fifo(uart_base_t base);

uart_error_t uart_disable_fifo(uart_base_t base);

uart_error_t uart_enable_two_stop_bit(uart_base_t base);

uart_error_t uart_disable_two_stop_bit(uart_base_t base);

uart_error_t uart_enable_break(uart_base_t base);

uart_error_t uart_disable_break(uart_base_t base);


uart_error_t uart_enable_tx(uart_base_t base);

uart_error_t uart_disable_tx(uart_base_t base);

uart_error_t uart_enable_rx(uart_base_t base);

uart_error_t uart_disable_rx(uart_base_t base);

uart_error_t uart_enable_loopback(uart_base_t base);

uart_error_t uart_disable_loopback(uart_base_t base);


uart_error_t uart_set_tx_fifo_level(uart_base_t base, uart_fifo_level_t level);

uart_error_t uart_set_rx_fifo_level(uart_base_t base, uart_fifo_level_t level);

uart_error_t uart_set_intr_mask(uart_base_t base, uint32_t mask);

uart_error_t uart_get_raw_intr_status(uart_base_t base, uint32_t* dest);

uart_error_t uart_get_masked_intr_status(uart_base_t base, uint32_t* dest);

uart_error_t uart_clear_intr(uart_base_t base, uint32_t mask);


uart_error_t uart_write_char(uart_base_t base, char src);

uart_error_t uart_read_char(uart_base_t base, char* dest);

uart_error_t uart_write_str(uart_base_t base, char src[]);

uart_error_t uart_read_str(uart_base_t base, char (*dest)[]);


#endif /* HAL_UART_H_ */
