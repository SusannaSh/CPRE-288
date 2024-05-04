/*
 * button.c
 *
 *  Created on: Jul 18, 2016
 *      Author: Eric Middleton, Zhao Zhang, Chad Nelson, & Zachary Glanz.
 *
 *  @edit: Lindsey Sleeth and Sam Stifter on 02/04/2019
 *  @edit: Phillip Jones 05/30/2019: Merged Spring 2019 version with Fall 2018
 *  @edit: Diane Rover 02/01/20: Corrected comments about ordering of switches for new LCD board and added busy-wait on PRGPIO
 */



//The buttons are on PORTE 3:0
// GPIO_PORTE_DATA_R -- Name of the memory mapped register for GPIO Port E,
// which is connected to the push buttons
#include <inc/tm4c123gh6pm.h>
#include <stdint.h>
#include "button.h"
#include "servo.h"


volatile int button_num;
/**
 * Initialize PORTE and configure bits 0-3 to be used as inputs for the buttons.
 */
void button_init() {
	SYSCTL_RCGCGPIO_R |= 0b010000; //Enables port E clock
	while((SYSCTL_PRGPIO_R & 0x10) == 0) {}; //Checks if ready
	GPIO_PORTE_DIR_R &= 0xF0; //Set up PE0-PE3 as inputs
	GPIO_PORTE_DEN_R |= 0x0F; //enables pins 0-3 for digital
}
	//interrupts for buttons
/*
	GPIO_PORTE_IM_R &= 0x00;

	GPIO_PORTE_IS_R &= 0xF0;

	GPIO_PORTE_IBE_R |= 0x0F;

	GPIO_PORTE_ICR_R = 0x0F;

	GPIO_PORTE_IM_R |= 0x0F;

	NVIC_EN0_R |= 0x10;

	IntRegister(INT_GPIOE, gpioe_handler);

	}

void gpioe_handler(void) {

    GPIO_PORTE_ICR_R |= 0x0F;

    button_num = button_getButton();

    if(calibration == 1)
    {
        if(button_num == 1)
        {
            servo_move(0);
            cal_factor = cal_factor + 1;
        }
        if(button_num == 2)
        {
            servo_move(0);
            cal_factor = cal_factor - 1;
        }
    }

}
*/




/**
 * Returns the position of the rightmost button being pushed.
 * @return the position of the rightmost button being pushed. 1 is the leftmost button, 4 is the rightmost button.  0 indicates no button being pressed
 */
uint8_t button_getButton() {


    if(((GPIO_PORTE_DATA_R >> 3) & 1) == 0)
    {
        return 4;
    }
    else if(((GPIO_PORTE_DATA_R >> 2) & 1) == 0)
    {
        return 3;
    }
    else if(((GPIO_PORTE_DATA_R >> 1) & 1) == 0)
    {
        return 2;
    }
    else if(((GPIO_PORTE_DATA_R >> 0) & 1) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
