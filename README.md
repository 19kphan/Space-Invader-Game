# Space-Invader-Game

California State University, Long Beach

CECS347 Fall 2023 Project 3

By Kevin Phan, James Quon, Rei Angelo Amurao

To design and create the classic Space Invaders game on the ARM LaunchPad, employing modular design and hardware components like Nokia5110 LCD, switches, potentiometer, and a DAC circuit.

### Brief Summary: 
To design and create a Space Invaders game on the ARM LaunchPad, employing modular design and hardware components like Nokia5110 LCD, switches, potentiometer, and a DAC circuit. To ensure organized step-by-step progress and testing, the project spans five developmental phases, implementing features such as game prompts, enemy movements, spaceship control via ADC, shooting mechanics, and integrating sound effects.

### Introduction:
The objective of this lab report is to show our understanding and mastery of embedded systems through the ARM-based microcontroller. This Space Invader project aims to combine both hardware and software to create a functional and interactive video game while exploring a combination of fundamental components such as the Nokia5110 LCD, switches, potentiometer, and a DAC circuit to create an engaging gaming experience. The project is structured into five distinct phases, each focusing on specific functionalities, including game prompts, enemy behaviors, user controls, shooting mechanics, and the integration of sound effects. And across these five phases, it delves into fundamental concepts including clock generation using Phase-Locked Loops (PLL), precise timing mechanisms through SysTick timers and interrupts, Analog-to-Digital Conversion (ADC) for user input, and utilizing Serial Synchronous Interface (SSI) for LCD communication. Furthermore, the incorporation of edge-triggered interrupts, real-time user control via ADC, and the creation of a sound generation mechanism through a 4-bit R2R DAC circuit added depth to the technical underpinnings of the project. Embracing these fundamental topics, the project aimed not only to create a functional game but also to imbue it with complexity and depth, incorporating multiple enemy rows and adaptive game levels, challenging the bounds of conventional Space Invaders gameplay. The following report outlines the methodology, development phases, challenges encountered, and the final outcomes achieved throughout this intricate yet rewarding project. 

### Operation:
  To successfully operate the Space Invader game, we first need to set up the hardware components, which include the LaunchPad microcontroller, a potentiometer, two switches, two LEDs, a Nokia5110 LCD with four 10k ohms, one 10k ohms, a 0.1uF capacitor, eight resistors consisting of five 10K ohms and three 5k ohms for the 4-bit DAC circuit, a speaker, and a LM386 audio amplifier. Due to the intricate features and functionalities of the program, it has been encapsulated across different phases of development.
	
 In SpaceInvaderV1, the foundational structure was established, beginning with the integration of the Nokia5110 LCD to display the initial prompt: "Space Invader Press SW2 To Start." This version focused on system initialization, implementing Phase-Locked Loops (PLL) to generate an 80MHz system clock and configuring edge-triggered interrupts to capture SW1 and SW2 presses. The groundwork laid the essential framework for subsequent phases, setting the stage for further feature development.
	
 SpaceInvadersV2 expanded the gaming experience by introducing dynamic enemy movements and game progression. Utilizing SysTick timers with interrupts at a 10Hz refresh rate, this version facilitated the movement of three different enemies from left to right on the screen. Each enemy vanished upon reaching the screen's edge, culminating in the display of the "Game Over Nice Try! Your Score: X" message for 3 seconds, achieved through SysTick timing mechanisms.
	
 Continuing the evolution of gameplay, SpaceInvaderV3 focused on user-controlled spaceship movements. This phase integrated the potentiometer input, converted via Analog-to-Digital Conversion (ADC), to govern the spaceship's positioning at the bottom of the screen. The precise user control added an interactive dimension to the game, enhancing the player's engagement with the gameplay mechanics.
	
 SpaceInvaderV4 elevated the gaming experience by introducing shooting mechanics. By leveraging SW1, players could fire bullets from the spaceship. The implementation of collision detection between bullets and enemies brought an additional layer of gameplay dynamics. Successful collisions resulted in an explosion effect, signaling a hit, while bullets that missed enemies disappeared upon reaching the screen's top.
	
 In the final phase, SpaceInvaderV5, sound effects were integrated to enrich the gaming experience further. Utilizing a 4-bit R2R DAC circuit, shooting and hit sounds were synchronized with gameplay actions. Timer 1 facilitated the precise timing of these sound effects, elevating the overall immersion of the game.

 ### Theory:
The Space Invaders project integrates various technologies, concepts, and ideas to achieve desired game mechanics and development. The project embraced a modular design approach, breaking down the game's functionalities into distinct modules such as main, Nokia5110, PLL, switches, SysTick, ADC, and DAC. This modular architecture streamlined development, allowing for efficient testing and debugging.

The integration of the Nokia5110 LCD necessitated comprehension of the Serial Synchronous Interface (SSI), a critical protocol used for communication between the LaunchPad and the LCD module. Pin configurations for data/command, clock, chip enable, reset, and power connections were meticulously managed to enable seamless data transfer and display control. Additionally, interfacing with components like switches, potentiometer, and the 4-bit R2R DAC circuit involved understanding GPIO pin configurations and ADC for analog signal conversion.

The Phase-Locked Loop (PLL) played a crucial role in generating an 80MHz system clock, providing the necessary timing and synchronization for various game functionalities. Additionally, the SysTick timer was employed to orchestrate a 10Hz screen refresh rate, essential for smooth and synchronized gameplay. It regulated the timing for enemy movements, game progression, and display functionalities.

The ADC was used to convert analog signals from the potentiometer into digital values, enabling precise user-controlled movements for the spaceship.

The project utilized interrupts to capture switch presses, enabling responsive and event-driven interactions. Edge-triggered interrupts were configured to detect changes in the switch states, initiating specific actions upon their triggers.

The integration of sound effects relied on a 4-bit R2R DAC circuit, converting digital values to analog signals to produce audible shooting and hit sounds synchronized with gameplay actions.
 
 Each phase of development was built upon the preceding one, progressively enhancing the gameplay experience. This iterative approach facilitated feature additions, refinement, and compatibility maintenance within the existing modular framework which allowed for an ideal organized progression.

### Hardware 
#### Embedded System Schematic:

![image](https://github.com/19kphan/Space-Invader-Game/assets/155543499/06163b0f-628c-4d9e-af59-aad45ebedab1)

#### Photo of Embedded System:

![image](https://github.com/19kphan/Space-Invader-Game/assets/155543499/b632c49a-c47e-42bf-b4da-c26b970a2cc0)

#### GPIO Ports & Pins:

![image](https://github.com/19kphan/Space-Invader-Game/assets/155543499/be7fd37e-895d-4e78-bc9e-64a4a867c5f6)

#### Flowchart: 

![image](https://github.com/19kphan/Space-Invader-Game/assets/155543499/18538589-a8a9-4479-a157-460b11939d77)

![image](https://github.com/19kphan/Space-Invader-Game/assets/155543499/e44f4c75-5606-46a3-ab52-e3f152ba2cfb)

#### Video Demonstration Link:

https://csulb-my.sharepoint.com/:v:/g/personal/james_quon01_student_csulb_edu/Edj5vlfifMhBoIbhzID7i7ABY8z2xT5JPpQLIwx_ZXV_rg?e=JxXERb&nav=eyJyZWZlcnJhbEluZm8iOnsicmVmZXJyYWxBcHAiOiJTdHJlYW1XZWJBcHAiLCJyZWZlcnJhbFZpZXciOiJTaGFyZURpYWxvZy1MaW5rIiwicmVmZXJyYWxBcHBQbGF0Zm9ybSI6IldlYiIsInJlZmVycmFsTW9kZSI6InZpZXcifX0%3D

### Conclusion

The Space Invaders Game project uses various technologies, concepts, and ideas to achieve hardware-software integration, modular design, and iterative development. Through the combination of these factors, the project unfolded in distinct phases, each contributing significantly to the evolution of the gameplay experience. The project saw several successes, primarily in the successful implementation of modular design, enabling seamless integration and scalability of functionalities. Utilizing essential elements such as the PLL for clock generation and SysTick timers for precise timing greatly enhanced the game's fluidity and synchronization. Additionally, the incorporation of ADC for user-controlled spaceship movements and DAC for synchronized sound effects added depth and interactivity to the gameplay experience. Along the developmental path, challenges surfaced, providing valuable learning experiences. Reversing the logic for the y-coordinate due to LCD behavior and mitigating dimming issues caused by shared voltage sources for the LCD and DAC were noteworthy hurdles. These challenges were addressed through innovative solutions, such as using separate voltage sources and adapting logic to ensure seamless integration and functionality. The project underscored the importance of adaptability and problem-solving in real-world applications. The need for careful planning and consideration for both aesthetic and functional aspects became apparent, as seen in the reevaluation of design choices due to wiring complications caused by aesthetic cover implementation.


