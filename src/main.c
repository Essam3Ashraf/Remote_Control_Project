
# include "../include/STD_TYPES.h"
# include "../include/BIT_MATH.h"

# include "../include/RCC_interface.h"
# include "../include/GPIO_interface.h"
# include "../include/NVIC_interface.h"
# include "../include/STK_interface.h"
# include "../include/EXTI_interface.h"

#define NO_START 0
#define START 1

void voidGetFrame(void);
void voidTakeAction(void);
void App_voidControlLED(void);
void HAL_voidSetAllLEDs(void);
void HAL_voidClearAllLEDs(void);

u8 Local_u8StartBitFlag = NO_START;
u32 u32ReceivedFrame[100];
u8 u8EdgeCounter = 0;
u8 u8ButtonData = 0;
u8 u8LEDsFlagsArray[8]={0, 0, 0, 0, 0, 0, 0, 0};

void main(void)
{
	MRCC_voidInit();
	MSTK_voidInit();
	MEXTI_voidInit();
	MNVIC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB_BUS, RCC_AHB_GPIOAEN);

	for(u8 Local_u8InitloopCounter=1; Local_u8InitloopCounter<12; Local_u8InitloopCounter++)
	{
	MGPIO_voidSetPinMode(PORTA, Local_u8InitloopCounter, OUTPUT);
	MGPIO_voidSetPinOutputMode(PORTA, Local_u8InitloopCounter, PUSH_PULL);
	MGPIO_voidSetPinOutputSpeed(PORTA, Local_u8InitloopCounter, LOW_SPEED);
    }

	/* important Note:
	 This because The GND Pin Was connected to Vcc 3.3 that mean to Turn On color Set his Pin LOW
	 And to Turn Off color Set his Pin HIGH.*/
	for(u8 Local_u8LEDloopCounter=1; Local_u8LEDloopCounter<4; Local_u8LEDloopCounter++)
	{
	  MGPIO_voidSetPinOutputValue(PORTA, Local_u8LEDloopCounter, HIGH);
	}

	// EXTI0 Pin (PA0)
	MGPIO_voidSetPinMode(PORTA, PIN0, INPUT);
	MGPIO_voidSetInputPinState(PORTA, PIN0, No_PULL_UP_PULL_DOWN);
    // ISR Function Call for EXTI0
	MEXTI_voidSetCallBack(MEXTI_EXTI0, voidGetFrame);
	MNVIC_voidPeripheralInterruptControl(6, NVIC_ENABLE);

  while(1)
  {

  }
}

void voidGetFrame(void)
{
  if(Local_u8StartBitFlag == NO_START)
  {
	  MSTK_voidSetPreloadValue(1000000);
	  MSTK_voidSetSingleInterval(voidTakeAction);
	  Local_u8StartBitFlag = START;
  }

  else
  {
	  u32ReceivedFrame[u8EdgeCounter] = MSTK_voidGetElapsedTime();
	  MSTK_voidResetTimer();
	  MSTK_voidSetPreloadValue(1000000);
	  u8EdgeCounter++;
  }
}

void voidTakeAction(void)
{
  u8 Local_u8Counter = 0;

  for(Local_u8Counter=0; Local_u8Counter<8; Local_u8Counter++)
  {
    if(u32ReceivedFrame[17+Local_u8Counter]>=1000 && u32ReceivedFrame[17+Local_u8Counter]<=1500)
    {
    	CLR_BIT(u8ButtonData, Local_u8Counter);
    }
    else
    {
    	SET_BIT(u8ButtonData, Local_u8Counter);
    }
  }

  u8EdgeCounter=0;
  Local_u8StartBitFlag = NO_START;
  MSTK_voidSTKEnable();
  App_voidControlLED();
}


void HAL_voidSetAllLEDs(void)
{
for(u8 Local_u8LEDloopCounter=4; Local_u8LEDloopCounter<12; Local_u8LEDloopCounter++)
  {
	MGPIO_voidSetPinOutputValue(PORTA, Local_u8LEDloopCounter, HIGH);
  }
}

void HAL_voidClearAllLEDs(void)
{
	for(u8 Local_u8LEDloopCounter=4; Local_u8LEDloopCounter<12; Local_u8LEDloopCounter++)
	  {
		MGPIO_voidSetPinOutputValue(PORTA, Local_u8LEDloopCounter, LOW);
	  }
}

void App_voidControlLED(void)
{
	if(u8ButtonData == 84 && u8LEDsFlagsArray[0] == 0) //  Button 1 To Red Color
	{
		MGPIO_voidSetPinOutputValue(PORTA, PIN1, LOW);
		u8LEDsFlagsArray[0]++;
	}

	else if(u8ButtonData == 84 && u8LEDsFlagsArray[0] == 1) //  Button 1 To Red Color
	{
		MGPIO_voidSetPinOutputValue(PORTA, PIN1, HIGH);
		u8LEDsFlagsArray[0]--;
	}

	else if(u8ButtonData == 22 && u8LEDsFlagsArray[1] == 0) //  Button 2 To Green Color
	{
		MGPIO_voidSetPinOutputValue(PORTA, PIN2, LOW);
		u8LEDsFlagsArray[1]++;
	}

	else if(u8ButtonData == 22 && u8LEDsFlagsArray[1] == 1) //  Button 2 To Green Color
	{
		MGPIO_voidSetPinOutputValue(PORTA, PIN2, HIGH);
		u8LEDsFlagsArray[1]--;
	}

	else if(u8ButtonData == 21 && u8LEDsFlagsArray[2] == 0) //  Button 3 To Blue Color
	{
		MGPIO_voidSetPinOutputValue(PORTA, PIN3, LOW);
		u8LEDsFlagsArray[2]++;
	}

	else if(u8ButtonData == 21 && u8LEDsFlagsArray[2] == 1) //  Button 3 To Blue Color
	{
		MGPIO_voidSetPinOutputValue(PORTA, PIN3, HIGH);
		u8LEDsFlagsArray[2]--;
	}

	else if(u8ButtonData == 80 && u8LEDsFlagsArray[3] == 0) //  Button 4 To 8 LEDs Animation_1
	{
		HAL_voidClearAllLEDs();
		for(u8 Local_u8LEDAnim1Counter=4; Local_u8LEDAnim1Counter<12; Local_u8LEDAnim1Counter+=2)
		{
		  MGPIO_voidSetPinOutputValue(PORTA, Local_u8LEDAnim1Counter, HIGH);
		}
		u8LEDsFlagsArray[3]++;
	}

	else if(u8ButtonData == 80 && u8LEDsFlagsArray[3] == 1) //  Button 4 To 8 LEDs Animation_1
	{
		HAL_voidClearAllLEDs();
		u8LEDsFlagsArray[3]--;
	}

	else if(u8ButtonData == 18 && u8LEDsFlagsArray[4] == 0) //  Button 5 To 8 LEDs Animation_2
	{
		HAL_voidClearAllLEDs();
		MGPIO_voidSetPinOutputValue(PORTA, PIN4, HIGH);
		MGPIO_voidSetPinOutputValue(PORTA, PIN5, HIGH);
		MGPIO_voidSetPinOutputValue(PORTA, PIN7, HIGH);
		MGPIO_voidSetPinOutputValue(PORTA, PIN8, HIGH);
		MGPIO_voidSetPinOutputValue(PORTA, PIN10, HIGH);
		MGPIO_voidSetPinOutputValue(PORTA, PIN11, HIGH);
		u8LEDsFlagsArray[4]++;
	}

	else if(u8ButtonData == 18 && u8LEDsFlagsArray[4] == 1) //  Button 5 To 8 LEDs Animation_2
	{
		HAL_voidClearAllLEDs();
		u8LEDsFlagsArray[4]--;
	}

	else if(u8ButtonData == 17 && u8LEDsFlagsArray[5] == 0) //  Button 6 To 8 LEDs Animation_3
	{
		HAL_voidClearAllLEDs();
		MGPIO_voidSetPinOutputValue(PORTA, PIN4, HIGH);
		MGPIO_voidSetPinOutputValue(PORTA, PIN5, HIGH);
		MGPIO_voidSetPinOutputValue(PORTA, PIN10, HIGH);
		MGPIO_voidSetPinOutputValue(PORTA, PIN11, HIGH);

		u8LEDsFlagsArray[5]++;
	}

	else if(u8ButtonData == 17 && u8LEDsFlagsArray[5] == 1) //  Button 6 To 8 LEDs Animation_3
	{
		HAL_voidClearAllLEDs();
		u8LEDsFlagsArray[5]--;
	}

	else if(u8ButtonData == 76 && u8LEDsFlagsArray[6] == 0) //  Button 7 To 8 LEDs Animation_4
	{
		HAL_voidClearAllLEDs();
		MGPIO_voidSetPinOutputValue(PORTA, PIN7, HIGH);
		MGPIO_voidSetPinOutputValue(PORTA, PIN8, HIGH);
		u8LEDsFlagsArray[6]++;
	}

	else if(u8ButtonData == 76 && u8LEDsFlagsArray[6] == 1) //  Button 7 To 8 LEDs Animation_4
	{
		HAL_voidClearAllLEDs();
		u8LEDsFlagsArray[6]--;
	}

	else if(u8ButtonData == 14 && u8LEDsFlagsArray[7] == 0) //  Button 8 To 8 LEDs Animation_5
	{
		HAL_voidClearAllLEDs();
		MGPIO_voidSetPinOutputValue(PORTA, PIN4, HIGH);
		MGPIO_voidSetPinOutputValue(PORTA, PIN7, HIGH);
		MGPIO_voidSetPinOutputValue(PORTA, PIN8, HIGH);
		MGPIO_voidSetPinOutputValue(PORTA, PIN11, HIGH);
		u8LEDsFlagsArray[7]++;
	}

	else if(u8ButtonData == 14 && u8LEDsFlagsArray[7] == 1) //  Button 8 To 8 LEDs Animation_5
	{
		HAL_voidClearAllLEDs();
		u8LEDsFlagsArray[7]--;
	}

	else if(u8ButtonData == 13 && u8LEDsFlagsArray[8] == 0) //  Button 9 To 8 LEDs Animation_6
	{
		HAL_voidClearAllLEDs();
		MGPIO_voidSetPinOutputValue(PORTA, PIN5, HIGH);
		MGPIO_voidSetPinOutputValue(PORTA, PIN6, HIGH);
		MGPIO_voidSetPinOutputValue(PORTA, PIN9, HIGH);
		MGPIO_voidSetPinOutputValue(PORTA, PIN10, HIGH);
		u8LEDsFlagsArray[8]++;
	}

	else if(u8ButtonData == 13 && u8LEDsFlagsArray[8] == 1) //  Button 9 To 8 LEDs Animation_6
	{
		HAL_voidClearAllLEDs();
		u8LEDsFlagsArray[8]--;
	}

	else if(u8ButtonData == 28 && u8LEDsFlagsArray[9] == 0) // Power Button To ON All 8 LEDs
	{
		HAL_voidSetAllLEDs();
		u8LEDsFlagsArray[9]++;
	}

	else if(u8ButtonData == 28 && u8LEDsFlagsArray[9] == 1) // Power Button To OFF All 8 LEDs
	{
		HAL_voidClearAllLEDs();
		u8LEDsFlagsArray[9]--;
	}
}

