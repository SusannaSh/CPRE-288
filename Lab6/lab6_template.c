/**
 * lab6_template.c
 *
 * Template file for CprE 288 Lab 6
 *
 * @author Diane Rover, 2/15/2020
 *
 */

#include "Timer.h"
#include "lcd.h"
#include "cyBot_Scan.h"  // For scan sensors
#include "uart-interrupt.h"

// Uncomment or add any include directives that are needed
// #include "open_interface.h"
// #include "movement.h"
// #include "button.h"


#warning "Possible unimplemented functions"
#define REPLACEME 0


int main(void) {
	timer_init(); // Must be called before lcd_init(), which uses timer functions
	lcd_init();
	uart_interrupt_init();
  // cyBOT_init_Scan();

	// YOUR CODE HERE
	    char message[20];
       // char text[20];
        int i = 0;
	while(1)
	{
       // char input = uart_receive();

            lcd_printf(message);
            uart_sendStr(message);
           // lcd_setCursorPos(0,1);
            char length [] = {0};
            sprintf(length, '%d' , strlen(message));
/*               lcd_puts(length);*/
           // i = 0;

           // uart_sendChar(message[i]);



/*        else {

            message[i] = input;
        }*/
        i++;
      // YOUR CODE HERE


	}

}
