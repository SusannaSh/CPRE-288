

#include "Timer.h"
#include "lcd.h"
#include "open_interface.h"
#include "movement.h"
#include "uart-interrupt.h"
#include "cyBot_Scan.h"
#include "string.h"
#include "stdio.h"
#include <math.h>




    void adc_init(void){

        //GPIO init
        SYSCTL_RCGCADC_R |= 0b01;
        SYSCTL_RCGCGPIO_R |= 0x2;
        timer_waitMillis(500);
        GPIO_PORTB_AFSEL_R |= 0x10;
        GPIO_PORTB_DEN_R &= ~0x10;
        GPIO_PORTB_DIR_R &= ~0x10;

        GPIO_PORTB_AMSEL_R |= 0x10;

        //ADC init
        ADC0_ACTSS_R &= ~0x1;
        ADC0_EMUX_R &= ~ADC_EMUX_EM0_PROCESSOR;//~0x00F0; //clear

        //ADC0_IM_R |= 0x02;

        ADC0_SSMUX0_R &= ~0x000F;     //clear
        ADC0_SSMUX0_R |= 0xA;
        ADC0_SSCTL0_R = 0x6;
        ADC0_IM_R &= ~0x1;
        //initialize analog input AIN10
        //ADC0_SSMUX0_R |= 0x0000000A;
        //Setting the first sample
        ADC0_SAC_R = 0x4;
        ADC0_ACTSS_R |= 0x1;



    }

    int adc_read(void){
        //initiate ADCPSSI
        ADC0_PSSI_R |= 0x1;
        //need a while loop to check the wait for the conversation, also need to return a value
        while ((ADC0_RIS_R & 0x01) == 0 ){

        }
        //use the adcfifo as a result
        return ADC0_SSFIFO0_R & 0xFFF;
    }




