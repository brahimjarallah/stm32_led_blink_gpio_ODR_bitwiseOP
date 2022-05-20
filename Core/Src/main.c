// stm32 baremetal led blink using bitwise operation & #define directive

#include "stm32f4xx.h"

//set bit0 in RCC_AHB1ENR to 1 (PORT D)
#define GPIOD_EN (1<<3) // 0x4 // 0b 0000 0000 0000 0000 0000 0000 0000 1000

//set bit30 to 1 and bit 31 to 0 in GPIO_MODER (LD6/PD15)
#define MODER_15_OUT (1<<30) // 0x40000000 // Ob 0100 0000 0000 0000 0000 0000 0000 0000

//write 1 to GPIOD_ODR bit 15 to set PD15 OFF, and write 0 to set it OFF
#define ODR_15_SET (1<<15)
#define ODR_15_RESET (0<<15)

#define LED_PIN (1<<15)

int main(void){

	RCC->AHB1ENR |= GPIOD_EN;  // enable clock access to port D
	GPIOD->MODER |= MODER_15_OUT; // set pin15 as output for port D

	while(1){
		for(int i=0; i<900000; i++); // dummy delay
		GPIOD->ODR ^= ODR_15_SET;  // set pin15 high
	}
}
