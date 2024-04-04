#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

// MC PORTS
#define  PORTA  100
#define  PORTB  101
#define  PORTC  102

// PINS
#define  PIN0   0
#define  PIN1   1
#define  PIN2   2
#define  PIN3   3
#define  PIN4   4
#define  PIN5   5
#define  PIN6   6
#define  PIN7   7
#define  PIN8   8
#define  PIN9   9
#define  PIN10  10
#define  PIN11  11
#define  PIN12  12
#define  PIN13  13
#define  PIN14  14
#define  PIN15  15

// MODES
#define  INPUT     0b00
#define  OUTPUT    0b01
#define  ALT_FUNC  0b10
#define  ANALOG    0b11

// OUTPUT MODES 
#define  PUSH_PULL   0
#define  OPEN_DRAIN  1

// OUTPUT SPEEDS 
#define  LOW_SPEED        0b00
#define  MEDIUM_SPEED     0b01
#define  HIGH_SPEED       0b10
#define  VERY_HIGH_SPEED  0b11

// OUTPUT VALUES 
#define  LOW   0
#define  HIGH  1

// INPUT STATES 
#define  No_PULL_UP_PULL_DOWN    0b00
#define  PULL_UP                 0b01
#define  PULL_DOWN               0b10

// Functions Prototypes for Pins
void MGPIO_voidSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pins, u8 Copy_u8Mode);      
void MGPIO_voidSetPinOutputMode(u8 Copy_u8Port, u8 Copy_u8OutputPin, u8 Copy_u8OutputMode);  
void MGPIO_voidSetPinOutputSpeed(u8 Copy_u8Port, u8 Copy_u8OutputPin, u8 Copy_u8Speed);   
void MGPIO_voidSetPinOutputValue(u8 Copy_u8Port, u8 Copy_u8OutputPin, u8 Copy_u8Value);  
void MGPIO_voidSetInputPinState(u8 Copy_u8Port, u8 Copy_u8InputPin, u8 Copy_u8State);   
u8 MGPIO_u8GetInputPinValue(u8 Copy_u8Port, u8 Copy_u8InputPin);   
void MGPIO_voidLockPin(u8 Copy_u8Port, u8 Copy_u8Pin); 

// Functions Prototypes for Ports
void MGPIO_voidSetPortMode(u8 Copy_u8Port, u8 Copy_u8Mode);
void MGPIO_voidSetPortOutputMode(u8 Copy_u8Port, u8 Copy_u8OutputMode);
void MGPIO_voidSetPortOutputSpeed(u8 Copy_u8Port, u8 Copy_u8Speed);
void MGPIO_voidSetPortOutputValue(u8 Copy_u8Port, u8 Copy_u8Value);
void MGPIO_voidSetInputPortState(u8 Copy_u8Port, u8 Copy_u8State);
u8 MGPIO_u8GetInputPortValue(u8 Copy_u8Port);
void MGPIO_voidLockPort(u8 Copy_u8Port);

#endif
