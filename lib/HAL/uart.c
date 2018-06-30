/***********************************************************************
* UART operations for ARM Microcontrollers UART Driver                 *
* @author Ahmed Elzoughby                                              *
* @date August 8, 2017                                                 *
* Purpose: Provide an easy interface to deal with UART                 *
***********************************************************************/



/***********************************************************************
*                             Include Files                            *
***********************************************************************/

#include "uart.h"


/***********************************************************************
*                            Macros & Typedef                          *
***********************************************************************/

/* None */


/***********************************************************************
*                         Structures & Enums                           *
***********************************************************************/

/* None */


/***********************************************************************
*                   Global Variables Declarations                      *
***********************************************************************/

/* None */


/***********************************************************************
*                        Function Definitions                          *
***********************************************************************/

uart_error_t uart_enable_clk(uart_base_t base)
{
    uart_error_t result = UART_STATE_SUCCESS;

    if (base == BASE_UART0)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_RCGCUART, 0);
    else if (base == BASE_UART1)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_RCGCUART, 1);
    else if (base == BASE_UART2)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_RCGCUART, 2);
    else if (base == BASE_UART3)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_RCGCUART, 3);
    else if (base == BASE_UART4)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_RCGCUART, 4);
    else if (base == BASE_UART5)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_RCGCUART, 5);
    else if (base == BASE_UART6)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_RCGCUART, 6);
    else if (base == BASE_UART7)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_RCGCUART, 7);
    else
        result = UART_STATE_BASE_ERROR;

    return result;
}

uart_error_t uart_disable_clk(uart_base_t base)
{
    uart_error_t result = UART_STATE_SUCCESS;

    if (base == BASE_UART0)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_RCGCUART, 0);
    else if (base == BASE_UART1)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_RCGCUART, 1);
    else if (base == BASE_UART2)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_RCGCUART, 2);
    else if (base == BASE_UART3)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_RCGCUART, 3);
    else if (base == BASE_UART4)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_RCGCUART, 4);
    else if (base == BASE_UART5)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_RCGCUART, 5);
    else if (base == BASE_UART6)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_RCGCUART, 6);
    else if (base == BASE_UART7)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_RCGCUART, 7);
    else
        result = UART_STATE_BASE_ERROR;

    return result;
}

uart_error_t uart_enable_sleep_clk(uart_base_t base)
{
    uart_error_t result = UART_STATE_SUCCESS;

    if (base == BASE_UART0)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_SCGCUART, 0);
    else if (base == BASE_UART1)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_SCGCUART, 1);
    else if (base == BASE_UART2)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_SCGCUART, 2);
    else if (base == BASE_UART3)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_SCGCUART, 3);
    else if (base == BASE_UART4)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_SCGCUART, 4);
    else if (base == BASE_UART5)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_SCGCUART, 5);
    else if (base == BASE_UART6)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_SCGCUART, 6);
    else if (base == BASE_UART7)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_SCGCUART, 7);
    else
        result = UART_STATE_BASE_ERROR;

    return result;
}

uart_error_t uart_disable_sleep_clk(uart_base_t base)
{
    uart_error_t result = UART_STATE_SUCCESS;

    if (base == BASE_UART0)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_SCGCUART, 0);
    else if (base == BASE_UART1)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_SCGCUART, 1);
    else if (base == BASE_UART2)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_SCGCUART, 2);
    else if (base == BASE_UART3)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_SCGCUART, 3);
    else if (base == BASE_UART4)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_SCGCUART, 4);
    else if (base == BASE_UART5)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_SCGCUART, 5);
    else if (base == BASE_UART6)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_SCGCUART, 6);
    else if (base == BASE_UART7)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_SCGCUART, 7);
    else
        result = UART_STATE_BASE_ERROR;

    return result;
}

uart_error_t uart_enable_deepsleep_clk(uart_base_t base)
{
    uart_error_t result = UART_STATE_SUCCESS;

    if (base == BASE_UART0)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_DCGCUART, 0);
    else if (base == BASE_UART1)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_DCGCUART, 1);
    else if (base == BASE_UART2)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_DCGCUART, 2);
    else if (base == BASE_UART3)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_DCGCUART, 3);
    else if (base == BASE_UART4)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_DCGCUART, 4);
    else if (base == BASE_UART5)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_DCGCUART, 5);
    else if (base == BASE_UART6)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_DCGCUART, 6);
    else if (base == BASE_UART7)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_DCGCUART, 7);
    else
        result = UART_STATE_BASE_ERROR;

    return result;
}

uart_error_t uart_disable_deepsleep_clk(uart_base_t base)
{
    uart_error_t result = UART_STATE_SUCCESS;

    if (base == BASE_UART0)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_DCGCUART, 0);
    else if (base == BASE_UART1)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_DCGCUART, 1);
    else if (base == BASE_UART2)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_DCGCUART, 2);
    else if (base == BASE_UART3)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_DCGCUART, 3);
    else if (base == BASE_UART4)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_DCGCUART, 4);
    else if (base == BASE_UART5)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_DCGCUART, 5);
    else if (base == BASE_UART6)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_DCGCUART, 6);
    else if (base == BASE_UART7)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_DCGCUART, 7);
    else
        result = UART_STATE_BASE_ERROR;

    return result;
}

uart_error_t uart_enable(uart_base_t base)
{
    HW_REG32_BIT_SET(base + OFFSET_UARTCTL, 0);
    return UART_STATE_SUCCESS;
}

uart_error_t uart_disable(uart_base_t base)
{
    HW_REG32_BIT_CLEAR(base + OFFSET_UARTCTL, 0);
    return UART_STATE_SUCCESS;
}

uart_error_t uart_enable_high_speed(uart_base_t base)
{
    HW_REG32_BIT_SET(base + OFFSET_UARTCTL, 5);
    return UART_STATE_SUCCESS;
}

uart_error_t uart_disable_high_speed(uart_base_t base)
{
    HW_REG32_BIT_CLEAR(base + OFFSET_UARTCTL, 5);
    return UART_STATE_SUCCESS;
}

uart_error_t uart_set_clk_src(uart_base_t base, uart_clk_t clk)
{
    HW_REG32_FIELD_WRITE(base + OFFSET_UARTCC, 0, 3, clk);
    return UART_STATE_SUCCESS;
}


uart_error_t uart_set_baudrate(uart_base_t base, uint32_t baudrate)
{
    uart_error_t result = UART_STATE_SUCCESS;

    uint8_t clk_div = HW_REG32_BIT_READ(base + OFFSET_UARTCTL, 5)? 8 : 16;
    uint32_t uart_clk = HW_REG32_FIELD_READ(base + OFFSET_UARTCC, 0, 3) == 0x5? 16000000 : 20000000;
    double bdr = uart_clk / (clk_div * baudrate);
    double bdrf = (bdr - (int) bdr) * 64 + 0.5;

    HW_REG32_WRITE(base + OFFSET_UARTIBRD, (uint16_t) bdr);
    HW_REG32_WRITE(base + OFFSET_UARTFBRD, (uint16_t) bdrf);

    return result;
}


uart_error_t uart_set_parity_mode(uart_base_t base, uart_parity_mode_t mode)
{
    uart_error_t result = UART_STATE_SUCCESS;

    if (mode == UART_PARITY_MODE_DISABLE)
    {
        HW_REG32_BIT_CLEAR(base + OFFSET_UARTLCRH, 1);
    }
    else if (mode == UART_PARITY_MODE_EVEN)
    {
        HW_REG32_BIT_SET(base + OFFSET_UARTLCRH, 1);
        HW_REG32_BIT_SET(base + OFFSET_UARTLCRH, 2);
        HW_REG32_BIT_CLEAR(base + OFFSET_UARTLCRH, 7);
    }
    else if (mode == UART_PARITY_MODE_ODD)
    {
        HW_REG32_BIT_SET(base + OFFSET_UARTLCRH, 1);
        HW_REG32_BIT_CLEAR(base + OFFSET_UARTLCRH, 2);
        HW_REG32_BIT_CLEAR(base + OFFSET_UARTLCRH, 7);
    }
    else if (mode == UART_PARITY_MODE_STICK_EVEN)
    {
        HW_REG32_BIT_SET(base + OFFSET_UARTLCRH, 1);
        HW_REG32_BIT_SET(base + OFFSET_UARTLCRH, 2);
        HW_REG32_BIT_SET(base + OFFSET_UARTLCRH, 7);
    }
    else if (mode == UART_PARITY_MODE_STICK_ODD)
    {
        HW_REG32_BIT_SET(base + OFFSET_UARTLCRH, 1);
        HW_REG32_BIT_CLEAR(base + OFFSET_UARTLCRH, 2);
        HW_REG32_BIT_SET(base + OFFSET_UARTLCRH, 7);
    }
    else
    {
        result = UART_STATE_PARITY_MODE_ERROR;
    }

    return result;
}

uart_error_t uart_set_data_len(uart_base_t base, uart_data_len_t len)
{
    HW_REG32_FIELD_WRITE(base + OFFSET_UARTLCRH, 5, 6, len);
    return UART_STATE_SUCCESS;
}

uart_error_t uart_enable_fifo(uart_base_t base)
{
    HW_REG32_BIT_SET(base + OFFSET_UARTLCRH, 4);
    return UART_STATE_SUCCESS;
}

uart_error_t uart_disable_fifo(uart_base_t base)
{
    HW_REG32_BIT_CLEAR(base + OFFSET_UARTLCRH, 4);
    return UART_STATE_SUCCESS;
}

uart_error_t uart_enable_two_stop_bit(uart_base_t base)
{
    HW_REG32_BIT_SET(base + OFFSET_UARTLCRH, 3);
    return UART_STATE_SUCCESS;
}

uart_error_t uart_disable_two_stop_bit(uart_base_t base)
{
    HW_REG32_BIT_CLEAR(base + OFFSET_UARTLCRH, 3);
    return UART_STATE_SUCCESS;
}

uart_error_t uart_enable_break(uart_base_t base)
{
    HW_REG32_BIT_SET(base + OFFSET_UARTLCRH, 0);
    return UART_STATE_SUCCESS;
}

uart_error_t uart_disable_break(uart_base_t base)
{
    HW_REG32_BIT_CLEAR(base + OFFSET_UARTLCRH, 0);
    return UART_STATE_SUCCESS;
}


uart_error_t uart_enable_tx(uart_base_t base)
{
    HW_REG32_BIT_SET(base + OFFSET_UARTCTL, 8);
    return UART_STATE_SUCCESS;
}

uart_error_t uart_disable_tx(uart_base_t base)
{
    HW_REG32_BIT_CLEAR(base + OFFSET_UARTCTL, 8);
    return UART_STATE_SUCCESS;
}

uart_error_t uart_enable_rx(uart_base_t base)
{
    HW_REG32_BIT_SET(base + OFFSET_UARTCTL, 9);
    return UART_STATE_SUCCESS;
}

uart_error_t uart_disable_rx(uart_base_t base)
{
    HW_REG32_BIT_CLEAR(base + OFFSET_UARTCTL, 9);
    return UART_STATE_SUCCESS;
}

uart_error_t uart_enable_loopback(uart_base_t base)
{
    HW_REG32_BIT_SET(base + OFFSET_UARTCTL, 7);
    return UART_STATE_SUCCESS;
}

uart_error_t uart_disable_loopback(uart_base_t base)
{
    HW_REG32_BIT_CLEAR(base + OFFSET_UARTCTL, 7);
    return UART_STATE_SUCCESS;
}


uart_error_t uart_set_tx_fifo_level(uart_base_t base, uart_fifo_level_t level)
{
    HW_REG32_FIELD_WRITE(base + OFFSET_UARTIFLS, 0, 2, level);
    return UART_STATE_SUCCESS;
}

uart_error_t uart_set_rx_fifo_level(uart_base_t base, uart_fifo_level_t level)
{
    HW_REG32_FIELD_WRITE(base + OFFSET_UARTIFLS, 3, 5, level);
    return UART_STATE_SUCCESS;
}

uart_error_t uart_set_intr_mask(uart_base_t base, uint32_t mask)
{
    HW_REG32_WRITE(base + OFFSET_UARTIM, mask);
    return UART_STATE_SUCCESS;
}

uart_error_t uart_get_raw_intr_status(uart_base_t base, uint32_t* dest)
{
    *dest = HW_REG32_READ(base + OFFSET_UARTRIS);
    return UART_STATE_SUCCESS;
}

uart_error_t uart_get_masked_intr_status(uart_base_t base, uint32_t* dest)
{
    *dest = HW_REG32_READ(base + OFFSET_UARTMIS);
    return UART_STATE_SUCCESS;
}

uart_error_t uart_clear_intr(uart_base_t base, uint32_t mask)
{
    HW_REG32_WRITE(base + OFFSET_UARTICR, mask);
    return UART_STATE_SUCCESS;
}


uart_error_t uart_write_char(uart_base_t base, char src)
{
    HW_REG32_FIELD_WRITE(base + OFFSET_UARTDR, 0, 7, (uint8_t) src);
    return UART_STATE_SUCCESS;
}

uart_error_t uart_read_char(uart_base_t base, char* dest)
{
    *dest = (char) HW_REG32_FIELD_READ(base + OFFSET_UARTDR, 0, 7);
    return UART_STATE_SUCCESS;
}

uart_error_t uart_write_str(uart_base_t base, char src[]);

uart_error_t uart_read_str(uart_base_t base, char (*dest)[]);


