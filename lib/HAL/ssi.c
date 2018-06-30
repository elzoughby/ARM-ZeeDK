/***********************************************************************
* SSI operations for ARM Microcontrollers SSI Driver                   *
* @author Ahmed Elzoughby                                              *
* @date August 8, 2017                                                 *
* Purpose: Provide an easy interface to deal with SSI                  *
***********************************************************************/



/***********************************************************************
*                             Include Files                            *
***********************************************************************/

#include "ssi.h"


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

ssi_error_t ssi_enable_clk(ssi_base_t base)
{
    ssi_error_t result = SSI_STATE_SUCCESS;

    if (base == BASE_SSI0)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_RCGCSSI, 0);
    else if (base == BASE_SSI1)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_RCGCSSI, 1);
    else if (base == BASE_SSI2)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_RCGCSSI, 2);
    else if (base == BASE_SSI3)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_RCGCSSI, 3);
    else
        result = SSI_STATE_BASE_ERROR;

    return result;
}

ssi_error_t ssi_disable_clk(ssi_base_t base)
{
    ssi_error_t result = SSI_STATE_SUCCESS;

    if (base == BASE_SSI0)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_RCGCSSI, 0);
    else if (base == BASE_SSI1)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_RCGCSSI, 1);
    else if (base == BASE_SSI2)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_RCGCSSI, 2);
    else if (base == BASE_SSI3)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_RCGCSSI, 3);
    else
        result = SSI_STATE_BASE_ERROR;

    return result;
}

ssi_error_t ssi_enable_sleep_clk(ssi_base_t base)
{
    ssi_error_t result = SSI_STATE_SUCCESS;

    if (base == BASE_SSI0)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_SCGCSSI, 0);
    else if (base == BASE_SSI1)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_SCGCSSI, 1);
    else if (base == BASE_SSI2)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_SCGCSSI, 2);
    else if (base == BASE_SSI3)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_SCGCSSI, 3);
    else
        result = SSI_STATE_BASE_ERROR;

    return result;
}

ssi_error_t ssi_disable_sleep_clk(ssi_base_t base)
{
    ssi_error_t result = SSI_STATE_SUCCESS;

    if (base == BASE_SSI0)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_SCGCSSI, 0);
    else if (base == BASE_SSI1)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_SCGCSSI, 1);
    else if (base == BASE_SSI2)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_SCGCSSI, 2);
    else if (base == BASE_SSI3)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_SCGCSSI, 3);
    else
        result = SSI_STATE_BASE_ERROR;

    return result;
}

ssi_error_t ssi_enable_deepsleep_clk(ssi_base_t base)
{
    ssi_error_t result = SSI_STATE_SUCCESS;

    if (base == BASE_SSI0)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_DCGCSSI, 0);
    else if (base == BASE_SSI1)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_DCGCSSI, 1);
    else if (base == BASE_SSI2)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_DCGCSSI, 2);
    else if (base == BASE_SSI3)
        HW_REG32_BIT_SET(BASE_SYSCTL + OFFSET_DCGCSSI, 3);
    else
        result = SSI_STATE_BASE_ERROR;

    return result;
}

ssi_error_t ssi_disable_deepsleep_clk(ssi_base_t base)
{
    ssi_error_t result = SSI_STATE_SUCCESS;

    if (base == BASE_SSI0)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_DCGCSSI, 0);
    else if (base == BASE_SSI1)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_DCGCSSI, 1);
    else if (base == BASE_SSI2)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_DCGCSSI, 2);
    else if (base == BASE_SSI3)
        HW_REG32_BIT_CLEAR(BASE_SYSCTL + OFFSET_DCGCSSI, 3);
    else
        result = SSI_STATE_BASE_ERROR;

    return result;
}

ssi_error_t ssi_enable(ssi_base_t base)
{
    HW_REG32_BIT_SET(base + OFFSET_SSICR1, 1);
    return SSI_STATE_SUCCESS;
}

ssi_error_t ssi_disable(ssi_base_t base)
{
    HW_REG32_BIT_CLEAR(base + OFFSET_SSICR1, 1);
    return SSI_STATE_SUCCESS;
}

ssi_error_t ssi_set_mode(ssi_base_t base, ssi_mode_t mode)
{
    ssi_error_t result = SSI_STATE_SUCCESS;

    if (mode == SSI_MODE_MASTER)
    {
        HW_REG32_BIT_CLEAR(base + OFFSET_SSICR1, 2);
        HW_REG32_BIT_CLEAR(base + OFFSET_SSICR1, 3);
    }
    else if (mode == SSI_MODE_SLAVE)
    {
        HW_REG32_BIT_SET(base + OFFSET_SSICR1, 2);
        HW_REG32_BIT_CLEAR(base + OFFSET_SSICR1, 3);
    }
    else if (mode == SSI_MODE_SLAVE_OUTPUT_DISABLED)
    {
        HW_REG32_BIT_SET(base + OFFSET_SSICR1, 2);
        HW_REG32_BIT_SET(base + OFFSET_SSICR1, 3);
    }
    else
    {
        result = SSI_STATE_MODE_ERROR;
    }

    return result;
}

ssi_error_t ssi_get_mode(ssi_base_t base, ssi_mode_t* dest)
{
    ssi_error_t result = SSI_STATE_SUCCESS;

    if (HW_REG32_BIT_READ(base + OFFSET_SSICR1, 2))
    {
        if (HW_REG32_BIT_READ(base + OFFSET_SSICR1, 2))
            *dest = SSI_MODE_SLAVE_OUTPUT_DISABLED;
        else
            *dest = SSI_MODE_SLAVE;
    }
    else
    {
        *dest = SSI_MODE_MASTER;
    }

    return result;
}

ssi_error_t ssi_set_clk_src(ssi_base_t base, ssi_clk_t clk)
{
    HW_REG32_FIELD_WRITE(base + OFFSET_SSICC, 0, 3, clk);
    return SSI_STATE_SUCCESS;
}

ssi_error_t ssi_set_clk_divider(ssi_base_t base, uint32_t clock_divider)
{
    ssi_error_t result = SSI_STATE_SUCCESS;
    if(clock_divider % 2 != 0)
        result = SSI_STATE_CLK_ERROR;
    else
        HW_REG32_WRITE(base + OFFSET_SSICPSR, clock_divider);

    return result;
}

ssi_error_t ssi_set_clk_rate(ssi_base_t base, uint8_t clk_rate)
{
    HW_REG32_FIELD_WRITE(base + OFFSET_SSICR0, 8, 15, clk_rate);
    return SSI_STATE_SUCCESS;
}

ssi_error_t ssi_set_spi_mode(ssi_base_t base, ssi_spi_mode_t spi_mode)
{
    HW_REG32_FIELD_WRITE(base + OFFSET_SSICR0, 6, 7, spi_mode);
    return SSI_STATE_SUCCESS;
}

ssi_error_t ssi_set_frame(ssi_base_t base, ssi_frame_t frame)
{
    HW_REG32_FIELD_WRITE(base + OFFSET_SSICR0, 4, 5, frame);
    return SSI_STATE_SUCCESS;
}

ssi_error_t ssi_set_data_size(ssi_base_t base, ssi_data_size_t data_size)
{
    HW_REG32_FIELD_WRITE(base + OFFSET_SSICR0, 0, 3, data_size);
    return SSI_STATE_SUCCESS;
}



ssi_error_t ssi_write_char(ssi_base_t base, char src)
{
    HW_REG32_FIELD_WRITE(base + OFFSET_SSIDR, 0, 7, (uint8_t) src);
    return SSI_STATE_SUCCESS;
}

ssi_error_t ssi_read_char(ssi_base_t base, char* dest)
{
    *dest = (char) HW_REG32_FIELD_READ(base + OFFSET_SSIDR, 0, 7);
    return SSI_STATE_SUCCESS;
}

ssi_error_t ssi_write_str(ssi_base_t base, char src[]);

ssi_error_t ssi_read_str(ssi_base_t base, char (*dest)[]);


