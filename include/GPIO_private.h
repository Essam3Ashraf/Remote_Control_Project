#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


                 /*****GPIOA Registers Definitions*****/

// GPIOA Base Address Definition:
 #define  GPIOA_BASE_ADDRESS   0x40020000

// GPIOA Registers Definitions:
#define GPIOA_MODER          *((volatile u32 *) (GPIOA_BASE_ADDRESS+0X00))
#define GPIOA_OTYPER         *((volatile u32 *) (GPIOA_BASE_ADDRESS+0X04))
#define GPIOA_OSPEEDR        *((volatile u32 *) (GPIOA_BASE_ADDRESS+0X08))
#define GPIOA_PUPDR          *((volatile u32 *) (GPIOA_BASE_ADDRESS+0X0C))
#define GPIOA_IDR            *((volatile u32 *) (GPIOA_BASE_ADDRESS+0X10))
#define GPIOA_ODR            *((volatile u32 *) (GPIOA_BASE_ADDRESS+0X14))
#define GPIOA_BSRR           *((volatile u32 *) (GPIOA_BASE_ADDRESS+0X18))
#define GPIOA_LCKR           *((volatile u32 *) (GPIOA_BASE_ADDRESS+0X1C))



                 /*****GPIOB Registers Definitions*****/

// GPIOB Base Address Definition:
 #define  GPIOB_BASE_ADDRESS   0x40020400

// GPIOB Registers Definitions:
#define GPIOB_MODER          *((volatile u32 *) (GPIOB_BASE_ADDRESS+0X00))
#define GPIOB_OTYPER         *((volatile u32 *) (GPIOB_BASE_ADDRESS+0X04))
#define GPIOB_OSPEEDR        *((volatile u32 *) (GPIOB_BASE_ADDRESS+0X08))
#define GPIOB_PUPDR          *((volatile u32 *) (GPIOB_BASE_ADDRESS+0X0C))
#define GPIOB_IDR            *((volatile u32 *) (GPIOB_BASE_ADDRESS+0X10))
#define GPIOB_ODR            *((volatile u32 *) (GPIOB_BASE_ADDRESS+0X14))
#define GPIOB_BSRR           *((volatile u32 *) (GPIOB_BASE_ADDRESS+0X18))
#define GPIOB_LCKR           *((volatile u32 *) (GPIOB_BASE_ADDRESS+0X1C))



                 /*****GPIOC Registers Definitions*****/

// GPIOC Base Address Definition:
 #define  GPIOC_BASE_ADDRESS   0x40020800

// GPIOC Registers Definitions:
#define GPIOC_MODER          *((volatile u32 *) (GPIOC_BASE_ADDRESS+0X00))
#define GPIOC_OTYPER         *((volatile u32 *) (GPIOC_BASE_ADDRESS+0X04))
#define GPIOC_OSPEEDR        *((volatile u32 *) (GPIOC_BASE_ADDRESS+0X08))
#define GPIOC_PUPDR          *((volatile u32 *) (GPIOC_BASE_ADDRESS+0X0C))
#define GPIOC_IDR            *((volatile u32 *) (GPIOC_BASE_ADDRESS+0X10))
#define GPIOC_ODR            *((volatile u32 *) (GPIOC_BASE_ADDRESS+0X14))
#define GPIOC_BSRR           *((volatile u32 *) (GPIOC_BASE_ADDRESS+0X18))
#define GPIOC_LCKR           *((volatile u32 *) (GPIOC_BASE_ADDRESS+0X1C))


// BIT Number 16 Location
#define   BIT16_LOCATION   16

// Numbers
#ifndef  ZERO
#define  ZERO  0
#endif
#ifndef  ONE
#define  ONE  1
#endif
#ifndef  PIN_OFFSET
#define  PIN_OFFSET  2
#endif

// Masks
#define  PIN_MODE_MASK   0b11
#define  PIN_OUTPUT_SPEED_MASK  0b11
#define  INPUT_PIN_STATE_MASK   0b11

// PORTS MODES
#define  INPUT_MODE  0
#define  OUTPUT_MODE 0x55555555
#define  ALT_FUNC_MODE 0xAAAAAAAA
#define  ANALOG_MODE  0xFFFFFFFF

// OUTPUT PORTS MODES
#define  PUSH_PULL_MODE  0
#define  OPEN_DRAIN_MODE 0xFFFF

// OUTPUT PORTS SPEEDS 
#define  LOW_SPD        0
#define  MEDIUM_SPD     0x55555555
#define  HIGH_SPD       0xAAAAAAAA
#define  VERY_HIGH_SPD  0xFFFFFFFF

// OUTPUT PORTS VALUES 
#define  LOW_VALUE   0
#define  HIGH_VALUE  0xFFFF

// INPUT PORT STATES 
#define  No_PULL_UP_PULL_DOWN_STATE    0
#define  PULL_UP_STATE                 0x55555555
#define  PULL_DOWN_STATE               0xAAAAAAAA


#endif
