/***********************************************************************
* SSI Registers for ARM Microcontrollers SSI Driver                    *
* @author Ahmed Elzoughby                                              *
* @date July 26, 2017                                                  *
* Purpose: Provide an easy interface to deal with SSI                  *
***********************************************************************/


#ifndef REG_HW_SSI_H_
#define REG_HW_SSI_H_


/***********************************************************************
*                             Include Files                            *
***********************************************************************/

#include "../config.h"


/***********************************************************************
*                            Macros & Typedef                          *
***********************************************************************/

typedef enum {
    BASE_SSI0 = 0x40008000,
    BASE_SSI1 = 0x40009000,
    BASE_SSI2 = 0x4000A000,
    BASE_SSI3 = 0x4000B000,
} ssi_base_t;


/*      Name                   Offset    Type Reset       Description                     */
/*----------------------------------------------------------------------------------------*/
#define OFFSET_SSICR0        0x000   /* RW  0x00000000  SSI Control 0                   */
#define OFFSET_SSICR1        0x004   /* RW  0x00000000  SSI Control 1                   */
#define OFFSET_SSIDR         0x008   /* RW  0x00000000  SSI Data                        */
#define OFFSET_SSISR         0x00C   /* RO  0x00000090  SSI Status                      */
#define OFFSET_SSICPSR       0x010   /* RW  0x00000000  SSI Clock Prescale              */
#define OFFSET_SSIIM         0x014   /* RW  0x00000000  SSI Interrupt Mask              */
#define OFFSET_SSIRIS        0x018   /* RW  0x00000000  SSI Raw Interrupt Status        */
#define OFFSET_SSIMIS        0x01C   /* RW  0x00000000  SSI Masked Interrupt Status     */
#define OFFSET_SSIICR        0x020   /* RW  0x00000300  SSI Interrupt Clear             */
#define OFFSET_SSIDMACTL     0x024   /* RW  0x00000012  SSI DMA Contro                  */
#define OFFSET_SSICC         0xFC8   /* RW  0x00000000  SSI Clock Configuration         */


#endif /* REG_HW_SSI_H_ */
