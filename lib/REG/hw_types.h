/***********************************************************************
* Low-Level Hardware Abstraction for ARM Microcontrollers GPIO Driver  *
* @author Ahmed Elzoughby                                              *
* @date July 26, 2017                                                  *
* Purpose: Provide an easy interface to deal with digital I/O devices  *
***********************************************************************/



#ifndef HW_TYPES_H_
#define HW_TYPES_H_


/***********************************************************************
*                             Include Files                            *
***********************************************************************/

#include "../types.h"


/***********************************************************************
*                            Macros & Typedef                          *
***********************************************************************/

#define HW_REG32_READ(reg_addr)                                                                 \
                hw_reg32_read(reg_addr)
#define HW_REG32_WRITE(reg_addr, val)                                                           \
                hw_reg32_write(reg_addr, val)
#define HW_REG32_MASKED_WRITE(reg_addr, mask, val)                                              \
                hw_reg32_masked_write(reg_addr, mask, val)
#define HW_REG32_BIT_READ(reg_addr, bit_num)                                                    \
                hw_reg32_bit_read(reg_addr, bit_num)
#define HW_REG32_BIT_SET(reg_addr, bit_num)                                                     \
                hw_reg32_bit_set(reg_addr, bit_num)
#define HW_REG32_BIT_CLEAR(reg_addr, bit_num)                                                   \
                hw_reg32_bit_clear(reg_addr, bit_num)
#define HW_REG32_BIT_WRITE(reg_addr, bit_num, val)                                              \
                hw_reg32_bit_write(reg_addr, bit_num, val)
#define HW_REG32_BIT_BANDED_WRITE(bitband_base, alias_base, reg_addr, bit_num, val)             \
                hw_reg32_banded_bit_write(bitband_base, alias_base, reg_addr, bit_num, val)
#define HW_REG32_FIELD_READ(reg_addr, start_bit, end_bit)                                       \
                hw_reg32_field_read(reg_addr, start_bit, end_bit)
#define HW_REG32_FIELD_WRITE(reg_addr, start_bit, end_bit, field_val)                           \
                hw_reg32_field_write(reg_addr, start_bit, end_bit, field_val)
#define HW_REG32_FIELD_MASKED_WRITE(reg_addr, field_mask, field_shift, field_val)               \
                hw_reg32_field_masked_write(reg_addr, field_mask, field_shift, field_val)

/* Define base address of bit-band */
#define BITBAND_SRAM_BASE                                                                       \
                0x20000000
/* Define base address of alias band */
#define ALIAS_SRAM_BASE                                                                         \
                0x22000000
/* Define base address of peripheral bit-band */
#define BITBAND_PERI_BASE                                                                       \
                0x40000000
/* Define base address of peripheral alias band */
#define ALIAS_PERI_BASE                                                                         \
                0x42000000
/* Convert register address to alias region address */
#define CALC_ALIAS_ADDR(bitband_base, alias_base, reg_addr, bit_num)                            \
                (alias_base + (reg_addr - bitband_base) * 32 + (bit_num * 4))

/* convert numeric address to register value */
#define REG_VALUE(address)                                                                      \
                (*((volatile uint32_t*) address))


/***********************************************************************
*                         Structures & Enums                           *
***********************************************************************/

/* None */


/***********************************************************************
*                   Global Variables Declarations                      *
***********************************************************************/

/* None */


/***********************************************************************
*                       Function Declarations                          *
***********************************************************************/

static inline uint32_t hw_reg32_read(uint32_t reg_addr);

static inline void hw_reg32_write(uint32_t reg_addr, uint32_t val);

static inline  void hw_reg32_masked_write(uint32_t reg_addr, uint32_t mask, uint32_t val);

static inline bit_t hw_reg32_bit_read(uint32_t reg_addr, uint8_t bit_num);

static inline void hw_reg32_bit_set(uint32_t reg_addr, uint8_t bit_num);

static inline void hw_reg32_bit_clear(uint32_t reg_addr, uint8_t bit_num);

/* alternative function */
static inline void hw_reg32_bit_write(uint32_t reg_addr, uint8_t bit_num, bit_t val);

static inline void hw_reg32_banded_bit_write(uint32_t bitband_base, uint32_t alias_base,
                                             uint32_t reg_addr, uint8_t bit_num, bit_t val);

static inline uint32_t hw_reg32_field_read(uint32_t reg_addr, uint8_t start_bit,
                                           uint8_t end_bit);

static inline void hw_reg32_field_write(uint32_t reg_addr, uint8_t start_bit,
                                        uint8_t end_bit, uint32_t field_val);

static inline void hw_reg32_field_masked_write(uint32_t reg_addr, uint32_t field_mask,
                                               uint8_t field_shift, uint32_t field_val);


/***********************************************************************
*                    Static Function Definitions                       *
***********************************************************************/

static inline uint32_t hw_reg32_read(uint32_t reg_addr) {
    return REG_VALUE(reg_addr);
}

static inline void hw_reg32_write(uint32_t reg_addr, uint32_t val) {
    REG_VALUE(reg_addr) = val;
}

static inline  void hw_reg32_masked_write(uint32_t reg_addr, uint32_t mask, uint32_t val) {
    REG_VALUE(reg_addr) = (REG_VALUE(reg_addr) & (~mask)) | (val & mask);
}

static inline bit_t hw_reg32_bit_read(uint32_t reg_addr, uint8_t bit_num) {
    return (REG_VALUE(reg_addr) & (1 << bit_num))? HIGH: LOW;
}

static inline void hw_reg32_bit_set(uint32_t reg_addr, uint8_t bit_num) {
    REG_VALUE(reg_addr) |= (1 << bit_num);
}

static inline void hw_reg32_bit_clear(uint32_t reg_addr, uint8_t bit_num) {
    REG_VALUE(reg_addr) &= ~(1 << bit_num);
}

/* alternative function */
static inline void hw_reg32_bit_write(uint32_t reg_addr, uint8_t bit_num, bit_t val) {
    REG_VALUE(reg_addr) = val? REG_VALUE(reg_addr) | (1 << bit_num) :
            REG_VALUE(reg_addr) & (~(1 << bit_num));
}

static inline void hw_reg32_banded_bit_write(uint32_t bitband_base,
                                             uint32_t alias_base, uint32_t reg_addr,
                                             uint8_t bit_num, bit_t val) {
    REG_VALUE(CALC_ALIAS_ADDR(bitband_base, alias_base, reg_addr, bit_num)) = val;
}

static inline uint32_t hw_reg32_field_read(uint32_t reg_addr, uint8_t start_bit,
                                           uint8_t end_bit) {
    return (((REG_VALUE(reg_addr) >> start_bit) << (31 - end_bit - start_bit))
            >> (31 - end_bit - start_bit));
}

static inline void hw_reg32_field_write(uint32_t reg_addr, uint8_t start_bit,
                                        uint8_t end_bit, uint32_t field_val) {
    REG_VALUE(reg_addr) &= (0xFFFFFFFF >> (32 - start_bit)) | (0xFFFFFFFF << (32 - (31 - end_bit)));
    REG_VALUE(reg_addr) ^= (field_val << start_bit);
}

static inline void hw_reg32_field_masked_write(uint32_t reg_addr, uint32_t field_mask,
                                        uint8_t field_shift, uint32_t field_val) {
    REG_VALUE(reg_addr) &= (~(field_mask << field_shift));
    REG_VALUE(reg_addr) |= (field_val & field_mask) << field_shift ;
}



#endif /* HW_TYPES_H_ */
