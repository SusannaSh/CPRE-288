#ifndef SERVO_H_
#define SERVO_H_

#include "Timer.h"
#include <inc/tm4c123gh6pm.h>
#include "button.h"
#include "lcd.h"

extern volatile int calibration;
extern volatile int cal_factor;

//Initializes the servo motors
void init_servo();


//Moves the servos
void move_servo(float degree);


/*
 * Calibrates the servo by moving it to the leftmost desired position.
 * We only need to calibrate the left most side because the cal_factor
 * will compensate for both directions.
 *
 */
void servo_cal();

#endif /* SERVO_H_ */
