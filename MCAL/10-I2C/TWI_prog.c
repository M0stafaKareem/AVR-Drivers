#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "TWI_Register.h"
#include "TWI_Interface.h"
#include "TWI_Config.h"
#include "TWI_Private.h"

void TWI_vidMasterInit(u32 Copy_u32Address){
	TWBR = 2 ;
	if ( Copy_u32Address){
		TWAR = Copy_u32Address<<1 ;
	}
	SET_BIT(TWCR, TWCR_TWEN);

}


void TWI_vidSlvInit(u8 Copy_u8Address){
		TWAR = Copy_u8Address<<1 ;
		SET_BIT(TWCR, TWCR_TWEN);
}


enu_ErorrStatus TWI_enuSendStartCondition(){
	enu_ErorrStatus error =  StartACKError;

SET_BIT(TWCR,TWCR_TWSTA);
SET_BIT(TWCR,TWCR_TWINT);
while( GET_BIT(TWCR,TWCR_TWINT)==0 );
if(  STATUS_VALUE == START_ACK ){
	error = NoError ;
}
return error ;

}


void TWI_enuSendStopCondition(){

SET_BIT(TWCR,TWCR_TWSTO);
SET_BIT(TWCR,TWCR_TWINT);
while( GET_BIT(TWCR,TWCR_TWINT)==0 );

}


enu_ErorrStatus TWI_enuSendRepeatedStart(){
	enu_ErorrStatus error =  RepeatedStartError;

SET_BIT(TWCR,TWCR_TWSTA);
SET_BIT(TWCR,TWCR_TWINT);
while( GET_BIT(TWCR,TWCR_TWINT)==0 );
if(  STATUS_VALUE == START_ACK ){
	error = NoError ;
}
return error ;

}


enu_ErorrStatus TWI_enuMasterSendAddress(u8 Copy_u8Address,TWI_Operations Copy_enuOperation){
	enu_ErorrStatus error =  Sent_SLVaddressErr;
	CLR_BIT(TWCR,TWCR_TWSTA);
	TWDR = (Copy_u8Address<<1 | Copy_enuOperation);

	SET_BIT(TWCR,TWCR_TWINT);
	while( GET_BIT(TWCR,TWCR_TWINT)==0 );
	if(  STATUS_VALUE == SLAVE_W_NACK || STATUS_VALUE == SLAVE_R_NACK || STATUS_VALUE == SLAVE_W_ACK || STATUS_VALUE == SLAVE_R_ACK){
		error = NoError ;
	}
	return error ;

}


enu_ErorrStatus TWI_enuMasterSendData(u8 Copy_u8Data){
	enu_ErorrStatus error =  Sent_dataErr;
		TWDR = Copy_u8Data;

		SET_BIT(TWCR,TWCR_TWINT);
		while( GET_BIT(TWCR,TWCR_TWINT)==0 );
		if(  STATUS_VALUE == SLAVE_DATA_ACK || STATUS_VALUE == SLAVE_DATA_NACK ){
			error = NoError ;
		}
		return error ;


}


enu_ErorrStatus TWI_enuMasterReceiveData(u8* pu8Data){
	enu_ErorrStatus error =  Received_dataErr;

		SET_BIT(TWCR,TWCR_TWINT);
		while( GET_BIT(TWCR,TWCR_TWINT)==0 );
		if(  STATUS_VALUE == MASTER_R_DATA_ACK || STATUS_VALUE == MASTER_R_DATA_NACK ){
			error = NoError ;
		}
		*pu8Data = TWDR ;

		return error ;

}







