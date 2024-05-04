
//servo.h includes timer.h
#include "servo.h"

volatile signed pulseWidth;
volatile int calibration = 1; //can be changed, 1 by default; 0: no calibration, 1: calibration
volatile int cal_factor = 6100; //by default 0, can be changed after a calibration
 //used for calibration and the general movement of the servo
volatile int button_check;

void init_servo(){
    //Initialize PORTB pin 5
    //starts clock for PORTB
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1; //MACROs are found in tm4c123gh6pm.h

    //sets PB5 as an output
    GPIO_PORTB_DIR_R |= 0x20;

    //digital enable
    GPIO_PORTB_DEN_R |= 0x20;

    //enables alternate functions of PB5
    GPIO_PORTB_AFSEL_R |= 0x20;
    GPIO_PORTB_PCTL_R |= 0x700000;


    //TIMER Config
    //starts clock for TIMER1
    SYSCTL_RCGCTIMER_R |= SYSCTL_RCGCTIMER_R1;

    //disables timer to config
    TIMER1_CTL_R &= ~TIMER_CTL_TBEN;

    //Set to a 16 bit counter
    TIMER1_CFG_R |= TIMER_CFG_16_BIT;

    //enables periodic and PWM
    TIMER1_TBMR_R |= 0x0A;
    TIMER1_TBMR_R &= ~(0x15);

    //makes the PWM non-inverted
    TIMER1_CTL_R &= ~TIMER_CTL_TBPWML;

    //set upper bound of timer
    TIMER1_TBILR_R |= 0xFFFF;
    TIMER1_TBPR_R |= 0x04;

    pulseWidth = 0;
    move_servo(pulseWidth); //# of clock periods = 320,000 or 0x04E200

    // set lower 16 bits of pulse width
        TIMER1_TBMATCHR_R = ((320000 - pulseWidth) & 0xFFFF);

        //set upper 8 bits of pulse width
        TIMER1_TBPMR_R = (((320000 - pulseWidth) >> 16) & 0xFF);

        //enable timer
        TIMER1_CTL_R |= TIMER_CTL_TBEN;

}

void move_servo(float degree){
    pulseWidth = ((28992 * (degree/180.0)) + cal_factor);

        //set lower 16 bits of pulse width
        TIMER1_TBMATCHR_R = ((320000 - pulseWidth) & 0xFFFF);

        //set the upper 8 bits of the pulse width
        TIMER1_TBPMR_R = (((320000 - pulseWidth) >> 16) & 0xFF);

        //Delay for the servo to move to the position
        timer_waitMillis(50);

}

void servo_cal(void)
{
button_check = 0;
    while(calibration == 1)
    {
        button_check = 0;
        move_servo(0);
        while(button_getButton() != 4) //first while loop allows for noticeable increments in either direction until satisfied
        {
            lcd_printf("B1 moves left\nB2 moves right\nPress B4 To End\nTry to get 0 degrees");
            if(button_getButton() == 1)
            {
                move_servo(0);
                cal_factor = cal_factor + 100;
            }
            if(button_getButton() == 2)
            {
                move_servo(0);
                cal_factor = cal_factor - 100;
            }
        }
        move_servo(180);
        while(button_check == 0) //second while loop makes sure when doing a 180 it is in it's desired position
        {
            lcd_printf("Is it at 180 degreesDoes this look good?B1 (Yes)  B2 (No)\ncal_factor: %d",cal_factor);
            if(button_getButton() == 1)
            {
                calibration = 0;
                button_check = 1;
            }
            if(button_getButton() == 2) //allows to redo measurments until desired
            {
                button_check = 1;
            }

        }

    }
    lcd_printf("Done with\nCalibration!");

}


