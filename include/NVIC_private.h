#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

// NVIC-Registers
typedef struct
{
   volatile u32 NVIC_ISER[8];
   volatile u32 RESERVED_0[24];
   volatile u32 NVIC_ICER[8];
   volatile u32 RESERVED_1[24];
   volatile u32 NVIC_ISPR[8];
   volatile u32 RESERVED_2[24];
   volatile u32 NVIC_ICPR[8];
   volatile u32 RESERVED_3[24];
   volatile u32 NVIC_IABR[8];
   volatile u32 RESERVED_4[56];
   volatile u32 NVIC_IPR[60];
   volatile u32 RESERVED_5[580];
   volatile u32 NVIC_STIR;
}NVIC_t;

// NVIC-Registers Pointer
#define   NVIC   ((volatile NVIC_t *) 0xE000E100)

// AIRCR Definations.
#define  SCB_AIRCR_REG  *((volatile u32 *) 0xE000ED0C)
#define  AIRCR_PRIVKEY  0x05FA
#define  PRIGROUP_BIT_0  8
#define VECTKEYSTAT_BIT_0  16

// Group PR and Sub PR Distribution.
#define     GRP_4_SUB_0_BITS        0b000
#define     GRP_3_SUB_1_BITS        0b100
#define     GRP_2_SUB_2_BITS        0b101
#define     GRP_1_SUB_3_BITS        0b110
#define     GRP_0_SUB_4_BITS        0b111

// NVIC-Interrupt-Priority-Mask
#define  NVIC_PRI_MASK   0b1111

// Numbers
#ifndef ZERO
#define ZERO 0
#endif
#ifndef ONE
#define ONE 1
#endif
#ifndef TWO
#define TWO 2
#endif
#ifndef THREE
#define THREE 3
#endif
#ifndef FOUR
#define FOUR 4
#endif
#ifndef TWELVE
#define TWELVE 12
#endif
#ifndef TWENTY
#define TWENTY 20
#endif
#ifndef TWENTY_EIGHT
#define TWENTY_EIGHT 28
#endif
#ifndef THIRTY_TWO
#define THIRTY_TWO 32
#endif

// Last Peripheral ID
 #define LAST_PERIPHERAL_ID 239

#endif
