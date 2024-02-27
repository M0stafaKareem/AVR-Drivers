#ifndef SEG_INTERFACE_H
#define SEG_INTERFACE_H

void Seg_vidUpCount			(u8 Copy_u8Port, u16 Copy_u16Delay_ms);
void Seg_vidDownCount		(u8 Copy_u8Port, u16 Copy_u16Delay_ms);
void Seg_vidDisplayNumber	(u8 Copy_u8Port, u8 Copy_u8Number);
void Seg_vidSetSegment		(u8 Copy_u8Port, u8 Copy_u8Pin);
void Seg_vidSetAllSegments	(u8 Copy_u8Port, u8 Copy_u8PortValue);
void Seg_vidClrSegment		(u8 Copy_u8Port, u8 Copy_u8Pin);

#endif
