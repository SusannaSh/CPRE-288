

#include "Timer.h"
#include "lcd.h"
#include "open_interface.h"
#include "movement.h"
#include "uart-interrupt.h"
#include "cyBot_Scan.h"
#include "string.h"
#include "stdio.h"
#include <math.h>


int array[180];
int ang[10];
float dist[10];
float widths[10];
/*int object = 0;
int midPoint = 0;*/


void doScan();
void findSmallestObject(oi_t *sensor_data);




    void adc_init(void){

        //GPIO init
        SYSCTL_RCGCGPIO_R |= 0x2;
        SYSCTL_RCGCADC_R |= 0b01;
        GPIO_PORTB_DEN_R &= ~0x10;
    //    GPIO_PORTB_DIR_R |= 0x10;
        GPIO_PORTB_AFSEL_R |= 0x10;
        GPIO_PORTB_AMSEL_R |= 0x10;

        //ADC init
        ADC0_ACTSS_R &= ~0x02;
        ADC0_EMUX_R &= ~0x00F0; //clear
        //ADC0_IM_R |= 0x02;
        ADC0_SSCTL1_R = 0x06;
        ADC0_SSMUX1_R &= ~0x000F;     //clear

        //initialize analog input AIN10
        ADC0_SSMUX1_R |= 0x0000000A;
        //Setting the first sample
        ADC0_ACTSS_R |= 0x02;



    }

    int adc_read(void){
        //initiate ADCPSSI
        ADC0_PSSI_R |= 0x02;
        //need a while loop to check the wait for the conversation, also need to return a value
        while ((ADC0_RIS_R & 0x02) ==0 ){

        }
        //use the adcfifo as a result
        return (int)ADC0_SSFIFO1_R;
    }




