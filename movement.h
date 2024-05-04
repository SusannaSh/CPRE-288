/*
 * movement.h
 *
 *  Created on: Feb 1, 2024
 *      Author: seshenou
 */

#ifndef MOVEMENT_H_
#define MOVEMENT_H_
#include "open_interface.h"


char move_forward (double distance_mm, oi_t*sensor);

/*void turn_right(oi_t *sensor, double degrees);

void turn_left(oi_t *sensor, double degrees);*/

void turn(double degrees, oi_t *sensor);

void bumpRight(oi_t*sensor);

void bumpLeft(oi_t*sensor);

void moveBack(int mm, oi_t*sensor);

void cliffLeft(oi_t*sensor);

void cliffRight(oi_t*sensor);

void frontCliffLeft(oi_t*sensor);

void frontCliffRight(oi_t*sensor);

#endif /* MOVEMENT_H_ */
