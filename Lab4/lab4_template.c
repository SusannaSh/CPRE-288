/**
 * lab4_template.c
 *
 * Template file for CprE 288 lab 4
 *
 * @author Zhao Zhang, Chad Nelson, Zachary Glanz
 * @date 08/14/2016
 */

#include "button.h"
#include "Timer.h"
#include "lcd.h"
#include "cyBot_uart.h"  // Functions for communicating between CyBot and Putty (via UART)
                         // PuTTy: Baud=115200, 8 data bits, No Flow Control, No Parity, COM1

#warning "Possible unimplemented functions"
#define REPLACEME 0

void sendMessage(char* input){
   int i;
   for (i=0; i<strlen(input); i++ ){
       cyBot_sendByte(input[i]);
   }


 }


int main(void) {
	button_init();
	timer_init(); // Must be called before lcd_init(), which uses timer functions
	lcd_init();
	cyBot_uart_init(); // Don't forget to initialize the cyBot UART before trying to use it

	// YOUR CODE HERE
	 char test [20];
	
	while(1)
	{
	    // YOUR CODE HERE

     // button_getButton();
	    int buttonNumber =  button_getButton();
	    //cyBot_getByte() = buttonNumber;
	   sprintf(test, "Button %d", buttonNumber);
	   sendMessage(test);
	        //cyBot_sendByte(buttonNumber);
	      //  sprintf(string, "Button 4");


	  //  else if(button_getButton() == )

      lcd_printf("%d",button_getButton());


	}

}
