#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

// NVIC (Enable/Disable) Definations (Interrupt-State).
#define NVIC_ENABLE 1
#define NVIC_DISABLE 0

// NVIC-Pendind-Flag (Set/Clear) Definations (Interrupt-Pending-Flag-State).
#define NVIC_PENDING_FLAG_SET 1
#define NVIC_PENDING_FLAG_CLR 0

// NVIC Functions Prototypes.
void MNVIC_voidInit(void);
void MNVIC_voidPeripheralInterruptControl(u8 Copy_u8PeripheralID, u8 Copy_u8InterruptState);
void MNVIC_voidPeripheralInterruptPendingFlagControl(u8 Copy_u8PeripheralID, u8 Copy_u8InterruptPendingFlagState);
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8PeripheralID);
void MNVIC_voidSetPeripheralPriority(u8 Copy_u8PeripheralID, u8 Copy_u8PeripheralPriority);

#endif
