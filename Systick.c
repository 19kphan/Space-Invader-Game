// CECS347 Project 3: Space Invaders 
// Student Names: Kevin Phan, James Quon, Rei Angelo Amurao
// Group: 3
// Date: December 6, 2023
// File description: Generates a timing of 0.1 seconds for the game to update with 

#include "tm4c123gh6pm.h"

// Initialize SysTick with busy wait running at bus clock.
void SysTick_Init(void){
//  NVIC_ST_CTRL_R = 0;                   // disable SysTick during setup
//  NVIC_ST_RELOAD_R = NVIC_ST_RELOAD_M;  // maximum reload value
//  NVIC_ST_CURRENT_R = 0;                // any write to current clears it
//                                        // enable SysTick with core clock
//  NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE+NVIC_ST_CTRL_CLK_SRC;

  NVIC_ST_CTRL_R = 0x00;          // disable SysTick during setup
  NVIC_ST_RELOAD_R = 0x007A1200 - 1;  // maximum reload value
  NVIC_ST_CURRENT_R = 0x00;       // any write to current clears it
  NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R & 0x1FFFFFFF) | 0x40000000;
  NVIC_ST_CTRL_R = 0x07;          // enable SysTick with core clock
} 
