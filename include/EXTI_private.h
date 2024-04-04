/*********************************************
 * Author:				Essam A. Elhamalawy
 * Creation Data:		29 Mar, 2024
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  29 Mar, 2024	Essam A. Elhamalawy		  Initial Creation
*********************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

// 0x40013C00
typedef struct
{
    volatile u32 IMR;
    volatile u32 EMR;
    volatile u32 RTSR;
    volatile u32 FTSR;
    volatile u32 SWIER;
    volatile u32 PR;
}EXTI_t;

enum
{
    MEXTI_BIT0 = 0,
    MEXTI_BIT1,
    MEXTI_BIT2,
    MEXTI_BIT3,
    MEXTI_BIT4,
    MEXTI_BIT5,
    MEXTI_BIT6,
    MEXTI_BIT7,
    MEXTI_BIT8,
    MEXTI_BIT9,
    MEXTI_BIT10,
    MEXTI_BIT11,
    MEXTI_BIT12,
    MEXTI_BIT13,
    MEXTI_BIT14,
    MEXTI_BIT15
};

enum
{
    MEXTI0 = 0,
    MEXTI1,
    MEXTI2,
    MEXTI3,
    MEXTI4,
    MEXTI5,
    MEXTI6,
    MEXTI7,
    MEXTI8,
    MEXTI9,
    MEXTI10,
    MEXTI11,
    MEXTI12,
    MEXTI13,
    MEXTI14,
    MEXTI15
};

enum
{
    MEXTI_ARR_POINTERS_INDEX0 = 0,
    MEXTI_ARR_POINTERS_INDEX1,
    MEXTI_ARR_POINTERS_INDEX2,
    MEXTI_ARR_POINTERS_INDEX3,
    MEXTI_ARR_POINTERS_INDEX4,
    MEXTI_ARR_POINTERS_INDEX5,
    MEXTI_ARR_POINTERS_INDEX6,
    MEXTI_ARR_POINTERS_INDEX7,
    MEXTI_ARR_POINTERS_INDEX8,
    MEXTI_ARR_POINTERS_INDEX9,
    MEXTI_ARR_POINTERS_INDEX10,
    MEXTI_ARR_POINTERS_INDEX11,
    MEXTI_ARR_POINTERS_INDEX12,
    MEXTI_ARR_POINTERS_INDEX13,
    MEXTI_ARR_POINTERS_INDEX14,
    MEXTI_ARR_POINTERS_INDEX15
};

#ifndef ZERO
#define ZERO 0
#endif

#ifndef ONE
#define ONE 1
#endif

#ifndef SIXTEEN
#define SIXTEEN 16
#endif

#define MEXTI_ENABLE 1
#define MEXTI_DISABLE 0

#define  MEXTI_RISING_MODE   10
#define  MEXTI_FALLING_MODE  11
#define  MEXTI_ONCHANGE_MODE 12

#define  EXTI_PORT_A  0b0000
#define  EXTI_PORT_B  0b0001
#define  EXTI_PORT_C  0b0010

#define    EXTICR_MASK      0b1111
#define    EXTI_BIT_OFFSET   4

#define     EXTI                     ((volatile EXTI_t *)0x40013C00)
#define     SYSCFG_EXTICR1          *((volatile u32 *)(0x40013800+0x08))
#define     SYSCFG_EXTICR2          *((volatile u32 *)(0x40013800+0x0C))
#define     SYSCFG_EXTICR3          *((volatile u32 *)(0x40013800+0x10))
#define     SYSCFG_EXTICR4          *((volatile u32 *)(0x40013800+0x14))

#endif
