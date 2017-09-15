/***********************************************************************
* GPIO operations for ARM Microcontrollers GPIO Driver                 *
* @author Ahmed Elzoughby                                              *
* @date August 8, 2017                                                 *
* Purpose: Provide an easy interface to deal with digital I/O devices  *
***********************************************************************/


#ifndef HAL_GPIO_H_
#define HAL_GPIO_H_



/***********************************************************************
*                             Include Files                            *
***********************************************************************/

#include "../types.h"
#include "../REG/hw_types.h"
#include "../REG/hw_gpio.h"
#include "../REG/hw_sysctl.h"


/***********************************************************************
*                            Macros & Typedef                          *
***********************************************************************/

#define GPIO_UNLOCK_KEY 0x4C4F434B
#define GPIO_LOCK_KEY   0xFFFFFFFF

#ifdef EASY_MODE

#define gpioMode_t      gpio_mode_t
#define gpioDir_t       gpio_dir_t
#define gpioCurr_t      gpio_curr_t
#define gpioIntrMode_t  gpio_intr_mode_t
#define gpioError_t     gpio_error_t

#endif


/***********************************************************************
*                         Structures & Enums                           *
***********************************************************************/

typedef enum {
    GPIO_MODE_DIGITAL,
    GPIO_MODE_ANALOG
} gpio_mode_t;

typedef enum {
    GPIO_DIR_INPUT,
    GPIO_DIR_INPUT_PULLUP,
    GPIO_DIR_INPUT_PULLDOWN,
    GPIO_DIR_INPUT_PULLUP_PULLDOWN,
    GPIO_DIR_OUTPUT,
    GPIO_DIR_OUTPUT_OPENDRAIN,
    GPIO_DIR_OUTPUT_OPENDRAIN_PULLUP
} gpio_dir_t;

typedef enum {
    GPIO_CURRENT_2MA,
    GPIO_CURRENT_4MA,
    GPIO_CURRENT_8MA,
    GPIO_CURRENT_8MA_SLR
} gpio_curr_t;

typedef enum {
    GPIO_INTR_FALLING_EDGE,
    GPIO_INTR_RISING_EDGE,
    GPIO_INTR_BOTH_EDGE,
    GPIO_INTR_LOW_LEVEL,
    GPIO_INTR_HIGH_LEVEL
} gpio_intr_mode_t;

typedef enum {
    GPIO_STATE_SUCCESS,
    GPIO_STATE_PORT_ERROR,
    GPIO_STATE_PIN_ERROR,
    GPIO_STATE_BIT_ERROR,
    GPIO_STATE_MODE_ERROR,
    GPIO_STATE_DIR_ERROR,
    GPIO_STATE_FUNC_ERROR,
    GPIO_STATE_CURR_ERROR,
    GPIO_STATE_INTR_ERROR,
    GPIO_STATE_LOCK_ERROR
} gpio_error_t;

#ifdef EASY_MODE

typedef struct {
    uint32_t base;
    uint8_t pinNum;
    gpioMode_t mode;
    gpioDir_t dir;
    gpioCurr_t curr;
    uint8_t altFunc;
    bit_t lock;
} gpioPin_t;

typedef struct {
    uint32_t base;
    gpioMode_t mode;
    gpioDir_t dir;
    gpioCurr_t curr;
    bit_t lock;
} gpioPort_t;

#endif


/***********************************************************************
*                   Global Variables Declarations                      *
***********************************************************************/

/* None */


/***********************************************************************
*                        Function Declarations                         *
***********************************************************************/

gpio_error_t gpio_port_set_clk(uint32_t base, bit_t state);

gpio_error_t gpio_port_set_sleep_clk(uint32_t base, bit_t state);

gpio_error_t gpio_port_set_deepsleep_clk(uint32_t base, bit_t state);

gpio_error_t gpio_pin_set_mode(uint32_t base, uint8_t pin_num, gpio_mode_t mode);

gpio_error_t gpio_pin_get_mode(uint32_t base, uint8_t pin_num, gpio_mode_t* dest);

gpio_error_t gpio_port_set_mode(uint32_t base, gpio_mode_t mode);

gpio_error_t gpio_port_get_mode(uint32_t base, gpio_mode_t* dest);

gpio_error_t gpio_pin_set_dir(uint32_t base, uint8_t pin_num, gpio_dir_t dir);

gpio_error_t gpio_pin_get_dir(uint32_t base, uint8_t pin_num, gpio_dir_t* dest);

gpio_error_t gpio_port_set_dir(uint32_t base, gpio_dir_t dir);

gpio_error_t gpio_port_get_dir(uint32_t base, gpio_dir_t* dest);

gpio_error_t gpio_pin_set_alt_func(uint32_t base, uint8_t pin_num, uint8_t func_num);

gpio_error_t gpio_pin_get_alt_func(uint32_t base, uint8_t pin_num, uint8_t* dest);

gpio_error_t gpio_pin_set_curr(uint32_t base, uint8_t pin_num, gpio_curr_t drive_curr);

gpio_error_t gpio_pin_get_curr(uint32_t base, uint8_t pin_num, gpio_curr_t* dest);

gpio_error_t gpio_port_set_curr(uint32_t base, gpio_curr_t drive_curr);

gpio_error_t gpio_port_get_curr(uint32_t base, gpio_curr_t* dest);

gpio_error_t gpio_pin_lock(uint32_t base, uint8_t pin_num);

gpio_error_t gpio_pin_unlock(uint32_t base, uint8_t pin_num, uint32_t magic_key);

gpio_error_t gpio_pin_get_lock(uint32_t base, uint8_t pin_num, bit_t* dest);

gpio_error_t gpio_port_lock(uint32_t base);

gpio_error_t gpio_port_unlock(uint32_t base, uint32_t magic_key);

gpio_error_t gpio_port_get_lock(uint32_t base, bit_t* dest);


gpio_error_t gpio_pin_set_intr(uint32_t base, uint8_t pin_num, bit_t state);

gpio_error_t gpio_pin_get_intr(uint32_t base, uint8_t pin_num, bit_t* dest);

gpio_error_t gpio_port_set_intr(uint32_t base, bit_t state);

gpio_error_t gpio_port_get_intr(uint32_t base, uint8_t* dest);

gpio_error_t gpio_pin_set_intr_mode(uint32_t base, uint8_t pin_num, gpio_intr_mode_t mode);

gpio_error_t gpio_pin_get_intr_mode(uint32_t base, uint8_t pin_num, gpio_intr_mode_t* dest);

gpio_error_t gpio_port_set_intr_mode(uint32_t base, gpio_intr_mode_t mode);

gpio_error_t gpio_port_get_intr_mode(uint32_t base, gpio_intr_mode_t* dest);

gpio_error_t gpio_pin_get_raw_intr_status(uint32_t base, uint8_t pin_num, bit_t* dest);

gpio_error_t gpio_port_get_raw_intr_status(uint32_t base, uint8_t* dest);

gpio_error_t gpio_pin_get_masked_intr_status(uint32_t base, uint8_t pin_num, bit_t* dest);

gpio_error_t gpio_port_get_masked_intr_status(uint32_t base, uint8_t* dest);

gpio_error_t gpio_pin_clear_intr(uint32_t base, uint8_t pin_num);

gpio_error_t gpio_port_clear_intr(uint32_t base);

gpio_error_t gpio_pin_set_adc_trgr(uint32_t base, uint8_t pin_num, bit_t trgr_state);

gpio_error_t gpio_pin_get_adc_trgr(uint32_t base, uint8_t pin_num, bit_t* dest);

gpio_error_t gpio_port_set_adc_trgr(uint32_t base, bit_t trgr_state);

gpio_error_t gpio_port_get_adc_trgr(uint32_t base, uint8_t* dest);

gpio_error_t gpio_pin_set_dma_trgr(uint32_t base, uint8_t pin_num, bit_t trgr_state);

gpio_error_t gpio_pin_get_dma_trgr(uint32_t base, uint8_t pin_num, bit_t* dest);

gpio_error_t gpio_port_set_dma_trgr(uint32_t base, bit_t trgr_state);

gpio_error_t gpio_port_get_dma_trgr(uint32_t base, uint8_t* dest);


gpio_error_t gpio_pin_write(uint32_t base, uint8_t pin_num, bit_t val);

gpio_error_t gpio_pin_read(uint32_t base, uint8_t pin_num, bit_t* dest);

gpio_error_t gpio_port_write(uint32_t base, uint8_t val);

gpio_error_t gpio_port_masked_write(uint32_t base, uint32_t mask, uint8_t val);

gpio_error_t gpio_port_read(uint32_t base, uint8_t* dest);

gpio_error_t gpio_field_write(uint32_t base, uint8_t start_pin, uint8_t end_pin, uint8_t val);

gpio_error_t gpio_field_masked_write(uint32_t base, uint32_t mask, uint8_t fld_shift, uint32_t val);

gpio_error_t gpio_field_read(uint32_t base, uint8_t start_pin, uint8_t end_pin, uint8_t* dest);

#ifdef EASY_MODE

gpioError_t GPIOPinInit(gpioPin_t* pinObj);

gpioError_t GPIOPortInit(gpioPort_t* portObj);

gpioError_t GPIOPinWrite(gpioPin_t* pinObj, bit_t val);

gpioError_t GPIOPortWrite(gpioPort_t* portObj, uint8_t val);

gpioError_t GPIOPinRead(gpioPin_t* pinObj, bit_t* dest);

gpioError_t GPIOPortRead(gpioPort_t* portObj, uint8_t* dest);

#endif


#endif /* HAL_GPIO_H_ */
