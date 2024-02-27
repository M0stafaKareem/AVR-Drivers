#ifndef TWI_INTERFACE_H
#define TWI_INTERFACE_H

typedef enum {
	NoError,
	StartACKError,
	RepeatedStartError,
	Starting_ConditionErr,
	Repeated_StartErr,
	Sent_dataErr,
	Received_dataErr,
	Sent_SLVaddressErr

}enu_ErorrStatus;

typedef enum{
	MasterWrite,
	MasterRead
}TWI_Operations;

void TWI_vidMasterInit(u32 Copy_u32Address);
void TWI_vidSlvInit(u8 Copy_u8Address);

enu_ErorrStatus TWI_enuSendStartCondition();
void TWI_enuSendStopCondition();
enu_ErorrStatus TWI_enuSendRepeatedStart();

enu_ErorrStatus TWI_enuMasterSendAddress(u8 Copy_u8Address,TWI_Operations Copy_enuOperation);
enu_ErorrStatus TWI_enuMasterReceiveData(u8* pu8Data);
enu_ErorrStatus TWI_enuMasterSendData(u8 Copy_u8Data);


#endif
