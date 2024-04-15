/**
 * lab6-interrupt_template.c
 *
 * Template file for CprE 288 Lab 6
 *
 * @author Diane Rover, 2/15/2020
 *
 */

#include "cyBot_Scan.h" // For scan sensors
#include "lcd.h"
#include "movement.h"
#include "Timer.h"
#include "uart-interrupt.h"
#include "adc.h"
// Uncomment or add any include directives that you want to use
// #include "open_interface.h"
// #include "movement.h"
// #include "button.h"

// Your code can use the global variables defined in uart-interrupt.c
// They are declared with the extern qualifier in uart-interrupt.h, which makes the variables visible to this file.

#warning "Possible unimplemented functions"
#define INT_UART1 22

int main(void)
{
    timer_init(); // Must be called before lcd_init(), which uses timer functions
    lcd_init();
    lcd_clear();
    oi_t *sensor_data = oi_alloc();
    oi_init(sensor_data);
    uart_interrupt_init();
    adc_init();

     right_calibration_value = 290500;
     left_calibration_value = 1214500;

    int i, j;
    int val = 15;
    uint16_t sum = 0;
    cyBOT_Scan_t scan;
    uint16_t adcValue;
    double adcDistValue;
    char ADC[50];
    char write[50];
    char c;
    while (1) {
        c = uart_receive();
        if (c == 's'){

//        for (i = 0; i < val; i++) {
//            cyBOT_Scan(90, &scan);
        adcValue = adc_read();

//            sum += adcValue;


//        }
//        uint16_t n = sum / val; //avg
        double inverse = 1.0 / adcValue;
        sum = 0;
//
        adcDistValue = 77.066* pow(2.71, (-.0007 *adcValue))-3.5;
        //print the avg ir value onto the screen
//        uart_sendStr('IR value');
        sprintf(ADC, "%d", adcValue);

        uart_sendStr(ADC);
        uart_sendStr("\r\n");
      //  uart_sendStr('Distance');
        double formatted = adcDistValue;
        sprintf(write, "%.2f \t\t %d", formatted, adcValue);
      //  lcd.begin(5,2);
//        lcd_setCursorPos(0,0);
        lcd_printf(write);
//        lcd_setCursorPos(0,1);
//        lcd_printf(ADC);


        uart_sendStr(write);
        uart_sendStr("\r\n");


    }
    }
    oi_free(sensor_data);
}
