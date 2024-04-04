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

#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H

// Select EXTI STATE (EXTIx_STATE).
// There Are Two Options: [MEXTI_DISABLE, MEXTI_ENABLE].
#define   EXTI0_STATE   MEXTI_ENABLE
#define   EXTI1_STATE   MEXTI_DISABLE
#define   EXTI2_STATE   MEXTI_DISABLE
#define   EXTI3_STATE   MEXTI_DISABLE
#define   EXTI4_STATE   MEXTI_DISABLE
#define   EXTI5_STATE   MEXTI_DISABLE
#define   EXTI6_STATE   MEXTI_DISABLE
#define   EXTI7_STATE   MEXTI_DISABLE
#define   EXTI8_STATE   MEXTI_DISABLE
#define   EXTI9_STATE   MEXTI_DISABLE
#define   EXTI10_STATE  MEXTI_DISABLE
#define   EXTI11_STATE  MEXTI_DISABLE
#define   EXTI12_STATE  MEXTI_DISABLE
#define   EXTI13_STATE  MEXTI_DISABLE
#define   EXTI14_STATE  MEXTI_DISABLE
#define   EXTI15_STATE  MEXTI_DISABLE

// Select EXTI SenseMode (EXTIx_SNS_MODE).
// There Are Three Options: [MEXTI_RISING_MODE, MEXTI_FALLING_MODE, MEXTI_ONCHANGE_MODE].
#define   EXTI0_SNS_MODE    MEXTI_FALLING_MODE
#define   EXTI1_SNS_MODE    MEXTI_RISING_MODE
#define   EXTI2_SNS_MODE    MEXTI_RISING_MODE
#define   EXTI3_SNS_MODE    MEXTI_RISING_MODE
#define   EXTI4_SNS_MODE    MEXTI_RISING_MODE
#define   EXTI5_SNS_MODE    MEXTI_RISING_MODE
#define   EXTI6_SNS_MODE    MEXTI_RISING_MODE
#define   EXTI7_SNS_MODE    MEXTI_RISING_MODE
#define   EXTI8_SNS_MODE    MEXTI_RISING_MODE
#define   EXTI9_SNS_MODE    MEXTI_RISING_MODE
#define   EXTI10_SNS_MODE   MEXTI_RISING_MODE
#define   EXTI11_SNS_MODE   MEXTI_RISING_MODE
#define   EXTI12_SNS_MODE   MEXTI_RISING_MODE
#define   EXTI13_SNS_MODE   MEXTI_RISING_MODE
#define   EXTI14_SNS_MODE   MEXTI_RISING_MODE
#define   EXTI15_SNS_MODE   MEXTI_RISING_MODE

// Select EXTI Port (EXTIx_PORT).
// There Are Three Options: [EXTI_PORT_A, EXTI_PORT_B, EXTI_PORT_C].
#define    EXTI0_PORT     EXTI_PORT_A
#define    EXTI1_PORT     EXTI_PORT_A
#define    EXTI2_PORT     EXTI_PORT_A
#define    EXTI3_PORT     EXTI_PORT_A
#define    EXTI4_PORT     EXTI_PORT_A
#define    EXTI5_PORT     EXTI_PORT_A
#define    EXTI6_PORT     EXTI_PORT_A
#define    EXTI7_PORT     EXTI_PORT_A
#define    EXTI8_PORT     EXTI_PORT_A
#define    EXTI9_PORT     EXTI_PORT_A
#define    EXTI10_PORT    EXTI_PORT_B
#define    EXTI11_PORT    EXTI_PORT_B
#define    EXTI12_PORT    EXTI_PORT_B
#define    EXTI13_PORT    EXTI_PORT_C
#define    EXTI14_PORT    EXTI_PORT_C
#define    EXTI15_PORT    EXTI_PORT_C

#endif
