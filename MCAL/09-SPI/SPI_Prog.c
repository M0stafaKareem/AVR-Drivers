#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../01-DIO/Dio_Interface.h"
#include "SPI_Register.h"

void SPI_MasterInit(){
	SPCR = 0b01010000;
}

void SPI_SlaveInit(){
	SPCR = 0b01000000;
}

u8 SPI_Tranciev(u8 Copy_u8TransmittedData){
	SPDR = Copy_u8TransmittedData;
	while( GET_BIT(SPSR,SPSR_SPIF)==0 );
	return SPDR ;
}
