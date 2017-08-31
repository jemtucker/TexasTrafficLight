#ifndef __PORT_H_
#define __PORT_H_

typedef enum EPortId {
	PORT_A = 0,
	PORT_B = 1,
	PORT_C = 2,
	PORT_D = 3,
	PORT_E = 4,
	PORT_F = 5,
} EPORT_ID;

typedef struct Port {
	volatile unsigned long* address;
	unsigned int mask;
} PORT, *PPORT;

int Port_Init(const EPORT_ID id, PPORT port, unsigned short bits, int output);

#endif
