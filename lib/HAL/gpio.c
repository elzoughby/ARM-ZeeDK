/***********************************************************************
* GPIO operations for ARM Microcontrollers GPIO Driver                 *
* @author Ahmed Elzoughby                                              *
* @date August 7, 2017                                                 *
* Purpose: Provide an easy interface to deal with digital I/O devices  *
***********************************************************************/



/***********************************************************************
*                             Include Files                            *
***********************************************************************/

#include "gpio.h"


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

gpio_error_t gpio_port_set_clk(uint32_t base, bit_t state)
{
    gpio_error_t result = GPIO_STATE_SUCCESS;

    if(base == PORTA)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_RCGCGPIO, 0, state);
    else if(base == PORTB)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_RCGCGPIO, 1, state);
    else if(base == PORTC)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_RCGCGPIO, 2, state);
    else if(base == PORTD)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_RCGCGPIO, 3, state);
    else if(base == PORTE)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_RCGCGPIO, 4, state);
    else if(base == PORTF)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_RCGCGPIO, 5, state);
    else
        result = GPIO_STATE_PORT_ERROR;

    return result;
}

gpio_error_t gpio_port_set_sleep_clk(uint32_t base, bit_t state)
{
    gpio_error_t result = GPIO_STATE_SUCCESS;

    if(base == PORTA)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_SCGCGPIO, 0, state);
    else if(base == PORTB)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_SCGCGPIO, 1, state);
    else if(base == PORTC)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_SCGCGPIO, 2, state);
    else if(base == PORTD)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_SCGCGPIO, 3, state);
    else if(base == PORTE)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_SCGCGPIO, 4, state);
    else if(base == PORTF)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_SCGCGPIO, 5, state);
    else
        result = GPIO_STATE_PORT_ERROR;

    return result;
}

gpio_error_t gpio_port_set_deepsleep_clk(uint32_t base, bit_t state)
{
    gpio_error_t result = GPIO_STATE_SUCCESS;

    if(base == PORTA)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_DCGCGPIO, 0, state);
    else if(base == PORTB)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_DCGCGPIO, 1, state);
    else if(base == PORTC)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_DCGCGPIO, 2, state);
    else if(base == PORTD)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_DCGCGPIO, 3, state);
    else if(base == PORTE)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_DCGCGPIO, 4, state);
    else if(base == PORTF)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_DCGCGPIO, 5, state);
    else
        result = GPIO_STATE_PORT_ERROR;

    return result;
}

gpio_error_t gpio_pin_set_mode(uint32_t base, uint8_t pin_num, gpio_mode_t mode)
{
    gpio_error_t result = GPIO_STATE_SUCCESS;

    if (mode == GPIO_MODE_DIGITAL)
    {
        HW_REG32_BIT_SET(base + OFFSET_GPIODEN, pin_num);
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIOAMSEL, pin_num);
    }
    else if (mode == GPIO_MODE_ANALOG)
    {
        HW_REG32_BIT_SET(base + OFFSET_GPIOAMSEL, pin_num);
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIODEN, pin_num);
    }
    else
    {
        result = GPIO_STATE_MODE_ERROR;
    }

    return result;
}

gpio_error_t gpio_pin_get_mode(uint32_t base, uint8_t pin_num, gpio_mode_t* dest)
{
    *dest = HW_REG32_BIT_READ(base + OFFSET_GPIOAMSEL, pin_num) ?
            GPIO_MODE_ANALOG : GPIO_MODE_DIGITAL;
    return GPIO_STATE_SUCCESS;
}

gpio_error_t gpio_port_set_mode(uint32_t base, gpio_mode_t mode)
{
    gpio_error_t result = GPIO_STATE_SUCCESS;

    if (mode == GPIO_MODE_DIGITAL)
    {
        HW_REG32_WRITE(base + OFFSET_GPIODEN, 0xFFFFFFFF);
        HW_REG32_WRITE(base + OFFSET_GPIOAMSEL, 0x00000000);
    }
    else if (mode == GPIO_MODE_ANALOG)
    {
        HW_REG32_WRITE(base + OFFSET_GPIOAMSEL, 0xFFFFFFFF);
        HW_REG32_WRITE(base + OFFSET_GPIODEN, 0x00000000);
    }
    else
    {
        result = GPIO_STATE_MODE_ERROR;
    }

    return result;
}

gpio_error_t gpio_port_get_mode(uint32_t base, gpio_mode_t* dest)
{
    gpio_error_t result = GPIO_STATE_SUCCESS;

    if (HW_REG32_FIELD_READ(base + OFFSET_GPIOAMSEL, 0, 7) == 0xFF)
    {
        *dest = GPIO_MODE_ANALOG;
    }
    else if (HW_REG32_FIELD_READ(base + OFFSET_GPIOAMSEL, 0, 7) == 0x00)
    {
        *dest = GPIO_MODE_DIGITAL;
    }
    else
    {
        result = GPIO_STATE_MODE_ERROR;
    }

    return result;
}

gpio_error_t gpio_pin_set_dir(uint32_t base, uint8_t pin_num, gpio_dir_t dir)
{
    gpio_error_t result = GPIO_STATE_SUCCESS;

    if (dir == GPIO_DIR_INPUT)
    {
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIODIR, pin_num);
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIOPUR, pin_num);
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIOPDR, pin_num);
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIOODR, pin_num);
    }
    else if (dir == GPIO_DIR_INPUT_PULLUP)
    {
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIODIR, pin_num);
        HW_REG32_BIT_SET(base + OFFSET_GPIOPUR, pin_num);
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIOPDR, pin_num);
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIOODR, pin_num);
    }
    else if (dir == GPIO_DIR_INPUT_PULLDOWN)
    {
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIODIR, pin_num);
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIOPUR, pin_num);
        HW_REG32_BIT_SET(base + OFFSET_GPIOPDR, pin_num);
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIOODR, pin_num);
    }
    else if (dir == GPIO_DIR_INPUT_PULLUP_PULLDOWN)
    {
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIODIR, pin_num);
        HW_REG32_BIT_SET(base + OFFSET_GPIOPUR, pin_num);
        HW_REG32_BIT_SET(base + OFFSET_GPIOPDR, pin_num);
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIOODR, pin_num);
    }
    else if (dir == GPIO_DIR_OUTPUT)
    {
        HW_REG32_BIT_SET(base + OFFSET_GPIODIR, pin_num);
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIOPUR, pin_num);
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIOPDR, pin_num);
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIOODR, pin_num);
    }
    else if (dir == GPIO_DIR_OUTPUT_OPENDRAIN)
    {
        HW_REG32_BIT_SET(base + OFFSET_GPIODIR, pin_num);
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIOPUR, pin_num);
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIOPDR, pin_num);
        HW_REG32_BIT_SET(base + OFFSET_GPIOODR, pin_num);
    }
    else if (dir == GPIO_DIR_OUTPUT_OPENDRAIN_PULLUP)
    {
        HW_REG32_BIT_SET(base + OFFSET_GPIODIR, pin_num);
        HW_REG32_BIT_SET(base + OFFSET_GPIOPUR, pin_num);
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIOPDR, pin_num);
        HW_REG32_BIT_SET(base + OFFSET_GPIOODR, pin_num);
    }
    else
    {
        result = GPIO_STATE_DIR_ERROR;
    }

    return result;
}

gpio_error_t gpio_pin_get_dir(uint32_t base, uint8_t pin_num, gpio_dir_t* dest)
{
    gpio_error_t result = GPIO_STATE_SUCCESS;

    bit_t tmp_dir = HW_REG32_BIT_READ(base + OFFSET_GPIODIR, pin_num);
    bit_t tmp_pur = HW_REG32_BIT_READ(base + OFFSET_GPIOPUR, pin_num);
    bit_t tmp_pdr = HW_REG32_BIT_READ(base + OFFSET_GPIOPDR, pin_num);
    bit_t tmp_odr = HW_REG32_BIT_READ(base + OFFSET_GPIOODR, pin_num);

    if (tmp_dir == LOW && tmp_pur == LOW && tmp_pdr == LOW && tmp_odr == LOW)
    {
        *dest = GPIO_DIR_INPUT;
    }
    else if (tmp_dir == LOW && tmp_pdr == LOW && tmp_odr == LOW && tmp_pur == HIGH)
    {
        *dest = GPIO_DIR_INPUT_PULLUP;
    }
    else if (tmp_dir == LOW && tmp_pur == LOW && tmp_odr == LOW && tmp_pdr == HIGH)
    {
        *dest = GPIO_DIR_INPUT_PULLDOWN;
    }
    else if (tmp_dir == LOW && tmp_odr == LOW && tmp_pdr == HIGH && tmp_pur == HIGH)
    {
        *dest = GPIO_DIR_INPUT_PULLUP_PULLDOWN;
    }
    else if (tmp_pur == LOW && tmp_pdr == LOW && tmp_odr == LOW && tmp_dir == HIGH)
    {
        *dest = GPIO_DIR_OUTPUT;
    }
    else if (tmp_pur == LOW && tmp_pdr == LOW && tmp_dir == HIGH && tmp_odr == HIGH)
    {
        *dest = GPIO_DIR_OUTPUT_OPENDRAIN;
    }
    else if (tmp_pdr == LOW && tmp_dir == HIGH && tmp_odr == HIGH && tmp_pur == HIGH)
    {
        *dest = GPIO_DIR_OUTPUT_OPENDRAIN_PULLUP;
    }
    else
    {
        result = GPIO_STATE_DIR_ERROR;
    }

    return result;
}

gpio_error_t gpio_port_set_dir(uint32_t base, gpio_dir_t dir)
{
    gpio_error_t result = GPIO_STATE_SUCCESS;

    if (dir == GPIO_DIR_INPUT)
    {
        HW_REG32_WRITE(base + OFFSET_GPIODIR, 0x00000000);
        HW_REG32_WRITE(base + OFFSET_GPIOPUR, 0x00000000);
        HW_REG32_WRITE(base + OFFSET_GPIOPDR, 0x00000000);
        HW_REG32_WRITE(base + OFFSET_GPIOODR, 0x00000000);
    }
    else if (dir == GPIO_DIR_INPUT_PULLUP)
    {
        HW_REG32_WRITE(base + OFFSET_GPIODIR, 0x00000000);
        HW_REG32_WRITE(base + OFFSET_GPIOPUR, 0xFFFFFFFF);
        HW_REG32_WRITE(base + OFFSET_GPIOPDR, 0x00000000);
        HW_REG32_WRITE(base + OFFSET_GPIOODR, 0x00000000);
    }
    else if (dir == GPIO_DIR_INPUT_PULLDOWN)
    {
        HW_REG32_WRITE(base + OFFSET_GPIODIR, 0x00000000);
        HW_REG32_WRITE(base + OFFSET_GPIOPUR, 0x00000000);
        HW_REG32_WRITE(base + OFFSET_GPIOPDR, 0xFFFFFFFF);
        HW_REG32_WRITE(base + OFFSET_GPIOODR, 0x00000000);
    }
    else if (dir == GPIO_DIR_INPUT_PULLUP_PULLDOWN)
    {
        HW_REG32_WRITE(base + OFFSET_GPIODIR, 0x00000000);
        HW_REG32_WRITE(base + OFFSET_GPIOPUR, 0xFFFFFFFF);
        HW_REG32_WRITE(base + OFFSET_GPIOPDR, 0xFFFFFFFF);
        HW_REG32_WRITE(base + OFFSET_GPIOODR, 0x00000000);
    }
    else if (dir == GPIO_DIR_OUTPUT)
    {
        HW_REG32_WRITE(base + OFFSET_GPIODIR, 0xFFFFFFFF);
        HW_REG32_WRITE(base + OFFSET_GPIOPUR, 0x00000000);
        HW_REG32_WRITE(base + OFFSET_GPIOPDR, 0x00000000);
        HW_REG32_WRITE(base + OFFSET_GPIOODR, 0x00000000);
    }
    else if (dir == GPIO_DIR_OUTPUT_OPENDRAIN)
    {
        HW_REG32_WRITE(base + OFFSET_GPIODIR, 0xFFFFFFFF);
        HW_REG32_WRITE(base + OFFSET_GPIOPUR, 0x00000000);
        HW_REG32_WRITE(base + OFFSET_GPIOPDR, 0x00000000);
        HW_REG32_WRITE(base + OFFSET_GPIOODR, 0xFFFFFFFF);
    }
    else if (dir == GPIO_DIR_OUTPUT_OPENDRAIN_PULLUP)
    {
        HW_REG32_WRITE(base + OFFSET_GPIODIR, 0xFFFFFFFF);
        HW_REG32_WRITE(base + OFFSET_GPIOPUR, 0xFFFFFFFF);
        HW_REG32_WRITE(base + OFFSET_GPIOPDR, 0x00000000);
        HW_REG32_WRITE(base + OFFSET_GPIOODR, 0xFFFFFFFF);
    }
    else
    {
        result = GPIO_STATE_DIR_ERROR;
    }

    return result;
}

gpio_error_t gpio_port_get_dir(uint32_t base, gpio_dir_t* dest)
{
    gpio_error_t result = GPIO_STATE_SUCCESS;

    uint8_t tmp_dir = HW_REG32_FIELD_READ(base + OFFSET_GPIODIR, 0, 7);
    uint8_t tmp_pur = HW_REG32_FIELD_READ(base + OFFSET_GPIOPUR, 0, 7);
    uint8_t tmp_pdr = HW_REG32_FIELD_READ(base + OFFSET_GPIOPDR, 0, 7);
    uint8_t tmp_odr = HW_REG32_FIELD_READ(base + OFFSET_GPIOODR, 0, 7);

    if (tmp_dir == 0x00 && tmp_pur == 0x00 && tmp_pdr == 0x00 && tmp_odr == 0x00)
    {
        *dest = GPIO_DIR_INPUT;
    }
    else if (tmp_dir == 0x00 && tmp_pdr == 0x00 && tmp_odr == 0x00 && tmp_pur == 0xFF)
    {
        *dest = GPIO_DIR_INPUT_PULLUP;
    }
    else if (tmp_dir == 0x00 && tmp_pur == 0x00 && tmp_odr == 0x00 && tmp_pdr == 0xFF)
    {
        *dest = GPIO_DIR_INPUT_PULLDOWN;
    }
    else if (tmp_dir == 0x00 && tmp_odr == 0x00 && tmp_pdr == 0xFF && tmp_pur == 0xFF)
    {
        *dest = GPIO_DIR_INPUT_PULLUP_PULLDOWN;
    }
    else if (tmp_pur == 0x00 && tmp_pdr == 0x00 && tmp_odr == 0x00 && tmp_dir == 0xFF)
    {
        *dest = GPIO_DIR_OUTPUT;
    }
    else if (tmp_pur == 0x00 && tmp_pdr == 0x00 && tmp_dir == 0xFF && tmp_odr == 0xFF)
    {
        *dest = GPIO_DIR_OUTPUT_OPENDRAIN;
    }
    else if (tmp_pdr == 0x00 && tmp_dir == 0xFF && tmp_odr == 0xFF && tmp_pur == 0xFF)
    {
        *dest = GPIO_DIR_OUTPUT_OPENDRAIN_PULLUP;
    }
    else
    {
        result = GPIO_STATE_DIR_ERROR;
    }

    return result;
}

gpio_error_t gpio_pin_set_alt_func(uint32_t base, uint8_t pin_num, uint8_t func_num)
{
    gpio_error_t result = GPIO_STATE_SUCCESS;

    if (func_num <= 15)
    {
        HW_REG32_BIT_SET(base + OFFSET_GPIOAFSEL, pin_num);
        HW_REG32_FIELD_WRITE(base + OFFSET_GPIOPCTL, pin_num * 4,
                             pin_num * 4 + 3, func_num);
    }
    else
    {
        result = GPIO_STATE_FUNC_ERROR;
    }

    return result;
}

gpio_error_t gpio_pin_get_alt_func(uint32_t base, uint8_t pin_num, uint8_t* dest)
{
    *dest = HW_REG32_FIELD_READ(base + OFFSET_GPIOPCTL, pin_num * 4,
                                pin_num * 4 + 3);
    return GPIO_STATE_SUCCESS;
}

gpio_error_t gpio_pin_set_curr(uint32_t base, uint8_t pin_num, gpio_curr_t drive_curr)
{
    gpio_error_t result = GPIO_STATE_SUCCESS;

    if (drive_curr == GPIO_CURRENT_2MA)
    {
        HW_REG32_BIT_SET(base + OFFSET_GPIODR2R, pin_num);
    }
    else if (drive_curr == GPIO_CURRENT_4MA)
    {
        HW_REG32_BIT_SET(base + OFFSET_GPIODR4R, pin_num);
    }
    else if (drive_curr == GPIO_CURRENT_8MA)
    {
        HW_REG32_BIT_SET(base + OFFSET_GPIODR8R, pin_num);
    }
    else if (drive_curr == GPIO_CURRENT_8MA_SLR)
    {
        HW_REG32_BIT_SET(base + OFFSET_GPIODR8R, pin_num);
        HW_REG32_BIT_SET(base + OFFSET_GPIOSLR, pin_num);
    }
    else
    {
        result = GPIO_STATE_CURR_ERROR;
    }

    return result;
}

gpio_error_t gpio_pin_get_curr(uint32_t base, uint8_t pin_num, gpio_curr_t* dest)
{
    if (HW_REG32_BIT_READ(base + OFFSET_GPIODR8R, pin_num))
    {
        if (HW_REG32_BIT_READ(base + OFFSET_GPIOSLR, pin_num))
            *dest = GPIO_CURRENT_8MA_SLR;
        else
            *dest = GPIO_CURRENT_8MA;
    }
    else if (HW_REG32_BIT_READ(base + OFFSET_GPIODR4R, pin_num))
    {
        *dest = GPIO_CURRENT_4MA;
    }
    else
    {
        *dest = GPIO_CURRENT_2MA;
    }

    return GPIO_STATE_SUCCESS;
}

gpio_error_t gpio_port_set_curr(uint32_t base, gpio_curr_t drive_curr)
{
    gpio_error_t result = GPIO_STATE_SUCCESS;

    if (drive_curr == GPIO_CURRENT_2MA)
    {
        HW_REG32_WRITE(base + OFFSET_GPIODR2R, 0xFFFFFFFF);
    }
    else if (drive_curr == GPIO_CURRENT_4MA)
    {
        HW_REG32_WRITE(base + OFFSET_GPIODR4R, 0xFFFFFFFF);
    }
    else if (drive_curr == GPIO_CURRENT_8MA)
    {
        HW_REG32_WRITE(base + OFFSET_GPIODR8R, 0xFFFFFFFF);
    }
    else if (drive_curr == GPIO_CURRENT_8MA_SLR)
    {
        HW_REG32_WRITE(base + OFFSET_GPIODR8R, 0xFFFFFFFF);
        HW_REG32_WRITE(base + OFFSET_GPIOSLR, 0xFFFFFFFF);
    }
    else
    {
        result = GPIO_STATE_CURR_ERROR;
    }

    return result;
}

gpio_error_t gpio_port_get_curr(uint32_t base, gpio_curr_t* dest)
{
    uint8_t tmp_dr4 = HW_REG32_FIELD_READ(base + OFFSET_GPIODR4R, 0, 7);
    uint8_t tmp_dr8 = HW_REG32_FIELD_READ(base + OFFSET_GPIODR8R, 0, 7);

    if (tmp_dr8 == 0xFF)
    {
        uint8_t tmp_slr = HW_REG32_FIELD_READ(base + OFFSET_GPIOSLR, 0, 7);
        if (tmp_slr == 0xFF)
            *dest = GPIO_CURRENT_8MA_SLR;
        else
            *dest = GPIO_CURRENT_8MA;
    }
    else if (tmp_dr4 == 0xFF)
    {
        *dest = GPIO_CURRENT_4MA;
    }
    else
    {
        *dest = GPIO_CURRENT_2MA;
    }

    return GPIO_STATE_SUCCESS;
}

gpio_error_t gpio_pin_lock(uint32_t base, uint8_t pin_num)
{
    HW_REG32_BIT_WRITE(base + OFFSET_GPIOCR, pin_num, LOW);
    HW_REG32_WRITE(base + OFFSET_GPIOLOCK, GPIO_LOCK_KEY);
    return GPIO_STATE_SUCCESS;
}

gpio_error_t gpio_pin_unlock(uint32_t base, uint8_t pin_num, uint32_t magic_key)
{
    gpio_error_t result = GPIO_STATE_SUCCESS;

    if (magic_key == GPIO_UNLOCK_KEY)
    {
        HW_REG32_WRITE(base + OFFSET_GPIOLOCK, magic_key);
        HW_REG32_BIT_WRITE(base + OFFSET_GPIOCR, pin_num, HIGH);
    }
    else
    {
        result = GPIO_STATE_LOCK_ERROR;
    }

    return result;
}

gpio_error_t gpio_pin_get_lock(uint32_t base, uint8_t pin_num, bit_t* dest)
{
    *dest = HW_REG32_BIT_READ(base + OFFSET_GPIOCR, pin_num)? OFF:ON;
    return GPIO_STATE_SUCCESS;
}


gpio_error_t gpio_port_lock(uint32_t base)
{
    HW_REG32_WRITE(base + OFFSET_GPIOCR, 0x00000000);
    HW_REG32_WRITE(base + OFFSET_GPIOLOCK, GPIO_LOCK_KEY);
    return GPIO_STATE_SUCCESS;
}

gpio_error_t gpio_port_unlock(uint32_t base, uint32_t magic_key)
{
    gpio_error_t result = GPIO_STATE_SUCCESS;

    if(magic_key == GPIO_UNLOCK_KEY)
    {
        HW_REG32_WRITE(base + OFFSET_GPIOLOCK, magic_key);
        HW_REG32_WRITE(base + OFFSET_GPIOCR, 0xFF);
    }
    else
    {
        result = GPIO_STATE_LOCK_ERROR;
    }

    return result;
}

gpio_error_t gpio_port_get_lock(uint32_t base, bit_t* dest)
{
    *dest = HW_REG32_FIELD_READ(base + OFFSET_GPIOCR, 0, 7) == 0xFF? OFF:ON;
    return GPIO_STATE_SUCCESS;
}



gpio_error_t gpio_pin_set_intr(uint32_t base, uint8_t pin_num, bit_t state)
{
    gpio_error_t result = GPIO_STATE_SUCCESS;

    if (state == 1)
    {
        HW_REG32_BIT_SET(base + OFFSET_GPIOIM, pin_num);
    }
    else if (state == 0)
    {
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIOIM, pin_num);
    }
    else
    {
        result = GPIO_STATE_BIT_ERROR;
    }

    return result;
}

gpio_error_t gpio_pin_get_intr(uint32_t base, uint8_t pin_num, bit_t* dest)
{
    *dest = HW_REG32_BIT_READ(base + OFFSET_GPIOIM, pin_num);
    return GPIO_STATE_SUCCESS;
}

gpio_error_t gpio_port_set_intr(uint32_t base, bit_t state)
{
    gpio_error_t result = GPIO_STATE_SUCCESS;

    if (state == 1)
    {
        HW_REG32_WRITE(base + OFFSET_GPIOIM, 0xFFFFFFFF);
    }
    else if (state == 0)
    {
        HW_REG32_WRITE(base + OFFSET_GPIOIM, 0x00000000);
    }
    else
    {
        result = GPIO_STATE_BIT_ERROR;
    }

    return result;
}

gpio_error_t gpio_port_get_intr(uint32_t base, uint8_t* dest)
{
    *dest = HW_REG32_FIELD_READ(base + OFFSET_GPIOIM, 0, 7);
    return GPIO_STATE_SUCCESS;
}

gpio_error_t gpio_pin_set_intr_mode(uint32_t base, uint8_t pin_num, gpio_intr_mode_t mode)
{
    gpio_error_t result = GPIO_STATE_SUCCESS;

    if (mode == GPIO_INTR_FALLING_EDGE)
    {
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIOIS, pin_num);
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIOIBE, pin_num);
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIOIEV, pin_num);
    }
    else if (mode == GPIO_INTR_RISING_EDGE)
    {
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIOIS, pin_num);
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIOIBE, pin_num);
        HW_REG32_BIT_SET(base + OFFSET_GPIOIEV, pin_num);
    }
    else if (mode == GPIO_INTR_BOTH_EDGE)
    {
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIOIS, pin_num);
        HW_REG32_BIT_SET(base + OFFSET_GPIOIBE, pin_num);
    }
    else if (mode == GPIO_INTR_LOW_LEVEL)
    {
        HW_REG32_BIT_SET(base + OFFSET_GPIOIS, pin_num);
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIOIBE, pin_num);
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIOIEV, pin_num);
    }
    else if (mode == GPIO_INTR_HIGH_LEVEL)
    {
        HW_REG32_BIT_SET(base + OFFSET_GPIOIS, pin_num);
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIOIBE, pin_num);
        HW_REG32_BIT_SET(base + OFFSET_GPIOIEV, pin_num);
    }
    else
    {
        result = GPIO_STATE_INTR_ERROR;
    }

    return result;
}

gpio_error_t gpio_pin_get_intr_mode(uint32_t base, uint8_t pin_num, gpio_intr_mode_t* dest)
{
    gpio_error_t result = GPIO_STATE_SUCCESS;

    bit_t tmp_is = HW_REG32_BIT_READ(base + OFFSET_GPIOIS, pin_num);
    bit_t tmp_ibe = HW_REG32_BIT_READ(base + OFFSET_GPIOIBE, pin_num);
    bit_t tmp_iev = HW_REG32_BIT_READ(base + OFFSET_GPIOIEV, pin_num);

    if (tmp_is == LOW && tmp_ibe == LOW && tmp_iev == LOW)
    {
        *dest = GPIO_INTR_FALLING_EDGE;
    }
    else if (tmp_is == LOW && tmp_ibe == LOW && tmp_iev == HIGH)
    {
        *dest = GPIO_INTR_RISING_EDGE;
    }
    else if (tmp_is == LOW && tmp_ibe == HIGH)
    {
        *dest = GPIO_INTR_BOTH_EDGE;
    }
    else if (tmp_iev == LOW && tmp_ibe == LOW && tmp_is == HIGH)
    {
        *dest = GPIO_INTR_LOW_LEVEL;
    }
    else if (tmp_ibe == LOW && tmp_is == HIGH && tmp_iev == HIGH)
    {
        *dest = GPIO_INTR_HIGH_LEVEL;
    }
    else
    {
        result = GPIO_STATE_INTR_ERROR;
    }

    return result;
}

gpio_error_t gpio_port_set_intr_mode(uint32_t base, gpio_intr_mode_t mode)
{
    gpio_error_t result = GPIO_STATE_SUCCESS;

    if (mode == GPIO_INTR_FALLING_EDGE)
    {
        HW_REG32_WRITE(base + OFFSET_GPIOIS, 0x00000000);
        HW_REG32_WRITE(base + OFFSET_GPIOIBE, 0x00000000);
        HW_REG32_WRITE(base + OFFSET_GPIOIEV, 0x00000000);
    }
    else if (mode == GPIO_INTR_RISING_EDGE)
    {
        HW_REG32_WRITE(base + OFFSET_GPIOIS, 0x00000000);
        HW_REG32_WRITE(base + OFFSET_GPIOIBE, 0x00000000);
        HW_REG32_WRITE(base + OFFSET_GPIOIEV, 0xFFFFFFFF);
    }
    else if (mode == GPIO_INTR_BOTH_EDGE)
    {
        HW_REG32_WRITE(base + OFFSET_GPIOIS, 0x00000000);
        HW_REG32_WRITE(base + OFFSET_GPIOIBE, 0xFFFFFFFF);
    }
    else if (mode == GPIO_INTR_LOW_LEVEL)
    {
        HW_REG32_WRITE(base + OFFSET_GPIOIS, 0xFFFFFFFF);
        HW_REG32_WRITE(base + OFFSET_GPIOIBE, 0x00000000);
        HW_REG32_WRITE(base + OFFSET_GPIOIEV, 0x00000000);
    }
    else if (mode == GPIO_INTR_HIGH_LEVEL)
    {
        HW_REG32_WRITE(base + OFFSET_GPIOIS, 0xFFFFFFFF);
        HW_REG32_WRITE(base + OFFSET_GPIOIBE, 0x00000000);
        HW_REG32_WRITE(base + OFFSET_GPIOIEV, 0xFFFFFFFF);
    }
    else
    {
        result = GPIO_STATE_INTR_ERROR;
    }

    return result;
}

gpio_error_t gpio_port_get_intr_mode(uint32_t base, gpio_intr_mode_t* dest)
{
    gpio_error_t result = GPIO_STATE_SUCCESS;

    uint8_t tmp_is = HW_REG32_FIELD_READ(base + OFFSET_GPIOIS, 0, 7);
    uint8_t tmp_ibe = HW_REG32_FIELD_READ(base + OFFSET_GPIOIBE, 0, 7);
    uint8_t tmp_iev = HW_REG32_FIELD_READ(base + OFFSET_GPIOIEV, 0, 7);

    if (tmp_is == 0x00 && tmp_ibe == 0x00 && tmp_iev == 0x00)
    {
        *dest = GPIO_INTR_FALLING_EDGE;
    }
    else if (tmp_is == 0x00 && tmp_ibe == 0x00 && tmp_iev == 0xFF)
    {
        *dest = GPIO_INTR_RISING_EDGE;
    }
    else if (tmp_is == 0x00 && tmp_ibe == 0xFF)
    {
        *dest = GPIO_INTR_BOTH_EDGE;
    }
    else if (tmp_iev == 0x00 && tmp_ibe == 0x00 && tmp_is == 0xFF)
    {
        *dest = GPIO_INTR_LOW_LEVEL;
    }
    else if (tmp_ibe == 0x00 && tmp_is == 0xFF && tmp_iev == 0xFF)
    {
        *dest = GPIO_INTR_HIGH_LEVEL;
    }
    else
    {
        result = GPIO_STATE_INTR_ERROR;
    }

    return result;
}

gpio_error_t gpio_pin_get_raw_intr_status(uint32_t base, uint8_t pin_num, bit_t* dest)
{
    *dest = HW_REG32_BIT_READ(base + OFFSET_GPIORIS, pin_num);
    return GPIO_STATE_SUCCESS;
}

gpio_error_t gpio_port_get_raw_intr_status(uint32_t base, uint8_t* dest)
{
    *dest = HW_REG32_READ(base + OFFSET_GPIORIS);
    return GPIO_STATE_SUCCESS;
}

gpio_error_t gpio_pin_get_masked_intr_status(uint32_t base, uint8_t pin_num, bit_t* dest)
{
    *dest = HW_REG32_BIT_READ(base + OFFSET_GPIOMIS, pin_num);
    return GPIO_STATE_SUCCESS;
}

gpio_error_t gpio_port_get_masked_intr_status(uint32_t base, uint8_t* dest)
{
    *dest = HW_REG32_READ(base + OFFSET_GPIORIS);
    return GPIO_STATE_SUCCESS;
}

gpio_error_t gpio_pin_clear_intr(uint32_t base, uint8_t pin_num)
{
    HW_REG32_BIT_SET(base + OFFSET_GPIOICR, pin_num);
    return GPIO_STATE_SUCCESS;
}

gpio_error_t gpio_port_clear_intr(uint32_t base)
{
    HW_REG32_WRITE(base + OFFSET_GPIOICR, 0xFFFFFFFF);
    return GPIO_STATE_SUCCESS;
}

gpio_error_t gpio_pin_set_adc_trgr(uint32_t base, uint8_t pin_num, bit_t trgr_state)
{
    gpio_error_t result = GPIO_STATE_SUCCESS;

    if (trgr_state == 1)
    {
        HW_REG32_BIT_SET(base + OFFSET_GPIOADCCTL, pin_num);
    }
    else if (trgr_state == 0)
    {
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIOADCCTL, pin_num);
    }
    else
    {
        result = GPIO_STATE_BIT_ERROR;
    }

    return result;
}

gpio_error_t gpio_pin_get_adc_trgr(uint32_t base, uint8_t pin_num, bit_t* dest)
{
    *dest = HW_REG32_BIT_READ(base + OFFSET_GPIOADCCTL, pin_num);
    return GPIO_STATE_SUCCESS;
}

gpio_error_t gpio_port_set_adc_trgr(uint32_t base, bit_t trgr_state)
{
    gpio_error_t result = GPIO_STATE_SUCCESS;

    if (trgr_state == 1)
    {
        HW_REG32_WRITE(base + OFFSET_GPIOADCCTL, 0xFFFFFFFF);
    }
    else if (trgr_state == 0)
    {
        HW_REG32_WRITE(base + OFFSET_GPIOADCCTL, 0x00000000);
    }
    else
    {
        result = GPIO_STATE_BIT_ERROR;
    }

    return result;
}

gpio_error_t gpio_port_get_adc_trgr(uint32_t base, uint8_t* dest)
{
    *dest = HW_REG32_FIELD_READ(base + OFFSET_GPIOADCCTL, 0, 7);
    return GPIO_STATE_SUCCESS;
}

gpio_error_t gpio_pin_set_dma_trgr(uint32_t base, uint8_t pin_num, bit_t trgr_state)
{
    gpio_error_t result = GPIO_STATE_SUCCESS;

    if (trgr_state == 1)
    {
        HW_REG32_BIT_SET(base + OFFSET_GPIODMACTL, pin_num);
    }
    else if (trgr_state == 0)
    {
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIODMACTL, pin_num);
    }
    else
    {
        result = GPIO_STATE_BIT_ERROR;
    }

    return result;
}

gpio_error_t gpio_pin_get_dma_trgr(uint32_t base, uint8_t pin_num, bit_t* dest)
{
    *dest = HW_REG32_BIT_READ(base + OFFSET_GPIODMACTL, pin_num);
    return GPIO_STATE_SUCCESS;
}

gpio_error_t gpio_port_set_dma_trgr(uint32_t base, bit_t trgr_state)
{
    gpio_error_t result = GPIO_STATE_SUCCESS;

    if (trgr_state == 1)
    {
        HW_REG32_WRITE(base + OFFSET_GPIODMACTL, 0xFFFFFFFF);
    }
    else if (trgr_state == 0)
    {
        HW_REG32_WRITE(base + OFFSET_GPIODMACTL, 0x00000000);
    }
    else
    {
        result = GPIO_STATE_BIT_ERROR;
    }

    return result;
}

gpio_error_t gpio_port_get_dma_trgr(uint32_t base, uint8_t* dest)
{
    *dest = HW_REG32_FIELD_READ(base + OFFSET_GPIODMACTL, 0, 7);
    return GPIO_STATE_SUCCESS;
}


gpio_error_t gpio_pin_write(uint32_t base, uint8_t pin_num, bit_t val)
{
    gpio_error_t result = GPIO_STATE_SUCCESS;

    if (val == 1)
    {
        HW_REG32_BIT_SET(base + OFFSET_GPIODATA_NM, pin_num);
    }
    else if (val == 0)
    {
        HW_REG32_BIT_CLEAR(base + OFFSET_GPIODATA_NM, pin_num);
    }
    else
    {
        result = GPIO_STATE_BIT_ERROR;
    }

    return result;
}

gpio_error_t gpio_pin_read(uint32_t base, uint8_t pin_num, bit_t* dest)
{
    *dest = HW_REG32_BIT_READ(base + OFFSET_GPIODATA_NM, pin_num);
    return GPIO_STATE_SUCCESS;
}

gpio_error_t gpio_port_write(uint32_t base, uint8_t val)
{
    HW_REG32_WRITE(base + OFFSET_GPIODATA_NM, val);
    return GPIO_STATE_SUCCESS;
}

gpio_error_t gpio_port_masked_write(uint32_t base, uint32_t mask, uint8_t val)
{
    /* HW_REG32_MASKED_WRITE(base + OFFSET_GPIODATA_ALL, mask, val); */
    HW_REG32_WRITE(base + (mask << 2), val);
    return GPIO_STATE_SUCCESS;
}

gpio_error_t gpio_port_read(uint32_t base, uint8_t* dest)
{
    *dest = HW_REG32_READ(base + OFFSET_GPIODATA_NM);
    return GPIO_STATE_SUCCESS;
}

gpio_error_t gpio_field_write(uint32_t base, uint8_t start_pin, uint8_t end_pin, uint8_t val)
{
    gpio_error_t result = GPIO_STATE_SUCCESS;

    if (start_pin < 8 && end_pin < 8)
    {
        HW_REG32_FIELD_WRITE(base + OFFSET_GPIODATA_NM, start_pin, end_pin, val);
    }
    else
    {
        result = GPIO_STATE_PIN_ERROR;
    }

    return result;
}

gpio_error_t gpio_field_masked_write(uint32_t base, uint32_t mask, uint8_t fld_shift, uint32_t val)
{
    HW_REG32_FIELD_MASKED_WRITE(base + OFFSET_GPIODATA_NM, mask, fld_shift, val);
    return GPIO_STATE_SUCCESS;
}

gpio_error_t gpio_field_read(uint32_t base, uint8_t start_pin, uint8_t end_pin, uint8_t* dest) {

    gpio_error_t result = GPIO_STATE_SUCCESS;

    if (start_pin < 8 && end_pin < 8)
    {
        *dest = HW_REG32_FIELD_READ(base + OFFSET_GPIODATA_NM, start_pin, end_pin);
    }
    else
    {
        result = GPIO_STATE_PIN_ERROR;
    }

    return result;
}


#ifdef EASY_MODE

gpioError_t GPIOPinInit(gpioPin_t* pinObj)
{
    gpioError_t result = GPIO_STATE_SUCCESS;

    if(pinObj->base == PORTA || pinObj->base == PORTB
            || pinObj->base == PORTC || pinObj->base == PORTD
            || pinObj->base == PORTE || pinObj->base == PORTF)
    {
        if(pinObj->pinNum < 8)
        {
            gpio_port_set_clk(pinObj->base, ON);
            if(pinObj->lock == ON)
            {
                gpio_pin_unlock(pinObj->base, pinObj->pinNum, GPIO_UNLOCK_KEY);
            }
            result = gpio_pin_set_mode(pinObj->base, pinObj->pinNum, pinObj->mode);
            if(result == GPIO_STATE_SUCCESS)
            {
                result = gpio_pin_set_dir(pinObj->base, pinObj->pinNum, pinObj->dir);
                if(result == GPIO_STATE_SUCCESS)
                {
                    result = gpio_pin_set_curr(pinObj->base, pinObj->pinNum, pinObj->curr);
                    if(result == GPIO_STATE_SUCCESS)
                    {
                        if(pinObj->mode == GPIO_MODE_ANALOG)
                        {
                            result = gpio_pin_set_alt_func(pinObj->base, pinObj->pinNum, pinObj->altFunc);
                        }
                    }
                }
            }
        }
        else
        {
            result = GPIO_STATE_PIN_ERROR;
        }
    }
    else
    {
        result = GPIO_STATE_PORT_ERROR;
    }

    return result;
}

gpioError_t GPIOPortInit(gpioPort_t* portObj)
{
    gpioError_t result = GPIO_STATE_SUCCESS;

    if (portObj->base == PORTA || portObj->base == PORTB
            || portObj->base == PORTC || portObj->base == PORTD
            || portObj->base == PORTE || portObj->base == PORTF)
    {
        gpio_port_set_clk(portObj->base, ON);
        if(portObj->lock == ON)
        {
            gpio_port_unlock(portObj->base, GPIO_UNLOCK_KEY);
        }
        result = gpio_port_set_mode(portObj->base, portObj->mode);
        if (result == GPIO_STATE_SUCCESS)
        {
            result = gpio_port_set_dir(portObj->base, portObj->dir);
            if (result == GPIO_STATE_SUCCESS)
            {
                result = gpio_port_set_curr(portObj->base, portObj->curr);
            }
        }
    }
    else
    {
        result = GPIO_STATE_PORT_ERROR;
    }

    return result;
}

gpioError_t GPIOPinWrite(gpioPin_t* pinObj, bit_t val)
{
    gpioError_t result = GPIO_STATE_SUCCESS;

    if(pinObj->base == PORTA || pinObj->base == PORTB
            || pinObj->base == PORTC || pinObj->base == PORTD
            || pinObj->base == PORTE || pinObj->base == PORTF)
    {
        if(pinObj->pinNum < 8)
        {
            if(pinObj->mode == GPIO_MODE_DIGITAL)
            {
                if(pinObj->dir == GPIO_DIR_OUTPUT
                    || pinObj->dir == GPIO_DIR_OUTPUT_OPENDRAIN
                    || pinObj->dir == GPIO_DIR_OUTPUT_OPENDRAIN_PULLUP)
                {
                    if(pinObj->altFunc == 0)
                    {
                        result = gpio_pin_write(pinObj->base, pinObj->pinNum, val);
                    }
                    else
                    {
                        result = GPIO_STATE_FUNC_ERROR;
                    }
                }
                else
                {
                    result = GPIO_STATE_DIR_ERROR;
                }
            }
            else
            {
                result = GPIO_STATE_MODE_ERROR;
            }
        }
        else
        {
            result = GPIO_STATE_PIN_ERROR;
        }
    }
    else
    {
        result = GPIO_STATE_PORT_ERROR;
    }

    return result;
}

gpioError_t GPIOPortWrite(gpioPort_t* portObj, uint8_t val)
{
    gpioError_t result = GPIO_STATE_SUCCESS;

    if (portObj->base == PORTA || portObj->base == PORTB
            || portObj->base == PORTC || portObj->base == PORTD
            || portObj->base == PORTE || portObj->base == PORTF)
    {
        if (portObj->mode == GPIO_MODE_DIGITAL)
        {
            if (portObj->dir == GPIO_DIR_OUTPUT
                    || portObj->dir == GPIO_DIR_OUTPUT_OPENDRAIN
                    || portObj->dir == GPIO_DIR_OUTPUT_OPENDRAIN_PULLUP)
            {
                    result = gpio_port_write(portObj->base, val);
            }
            else
            {
                result = GPIO_STATE_DIR_ERROR;
            }
        }
        else
        {
            result = GPIO_STATE_MODE_ERROR;
        }
    }
    else
    {
        result = GPIO_STATE_PORT_ERROR;
    }

    return result;
}

gpioError_t GPIOPinRead(gpioPin_t* pinObj, bit_t* dest)
{
    gpioError_t result = GPIO_STATE_SUCCESS;

    if(pinObj->base == PORTA || pinObj->base == PORTB
            || pinObj->base == PORTC || pinObj->base == PORTD
            || pinObj->base == PORTE || pinObj->base == PORTF)
    {
        if(pinObj->pinNum < 8)
        {
            if (pinObj->mode == GPIO_MODE_DIGITAL)
            {
                if (pinObj->altFunc == 0)
                {
                    result = gpio_pin_read(pinObj->base, pinObj->pinNum, dest);
                }
                else
                {
                    result = GPIO_STATE_FUNC_ERROR;
                }
            }
            else
            {
                result = GPIO_STATE_MODE_ERROR;
            }
        }
        else
        {
            result = GPIO_STATE_PIN_ERROR;
        }
    }
    else
    {
        result = GPIO_STATE_PORT_ERROR;
    }

    return result;
}

gpioError_t GPIOPortRead(gpioPort_t* portObj, uint8_t* dest)
{
    gpioError_t result = GPIO_STATE_SUCCESS;

    if (portObj->base == PORTA || portObj->base == PORTB
            || portObj->base == PORTC || portObj->base == PORTD
            || portObj->base == PORTE || portObj->base == PORTF)
    {
        if (portObj->mode == GPIO_MODE_DIGITAL)
        {
            result = gpio_port_read(portObj->base, dest);
        }
        else
        {
            result = GPIO_STATE_MODE_ERROR;
        }
    }
    else
    {
        result = GPIO_STATE_PORT_ERROR;
    }

    return result;
}

#endif
