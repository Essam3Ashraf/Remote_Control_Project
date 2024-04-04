#ifndef RCC_config_H
#define RCC_config_H

// Select RCC Clock Source (RCC_CLOCK_SOURCE).
// There Are Three Options: [RCC_CLK_HSI, RCC_CLK_HSE, RCC_CLK_PLL].

  #define RCC_CLOCK_SOURCE  RCC_CLK_HSI   



// if RCC_CLOCK_SOURCE is RCC_CLK_PLL you need to select RCC_CLK_PLL_SRC.
// There Are Two Options: [RCC_CLK_HSI, RCC_CLK_HSE].

  #define RCC_CLK_PLL_SRC  RCC_CLK_HSI



// Select RCC AHB Prescaler.
/* There Are Nine Options: 
                [RCC_AHB_DIV_1,   RCC_AHB_DIV_2,   RCC_AHB_DIV_4
                 RCC_AHB_DIV_8,   RCC_AHB_DIV_16,  RCC_AHB_DIV_64
                 RCC_AHB_DIV_128, RCC_AHB_DIV_256, RCC_AHB_DIV_512]. */

  #define RCC_AHB_PRESCALER  RCC_AHB_DIV_2



// Select RCC APB1 Prescaler.
/* There Are Five Options: 
                [RCC_APB1_DIV_1,   RCC_APB1_DIV_2,   RCC_APB1_DIV_4
                 RCC_APB1_DIV_8,   RCC_APB1_DIV_16]. */

  #define RCC_APB1_PRESCALER  RCC_APB1_DIV_1



// Select RCC APB2 Prescaler.
/* There Are Five Options: 
                [RCC_APB2_DIV_1,   RCC_APB2_DIV_2,   RCC_APB2_DIV_4
                 RCC_APB2_DIV_8,   RCC_APB2_DIV_16]. */

  #define RCC_APB2_PRESCALER  RCC_APB2_DIV_1


// Select PLLN Value.
/* There Are MANY Options: PLLN>=2 && PLLN<=510  f(VCO clock) = f(PLL clock input) * (PLLN / PLLM) The software has to set these bits correctly to ensure that the VCO 
output frequency is between 192 and 432MHz. NOTE: 433 is wrong config*/

  #define PLLN_VALUE  2


// Select PLLM Value.
/* There Are MANY Options: PLLM>=2 && PLLM<=63  f(VCO clock) = f(PLL clock input) * (PLLN / PLLM)  The software has to set these bits correctly to ensure that the VCO 
input frequency ranges from 1 to 2MHz. It is recommended to select a frequency of 2MHz to limit PLL jitter.*/

  #define PLLM_VALUE  2


// Select PLLP Value.
/* There Are Four Options: [PLLP_DIV_2, PLLP_DIV_4, PLLP_DIV_6, PLLP_DIV_8] f(PLL general clock output) = f(VCO clock) / PLLP  The software has to set these bits correctly not to exceed 84MHz on this domain.*/

  #define PLLP_VALUE  PLLP_DIV_2


// Select PLLQ Value.
/* There Are MANY Options: PLLN>=2 && PLLN<=15 f(USB OTG FS, SDIO, RNG clock output) = f(VCO clock) / PLLQ  The USB OTG FS requires a 48 MHz clock to work correctly. 
The SDIO and the random number generator need a frequency lower than or equal to 48 MHz to work correctly.*/

  #define PLLQ_VALUE  2

#endif
