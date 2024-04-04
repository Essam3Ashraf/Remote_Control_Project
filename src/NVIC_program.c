// Library Inclusion
# include "../include/STD_TYPES.h"
# include "../include/BIT_MATH.h"

// Lower Layer Inclusion

// Self Layer Inclusion

// Self Files Inclusion
# include "../include/NVIC_interface.h"
# include "../include/NVIC_private.h"
# include "../include/NVIC_config.h"

void MNVIC_voidInit(void)
{
    #if (NVIC_GRP_SUB_DISTRIBUTION==GRP_4_SUB_0_BITS || NVIC_GRP_SUB_DISTRIBUTION==GRP_3_SUB_1_BITS || NVIC_GRP_SUB_DISTRIBUTION==GRP_2_SUB_2_BITS || NVIC_GRP_SUB_DISTRIBUTION==GRP_1_SUB_3_BITS || NVIC_GRP_SUB_DISTRIBUTION==GRP_0_SUB_4_BITS)
     SCB_AIRCR_REG |= ((AIRCR_PRIVKEY << VECTKEYSTAT_BIT_0)|(NVIC_GRP_SUB_DISTRIBUTION << PRIGROUP_BIT_0));
    #else
        #error "NVIC_GRP_SUB_DISTRIBUTION Configuration Error"
    #endif
}

void MNVIC_voidPeripheralInterruptControl(u8 Copy_u8PeripheralID, u8 Copy_u8InterruptState)
{
 if(Copy_u8PeripheralID <= LAST_PERIPHERAL_ID && (Copy_u8InterruptState == NVIC_ENABLE || Copy_u8InterruptState == NVIC_DISABLE))
 {
  u8 LOCAL_u8Index;
  u8 LOCAL_u8Count;
  LOCAL_u8Index = Copy_u8PeripheralID / THIRTY_TWO;
  LOCAL_u8Count = Copy_u8PeripheralID % THIRTY_TWO;
  if(Copy_u8InterruptState == NVIC_ENABLE)
  {
    NVIC -> NVIC_ISER[LOCAL_u8Index] = ONE << LOCAL_u8Count;
  }
  else
  {
    NVIC -> NVIC_ICER[LOCAL_u8Index] = ONE << LOCAL_u8Count;
  }
 }

 else
 {
   // error
 }
}

void MNVIC_voidPeripheralInterruptPendingFlagControl(u8 Copy_u8PeripheralID, u8 Copy_u8InterruptPendingFlagState)
{
 if(Copy_u8PeripheralID <= LAST_PERIPHERAL_ID && (Copy_u8InterruptPendingFlagState == NVIC_PENDING_FLAG_SET || Copy_u8InterruptPendingFlagState == NVIC_PENDING_FLAG_CLR))
 {
  u8 LOCAL_u8Index;
  u8 LOCAL_u8Count;
  LOCAL_u8Index = Copy_u8PeripheralID / THIRTY_TWO;
  LOCAL_u8Count = Copy_u8PeripheralID % THIRTY_TWO;
  if(Copy_u8InterruptPendingFlagState == NVIC_PENDING_FLAG_SET)
  {
    NVIC -> NVIC_ISPR[LOCAL_u8Index] = ONE << LOCAL_u8Count;
  }
  else
  {
    NVIC -> NVIC_ICPR[LOCAL_u8Index] = ONE << LOCAL_u8Count;
  }
 }

 else
 {
   // error
 }
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8PeripheralID)
{
 if(Copy_u8PeripheralID <= LAST_PERIPHERAL_ID)
 {
  u8 LOCAL_u8Index;
  u8 LOCAL_u8Count;
  LOCAL_u8Index = Copy_u8PeripheralID / THIRTY_TWO;
  LOCAL_u8Count = Copy_u8PeripheralID % THIRTY_TWO;
  return GET_BIT(NVIC -> NVIC_IABR[LOCAL_u8Index], LOCAL_u8Count);
 }

 else
 {
   // error
 }
}

void MNVIC_voidSetPeripheralPriority(u8 Copy_u8PeripheralID, u8 Copy_u8PeripheralPriority)
{
 if(Copy_u8PeripheralID <= LAST_PERIPHERAL_ID)
 {
  u8 LOCAL_u8Index;
  u8 LOCAL_u8Count;
  LOCAL_u8Index = Copy_u8PeripheralID / FOUR;
  LOCAL_u8Count = Copy_u8PeripheralID % FOUR;
  switch(LOCAL_u8Count)
  {
    case ZERO:
    LOCAL_u8Count = FOUR;
    break;
    case ONE:
    LOCAL_u8Count = TWELVE;
    break;
    case TWO:
    LOCAL_u8Count = TWENTY;
    break;
    case THREE:
    LOCAL_u8Count = TWENTY_EIGHT;
    break;
    default:
    // Error
    break;
  }
  NVIC -> NVIC_IPR[LOCAL_u8Index] &= ~(NVIC_PRI_MASK << LOCAL_u8Count);
  NVIC -> NVIC_IPR[LOCAL_u8Index] |= (Copy_u8PeripheralPriority << LOCAL_u8Count);
 }

 else
 {
   // error
 }
}