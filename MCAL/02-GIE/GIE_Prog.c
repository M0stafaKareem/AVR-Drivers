#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "GIE_Register.h"

void GIE_vidEnable(void){
	SET_BIT(SREG,SREG_I_BIT);
}

void GIE_vidDisable(void){
	CLR_BIT(SREG,SREG_I_BIT);
}
