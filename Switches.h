// CECS347 Project 3: Space Invaders 
// Student Names: Kevin Phan, James Quon, Rei Angelo Amurao
// Group: 3
// Date: December 6, 2023
// File description: Header file for Switches.c 

#define SWITCH (*((volatile unsigned long *)0x40025044))  // use onboard three LEDs: PF41
	
void Switch_Init(void);