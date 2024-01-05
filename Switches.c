// CECS347 Project 3: Space Invaders 
// Student Names: Kevin Phan, James Quon, Rei Angelo Amurao
// Group: 3
// Date: December 6, 2023
// File description: Controls the two onboard switches of the microcontroller 

#include "tm4c123gh6pm.h"
#include "Switches.h"

void Switch_Init(void){ 
	// Activate F clock if not activated
	if(((SYSCTL_RCGC2_R&0x00000020)!=0x00000020)){
		SYSCTL_RCGC2_R |= 0x00000020;
		while ((SYSCTL_RCGC2_R&0x00000020)!=0x00000020){}
	}
		
  GPIO_PORTF_LOCK_R = 0x4C4F434B;   	// unlock PortF PF0  
	GPIO_PORTF_CR_R |= 0x11;         		// allow changes to PF4-0 :11111->0x1F     
  GPIO_PORTF_AMSEL_R &= ~0x11;        // disable analog function
  GPIO_PORTF_PCTL_R &= ~0x000F000F; 	// GPIO clear bit PCTL  
  GPIO_PORTF_DIR_R &= ~0x11;          // PF4,PF0 input   
	GPIO_PORTF_AFSEL_R &= ~0x11;        // no alternate function
  GPIO_PORTF_PUR_R |= 0x11;          	// enable pullup resistors on PF4,PF0       
  GPIO_PORTF_DEN_R |= 0x11;          	// enable digital pins PF4-PF0   

	// Set PF0/4 for both edge interrupt
	GPIO_PORTF_IS_R &= ~0x11; // clear for edge triggered
	GPIO_PORTF_IBE_R &= ~0x11; // set for both edges	

	GPIO_PORTF_ICR_R |= 0x11; // clear flags
	GPIO_PORTF_IM_R |= 0x11; // arm interrupts
	
	NVIC_PRI7_R = (NVIC_PRI7_R&0xFF1FFFFF)|0x00A00000; // Set Port F interrupt to priority 5
	NVIC_EN0_R |= 0x40000000; // Enable interrupt on Port F
}