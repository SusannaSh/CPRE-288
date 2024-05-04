#include "Timer.h"
#include "lcd.h"
#include "movement.h"
#include "uart-interrupt.h"
#include "Timer.h"
#include "cyBot_Scan.h"
#include "music.h"
#include "servo.h"
#include "ping_template.h"



int main(void) {

        oi_t *sensor_data = oi_alloc();

        oi_init(sensor_data);


        init_servo();
        //servo_cal();


        char letter; //initialize scan command


        char data[100];
        char str[100];

        int i;
        float totalDis;
        float totalDeg;


        timer_init();
        lcd_init();
        cyBOT_init_Scan(0b0111);
        uart_interrupt_init();

        int calc = 0;
        // cyBOT_SERVO_cal();

        right_calibration_value = 269500;
          left_calibration_value = 1267000;


        load_music(FFVII);
        load_music(DRIFT1);
        load_music(DRIFT2);
        load_music(DRIFT3);


        oi_play_song(DRIFT1);
        timer_waitMillis(2880);
        oi_play_song(DRIFT2);

        letter = uart_receive();
        if (letter == 'm' || letter == 'M') //initialize the scan
        {
            sprintf(data, "angle\t\tPing distance \t\t calibrated Distance\r\n");


                uart_sendStr(data);



            for (i = 0; i <= 180; i += 2) // scans the distance from the scanner and assigns it to the arrayData[]
            {
                float distance = 0;
                move_servo(i);
                distance += ping_getDistance(); // get the distance
                distance += ping_getDistance(); // get the distance
                distance += ping_getDistance(); // get the distance
                distance /= 3;

                //calc = ((3.0 * (pow(10, 7))) * (pow(distance, -1.934)))+3;
                calc = distance;

                sprintf(str, "%d, %d \n\r", i,  calc);


                    uart_sendStr(str); // print to cybot


            }

        }

        char letter2;
        int checked = 0;

        int parked = 0;

        while(!parked)
        {
            letter2 = uart_receive_nonblocking();

            if (letter2 == 'w' || letter2 == 'W')
            {
                letter2 = move_forward(10, sensor_data);
                totalDis += sensor_data->distance / 5;
                sprintf(str, "Distance: %.2f\n\r", totalDis);
                uart_sendStr(str);

            }
            else if (letter2 == 's' || letter2 == 'S')
            {

                moveBack(10, sensor_data);
                totalDis += sensor_data->distance / 5;
                sprintf(str, "Distance: %.2f\n\r", totalDis);
                uart_sendStr(str);

            }
            else if (letter2 == 'a' || letter2 == 'A')
            {
                turn(1, sensor_data);
                totalDeg += (sensor_data->angle * 90 / 85);
                sprintf(str, "Angle: %f\n\r", totalDeg);
                uart_sendStr(str);


            }
            else if (letter2 == 'd' || letter2 == 'D')
            {

                turn(-1, sensor_data);
                totalDeg += (sensor_data->angle  * 90 / 85);

                sprintf(str, "Angle: %f\n\r", totalDeg);
                uart_sendStr(str);


            }
            else if ((letter2 == 'm' || letter2 == 'M') && !checked)
            {
                for (i = 0; i <= 180; i += 2) // scans the distance from the scanner and assigns it to the arrayData[]
                {
                    totalDis = 0;

                    checked = 1;
                    float distance = 0;
                    move_servo(i);
                                    distance += ping_getDistance(); // get the distance
                                    distance += ping_getDistance(); // get the distance
                                    distance += ping_getDistance(); // get the distance
                                    distance /= 3;

                                    //calc = ((3.0 * (pow(10, 7))) * (pow(distance, -1.934)))+3;
                                    calc = distance - 4;

                                    sprintf(str, "%d, %d \n\r", i,  calc);



                    uart_sendStr(str); // print to cybot
                }



            }
            else if ((letter2 == 'n' || letter2 == 'N') && !checked) {

                for (i = 80; i <= 120; i += 2) // scans the distance from the scanner and assigns it to the arrayData[]
                {
                    totalDis = 0;

                    checked = 1;
                    float distance = 0;
                    move_servo(i);
                                    distance += ping_getDistance(); // get the distance
                                    distance += ping_getDistance(); // get the distance
                                    distance += ping_getDistance(); // get the distance
                                    distance /= 3;

                                    //calc = ((3.0 * (pow(10, 7))) * (pow(distance, -1.934)))+3;
                                    calc = distance - 4;

                                    sprintf(str, "%d, %d \n\r", i,  calc);



                        uart_sendStr(str); // print to cybot
                }
            }
            else if (letter2 == 'c' || letter2 == 'C') {

                parked = 1;

            }
            else if (letter2 == ' ' )
            {
                totalDeg = 0;
                totalDis = 0;
            }
            else if(letter2 == 'h')
            {
                oi_play_song(DRIFT3);
            }
            else
                letter2 = ' ';
                checked = 0;





       }
       oi_play_song(FFVII);
       lcd_printf("You Have Arrived");
}


