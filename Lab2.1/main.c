

/**
 * main.c
 */
#include "open_interface.h"
#include "movement.h"

void main()
{



oi_t *sensor = oi_alloc();
oi_init(sensor);

      /* turn_right(sensor, 90);
       turn_left(sensor, 90);*/
  move_forward(sensor, 2000);



}
