/***********************************************************************
* SPI operations for ARM Microcontrollers SPI Driver                   *
* @author Ahmed Elzoughby                                              *
* @date August 8, 2017                                                 *
* Purpose: Provide an easy interface to deal with SPI                  *
***********************************************************************/

#ifndef HAL_SSI_H_
#define HAL_SSI_H_


/***********************************************************************
*                             Include Files                            *
***********************************************************************/

#include "../types.h"
#include "../REG/hw_types.h"
#include "../REG/hw_sysctl.h"
#include "../REG/hw_ssi.h"


/***********************************************************************
*                            Macros & Typedef                          *
***********************************************************************/

/* None */


/***********************************************************************
*                         Structures & Enums                           *
***********************************************************************/

typedef enum {
    SSI_MODE_MASTER,
    SSI_MODE_SLAVE,
    SSI_MODE_SLAVE_OUTPUT_DISABLED
} ssi_mode_t;

typedef enum {
    SSI_SPI_MODE_0,
    SSI_SPI_MODE_1,
    SSI_SPI_MODE_2,
    SSI_SPI_MODE_3
} ssi_spi_mode_t;

typedef enum {
    SSI_FRAME_SPI,
    SSI_FRAME_SSI,
    SSI_FRAME_MICROWIRE
} ssi_frame_t;

typedef enum {
    SSI_DATA_LEN_4BITS  = 0x3,
    SSI_DATA_LEN_5BITS  = 0x4,
    SSI_DATA_LEN_6BITS  = 0x5,
    SSI_DATA_LEN_7BITS  = 0x6,
    SSI_DATA_LEN_8BITS  = 0x7,
    SSI_DATA_LEN_9BITS  = 0x8,
    SSI_DATA_LEN_10BITS = 0x9,
    SSI_DATA_LEN_11BITS = 0xA,
    SSI_DATA_LEN_12BITS = 0xB,
    SSI_DATA_LEN_13BITS = 0xC,
    SSI_DATA_LEN_14BITS = 0xD,
    SSI_DATA_LEN_15BITS = 0xE,
    SSI_DATA_LEN_16BITS = 0xF
} ssi_data_size_t;

typedef enum {
    SSI_CLK_SYS = 0,
    SSI_CLK_PIOSC = 5
} ssi_clk_t;

typedef enum {
    SSI_STATE_SUCCESS,
    SSI_STATE_CLK_ERROR,
    SSI_STATE_BASE_ERROR,
    SSI_STATE_MODE_ERROR,
    SSI_STATE_DATA_LEN_ERROR
} ssi_error_t;


/***********************************************************************
*                   Global Variables Declarations                      *
***********************************************************************/

/* None */


/***********************************************************************
*                        Function Declarations                         *
***********************************************************************/

ssi_error_t ssi_enable_clk(ssi_base_t base);

ssi_error_t ssi_disable_clk(ssi_base_t base);

ssi_error_t ssi_enable_sleep_clk(ssi_base_t base);

ssi_error_t ssi_disable_sleep_clk(ssi_base_t base);

ssi_error_t ssi_enable_deepsleep_clk(ssi_base_t base);

ssi_error_t ssi_disable_deepsleep_clk(ssi_base_t base);

ssi_error_t ssi_enable(ssi_base_t base);

ssi_error_t ssi_disable(ssi_base_t base);

ssi_error_t ssi_set_mode(ssi_base_t base, ssi_mode_t mode);

ssi_error_t ssi_get_mode(ssi_base_t base, ssi_mode_t* dest);

ssi_error_t ssi_set_clk_src(ssi_base_t base, ssi_clk_t clk);

ssi_error_t ssi_set_clk_divider(ssi_base_t base, uint32_t clock_divider);

ssi_error_t ssi_set_clk_rate(ssi_base_t base, uint8_t clk_rate);

ssi_error_t ssi_set_spi_mode(ssi_base_t base, ssi_spi_mode_t spi_mode);

ssi_error_t ssi_set_frame(ssi_base_t base, ssi_frame_t frame);

ssi_error_t ssi_set_data_size(ssi_base_t base, ssi_data_size_t data_size);



ssi_error_t ssi_write_char(ssi_base_t base, char src);

ssi_error_t ssi_read_char(ssi_base_t base, char* dest);

ssi_error_t ssi_write_str(ssi_base_t base, char src[]);

ssi_error_t ssi_read_str(ssi_base_t base, char (*dest)[]);


#endif /* HAL_SSI_H_ */
