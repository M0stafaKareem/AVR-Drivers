#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H

void EEPROM_WriteMultiByte();
void EEPROM_WritePage();

void EEPROM_WriteByte(u8 Copy_u8DataByte, u8 Copy_u8BloclAddress);
void EEPROM_ReadByte(u8 Copy_u8BloclAddress, u8* pu8ReceivedData);


#endif /* HAL_04_EEPROM_EEPROM_INTERFACE_H_ */
