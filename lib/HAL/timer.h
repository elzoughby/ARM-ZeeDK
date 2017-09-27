/***********************************************************************
* Timer operations for ARM Microcontrollers GPIO Driver                *
* @author Ahmed Elzoughby                                              *
* @date August 8, 2017                                                 *
* Purpose: Provide an easy interface to deal with Timers               *
***********************************************************************/


#ifndef HAL_TIMER_H_
#define HAL_TIMER_H_


/***********************************************************************
*                             Include Files                            *
***********************************************************************/

#include "../types.h"
#include "../REG/hw_types.h"
#include "../REG/hw_sysctl.h"
#include "../REG/hw_timer.h"


/***********************************************************************
*                            Macros & Typedef                          *
***********************************************************************/

/* None */


/***********************************************************************
*                         Structures & Enums                           *
***********************************************************************/

typedef enum {
    TIMER_UNITA,
    TIMER_UNITB,
    TIMER_UNITAB
} timer_unit_t;

typedef enum {
    TIMER_MODE_ONE_SHOOT,
    TIMER_MODE_PERIODIC,
    TIMER_MODE_REALTIME_CLOCK,
    TIMER_MODE_INPUT_EDGE_COUNT,
    TIMER_MODE_INPUT_EDGE_TIME,
    TIMER_MODE_PWM
} timer_mode_t;

typedef enum {
    TIMER_DIR_DOWN,
    TIMER_DIR_UP
} timer_dir_t;

typedef enum {
    TIMER_STATE_SUCCESS,
    TIMER_STATE_BASE_ERROR,
    TIMER_STATE_UNIT_ERROR,
    TIMER_STATE_MODE_ERROR
} timer_error_t;


/***********************************************************************
*                   Global Variables Declarations                      *
***********************************************************************/

/* None */


/***********************************************************************
*                        Function Declarations                         *
***********************************************************************/

timer_error_t timer_set_clk(timer_base_t base, bit_t state);

timer_error_t timer_set_sleep_clk(timer_base_t base, bit_t state);

timer_error_t timer_set_deepsleep_clk(timer_base_t base, bit_t state);

timer_error_t timer_en(timer_base_t base, timer_unit_t unit);

timer_error_t timer_dis(timer_base_t base, timer_unit_t unit);

timer_error_t timer_reset_config(timer_base_t base, timer_unit_t unit);

timer_error_t timer_set_mode(timer_base_t base, timer_unit_t unit, timer_mode_t mode);

timer_error_t timer_get_mode(timer_base_t base, timer_unit_t unit, timer_mode_t* dest);

timer_error_t timer_set_snapshot_mode(timer_base_t base, timer_unit_t unit, bit_t state);

timer_error_t timer_get_snapshot_mode(timer_base_t base, timer_unit_t unit, bit_t* dest);

timer_error_t timer_set_wait_on_trigger(timer_base_t base, timer_unit_t unit, bit_t state);

timer_error_t timer_get_wait_on_trigger(timer_base_t base, timer_unit_t unit, bit_t* dest);

timer_error_t timer_set_match_intr(timer_base_t base, timer_unit_t unit, bit_t state);

timer_error_t timer_get_match_intr(timer_base_t base, timer_unit_t unit, bit_t* dest);

timer_error_t timer_set_count_dir(timer_base_t base, timer_unit_t unit, timer_dir_t dir);

timer_error_t timer_get_count_dir(timer_base_t base, timer_unit_t unit, timer_dir_t* dest);

timer_error_t timer_set_load_val(timer_base_t base, timer_unit_t unit, uint64_t val);

timer_error_t timer_get_load_val(timer_base_t base, timer_unit_t unit, uint64_t* dest);

timer_error_t timer_set_intr_mask(timer_base_t base, uint32_t mask);

timer_error_t timer_get_intr_mask(timer_base_t base, uint32_t* dest);

timer_error_t timer_get_raw_intr_status(timer_base_t base, uint32_t* dest);

timer_error_t timer_clear_intr(timer_base_t base, uint32_t mask);

#endif /* HAL_TIMER_H_ */
