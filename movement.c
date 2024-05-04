/*
 * movement.c
 *
 *  Created on: Feb 1, 2024
 *      Author: seshenou
 */

#include "open_interface.h"
#include "lcd.h"
#include "Timer.h"
#include "movement.h"
#include "uart-interrupt.h"



/*void turn_right(oi_t *sensor, double degrees);
void turn_left(oi_t *sensor, double degrees);*/


char move_forward (double distance_mm, oi_t*sensor){
    oi_setWheels(100, 100);
    double sum1 = 0;
    char hold = 'w';
    while (sum1 < distance_mm){
        oi_update(sensor);
        sum1 += sensor -> distance; // use -> notation since pointer
        lcd_printf("%d", sensor->cliffLeftSignal);
        if (sensor->bumpLeft) {
            bumpLeft(sensor);
            sum1 = distance_mm;
            hold = ' ';


       }


        else if (sensor->bumpRight) {
               bumpRight(sensor);
               sum1 = distance_mm;
               hold = ' ';
          }
        else if (sensor->cliffLeftSignal > 2600 || sensor->cliffLeftSignal < 700) {
                     cliffLeft(sensor);

                     sum1 = distance_mm;
                                hold = ' ';
                        lcd_printf("%f", sensor->cliffLeft);
                }

                else if (sensor->cliffFrontLeftSignal > 2600 || sensor->cliffFrontLeftSignal < 700) {
                        frontCliffLeft(sensor);

                        sum1 = distance_mm;
                                   hold = ' ';
                   }
                else if (sensor->cliffFrontRightSignal > 2600 || sensor->cliffFrontRightSignal < 700) {
                            frontCliffRight(sensor);

                            sum1 = distance_mm;
                                       hold = ' ';
                        }
                else if (sensor->cliffRightSignal > 2600 || sensor->cliffRightSignal < 700) {
                            cliffRight(sensor);

                            sum1 = distance_mm;
                                       hold = ' ';
                        }


}
    oi_setWheels(0,0);
    return hold;
}



void moveBack(int mm, oi_t*sensor){

    oi_setWheels(0,0); // stop
    double amount = 0;
    oi_setWheels(-250, -250);
    while(amount<mm){

        oi_update(sensor);
        amount -= sensor ->distance;
    }
    oi_setWheels(0,0);
}

/*void turn_right(oi_t *sensor, double degrees){
    oi_setWheels(-250, 250);
    double sum3 = 0;

    while(sum3 < fabs(degrees - 10)){// sum3 < abs(degrees)
        oi_update(sensor);
        sum3 += fabs(sensor -> angle); // use -> notation since pointer || -=

    }
    oi_setWheels(0,0);
}

void turn_left(oi_t *sensor, double degrees){
    oi_setWheels(250, -250);
      double sum2 = 0;

      while(sum2 < degrees-10){
          oi_update(sensor);
          sum2 += fabs(sensor -> angle); // use -> notation since pointer
          }
      oi_setWheels(0,0);

}*/
void turn(double degrees, oi_t *sensor) {
    double tempDegrees = 0;
    if(degrees >= 0) { //Turns left if degrees is positive
       oi_setWheels(50,-50);
       while(degrees >= tempDegrees) {
           oi_update(sensor);
           tempDegrees += sensor -> angle; //Adds sensor angle to tempDegrees
       }
    } else { //Turns right if degrees is negative
        oi_setWheels(-50, 50);
        while(degrees <= tempDegrees) {
            oi_update(sensor);
            tempDegrees += sensor -> angle; //Adds sensor angle to tempDegrees
        }
    }
    oi_setWheels(0,0); //Stops Roomba
}

void bumpLeft(oi_t*sensor){
    moveBack(150, sensor);
    char str[20];
    sprintf(str, "LeftBumper\n\r");
    uart_sendStr(str);

}

void bumpRight(oi_t*sensor){
    moveBack(150, sensor);
    char str[20];
    sprintf(str, "RightBumper\n\r");
    uart_sendStr(str);

}

void cliffLeft(oi_t*sensor){
    if(sensor->cliffLeftSignal > 2600)
                         {
                             uart_sendStr("White Boarder\n\r");
                         }
    moveBack(150, sensor);
    char str[20];
    sprintf(str, "LeftCliff\n\r");
    uart_sendStr(str);

}

void cliffRight(oi_t*sensor){
    if(sensor->cliffRightSignal > 2600)
                                                   {
                                                       uart_sendStr("White Boarder\n\r");
                                                   }
    moveBack(150, sensor);
    char str[20];
    sprintf(str, "RightCliff\n\r");
    uart_sendStr(str);

}

void frontCliffLeft(oi_t*sensor){
    if(sensor->cliffFrontLeftSignal > 2600)
                                                {
                                                    uart_sendStr("White Boarder\n\r");
                                                }
    moveBack(150, sensor);
    char str[20];
    sprintf(str, "FrontLeftCliff\n\r");
    uart_sendStr(str);

}

void frontCliffRight(oi_t*sensor){
    if(sensor->cliffFrontRightSignal > 2600)
                                                    {
                                                        uart_sendStr("White Boarder\n\r");
                                                    }
    moveBack(150, sensor);
    char str[20];
    sprintf(str, "FrontRightCliff\n\r");
    uart_sendStr(str);

}







