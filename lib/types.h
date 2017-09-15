/***********************************************************************
* Custom types for ARM Microcontrollers GPIO Driver                    *
* @author Ahmed Elzoughby                                              *
* @date July 26, 2017                                                  *
* Purpose: Provide an easy interface to deal with digital I/O devices  *
***********************************************************************/


#ifndef MCAL_RAL_TYPES_H_
#define MCAL_RAL_TYPES_H_


/***********************************************************************
*                             Include Files                            *
***********************************************************************/

#include <stdint.h>


/***********************************************************************
*                            Macros & Typedef                          *
***********************************************************************/

#define NULL (void *)0

typedef void(*fptr_t)(void);

typedef enum {
    LOW = 0, ZERO = 0, OFF = 0,
    HIGH = 1, ONE = 1, ON = 1
} bit_t;


#endif /* TYPES_H_ */
