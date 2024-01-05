// CECS347 Project 3: Space Invaders 
// Student Names: Kevin Phan, James Quon, Rei Angelo Amurao
// Group: 3
// Date: December 6, 2023
// File description: Takes the input of the potentiometer to control the player ship movement 

#include "tm4c123gh6pm.h"
#include "ADC.h"

void ADC_Init(void){ 
  SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOD;   // 1) activate clock for Port E
	while ((SYSCTL_RCGC2_R&SYSCTL_RCGC2_GPIOD)!=SYSCTL_RCGC2_GPIOD){}

	GPIO_PORTD_DIR_R &= ~0x01;      // 2) make PD0 input
  GPIO_PORTD_AFSEL_R |= 0x01;     // 3) enable alternate function on PD0
  GPIO_PORTD_DEN_R &= ~0x01;      // 4) disable digital I/O on PD0
  GPIO_PORTD_AMSEL_R |= 0x01;     // 5) enable analog function on PD0
  
	SYSCTL_RCGC0_R |= 0x00010000;   // 6) activate ADC0 
	while ((SYSCTL_RCGC0_R&0x00010000)!=0x00010000){}
         
  SYSCTL_RCGC0_R &= ~0x00000300;  // 7) configure for 125K 
  ADC0_SSPRI_R = 0x0123;          // 8) Sequencer 3 is highest priority
  ADC0_ACTSS_R &= ~0x0008;        // 9) disable sample sequencer 3
  ADC0_EMUX_R &= ~0xF000;         // 10) seq3 is software trigger
  ADC0_SSMUX3_R = (ADC0_SSMUX3_R&0xFFFFFFF0)+7; // 11) channel Ain1 (PE2)
  ADC0_SSCTL3_R = 0x0006;         // 12) no TS0 D0, yes IE0 END0
  ADC0_ACTSS_R |= 0x0008;         // 13) enable sample sequencer 3
}

