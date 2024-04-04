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

#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/EXTI_interface.h"
#include "../include/EXTI_private.h"
#include "../include/EXTI_config.h"

// Array Of Pointers to Function
static void (*EXTI_pNotificationFunction[SIXTEEN])(void) = {NULLPTR,NULLPTR,NULLPTR,NULLPTR,NULLPTR,NULLPTR,NULLPTR,NULLPTR,NULLPTR,NULLPTR,NULLPTR,NULLPTR,NULLPTR,NULLPTR,NULLPTR,NULLPTR};

const u8 EXTI_STATES_Array[SIXTEEN]={EXTI0_STATE,EXTI1_STATE,EXTI2_STATE,EXTI3_STATE,EXTI4_STATE,EXTI5_STATE,EXTI6_STATE,EXTI7_STATE,EXTI8_STATE,EXTI9_STATE,EXTI10_STATE,EXTI11_STATE,EXTI12_STATE,EXTI13_STATE,EXTI14_STATE,EXTI15_STATE};
const u8 EXTI_MODES_Array[SIXTEEN]={EXTI0_SNS_MODE,EXTI1_SNS_MODE,EXTI2_SNS_MODE,EXTI3_SNS_MODE,EXTI4_SNS_MODE,EXTI5_SNS_MODE,EXTI6_SNS_MODE,EXTI7_SNS_MODE,EXTI8_SNS_MODE,EXTI9_SNS_MODE,EXTI10_SNS_MODE,EXTI11_SNS_MODE,EXTI12_SNS_MODE,EXTI13_SNS_MODE,EXTI14_SNS_MODE,EXTI15_SNS_MODE};
const u8 EXTI_PORTS_Array[SIXTEEN]={EXTI0_PORT,EXTI1_PORT,EXTI2_PORT,EXTI3_PORT,EXTI4_PORT,EXTI5_PORT,EXTI6_PORT,EXTI7_PORT,EXTI8_PORT,EXTI9_PORT,EXTI10_PORT,EXTI11_PORT,EXTI12_PORT,EXTI13_PORT,EXTI14_PORT,EXTI15_PORT};

//Pre-build Controled by EXTI_Config.h
void MEXTI_voidInit(void)
{
    for(u8 Local_u8Counter0=ZERO; Local_u8Counter0<SIXTEEN; Local_u8Counter0++)
    {
       EXTI->IMR &= ~(ONE<<Local_u8Counter0);
       EXTI->IMR |= (EXTI_STATES_Array[Local_u8Counter0]<<Local_u8Counter0);
    } 

    for(u8 Local_u8Counter1=ZERO; Local_u8Counter1<SIXTEEN; Local_u8Counter1++)
    {
       if(EXTI_MODES_Array[Local_u8Counter1] == MEXTI_RISING_MODE)
       {
          CLR_BIT(EXTI->FTSR, Local_u8Counter1);
          SET_BIT(EXTI->RTSR, Local_u8Counter1);
       }

       else if(EXTI_MODES_Array[Local_u8Counter1] == MEXTI_FALLING_MODE)
       {
          CLR_BIT(EXTI->RTSR, Local_u8Counter1);
          SET_BIT(EXTI->FTSR, Local_u8Counter1);
       }

       else if(EXTI_MODES_Array[Local_u8Counter1] == MEXTI_ONCHANGE_MODE)
       {
            SET_BIT(EXTI->RTSR, Local_u8Counter1);
            SET_BIT(EXTI->FTSR, Local_u8Counter1);
       }
    }

    for(u8 Local_u8Counter2=ZERO; Local_u8Counter2<SIXTEEN; Local_u8Counter2++)
    {
       if(Local_u8Counter2==MEXTI0||Local_u8Counter2==MEXTI1||Local_u8Counter2==MEXTI2||Local_u8Counter2==MEXTI3)
       {
         SYSCFG_EXTICR1 &= ~(EXTICR_MASK<<(Local_u8Counter2*EXTI_BIT_OFFSET));
         SYSCFG_EXTICR1 |= (EXTI_PORTS_Array[Local_u8Counter2]<<(Local_u8Counter2*EXTI_BIT_OFFSET)); 
       }
       else if(Local_u8Counter2==MEXTI4||Local_u8Counter2==MEXTI5||Local_u8Counter2==MEXTI6||Local_u8Counter2==MEXTI7)
       {
         SYSCFG_EXTICR2 &= ~(EXTICR_MASK<<(Local_u8Counter2*EXTI_BIT_OFFSET));
         SYSCFG_EXTICR2 |= (EXTI_PORTS_Array[Local_u8Counter2]<<(Local_u8Counter2*EXTI_BIT_OFFSET)); 
       }
       else if(Local_u8Counter2==MEXTI8||Local_u8Counter2==MEXTI9||Local_u8Counter2==MEXTI10||Local_u8Counter2==MEXTI11)
       {
         SYSCFG_EXTICR3 &= ~(EXTICR_MASK<<(Local_u8Counter2*EXTI_BIT_OFFSET));
         SYSCFG_EXTICR3 |= (EXTI_PORTS_Array[Local_u8Counter2]<<(Local_u8Counter2*EXTI_BIT_OFFSET)); 
       }
       else if(Local_u8Counter2==MEXTI12||Local_u8Counter2==MEXTI13||Local_u8Counter2==MEXTI14||Local_u8Counter2==MEXTI15)
       {
         SYSCFG_EXTICR4 &= ~(EXTICR_MASK<<(Local_u8Counter2*EXTI_BIT_OFFSET));
         SYSCFG_EXTICR4 |= (EXTI_PORTS_Array[Local_u8Counter2]<<(Local_u8Counter2*EXTI_BIT_OFFSET)); 
       }
    }    
}

void MEXTI_voidEnableInterrupt(MEXTI_INTERRUPT_LINE_t Copy_tInterrupLine)
{
    SET_BIT(EXTI->IMR, Copy_tInterrupLine);
}

void MEXTI_voidDisableInterrupt(MEXTI_INTERRUPT_LINE_t Copy_tInterrupLine)
{
    CLR_BIT(EXTI->IMR, Copy_tInterrupLine);
}

void MEXTI_voidChangeSenseMode(MEXTI_INTERRUPT_LINE_t Copy_tInterrupLine, MEXTI_INTERRUPT_SENSE_SIGNAL_t Copy_tSenseSignal)
{
    switch(Copy_tSenseSignal)
    {
        case MEXTI_RISING:
            CLR_BIT(EXTI->FTSR, Copy_tInterrupLine);
            SET_BIT(EXTI->RTSR, Copy_tInterrupLine);
        break;

        case MEXTI_FALLING:
            CLR_BIT(EXTI->RTSR, Copy_tInterrupLine);
            SET_BIT(EXTI->FTSR, Copy_tInterrupLine);
        break;

        case MEXTI_ONCHANGE:
            SET_BIT(EXTI->RTSR, Copy_tInterrupLine);
            SET_BIT(EXTI->FTSR, Copy_tInterrupLine);
        break;

        default:
            // error
        break;
    }
}

void MEXTI_voidSetCallBack(MEXTI_INTERRUPT_LINE_t Copy_tInterrupLine, void (*pCallBackFunction)(void))
{
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;
}


void EXTI0_IRQHandler(void)
{
    
    if(EXTI_pNotificationFunction[MEXTI_ARR_POINTERS_INDEX0] != NULLPTR)
    {
        EXTI_pNotificationFunction[MEXTI_ARR_POINTERS_INDEX0]();
    }
    else
    {
        // Do Nothing
    }

    SET_BIT(EXTI->PR, MEXTI_BIT0);
}

void EXTI1_IRQHandler(void)
{
    if(EXTI_pNotificationFunction[MEXTI_ARR_POINTERS_INDEX1] != NULLPTR)
    {
        EXTI_pNotificationFunction[MEXTI_ARR_POINTERS_INDEX1]();
    }
    else
    {
        // Do Nothing
    }

    SET_BIT(EXTI->PR, MEXTI_BIT1);
}

void EXTI2_IRQHandler(void)
{
    if(EXTI_pNotificationFunction[MEXTI_ARR_POINTERS_INDEX2] != NULLPTR)
    {
         EXTI_pNotificationFunction[MEXTI_ARR_POINTERS_INDEX2]();
    }
    else
    {
        // Do Nothing
    }

    SET_BIT(EXTI->PR, MEXTI_BIT2);
}

void EXTI3_IRQHandler(void)
{
    if(EXTI_pNotificationFunction[MEXTI_ARR_POINTERS_INDEX3] != NULLPTR)
    {
         EXTI_pNotificationFunction[MEXTI_ARR_POINTERS_INDEX3]();
    }
    else
    {
        // Do Nothing
    }

    SET_BIT(EXTI->PR, MEXTI_BIT3);
}

void EXTI4_IRQHandler(void)
{
    if(EXTI_pNotificationFunction[MEXTI_ARR_POINTERS_INDEX4] != NULLPTR)
    {
         EXTI_pNotificationFunction[MEXTI_ARR_POINTERS_INDEX4]();
    }
    else
    {
        // Do Nothing
    }

    SET_BIT(EXTI->PR, MEXTI_BIT4);
}

void EXTI9_5_IRQHandler(void)
{
  
    if(GET_BIT(EXTI->PR, MEXTI_BIT5) == ONE) {EXTI_pNotificationFunction[MEXTI_ARR_POINTERS_INDEX5](); SET_BIT(EXTI->PR, MEXTI_BIT5);}
    else if(GET_BIT(EXTI->PR, MEXTI_BIT6) == ONE){EXTI_pNotificationFunction[MEXTI_ARR_POINTERS_INDEX6](); SET_BIT(EXTI->PR, MEXTI_BIT6);}
    else if(GET_BIT(EXTI->PR, MEXTI_BIT7) == ONE){EXTI_pNotificationFunction[MEXTI_ARR_POINTERS_INDEX7](); SET_BIT(EXTI->PR, MEXTI_BIT7);}
    else if(GET_BIT(EXTI->PR, MEXTI_BIT8) == ONE){EXTI_pNotificationFunction[MEXTI_ARR_POINTERS_INDEX8](); SET_BIT(EXTI->PR, MEXTI_BIT8);}
    else if(GET_BIT(EXTI->PR, MEXTI_BIT9) == ONE){EXTI_pNotificationFunction[MEXTI_ARR_POINTERS_INDEX9](); SET_BIT(EXTI->PR, MEXTI_BIT9);}
    else
    {
      // Do Nothing
    }
}

void EXTI15_10_IRQHandler(void)
{
    if(GET_BIT(EXTI->PR, MEXTI_BIT10) == ONE) {EXTI_pNotificationFunction[MEXTI_ARR_POINTERS_INDEX10](); SET_BIT(EXTI->PR, MEXTI_BIT10);}
    else if(GET_BIT(EXTI->PR, MEXTI_BIT11) == ONE){EXTI_pNotificationFunction[MEXTI_ARR_POINTERS_INDEX11](); SET_BIT(EXTI->PR, MEXTI_BIT11);}
    else if(GET_BIT(EXTI->PR, MEXTI_BIT12) == ONE){EXTI_pNotificationFunction[MEXTI_ARR_POINTERS_INDEX12](); SET_BIT(EXTI->PR, MEXTI_BIT12);}
    else if(GET_BIT(EXTI->PR, MEXTI_BIT13) == ONE){EXTI_pNotificationFunction[MEXTI_ARR_POINTERS_INDEX13](); SET_BIT(EXTI->PR, MEXTI_BIT13);}
    else if(GET_BIT(EXTI->PR, MEXTI_BIT14) == ONE){EXTI_pNotificationFunction[MEXTI_ARR_POINTERS_INDEX14](); SET_BIT(EXTI->PR, MEXTI_BIT14);}
    else if(GET_BIT(EXTI->PR, MEXTI_BIT15) == ONE){EXTI_pNotificationFunction[MEXTI_ARR_POINTERS_INDEX15](); SET_BIT(EXTI->PR, MEXTI_BIT15);}
    else
    {
      // Do Nothing
    }
}

void MEXTI_voidSelectEXTIPin(MEXTI_INTERRUPT_LINE_t Copy_tInterrupLine, u8 Copy_u8Port)
{
  if(Copy_tInterrupLine==MEXTI_EXTI0||Copy_tInterrupLine==MEXTI_EXTI1||Copy_tInterrupLine==MEXTI_EXTI2||Copy_tInterrupLine==MEXTI_EXTI3)
  {
    SYSCFG_EXTICR1 &= ~(EXTICR_MASK<<(Copy_tInterrupLine*EXTI_BIT_OFFSET));
    SYSCFG_EXTICR1 |= (Copy_u8Port<<(Copy_tInterrupLine*EXTI_BIT_OFFSET)); 
  }
  else if(Copy_tInterrupLine==MEXTI_EXTI4||Copy_tInterrupLine==MEXTI_EXTI5||Copy_tInterrupLine==MEXTI_EXTI6||Copy_tInterrupLine==MEXTI_EXTI7)
  {
    SYSCFG_EXTICR2 &= ~(EXTICR_MASK<<(Copy_tInterrupLine*EXTI_BIT_OFFSET));
    SYSCFG_EXTICR2 |= (Copy_u8Port<<(Copy_tInterrupLine*EXTI_BIT_OFFSET)); 
  }
  else if(Copy_tInterrupLine==MEXTI_EXTI8||Copy_tInterrupLine==MEXTI_EXTI9||Copy_tInterrupLine==MEXTI_EXTI10||Copy_tInterrupLine==MEXTI_EXTI11)
  {
    SYSCFG_EXTICR3 &= ~(EXTICR_MASK<<(Copy_tInterrupLine*EXTI_BIT_OFFSET));
    SYSCFG_EXTICR3 |= (Copy_u8Port<<(Copy_tInterrupLine*EXTI_BIT_OFFSET)); 
  }
  else if(Copy_tInterrupLine==MEXTI_EXTI12||Copy_tInterrupLine==MEXTI_EXTI13||Copy_tInterrupLine==MEXTI_EXTI14||Copy_tInterrupLine==MEXTI_EXTI15)
  {
    SYSCFG_EXTICR4 &= ~(EXTICR_MASK<<(Copy_tInterrupLine*EXTI_BIT_OFFSET));
    SYSCFG_EXTICR4 |= (Copy_u8Port<<(Copy_tInterrupLine*EXTI_BIT_OFFSET)); 
  }
  else
  {
    // error
  }
}
