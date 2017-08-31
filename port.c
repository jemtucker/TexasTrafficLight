#include "port.h"

#include "tm4c123gh6pm.h"

#include "utils.h"

int PortA_Init(PPORT port, unsigned short bit, int output) {
	volatile unsigned long delay;
	
	port->address = &GPIO_PORTA_DATA_R;
	port->mask = (0x01 << bit);
	
  SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOA; // Clock
	delay = SYSCTL_RCGC2_R;               // Delay
  GPIO_PORTA_LOCK_R = GPIO_LOCK_KEY;    // Unlock Port
	GPIO_PORTA_CR_R |= port->mask;        // Allow changes to bit at index 'bit'      
  GPIO_PORTA_AMSEL_R = 0x00;            // Disable analog function
  GPIO_PORTA_PCTL_R = 0x00000000;       // GPIO clear bit PCTL
	
	// Configure as either input or output
	if (output)
		GPIO_PORTA_DIR_R |= port->mask;
	else
		GPIO_PORTA_DIR_R &= (~port->mask);
	
  GPIO_PORTA_AFSEL_R = 0x00;      // No alternate function     
  GPIO_PORTA_DEN_R |= port->mask; // Enable pin  
	
	return TRUE;
}

int PortB_Init(PPORT port, unsigned short bit, int output) {
	volatile unsigned long delay;
	
	port->address = &GPIO_PORTB_DATA_R;
	port->mask = (0x01 << bit);
	
  SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOB; // Clock
	delay = SYSCTL_RCGC2_R;               // Delay
  GPIO_PORTB_LOCK_R = GPIO_LOCK_KEY;    // Unlock Port
	GPIO_PORTB_CR_R |= port->mask;        // Allow changes to bit at index 'bit'      
  GPIO_PORTB_AMSEL_R = 0x00;            // Disable analog function
  GPIO_PORTB_PCTL_R = 0x00000000;       // GPIO clear bit PCTL
	
	// Configure as either input or output
	if (output)
		GPIO_PORTB_DIR_R |= port->mask;
	else
		GPIO_PORTB_DIR_R &= (~port->mask);
	
  GPIO_PORTB_AFSEL_R = 0x00;      // No alternate function     
  GPIO_PORTB_DEN_R |= port->mask; // Enable pin  
	
	return TRUE;
}

int PortC_Init(PPORT port, unsigned short bit, int output) {
	volatile unsigned long delay;
	
	port->address = &GPIO_PORTC_DATA_R;
	port->mask = (0x01 << bit);
	
  SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOC; // Clock
	delay = SYSCTL_RCGC2_R;               // Delay
  GPIO_PORTC_LOCK_R = GPIO_LOCK_KEY;    // Unlock Port
	GPIO_PORTC_CR_R |= port->mask;        // Allow changes to bit at index 'bit'      
  GPIO_PORTC_AMSEL_R = 0x00;            // Disable analog function
  GPIO_PORTC_PCTL_R = 0x00000000;       // GPIO clear bit PCTL
	
	// Configure as either input or output
	if (output)
		GPIO_PORTC_DIR_R |= port->mask;
	else
		GPIO_PORTC_DIR_R &= (~port->mask);
	
  GPIO_PORTC_AFSEL_R = 0x00;      // No alternate function     
  GPIO_PORTC_DEN_R |= port->mask; // Enable pin  
	
	return TRUE;
}

int PortD_Init(PPORT port, unsigned short bit, int output) {
	volatile unsigned long delay;
	
	port->address = &GPIO_PORTD_DATA_R;
	port->mask = (0x01 << bit);
	
  SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOD; // Clock
	delay = SYSCTL_RCGC2_R;               // Delay
  GPIO_PORTD_LOCK_R = GPIO_LOCK_KEY;    // Unlock Port
	GPIO_PORTD_CR_R |= port->mask;        // Allow changes to bit at index 'bit'      
  GPIO_PORTD_AMSEL_R = 0x00;            // Disable analog function
  GPIO_PORTD_PCTL_R = 0x00000000;       // GPIO clear bit PCTL
	
	// Configure as either input or output
	if (output)
		GPIO_PORTD_DIR_R |= port->mask;
	else
		GPIO_PORTD_DIR_R &= (~port->mask);
	
  GPIO_PORTD_AFSEL_R = 0x00;      // No alternate function     
  GPIO_PORTD_DEN_R |= port->mask; // Enable pin  
	
	return TRUE;
}

int PortE_Init(PPORT port, unsigned short bit, int output) {
	volatile unsigned long delay;
	
	port->address = &GPIO_PORTE_DATA_R;
	port->mask = (0x01 << bit);
	
  SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOE; // Clock
	delay = SYSCTL_RCGC2_R;               // Delay
  GPIO_PORTE_LOCK_R = GPIO_LOCK_KEY;    // Unlock Port
	GPIO_PORTE_CR_R |= port->mask;        // Allow changes to bit at index 'bit'      
  GPIO_PORTE_AMSEL_R = 0x00;            // Disable analog function
  GPIO_PORTE_PCTL_R = 0x00000000;       // GPIO clear bit PCTL
	
	// Configure as either input or output
	if (output)
		GPIO_PORTE_DIR_R |= port->mask;
	else
		GPIO_PORTE_DIR_R &= (~port->mask);
	
  GPIO_PORTE_AFSEL_R = 0x00;      // No alternate function     
  GPIO_PORTE_DEN_R |= port->mask; // Enable pin  
	
	return TRUE;
}

int PortF_Init(PPORT port, unsigned short bit, int output) {
	volatile unsigned long delay;
	
	port->address = &GPIO_PORTF_DATA_R;
	port->mask = (0x01 << bit);
	
  SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF; // Clock
	delay = SYSCTL_RCGC2_R;               // Delay
  GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;    // Unlock Port
	GPIO_PORTF_CR_R |= port->mask;        // Allow changes to bit at index 'bit'      
  GPIO_PORTF_AMSEL_R = 0x00;            // Disable analog function
  GPIO_PORTF_PCTL_R = 0x00000000;       // GPIO clear bit PCTL
	
	// Configure as either input or output
	if (output)
		GPIO_PORTF_DIR_R |= port->mask;
	else
		GPIO_PORTF_DIR_R &= (~port->mask);
	
  GPIO_PORTF_AFSEL_R = 0x00;      // No alternate function     
  GPIO_PORTF_DEN_R |= port->mask; // Enable pin  
	
	return TRUE;
}

int Port_Init(const EPORT_ID id, PPORT port, unsigned short bit, int output) {	
	if (!port || bit > 7)
		return FALSE;
	
	switch (id) {
		case PORT_A:
			return PortA_Init(port, bit, output);
		case PORT_B:
			return PortB_Init(port, bit, output);
		case PORT_C:
			return PortC_Init(port, bit, output);
		case PORT_D:
			return PortD_Init(port, bit, output);
		case PORT_E:
			return PortE_Init(port, bit, output);
		case PORT_F:
			return PortF_Init(port, bit, output);
		default:
			return FALSE;
	}
}
