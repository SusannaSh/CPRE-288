/// Simple 'Hello, world' program
/**
 * This program prints "Hello, world" to the LCD screen
 * @author Chad Nelson
 * @date 06/26/2012
 *
 * updated: phjones 9/3/2019
 * Description: Added timer_init call, and including Timer.h
 */

#include "Timer.h"
#include "lcd.h"


int main (void) {

	timer_init(); // Initialize Timer, needed before any LCD screen functions can be called 
	              // and enables time functions (e.g. timer_waitMillis)

	lcd_init();   // Initialize the LCD screen.  This also clears the screen. 

	// Print "Hello, world" on the LCD
	//lcd_init():


	    char arr [] = "Microcontrollers are lots of fun!";
	    char arr1 [] = "                    Microcontrollers are lots of fun!";
	    int i = 0;
	   for (i= 0; i<=33;i++){

	       lcd_printf("%.20s", arr);
	       timer_waitMillis(300);

	       char hold = arr[0];
	       int j = 0;
	              while(j <= 33){
	                  arr[j] = arr[j+1];
	                  j++;
	              }
	              arr[34] = hold;

	      // lcd_printf("%.20s", arr);


	       //lcd_printf(arr);
	   }
	    while(1){

	           lcd_printf("%.20s", arr1);
	           timer_waitMillis(300);

	           char hold = arr1[0];
	           int i = 0;
	                  while(i <= 53){
	                      arr1[i] = arr1[i+1];
	                      i++;
	                  }
	                  arr1[54] = hold;

	          // lcd_printf("%.20s", arr);


	           //lcd_printf(arr);
	       }




	    //lcd_puts("Microcontrollers are");
	   // timer_waitMillis(300);
	   // lcd_clear();
	    //lcd_printf(const char 'l');

	//lcd_puts("Microcontrollers are lots of fun!");



	// lcd_puts("Hello, world"); // Replace lcd_printf with lcd_puts
        // step through in debug mode and explain to TA how it works
    
	// NOTE: It is recommended that you use only lcd_init(), lcd_printf(), lcd_putc, and lcd_puts from lcd.h.
       // NOTE: For time functions, see Timer.h

	return 0;
}
