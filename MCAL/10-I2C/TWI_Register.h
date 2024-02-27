#ifndef TWI_REGISTER_H_
#define TWI_REGISTER_H_

#define TWCR (*((volatile u8 *) 0x56))
#define TWDR (*((volatile u8 *) 0x23))
#define TWAR (*((volatile u8 *) 0x22))
#define TWSR (*((volatile u8 *) 0x21))
#define TWBR (*((volatile u8 *) 0x20))

/* TWCR bits */
#define   TWCR_TWINT   7
#define   TWCR_TWEA    6
#define   TWCR_TWSTA   5
#define   TWCR_TWSTO   4
#define   TWCR_TWWC    3
#define   TWCR_TWEN    2
#define   TWCR_TWIE    0

/* TWAR bits */
#define   TWAR_TWA0    1
#define   TWAR_TWGCE   0

/* TWSR */
#define   TWSR_TWS7     7
#define   TWSR_TWS6     6
#define   TWSR_TWS5     5
#define   TWSR_TWS4     4
#define   TWSR_TWS3     3
#define   TWSR_TWPS1    1
#define   TWSR_TWPS0    0


#endif
