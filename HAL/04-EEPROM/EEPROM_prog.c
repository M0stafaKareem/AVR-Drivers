#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/10-I2C/TWI_Interface.h"
#include "EEPROM_Interface.h"

void EEPROM_WriteByte(u8 Copy_u8DataByte, u8 Copy_u8BloclAddress) {
	TWI_enuSendStartCondition();
	TWI_enuMasterSendAddress(0b10100000, MasterWrite);
	TWI_enuMasterSendData(Copy_u8BloclAddress);
	TWI_enuMasterSendData(Copy_u8DataByte);
	TWI_enuSendStopCondition();
}

void EEPROM_ReadByte(u8 Copy_u8BloclAddress, u8* pu8ReceivedData) {
	TWI_enuSendStartCondition();
	TWI_enuMasterSendAddress(0b10100000, MasterWrite);
	TWI_enuMasterSendData(Copy_u8BloclAddress);

	TWI_enuSendRepeatedStart();
	TWI_enuMasterReceiveData(pu8ReceivedData);

	TWI_enuSendStopCondition();

}
