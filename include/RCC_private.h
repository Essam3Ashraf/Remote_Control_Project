#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

#define ZERO 0

//RCC Base Address Definition
 #define  RCC_BASE_ADDRESS   0x40023800

                 /***RCC Registers Definitions***/

#define   RCC_CR          *((volatile u32 *) (RCC_BASE_ADDRESS+0x00))
#define   RCC_PLLCFGR     *((volatile u32 *) (RCC_BASE_ADDRESS+0x04))
#define   RCC_CFGR        *((volatile u32 *) (RCC_BASE_ADDRESS+0x08))
#define   RCC_CIR         *((volatile u32 *) (RCC_BASE_ADDRESS+0x0C))
#define   RCC_AHB1RSTR    *((volatile u32 *) (RCC_BASE_ADDRESS+0x10))
#define   RCC_AHB2RSTR    *((volatile u32 *) (RCC_BASE_ADDRESS+0x14))
#define   RCC_APB1RSTR    *((volatile u32 *) (RCC_BASE_ADDRESS+0x20))
#define   RCC_APB2RSTR    *((volatile u32 *) (RCC_BASE_ADDRESS+0x24))
#define   RCC_AHB1ENR     *((volatile u32 *) (RCC_BASE_ADDRESS+0x30))
#define   RCC_AHB2ENR     *((volatile u32 *) (RCC_BASE_ADDRESS+0x34))
#define   RCC_APB1ENR     *((volatile u32 *) (RCC_BASE_ADDRESS+0x40))
#define   RCC_APB2ENR     *((volatile u32 *) (RCC_BASE_ADDRESS+0x44))
#define   RCC_AHB1LPENR   *((volatile u32 *) (RCC_BASE_ADDRESS+0x50))
#define   RCC_AHB2LPENR   *((volatile u32 *) (RCC_BASE_ADDRESS+0x54))
#define   RCC_APB1LPENR   *((volatile u32 *) (RCC_BASE_ADDRESS+0x60))
#define   RCC_APB2LPENR   *((volatile u32 *) (RCC_BASE_ADDRESS+0x64))
#define   RCC_BDCR        *((volatile u32 *) (RCC_BASE_ADDRESS+0x70))
#define   RCC_CSR         *((volatile u32 *) (RCC_BASE_ADDRESS+0x74))
#define   RCC_SSCGR       *((volatile u32 *) (RCC_BASE_ADDRESS+0x80))
#define   RCC_PLLI2SCFGR  *((volatile u32 *) (RCC_BASE_ADDRESS+0x84))
#define   RCC_DCKCFGR     *((volatile u32 *) (RCC_BASE_ADDRESS+0x8C))


               /***RCC Clock Source Definitions***/

  #define  RCC_HSI  0
  #define  RCC_HSE  1
  #define  RCC_PLL  2


               /***RCC System Clock Switch Definitions***/

  #define  RCC_HSI_INPUT_TO_SYSTEM  0b00
  #define  RCC_HSE_INPUT_TO_SYSTEM  0b01
  #define  RCC_PLL_INPUT_TO_SYSTEM  0b10

// RCC CLOCK SWITCH Mask
 #define RCC_CLOCK_SWITCH_MASK  0b11


                      /***PLLP  Division Factor***/

  #define  PLLP_DIV_2  0b00
  #define  PLLP_DIV_4  0b01
  #define  PLLP_DIV_6  0b10
  #define  PLLP_DIV_8  0b11


                         /***RCC_AHB Prescaler***/

  #define   RCC_AHB_DIV_1     0b0000
  #define   RCC_AHB_DIV_2     0b1000
  #define   RCC_AHB_DIV_4     0b1001
  #define   RCC_AHB_DIV_8     0b1010
  #define   RCC_AHB_DIV_16    0b1011
  #define   RCC_AHB_DIV_64    0b1100
  #define   RCC_AHB_DIV_128   0b1101
  #define   RCC_AHB_DIV_256   0b1110
  #define   RCC_AHB_DIV_512   0b1111

// RCC_AHB Prescaler Mask
 #define RCC_AHB_PRESCALER_MASK  0b1111


                         /***RCC_APB1 Prescaler***/

  #define   RCC_APB1_DIV_1     0b000
  #define   RCC_APB1_DIV_2     0b100
  #define   RCC_APB1_DIV_4     0b101
  #define   RCC_APB1_DIV_8     0b110
  #define   RCC_APB1_DIV_16    0b111

// RCC_APB1 Prescaler Mask
 #define RCC_APB1_PRESCALER_MASK  0b111


                         /***RCC_APB2 Prescaler***/

  #define   RCC_APB2_DIV_1     0b000
  #define   RCC_APB2_DIV_2     0b100
  #define   RCC_APB2_DIV_4     0b101
  #define   RCC_APB2_DIV_8     0b110
  #define   RCC_APB2_DIV_16    0b111

// RCC_APB2 Prescaler Mask
 #define RCC_APB2_PRESCALER_MASK  0b111


                        /***(RCC_CR) Register Bits***/

  #define  RCC_HSI_BIT                  0
  #define  RCC_HSI_READY_FLAG           1
  #define  RCC_HSI_TRIM_BIT_0           3
  #define  RCC_HSI_TRIM_BIT_1           4
  #define  RCC_HSI_TRIM_BIT_2           5
  #define  RCC_HSI_TRIM_BIT_3           6
  #define  RCC_HSI_TRIM_BIT_4           7
  #define  RCC_HSI_CALIBRATION_BIT_0    8
  #define  RCC_HSI_CALIBRATION_BIT_1    9
  #define  RCC_HSI_CALIBRATION_BIT_2    10
  #define  RCC_HSI_CALIBRATION_BIT_3    11
  #define  RCC_HSI_CALIBRATION_BIT_4    12
  #define  RCC_HSI_CALIBRATION_BIT_5    13
  #define  RCC_HSI_CALIBRATION_BIT_6    14
  #define  RCC_HSI_CALIBRATION_BIT_7    15
  #define  RCC_HSE_BIT                  16
  #define  RCC_HSE_READY_FLAG           17
  #define  RCC_HSE_BY_PASS_BIT          18
  #define  CLOCK_SECURITY_BIT           19
  #define  RCC_PLL_BIT                  24
  #define  RCC_PLL_READY_FLAG           25
  #define  RCC_PLLI2C_BIT               26
  #define  RCC_PLLI2C_READY_FLAG        27


                        /***(RCC_PLLCFGR) Register Bits***/

//////////////////////////////////////////////
  #define  RCC_PLLM_BIT_0                0
  #define  RCC_PLLM_BIT_1                1
  #define  RCC_PLLM_BIT_2                2    // Bits 0:5  Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock.
  #define  RCC_PLLM_BIT_3                3
  #define  RCC_PLLM_BIT_4                4
  #define  RCC_PLLM_BIT_5                5
//////////////////////////////////////////////
  #define  RCC_PLLN_BIT_0                6
  #define  RCC_PLLN_BIT_1                7
  #define  RCC_PLLN_BIT_2                8
  #define  RCC_PLLN_BIT_3                9 
  #define  RCC_PLLN_BIT_4                10   // Bits 6:14 PLLN: Main PLL (PLL) multiplication factor for VCO.
  #define  RCC_PLLN_BIT_5                11
  #define  RCC_PLLN_BIT_6                12
  #define  RCC_PLLN_BIT_7                13
  #define  RCC_PLLN_BIT_8                14
//////////////////////////////////////////////
  #define  RCC_PLLP_BIT_0                16   // Bits 16:17 PLLP: Main PLL (PLL) division factor for main system clock.
  #define  RCC_PLLP_BIT_1                17
//////////////////////////////////////////////
  #define  RCC_PLLSRC                    22   // Bit 22 PLLSRC: Main PLL(PLL) and audio PLL (PLLI2S) entry clock source.
//////////////////////////////////////////////
  #define  RCC_PLLQ_BIT_0                24
  #define  RCC_PLLQ_BIT_1                25   // Bits 24:27 PLLQ: Main PLL (PLL) division factor for USB OTG FS, SDIO and random number generator clocks.
  #define  RCC_PLLQ_BIT_2                26
  #define  RCC_PLLQ_BIT_3                27


                        /***(RCC_CFGR) Register Bits***/

  #define  RCC_SYSTEM_CLOCK_SWITCH_BIT_0        0
  #define  RCC_SYSTEM_CLOCK_SWITCH_BIT_1        1
  #define  RCC_SYSTEM_CLOCK_SWITCH_STATUS_0     2
  #define  RCC_SYSTEM_CLOCK_SWITCH_STATUS_1     3
  #define  RCC_AHB_PRESCALER_BIT_0              4
  #define  RCC_AHB_PRESCALER_BIT_1              5
  #define  RCC_AHB_PRESCALER_BIT_2              6
  #define  RCC_AHB_PRESCALER_BIT_3              7
  #define  RCC_APB1_PRESCALER_BIT_0             10
  #define  RCC_APB1_PRESCALER_BIT_1             11
  #define  RCC_APB1_PRESCALER_BIT_2             12
  #define  RCC_APB2_PRESCALER_BIT_0             13
  #define  RCC_APB2_PRESCALER_BIT_1             14
  #define  RCC_APB2_PRESCALER_BIT_2             15
  #define  RCC_HSE_DIV_FACTOR_RTC_CLOCK_BIT_0   16
  #define  RCC_HSE_DIV_FACTOR_RTC_CLOCK_BIT_1   17
  #define  RCC_HSE_DIV_FACTOR_RTC_CLOCK_BIT_2   18
  #define  RCC_HSE_DIV_FACTOR_RTC_CLOCK_BIT_3   19
  #define  RCC_HSE_DIV_FACTOR_RTC_CLOCK_BIT_4   20
  #define  RCC_MCO1_BIT_0                       21   
  #define  RCC_MCO1_BIT_1                       22   
  #define  RCC_I2S_CLOCK_SELECTION              23
  #define  RCC_MCO1_PRESCALER_BIT_0             24
  #define  RCC_MCO1_PRESCALER_BIT_1             25
  #define  RCC_MCO1_PRESCALER_BIT_2             26
  #define  RCC_MCO2_PRESCALER_BIT_0             27
  #define  RCC_MCO2_PRESCALER_BIT_1             28
  #define  RCC_MCO2_PRESCALER_BIT_2             29
  #define  RCC_MCO2_BIT_0                       30   
  #define  RCC_MCO2_BIT_1                       31 

#endif
