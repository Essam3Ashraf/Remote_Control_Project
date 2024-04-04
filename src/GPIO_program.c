// Library Inclusion
# include "../include/STD_TYPES.h"
# include "../include/BIT_MATH.h"

// Lower Layer Inclusion

// Self Layer Inclusion

// Self Files Inclusion
# include "../include/GPIO_interface.h"
# include "../include/GPIO_private.h"
# include "../include/GPIO_config.h"


void MGPIO_voidSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode)
{
  if(Copy_u8Port>=PORTA && Copy_u8Port<=PORTC && Copy_u8Pin>=PIN0 && Copy_u8Pin<=PIN15 && (Copy_u8Mode==INPUT || Copy_u8Mode==OUTPUT || Copy_u8Mode==ALT_FUNC|| Copy_u8Mode==ANALOG))
  {
    if(Copy_u8Port == PORTA)
    {
       GPIOA_MODER &= ~ (PIN_MODE_MASK << (Copy_u8Pin*PIN_OFFSET));
       GPIOA_MODER |= (Copy_u8Mode << (Copy_u8Pin*PIN_OFFSET));
    }

    else if(Copy_u8Port == PORTB)
    {
       GPIOB_MODER &= ~ (PIN_MODE_MASK << (Copy_u8Pin*PIN_OFFSET));
       GPIOB_MODER |= (Copy_u8Mode << (Copy_u8Pin*PIN_OFFSET));
    }

    else if(Copy_u8Port == PORTC && Copy_u8Pin>=PIN13 && Copy_u8Pin<=PIN15)
    {
       GPIOC_MODER &= ~ (PIN_MODE_MASK << (Copy_u8Pin*PIN_OFFSET));
       GPIOC_MODER |= (Copy_u8Mode << (Copy_u8Pin*PIN_OFFSET));
    }    
  }

  else
  {
    // error
  }
}


void MGPIO_voidSetPinOutputMode(u8 Copy_u8Port, u8 Copy_u8OutputPin, u8 Copy_u8OutputMode)
{
  if(Copy_u8Port>=PORTA && Copy_u8Port<=PORTC && Copy_u8OutputPin>=PIN0 && Copy_u8OutputPin<=PIN15 && (Copy_u8OutputMode==PUSH_PULL || Copy_u8OutputMode==OPEN_DRAIN))
  {
    if(Copy_u8Port == PORTA)
    {
       CLR_BIT(GPIOA_OTYPER, Copy_u8OutputPin);
       GPIOA_OTYPER |= (Copy_u8OutputMode << Copy_u8OutputPin);
    }

    else if(Copy_u8Port == PORTB)
    {
       CLR_BIT(GPIOB_OTYPER, Copy_u8OutputPin);
       GPIOB_OTYPER |= (Copy_u8OutputMode << Copy_u8OutputPin);
    }
   
    else if(Copy_u8Port == PORTC && Copy_u8OutputPin>=PIN13 && Copy_u8OutputPin<=PIN15)
    {
       CLR_BIT(GPIOC_OTYPER, Copy_u8OutputPin);
       GPIOC_OTYPER |= (Copy_u8OutputMode << Copy_u8OutputPin);
    }
  }

  else
  {
    // error
  }
}


void MGPIO_voidSetPinOutputSpeed(u8 Copy_u8Port, u8 Copy_u8OutputPin, u8 Copy_u8Speed)
{
  if(Copy_u8Port>=PORTA && Copy_u8Port<=PORTC && Copy_u8OutputPin>=PIN0 && Copy_u8OutputPin<=PIN15 && (Copy_u8Speed==LOW_SPEED || Copy_u8Speed==MEDIUM_SPEED || Copy_u8Speed==HIGH_SPEED || Copy_u8Speed==VERY_HIGH_SPEED))
  {
    if(Copy_u8Port == PORTA)
    {
       GPIOA_OSPEEDR &= ~ (PIN_OUTPUT_SPEED_MASK << (Copy_u8OutputPin*PIN_OFFSET));
       GPIOA_OSPEEDR |= (Copy_u8Speed << (Copy_u8OutputPin*PIN_OFFSET));
    }

    else if(Copy_u8Port == PORTB)
    {
       GPIOB_OSPEEDR &= ~ (PIN_OUTPUT_SPEED_MASK << (Copy_u8OutputPin*PIN_OFFSET));
       GPIOB_OSPEEDR |= (Copy_u8Speed << (Copy_u8OutputPin*PIN_OFFSET));
    }

    else if(Copy_u8Port == PORTC && Copy_u8OutputPin>=PIN13 && Copy_u8OutputPin<=PIN15)
    {
       GPIOC_OSPEEDR &= ~ (PIN_OUTPUT_SPEED_MASK << (Copy_u8OutputPin*PIN_OFFSET));
       GPIOC_OSPEEDR |= (Copy_u8Speed << (Copy_u8OutputPin*PIN_OFFSET));
    }
  }

  else
  {
    // error
  }
}


void MGPIO_voidSetPinOutputValue(u8 Copy_u8Port, u8 Copy_u8OutputPin, u8 Copy_u8Value)
{
  if(Copy_u8Port>=PORTA && Copy_u8Port<=PORTC && Copy_u8OutputPin>=PIN0 && Copy_u8OutputPin<=PIN15 && (Copy_u8Value==LOW || Copy_u8Value==HIGH))
  {
    if(Copy_u8Port == PORTA)
    {
      if(Copy_u8Value == LOW)
      {
        GPIOA_BSRR = (ONE << (Copy_u8OutputPin + BIT16_LOCATION));
      }
      else
      {
        GPIOA_BSRR = (ONE << Copy_u8OutputPin);
      }
    }

    else if(Copy_u8Port == PORTB)
    {
      if(Copy_u8Value == LOW)
      {
        GPIOB_BSRR = (ONE << (Copy_u8OutputPin + BIT16_LOCATION));
      }
      else
      {
        GPIOB_BSRR = (ONE << Copy_u8OutputPin);
      }
    } 

    else if(Copy_u8Port == PORTC && Copy_u8OutputPin>=PIN13 && Copy_u8OutputPin<=PIN15)
    {
      if(Copy_u8Value == LOW)
      {
        GPIOC_BSRR = (ONE << (Copy_u8OutputPin + BIT16_LOCATION));
      }
      else
      {
        GPIOC_BSRR = (ONE << Copy_u8OutputPin);
      }
    }
  }

  else
  {
    // error
  }
}


void MGPIO_voidSetInputPinState(u8 Copy_u8Port, u8 Copy_u8InputPin, u8 Copy_u8State)
{
  if(Copy_u8Port>=PORTA && Copy_u8Port<=PORTC && Copy_u8InputPin>=PIN0 && Copy_u8InputPin<=PIN15 && (Copy_u8State==No_PULL_UP_PULL_DOWN || Copy_u8State==PULL_UP || Copy_u8State==PULL_DOWN))
  {
    if(Copy_u8Port == PORTA)
    {
       GPIOA_PUPDR &= ~ (INPUT_PIN_STATE_MASK << (Copy_u8InputPin*PIN_OFFSET));
       GPIOA_PUPDR |= (Copy_u8State << (Copy_u8InputPin*PIN_OFFSET));
    }

    else if(Copy_u8Port == PORTB)
    {
       GPIOB_PUPDR &= ~ (INPUT_PIN_STATE_MASK << (Copy_u8InputPin*PIN_OFFSET));
       GPIOB_PUPDR |= (Copy_u8State << (Copy_u8InputPin*PIN_OFFSET));
    }

    else if(Copy_u8Port == PORTC && Copy_u8InputPin>=PIN13 && Copy_u8InputPin<=PIN15)
    {
       GPIOC_PUPDR &= ~ (INPUT_PIN_STATE_MASK << (Copy_u8InputPin*PIN_OFFSET));
       GPIOC_PUPDR |= (Copy_u8State << (Copy_u8InputPin*PIN_OFFSET));
    }
  }

  else
  {
    // error    
  }
}


u8 MGPIO_u8GetInputPinValue(u8 Copy_u8Port, u8 Copy_u8InputPin)
{
  if(Copy_u8Port>=PORTA && Copy_u8Port<=PORTC && Copy_u8InputPin>=PIN0 && Copy_u8InputPin<=PIN15)
  {
    u8 LOC_u8PinValue;
    if(Copy_u8Port == PORTA)
    {
       LOC_u8PinValue = GET_BIT(GPIOA_IDR, Copy_u8InputPin);
    }

    else if(Copy_u8Port == PORTB)
    {
       LOC_u8PinValue = GET_BIT(GPIOB_IDR, Copy_u8InputPin);
    }

    else if(Copy_u8Port == PORTC && Copy_u8InputPin>=PIN13 && Copy_u8InputPin<=PIN15)
    {
       LOC_u8PinValue = GET_BIT(GPIOC_IDR, Copy_u8InputPin);
    }
    return LOC_u8PinValue;
  }

  else
  {
    // error
  }
}


void MGPIO_voidLockPin(u8 Copy_u8Port, u8 Copy_u8Pin)
{
  if(Copy_u8Port>=PORTA && Copy_u8Port<=PORTC && Copy_u8Pin>=PIN0 && Copy_u8Pin<=PIN15)
  {
    if(Copy_u8Port == PORTA)
    {
       GPIOA_LCKR |= ((ONE << BIT16_LOCATION) + (ONE << Copy_u8Pin));
       GPIOA_LCKR &= (ONE << Copy_u8Pin);
       GPIOA_LCKR |= ((ONE << BIT16_LOCATION) + (ONE << Copy_u8Pin));
    } 

    else if(Copy_u8Port == PORTB)
    {
       GPIOB_LCKR |= ((ONE << BIT16_LOCATION) + (ONE << Copy_u8Pin));
       GPIOB_LCKR &= (ONE << Copy_u8Pin);
       GPIOB_LCKR |= ((ONE << BIT16_LOCATION) + (ONE << Copy_u8Pin));      
    }

    else if(Copy_u8Port == PORTC && Copy_u8Pin>=PIN13 && Copy_u8Pin<=PIN15)
    {
       GPIOC_LCKR |= ((ONE << BIT16_LOCATION) + (ONE << Copy_u8Pin));
       GPIOC_LCKR &= (ONE << Copy_u8Pin);
       GPIOC_LCKR |= ((ONE << BIT16_LOCATION) + (ONE << Copy_u8Pin));   
    }
  }

  else
  {
    // error    
  }
}


void MGPIO_voidSetPortMode(u8 Copy_u8Port, u8 Copy_u8Mode)
{
  if(Copy_u8Port>=PORTA && Copy_u8Port<=PORTC && (Copy_u8Mode==INPUT || Copy_u8Mode==OUTPUT || Copy_u8Mode==ALT_FUNC || Copy_u8Mode==ANALOG))
  {
    if(Copy_u8Port == PORTA)
    {
       if(Copy_u8Mode == INPUT) {GPIOA_MODER &= INPUT_MODE;}
       else if(Copy_u8Mode == OUTPUT) {GPIOA_MODER &= ZERO; GPIOA_MODER |= OUTPUT_MODE;}
       else if(Copy_u8Mode == ALT_FUNC) {GPIOA_MODER &= ZERO; GPIOA_MODER |= ALT_FUNC_MODE;}
       else {GPIOA_MODER |= ANALOG_MODE;}
    }

    else if(Copy_u8Port == PORTB)
    {
       if(Copy_u8Mode == INPUT) {GPIOB_MODER &= INPUT_MODE;}
       else if(Copy_u8Mode == OUTPUT) {GPIOB_MODER &= ZERO; GPIOB_MODER |= OUTPUT_MODE;}
       else if(Copy_u8Mode == ALT_FUNC) {GPIOB_MODER &= ZERO; GPIOB_MODER |= ALT_FUNC_MODE;}
       else {GPIOB_MODER |= ANALOG_MODE;}
    }

    else
    {
       if(Copy_u8Mode == INPUT) {GPIOC_MODER &= INPUT_MODE;}
       else if(Copy_u8Mode == OUTPUT) {GPIOC_MODER &= ZERO; GPIOC_MODER |= OUTPUT_MODE;}
       else if(Copy_u8Mode == ALT_FUNC) {GPIOC_MODER &= ZERO; GPIOC_MODER |= ALT_FUNC_MODE;}
       else {GPIOC_MODER |= ANALOG_MODE;}
    }    
  }

  else
  {
    // error
  }
}


void MGPIO_voidSetPortOutputMode(u8 Copy_u8Port, u8 Copy_u8OutputMode)
{
  if(Copy_u8Port>=PORTA && Copy_u8Port<=PORTC && (Copy_u8OutputMode==PUSH_PULL || Copy_u8OutputMode==OPEN_DRAIN))
  {
    if(Copy_u8Port == PORTA)
    {
       if(Copy_u8OutputMode == PUSH_PULL) { GPIOA_OTYPER &= PUSH_PULL_MODE;}
       else {GPIOA_OTYPER |= OPEN_DRAIN_MODE;}
    } 

    else if(Copy_u8Port == PORTB)
    {
       if(Copy_u8OutputMode == PUSH_PULL) { GPIOB_OTYPER &= PUSH_PULL_MODE;}
       else {GPIOB_OTYPER |= OPEN_DRAIN_MODE;}     
    }

    else
    {
       if(Copy_u8OutputMode == PUSH_PULL) { GPIOC_OTYPER &= PUSH_PULL_MODE;}
       else {GPIOC_OTYPER |= OPEN_DRAIN_MODE;}     
    }
  }

  else
  {
    // error
  }
}


void MGPIO_voidSetPortOutputSpeed(u8 Copy_u8Port, u8 Copy_u8Speed)
{
  if(Copy_u8Port>=PORTA && Copy_u8Port<=PORTC && (Copy_u8Speed==LOW_SPEED || Copy_u8Speed==MEDIUM_SPEED || Copy_u8Speed==HIGH_SPEED || Copy_u8Speed==VERY_HIGH_SPEED))
  {
    if(Copy_u8Port == PORTA)
    {
       if(Copy_u8Speed == LOW_SPEED) {GPIOA_OSPEEDR &= LOW_SPD;}
       else if(Copy_u8Speed == MEDIUM_SPEED) {GPIOA_OSPEEDR &= ZERO; GPIOA_OSPEEDR |= MEDIUM_SPD;}
       else if(Copy_u8Speed == HIGH_SPEED) {GPIOA_OSPEEDR &= ZERO; GPIOA_OSPEEDR |= HIGH_SPD;}
       else {GPIOA_OSPEEDR |= VERY_HIGH_SPD;}
    }

    else if(Copy_u8Port == PORTB)
    {
       if(Copy_u8Speed == LOW_SPEED) {GPIOB_OSPEEDR &= LOW_SPD;}
       else if(Copy_u8Speed == MEDIUM_SPEED) {GPIOB_OSPEEDR &= ZERO; GPIOB_OSPEEDR |= MEDIUM_SPD;}
       else if(Copy_u8Speed == HIGH_SPEED) {GPIOB_OSPEEDR &= ZERO; GPIOB_OSPEEDR |= HIGH_SPD;}
       else {GPIOB_OSPEEDR |= VERY_HIGH_SPD;}
    }

    else
    {
       if(Copy_u8Speed == LOW_SPEED) {GPIOC_OSPEEDR &= LOW_SPD;}
       else if(Copy_u8Speed == MEDIUM_SPEED) {GPIOC_OSPEEDR &= ZERO; GPIOC_OSPEEDR |= MEDIUM_SPD;}
       else if(Copy_u8Speed == HIGH_SPEED) {GPIOC_OSPEEDR &= ZERO; GPIOC_OSPEEDR |= HIGH_SPD;}
       else {GPIOC_OSPEEDR |= VERY_HIGH_SPD;}
    }   
  }

  else
  {
    // error
  }
}


void MGPIO_voidSetPortOutputValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
  if(Copy_u8Port>=PORTA && Copy_u8Port<=PORTC && (Copy_u8Value==LOW || Copy_u8Value==HIGH))
  {
    if(Copy_u8Port == PORTA)
    {
      if(Copy_u8Value == LOW) {GPIOA_ODR &= LOW_VALUE;}
      else {GPIOA_ODR |= HIGH_VALUE;}
    }

    else if(Copy_u8Port == PORTB)
    {
      if(Copy_u8Value == LOW) {GPIOB_ODR &= LOW_VALUE;}
      else {GPIOB_ODR |= HIGH_VALUE;}
    }

    else
    {
      if(Copy_u8Value == LOW) {GPIOC_ODR &= LOW_VALUE;}
      else {GPIOC_ODR |= HIGH_VALUE;}
    }
  }

  else
  {
    // error
  }
}  


void MGPIO_voidSetInputPortState(u8 Copy_u8Port, u8 Copy_u8State)
{
  if(Copy_u8Port>=PORTA && Copy_u8Port<=PORTC && (Copy_u8State==No_PULL_UP_PULL_DOWN || Copy_u8State==PULL_UP || Copy_u8State==PULL_DOWN))
  {
    if(Copy_u8Port == PORTA)
    {
       if(Copy_u8State == No_PULL_UP_PULL_DOWN) {GPIOA_PUPDR &= No_PULL_UP_PULL_DOWN_STATE;}
       else if(Copy_u8State == PULL_UP) {GPIOA_PUPDR &= ZERO; GPIOA_PUPDR |= PULL_UP_STATE;}
       else {GPIOA_PUPDR &= ZERO; GPIOA_PUPDR |= PULL_DOWN_STATE;}
    }

    else if(Copy_u8Port == PORTB)
    {
       if(Copy_u8State == No_PULL_UP_PULL_DOWN) {GPIOB_PUPDR &= No_PULL_UP_PULL_DOWN_STATE;}
       else if(Copy_u8State == PULL_UP) {GPIOB_PUPDR &= ZERO; GPIOB_PUPDR |= PULL_UP_STATE;}
       else {GPIOB_PUPDR &= ZERO; GPIOB_PUPDR |= PULL_DOWN_STATE;}
    }

    else
    {
       if(Copy_u8State == No_PULL_UP_PULL_DOWN) {GPIOC_PUPDR &= No_PULL_UP_PULL_DOWN_STATE;}
       else if(Copy_u8State == PULL_UP) {GPIOC_PUPDR &= ZERO; GPIOC_PUPDR |= PULL_UP_STATE;}
       else {GPIOC_PUPDR &= ZERO; GPIOC_PUPDR |= PULL_DOWN_STATE;}
    }
  }

  else
  {
    // error    
  }
}


u8 MGPIO_u8GetInputPortValue(u8 Copy_u8Port)
{
  if(Copy_u8Port>=PORTA && Copy_u8Port<=PORTC)
  {
     u8 LOC_u8Flag = LOW;
     volatile u16 LOC_u16GpioIdrValue;

    if(Copy_u8Port == PORTA) 
    {
      LOC_u16GpioIdrValue = GPIOA_IDR;
      if(LOC_u16GpioIdrValue==HIGH_VALUE) {LOC_u8Flag = HIGH;}
    }

    else if(Copy_u8Port == PORTB)
    {
      LOC_u16GpioIdrValue = GPIOB_IDR;
      if(LOC_u16GpioIdrValue==HIGH_VALUE) {LOC_u8Flag = HIGH;}
    }

    else
    {
      LOC_u16GpioIdrValue = GPIOC_IDR;
      if(LOC_u16GpioIdrValue==HIGH_VALUE) {LOC_u8Flag = HIGH;}
    }

    return LOC_u8Flag;
  }

  else
  {
    // error
  }
}


void MGPIO_voidLockPort(u8 Copy_u8Port)
{
  if(Copy_u8Port>=PORTA && Copy_u8Port<=PORTC)
  {
    if(Copy_u8Port == PORTA)
    {
       GPIOA_LCKR |= ((ONE << BIT16_LOCATION) + HIGH_VALUE);
       GPIOA_LCKR &= HIGH_VALUE;
       GPIOA_LCKR |= ((ONE << BIT16_LOCATION) + HIGH_VALUE);
    } 

    else if(Copy_u8Port == PORTB)
    {
       GPIOB_LCKR |= ((ONE << BIT16_LOCATION) + HIGH_VALUE);
       GPIOB_LCKR &= HIGH_VALUE;
       GPIOB_LCKR |= ((ONE << BIT16_LOCATION) + HIGH_VALUE);      
    }

    else
    {
       GPIOC_LCKR |= ((ONE << BIT16_LOCATION) + HIGH_VALUE);
       GPIOC_LCKR &= HIGH_VALUE;
       GPIOC_LCKR |= ((ONE << BIT16_LOCATION) + HIGH_VALUE);   
    }
  }

  else
  {
    // error    
  }
}
