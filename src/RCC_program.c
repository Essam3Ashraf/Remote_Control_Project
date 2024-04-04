// Library Inclusion
# include "../include/STD_TYPES.h"
# include "../include/BIT_MATH.h"

// Lower Layer Inclusion

// Self Layer Inclusion

// Self Files Inclusion
# include "../include/RCC_interface.h"
# include "../include/RCC_private.h"
# include "../include/RCC_config.h"


            /***Pre-Build_Configuration***/

void MRCC_voidInit(void)
{
  #if RCC_CLOCK_SOURCE == RCC_CLK_HSI /* RCC Clock Source is HSI */
   SET_BIT(RCC_CR, RCC_HSI_BIT);     // Enable HSI
   CLR_BIT(RCC_CR, RCC_HSE_BIT);     // Disable HSE
   CLR_BIT(RCC_CR, RCC_PLL_BIT);     // Disable PLL

    // Busy-Wait Till HSI Is Ready
    while(GET_BIT(RCC_CR, RCC_HSI_READY_FLAG) == ZERO);

    // Select The HSI As Input Clock Source To The Processor
    RCC_CFGR &= ~ (RCC_CLOCK_SWITCH_MASK << RCC_SYSTEM_CLOCK_SWITCH_BIT_0);
    RCC_CFGR |= (RCC_HSI_INPUT_TO_SYSTEM << RCC_SYSTEM_CLOCK_SWITCH_BIT_0);

  #elif RCC_CLOCK_SOURCE == RCC_CLK_HSE /* RCC Clock Source is HSE */
   SET_BIT(RCC_CR, RCC_HSE_BIT);     // Enable HSE
   CLR_BIT(RCC_CR, RCC_HSI_BIT);     // Disable HSI
   CLR_BIT(RCC_CR, RCC_PLL_BIT);     // Disable PLL

    // Busy-Wait Till HSE Is Ready
    while(GET_BIT(RCC_CR, RCC_HSE_READY_FLAG) == ZERO);

    // Select The HSE As Input Clock Source To The Processor
    RCC_CFGR &= ~ (RCC_CLOCK_SWITCH_MASK << RCC_SYSTEM_CLOCK_SWITCH_BIT_0);
    RCC_CFGR |= (RCC_HSE_INPUT_TO_SYSTEM << RCC_SYSTEM_CLOCK_SWITCH_BIT_0);

  #elif RCC_CLOCK_SOURCE == RCC_CLK_PLL /* RCC Clock Source is PLL */
     RCC_PLLCFGR &= ZERO;
     RCC_PLLCFGR |= (PLLN_VALUE << RCC_PLLN_BIT_0);
     RCC_PLLCFGR |= PLLM_VALUE;
     RCC_PLLCFGR |= (PLLP_VALUE << RCC_PLLP_BIT_0);
     RCC_PLLCFGR |= (PLLQ_VALUE << RCC_PLLQ_BIT_0);

     #if RCC_CLK_PLL_SRC == RCC_CLK_HSI // PLL CLK SRC is HSI
      CLR_BIT(RCC_PLLCFGR, RCC_PLLSRC);

     #elif RCC_CLK_PLL_SRC == RCC_CLK_HSE // PLL CLK SRC is HSE
      SET_BIT(RCC_PLLCFGR, RCC_PLLSRC);

     #else
          #error "PLL_CLOCK_SOURCE Configuration Error"

     #endif

   SET_BIT(RCC_CR, RCC_PLL_BIT);     // Enable PLL
   CLR_BIT(RCC_CR, RCC_HSE_BIT);     // Disable HSE
   CLR_BIT(RCC_CR, RCC_HSI_BIT);     // Disable HSI

    // Busy-Wait Till PLL Is Ready
    while(GET_BIT(RCC_CR, RCC_PLL_READY_FLAG) == ZERO);

    // Select The PLL As Input Clock Source To The Processor
    RCC_CFGR &= ~ (RCC_CLOCK_SWITCH_MASK << RCC_SYSTEM_CLOCK_SWITCH_BIT_0);
    RCC_CFGR |= (RCC_PLL_INPUT_TO_SYSTEM << RCC_SYSTEM_CLOCK_SWITCH_BIT_0);

  #else
       #error "RCC_CLOCK_SOURCE Configuration Error"

  #endif

 // RCC_AHB Prescaler Settings.
  #if (RCC_AHB_PRESCALER == RCC_AHB_DIV_1 || RCC_AHB_PRESCALER == RCC_AHB_DIV_2 || RCC_AHB_PRESCALER == RCC_AHB_DIV_4 || RCC_AHB_PRESCALER == RCC_AHB_DIV_8 || RCC_AHB_PRESCALER == RCC_AHB_DIV_16 || RCC_AHB_PRESCALER == RCC_AHB_DIV_64 || RCC_AHB_PRESCALER == RCC_AHB_DIV_128 || RCC_AHB_PRESCALER == RCC_AHB_DIV_256 || RCC_AHB_PRESCALER == RCC_AHB_DIV_512)
   RCC_CFGR &= ~ (RCC_AHB_PRESCALER_MASK << RCC_AHB_PRESCALER_BIT_0);
   RCC_CFGR |= (RCC_AHB_PRESCALER << RCC_AHB_PRESCALER_BIT_0);
  
  #else
       #error "RCC_AHB_PRESCALER Configuration Error"

  #endif

// RCC_APB1 Prescaler Settings.
  #if (RCC_APB1_PRESCALER == RCC_APB1_DIV_1 || RCC_APB1_PRESCALER == RCC_APB1_DIV_2 || RCC_APB1_PRESCALER == RCC_APB1_DIV_4 || RCC_APB1_PRESCALER == RCC_APB1_DIV_8 || RCC_APB1_PRESCALER == RCC_APB1_DIV_16)
   RCC_CFGR &= ~ (RCC_APB1_PRESCALER_MASK << RCC_APB1_PRESCALER_BIT_0);
   RCC_CFGR |= (RCC_APB1_PRESCALER << RCC_APB1_PRESCALER_BIT_0);
  
  #else
       #error "RCC_APB1_PRESCALER Configuration Error"

  #endif

// RCC_APB2 Prescaler Settings.
  #if (RCC_APB2_PRESCALER == RCC_APB2_DIV_1 || RCC_APB2_PRESCALER == RCC_APB2_DIV_2 || RCC_APB2_PRESCALER == RCC_APB2_DIV_4 || RCC_APB2_PRESCALER == RCC_APB2_DIV_8 || RCC_APB2_PRESCALER == RCC_APB2_DIV_16)
   RCC_CFGR &= ~ (RCC_APB2_PRESCALER_MASK << RCC_APB2_PRESCALER_BIT_0);
   RCC_CFGR |= (RCC_APB2_PRESCALER << RCC_APB2_PRESCALER_BIT_0);
  
  #else
       #error "RCC_APB2_PRESCALER Configuration Error"

  #endif
}


            /***Post-Build_Configuration***/

void MRCC_voidEnableClockSource(u8 Copy_u8ClockSource)
{
    if(Copy_u8ClockSource == RCC_CLK_HSI)
    {
      SET_BIT(RCC_CR, RCC_HSI_BIT);     // Enable HSI
    }

    else if(Copy_u8ClockSource == RCC_CLK_HSE)
    {
      SET_BIT(RCC_CR, RCC_HSE_BIT);     // Enable HSE
    }

    else if(Copy_u8ClockSource == RCC_CLK_PLL)
    {
      SET_BIT(RCC_CR, RCC_PLL_BIT);     // Enable PLL
    }

    else
    {
       // error
    }
}


void MRCC_voidDisableClockSource(u8 Copy_u8ClockSource)
{
    if(Copy_u8ClockSource == RCC_CLK_HSI)
    {
       CLR_BIT(RCC_CR, RCC_HSI_BIT);
    }

    else if(Copy_u8ClockSource == RCC_CLK_HSE)
    {
       CLR_BIT(RCC_CR, RCC_HSE_BIT);
    }

    else if(Copy_u8ClockSource == RCC_CLK_PLL)
    {
       CLR_BIT(RCC_CR, RCC_PLL_BIT);
    }

    else
    {
       // error
    }
}


void MRCC_voidEnablePeripheralClock(u8 Copy_u8BusName, u8 Copy_u8PeripheralName)
{
    switch(Copy_u8BusName)
    {
      case RCC_AHB_BUS:
        SET_BIT(RCC_AHB1ENR, Copy_u8PeripheralName);
      break;

      case RCC_APB1_BUS:
        SET_BIT(RCC_APB1ENR, Copy_u8PeripheralName);
      break;

      case RCC_APB2_BUS:
        SET_BIT(RCC_APB2ENR, Copy_u8PeripheralName);
      break;

      default:
        // Error
    	 break;
    }
}


void MRCC_voidDisablePeripheralClock(u8 Copy_u8BusName, u8 Copy_u8PeripheralName)
{
    switch(Copy_u8BusName)
    {
      case RCC_AHB_BUS:
        CLR_BIT(RCC_AHB1ENR, Copy_u8PeripheralName);
      break;

      case RCC_APB1_BUS:
        CLR_BIT(RCC_APB1ENR, Copy_u8PeripheralName);
      break;

      case RCC_APB2_BUS:
        CLR_BIT(RCC_APB2ENR, Copy_u8PeripheralName);
      break;

      default:
        // Error
      break;
    }
}
