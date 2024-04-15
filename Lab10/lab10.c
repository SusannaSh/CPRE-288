#include "Timer.h"
#include "lcd.h"
#include "servo.h"

int main(void) {
    timer_init();
    lcd_init();
    servo_init();

    lcd_printf("hello");

    servo_move(0);
    timer_waitMillis(10000);
    servo_move(30);
    timer_waitMillis(10000);
    servo_move(150);
    timer_waitMillis(10000);
    servo_move(90);


}
