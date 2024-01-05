// CECS347 Project 3: Space Invaders 
// Student Names: Kevin Phan, James Quon, Rei Angelo Amurao
// Group: 3
// Date: December 6, 2023
// File description: DAC used to output the sound signals to the buzzer.

// dac.c
// This software configures DAC output
// Lab 6 requires a minimum of 4 bits for the DAC, but you could have 5 or 6 bits
// Runs on LM4F120 or TM4C123
// Program written by: put your names here
// Date Created: 3/6/17 
// Last Modified: 1/17/2020 
// Lab number: 6
// Hardware connections
// TO STUDENTS "REMOVE THIS LINE AND SPECIFY YOUR HARDWARE********

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "DAC.h"

#define DAC_DATA (*((volatile uint32_t *)0x4000503C))  // PB0-3: output to DAC circuit
  
// Code files contain the actual implemenation for public functions
// this file also contains an private functions and private data

// **************DAC_Init*********************
// Initialize 3-bit DAC, called once 
// DAC bit 0 on PB0 (least significant bit)
// DAC bit 1 on PB1
// DAC bit 2 on PB2
// DAC bit 3 on PB3 (most significant bit)
// Input: none
// Output: none
void DAC_Init(void){  
  SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOB; // activate port B
	while ((SYSCTL_RCGC2_R&SYSCTL_RCGC2_GPIOB)!=SYSCTL_RCGC2_GPIOB){}

  
  GPIO_PORTB_AMSEL_R &= ~0x0F;      // no analog 
  GPIO_PORTB_PCTL_R &= ~0x0000FFFF; // regular function
  GPIO_PORTB_DIR_R |= 0x0F;      // make PB3-0 out
  GPIO_PORTB_AFSEL_R &= ~0x0F;   // disable alt funct on PB3-0
  GPIO_PORTB_DEN_R |= 0x0F;      // enable digital I/O on PB3-0
}

// **************DAC_Out*********************
// output to DAC
// Input: 4-bit data, 0 to 15 
// Input=n is converted to n*3.3V/15
// Output: none
void DAC_Out(uint8_t data){
  DAC_DATA = data;
}
