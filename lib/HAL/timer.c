/***********************************************************************
* Timer operations for ARM Microcontrollers GPIO Driver                *
* @author Ahmed Elzoughby                                              *
* @date August 8, 2017                                                 *
* Purpose: Provide an easy interface to deal with Timers               *
***********************************************************************/



/***********************************************************************
*                             Include Files                            *
***********************************************************************/

#include "timer.h"


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

timer_error_t timer_set_clk(timer_base_t base, bit_t state)
{
    timer_error_t result = TIMER_STATE_SUCCESS;

    if (base == BASE_TIMER0)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_RCGCTIMER, 0, state);
    else if (base == BASE_TIMER1)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_RCGCTIMER, 1, state);
    else if (base == BASE_TIMER2)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_RCGCTIMER, 2, state);
    else if (base == BASE_TIMER3)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_RCGCTIMER, 3, state);
    else if (base == BASE_TIMER4)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_RCGCTIMER, 4, state);
    else if (base == BASE_TIMER5)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_RCGCTIMER, 5, state);
    else if (base == BASE_WTIMER0)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_RCGCWTIMER, 0, state);
    else if (base == BASE_WTIMER1)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_RCGCWTIMER, 1, state);
    else if (base == BASE_WTIMER2)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_RCGCWTIMER, 2, state);
    else if (base == BASE_WTIMER3)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_RCGCWTIMER, 3, state);
    else if (base == BASE_WTIMER4)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_RCGCWTIMER, 4, state);
    else if (base == BASE_WTIMER5)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_RCGCWTIMER, 5, state);
    else
        result = TIMER_STATE_BASE_ERROR;

    return result;
}

timer_error_t timer_set_sleep_clk(timer_base_t base, bit_t state)
{
    timer_error_t result = TIMER_STATE_SUCCESS;

    if (base == BASE_TIMER0)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_SCGCTIMER, 0, state);
    else if (base == BASE_TIMER1)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_SCGCTIMER, 1, state);
    else if (base == BASE_TIMER2)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_SCGCTIMER, 2, state);
    else if (base == BASE_TIMER3)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_SCGCTIMER, 3, state);
    else if (base == BASE_TIMER4)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_SCGCTIMER, 4, state);
    else if (base == BASE_TIMER5)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_SCGCTIMER, 5, state);
    else if (base == BASE_WTIMER0)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_SCGCWTIMER, 0, state);
    else if (base == BASE_WTIMER1)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_SCGCWTIMER, 1, state);
    else if (base == BASE_WTIMER2)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_SCGCWTIMER, 2, state);
    else if (base == BASE_WTIMER3)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_SCGCWTIMER, 3, state);
    else if (base == BASE_WTIMER4)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_SCGCWTIMER, 4, state);
    else if (base == BASE_WTIMER5)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_SCGCWTIMER, 5, state);
    else
        result = TIMER_STATE_BASE_ERROR;

    return result;
}

timer_error_t timer_set_deepsleep_clk(timer_base_t base, bit_t state)
{
    timer_error_t result = TIMER_STATE_SUCCESS;

    if (base == BASE_TIMER0)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_DCGCTIMER, 0, state);
    else if (base == BASE_TIMER1)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_DCGCTIMER, 1, state);
    else if (base == BASE_TIMER2)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_DCGCTIMER, 2, state);
    else if (base == BASE_TIMER3)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_DCGCTIMER, 3, state);
    else if (base == BASE_TIMER4)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_DCGCTIMER, 4, state);
    else if (base == BASE_TIMER5)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_DCGCTIMER, 5, state);
    else if (base == BASE_WTIMER0)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_DCGCWTIMER, 0, state);
    else if (base == BASE_WTIMER1)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_DCGCWTIMER, 1, state);
    else if (base == BASE_WTIMER2)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_DCGCWTIMER, 2, state);
    else if (base == BASE_WTIMER3)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_DCGCWTIMER, 3, state);
    else if (base == BASE_WTIMER4)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_DCGCWTIMER, 4, state);
    else if (base == BASE_WTIMER5)
        HW_REG32_BIT_WRITE(BASE_SYSCTL + OFFSET_DCGCWTIMER, 5, state);
    else
        result = TIMER_STATE_BASE_ERROR;

    return result;
}

timer_error_t timer_en(timer_base_t base, timer_unit_t unit)
{
    timer_error_t result = TIMER_STATE_SUCCESS;

    if (unit == TIMER_UNITAB)
    {
        HW_REG32_BIT_SET(base + OFFSET_GPTMCTL, BIT_TBEN);
        HW_REG32_BIT_SET(base + OFFSET_GPTMCTL, BIT_TAEN);
    }
    else if (unit == TIMER_UNITA)
    {
        HW_REG32_BIT_SET(base + OFFSET_GPTMCTL, BIT_TAEN);
    }
    else if (unit == TIMER_UNITB)
    {
        HW_REG32_BIT_SET(base + OFFSET_GPTMCTL, BIT_TBEN);
    }
    else
    {
        result = TIMER_STATE_UNIT_ERROR;
    }

    return result;
}

timer_error_t timer_dis(timer_base_t base, timer_unit_t unit)
{
    timer_error_t result = TIMER_STATE_SUCCESS;

    if (unit == TIMER_UNITAB)
    {
        HW_REG32_BIT_CLEAR(base + OFFSET_GPTMCTL, BIT_TBEN);
        HW_REG32_BIT_CLEAR(base + OFFSET_GPTMCTL, BIT_TAEN);
    }
    else if (unit == TIMER_UNITA)
    {
        HW_REG32_BIT_CLEAR(base + OFFSET_GPTMCTL, BIT_TAEN);
    }
    else if (unit == TIMER_UNITB)
    {
        HW_REG32_BIT_CLEAR(base + OFFSET_GPTMCTL, BIT_TBEN);
    }
    else
    {
        result = TIMER_STATE_UNIT_ERROR;
    }

    return result;
}

timer_error_t timer_reset_config(timer_base_t base, timer_unit_t unit)
{
    timer_error_t result = TIMER_STATE_SUCCESS;

    if (unit == TIMER_UNITAB)
    {
        HW_REG32_WRITE(base + OFFSET_GPTMCTL, 0x00000000);
        HW_REG32_WRITE(base + OFFSET_GPTMCFG, 0x00000000);
        HW_REG32_WRITE(base + OFFSET_GPTMTBMR, 0x00000000);
        HW_REG32_WRITE(base + OFFSET_GPTMTAMR, 0x00000000);
    }
    else if (unit == TIMER_UNITA)
    {
        HW_REG32_FIELD_MASKED_WRITE(base + OFFSET_GPTMCTL, 0x6F, 0, 0x00);
        HW_REG32_WRITE(base + OFFSET_GPTMCFG, 0x00000000);
        HW_REG32_WRITE(base + OFFSET_GPTMTAMR, 0x00000000);
    }
    else if (unit == TIMER_UNITB)
    {
        HW_REG32_FIELD_MASKED_WRITE(base + OFFSET_GPTMCTL, 0x6F, 8, 0x00);
        HW_REG32_WRITE(base + OFFSET_GPTMCFG, 0x00000000);
        HW_REG32_WRITE(base + OFFSET_GPTMTAMR, 0x00000000);
    }
    else
    {
        result = TIMER_STATE_UNIT_ERROR;
    }

    return result;
}

timer_error_t timer_set_mode(timer_base_t base, timer_unit_t unit, timer_mode_t mode)
{
    timer_error_t result = TIMER_STATE_SUCCESS;

    if (mode == TIMER_MODE_ONE_SHOOT)
    {
        if (unit == TIMER_UNITAB)
        {
            HW_REG32_WRITE(base + OFFSET_GPTMCFG, 0x0);
            HW_REG32_FIELD_WRITE(base + OFFSET_GPTMTAMR, 0, 1, 0x1);
        }
        else if (unit == TIMER_UNITA)
        {
            HW_REG32_WRITE(base + OFFSET_GPTMCFG, 0x4);
            HW_REG32_FIELD_WRITE(base + OFFSET_GPTMTAMR, 0, 1, 0x1);
        }
        else if (unit == TIMER_UNITB)
        {
            HW_REG32_WRITE(base + OFFSET_GPTMCFG, 0x4);
            HW_REG32_FIELD_WRITE(base + OFFSET_GPTMTBMR, 0, 1, 0x1);
        }
        else
        {
            result = TIMER_STATE_UNIT_ERROR;
        }
    }
    else if (mode ==  TIMER_MODE_PERIODIC)
    {
        if (unit == TIMER_UNITAB)
        {
            HW_REG32_WRITE(base + OFFSET_GPTMCFG, 0x0);
            HW_REG32_FIELD_WRITE(base + OFFSET_GPTMTAMR, 0, 1, 0x2);
        }
        else if (unit == TIMER_UNITA)
        {
            HW_REG32_WRITE(base + OFFSET_GPTMCFG, 0x4);
            HW_REG32_FIELD_WRITE(base + OFFSET_GPTMTAMR, 0, 1, 0x2);
        }
        else if (unit == TIMER_UNITB)
        {
            HW_REG32_WRITE(base + OFFSET_GPTMCFG, 0x4);
            HW_REG32_FIELD_WRITE(base + OFFSET_GPTMTBMR, 0, 1, 0x2);
        }
        else
        {
            result = TIMER_STATE_UNIT_ERROR;
        }
    }
    else if (mode == TIMER_MODE_REALTIME_CLOCK)
    {
        /* Not supported yet */
    }
    else if (mode == TIMER_MODE_INPUT_EDGE_TIME)
    {
        /* Not supported yet */
    }
    else if (mode == TIMER_MODE_INPUT_EDGE_COUNT)
    {
        /* Not supported yet */
    }
    else
    {
        result = TIMER_STATE_MODE_ERROR;
    }

    return result;
}

timer_error_t timer_get_mode(timer_base_t base, timer_unit_t unit, timer_mode_t* dest)
{
    timer_error_t result = TIMER_STATE_SUCCESS;

    /* Not supported yet */

    return result;
}

timer_error_t timer_set_snapshot_mode(timer_base_t base, timer_unit_t unit, bit_t state)
{
    timer_error_t result = TIMER_STATE_SUCCESS;

    if (unit == TIMER_UNITAB)
    {
        HW_REG32_BIT_WRITE(base + OFFSET_GPTMTAMR, 7, state);
    }
    else if (unit == TIMER_UNITA)
    {
        HW_REG32_BIT_WRITE(base + OFFSET_GPTMTAMR, 7, state);
    }
    else if (unit == TIMER_UNITB)
    {
        HW_REG32_BIT_WRITE(base + OFFSET_GPTMTBMR, 7, state);
    }
    else
    {
        result = TIMER_STATE_UNIT_ERROR;
    }

    return result;
}

timer_error_t timer_get_snapshot_mode(timer_base_t base, timer_unit_t unit, bit_t* dest)
{
    timer_error_t result = TIMER_STATE_SUCCESS;

    if (unit == TIMER_UNITAB)
    {
        *dest = HW_REG32_BIT_READ(base + OFFSET_GPTMTAMR, 7);
    }
    else if (unit == TIMER_UNITA)
    {
        *dest = HW_REG32_BIT_READ(base + OFFSET_GPTMTAMR, 7);
    }
    else if (unit == TIMER_UNITB)
    {
        *dest = HW_REG32_BIT_READ(base + OFFSET_GPTMTBMR, 7);
    }
    else
    {
        result = TIMER_STATE_UNIT_ERROR;
    }

    return result;
}

timer_error_t timer_set_wait_on_trigger(timer_base_t base, timer_unit_t unit, bit_t state)
{
    timer_error_t result = TIMER_STATE_SUCCESS;

    if (unit == TIMER_UNITAB)
    {
        HW_REG32_BIT_WRITE(base + OFFSET_GPTMTAMR, 6, state);
    }
    else if (unit == TIMER_UNITA)
    {
        HW_REG32_BIT_WRITE(base + OFFSET_GPTMTAMR, 6, state);
    }
    else if (unit == TIMER_UNITB)
    {
        HW_REG32_BIT_WRITE(base + OFFSET_GPTMTBMR, 6, state);
    }
    else
    {
        result = TIMER_STATE_UNIT_ERROR;
    }

    return result;
}

timer_error_t timer_get_wait_on_trigger(timer_base_t base, timer_unit_t unit, bit_t* dest)
{
    timer_error_t result = TIMER_STATE_SUCCESS;

    if (unit == TIMER_UNITAB)
    {
        *dest = HW_REG32_BIT_READ(base + OFFSET_GPTMTAMR, 6);
    }
    else if (unit == TIMER_UNITA)
    {
        *dest = HW_REG32_BIT_READ(base + OFFSET_GPTMTAMR, 6);
    }
    else if (unit == TIMER_UNITB)
    {
        *dest = HW_REG32_BIT_READ(base + OFFSET_GPTMTBMR, 6);
    }
    else
    {
        result = TIMER_STATE_UNIT_ERROR;
    }

    return result;
}

timer_error_t timer_set_match_intr(timer_base_t base, timer_unit_t unit, bit_t state)
{
    timer_error_t result = TIMER_STATE_SUCCESS;

    if (unit == TIMER_UNITAB)
    {
        HW_REG32_BIT_WRITE(base + OFFSET_GPTMTAMR, 5, state);
    }
    else if (unit == TIMER_UNITA)
    {
        HW_REG32_BIT_WRITE(base + OFFSET_GPTMTAMR, 5, state);
    }
    else if (unit == TIMER_UNITB)
    {
        HW_REG32_BIT_WRITE(base + OFFSET_GPTMTBMR, 5, state);
    }
    else
    {
        result = TIMER_STATE_UNIT_ERROR;
    }

    return result;
}

timer_error_t timer_get_match_intr(timer_base_t base, timer_unit_t unit, bit_t* dest)
{
    timer_error_t result = TIMER_STATE_SUCCESS;

    if (unit == TIMER_UNITAB)
    {
        *dest = HW_REG32_BIT_READ(base + OFFSET_GPTMTAMR, 5);
    }
    else if (unit == TIMER_UNITA)
    {
        *dest = HW_REG32_BIT_READ(base + OFFSET_GPTMTAMR, 5);
    }
    else if (unit == TIMER_UNITB)
    {
        *dest = HW_REG32_BIT_READ(base + OFFSET_GPTMTBMR, 5);
    }
    else
    {
        result = TIMER_STATE_UNIT_ERROR;
    }

    return result;
}

timer_error_t timer_set_count_dir(timer_base_t base, timer_unit_t unit, timer_dir_t dir)
{
    timer_error_t result = TIMER_STATE_SUCCESS;

    if (unit == TIMER_UNITAB)
    {
        HW_REG32_BIT_WRITE(base + OFFSET_GPTMTAMR, 4, dir? ONE:ZERO);
    }
    else if (unit == TIMER_UNITA)
    {
        HW_REG32_BIT_WRITE(base + OFFSET_GPTMTAMR, 4, dir? ONE:ZERO);
    }
    else if (unit == TIMER_UNITB)
    {
        HW_REG32_BIT_WRITE(base + OFFSET_GPTMTBMR, 4, dir? ONE:ZERO);
    }
    else
    {
        result = TIMER_STATE_UNIT_ERROR;
    }

    return result;
}

timer_error_t timer_get_count_dir(timer_base_t base, timer_unit_t unit, timer_dir_t* dest)
{
    timer_error_t result = TIMER_STATE_SUCCESS;

    if (unit == TIMER_UNITAB)
    {
        *dest = HW_REG32_BIT_READ(base + OFFSET_GPTMTAMR, 4)? TIMER_DIR_UP : TIMER_DIR_DOWN;
    }
    else if (unit == TIMER_UNITA)
    {
        *dest = HW_REG32_BIT_READ(base + OFFSET_GPTMTAMR, 4)? TIMER_DIR_UP : TIMER_DIR_DOWN;
    }
    else if (unit == TIMER_UNITB)
    {
        *dest = HW_REG32_BIT_READ(base + OFFSET_GPTMTBMR, 4)? TIMER_DIR_UP : TIMER_DIR_DOWN;
    }
    else
    {
        result = TIMER_STATE_UNIT_ERROR;
    }

    return result;
}

timer_error_t timer_set_load_val(timer_base_t base, timer_unit_t unit, uint64_t val)
{
    timer_error_t result = TIMER_STATE_SUCCESS;

    if (unit == TIMER_UNITAB)
    {
        HW_REG32_WRITE(base + OFFSET_GPTMTAILR, val);
        if (base == BASE_WTIMER0 || base == BASE_WTIMER1 || base == BASE_WTIMER2
                || base == BASE_WTIMER3 || base == BASE_WTIMER4
                || base == BASE_WTIMER5)
            HW_REG32_WRITE(base + OFFSET_GPTMTBILR, (val >> 32));
    }
    else if (unit == TIMER_UNITA)
    {
        HW_REG32_WRITE(base + OFFSET_GPTMTAILR, val);
    }
    else if (unit == TIMER_UNITB)
    {
        HW_REG32_WRITE(base + OFFSET_GPTMTBILR, val);
    }
    else
    {
        result = TIMER_STATE_UNIT_ERROR;
    }

    return result;
}

timer_error_t timer_get_load_val(timer_base_t base, timer_unit_t unit, uint64_t* dest)
{
    timer_error_t result = TIMER_STATE_SUCCESS;

    if (unit == TIMER_UNITAB)
    {
        *dest = HW_REG32_READ(base + OFFSET_GPTMTAILR);
        if (base == BASE_WTIMER0 || base == BASE_WTIMER1 || base == BASE_WTIMER2
                || base == BASE_WTIMER3 || base == BASE_WTIMER4
                || base == BASE_WTIMER5)
        {
            uint64_t tmp = HW_REG32_READ(base + OFFSET_GPTMTBILR);
            *dest += (tmp << 32);
        }
    }
    else if (unit == TIMER_UNITA)
    {
        *dest = HW_REG32_READ(base + OFFSET_GPTMTAILR);
    }
    else if (unit == TIMER_UNITB)
    {
        *dest = HW_REG32_READ(base + OFFSET_GPTMTBILR);
    }
    else
    {
        result = TIMER_STATE_UNIT_ERROR;
    }

    return result;
}

timer_error_t timer_set_intr_mask(timer_base_t base, uint32_t mask)
{
    timer_error_t result = TIMER_STATE_SUCCESS;

    HW_REG32_WRITE(base + OFFSET_GPTMIMR, mask);

    return result;
}

timer_error_t timer_get_intr_mask(timer_base_t base, uint32_t* dest)
{
    timer_error_t result = TIMER_STATE_SUCCESS;

    *dest = HW_REG32_READ(base + OFFSET_GPTMIMR);

    return result;
}

timer_error_t timer_get_raw_intr_status(timer_base_t base, uint32_t* dest)
{
    timer_error_t result = TIMER_STATE_SUCCESS;

    *dest = HW_REG32_READ(base + OFFSET_GPTMRIS);

    return result;
}

timer_error_t timer_clear_intr(timer_base_t base, uint32_t mask)
{
    timer_error_t result = TIMER_STATE_SUCCESS;

    HW_REG32_WRITE(base + OFFSET_GPTMICR, mask);

    return result;
}

