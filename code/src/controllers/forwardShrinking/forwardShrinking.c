/*

 */

#include <webots/robot.h>
#include <webots/motor.h>
#include <webots/camera.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define TIME_STEP 32

int main(int argc, char **argv)
{
  // init webots stuff
  wb_robot_init();

  WbDeviceTag front_left_wheel  = wb_robot_get_device("front_left_wheel");
  WbDeviceTag front_right_wheel = wb_robot_get_device("front_right_wheel");
  WbDeviceTag back_left_wheel   = wb_robot_get_device("back_left_wheel");
  WbDeviceTag back_right_wheel  = wb_robot_get_device("back_right_wheel");

  int count = 0;

  // init motors
  wb_motor_set_position(front_left_wheel, INFINITY);
  wb_motor_set_position(front_right_wheel,INFINITY);
  wb_motor_set_position(back_left_wheel,  INFINITY);
  wb_motor_set_position(back_right_wheel, INFINITY);
  
  // init speed for each wheel
  double back_left_speed  = 3.0, back_right_speed  = 3.0;
  double front_left_speed = 3.0, front_right_speed = 3.0;
  wb_motor_set_velocity(front_left_wheel,  front_left_speed);
  wb_motor_set_velocity(front_right_wheel, front_right_speed);
  wb_motor_set_velocity(back_left_wheel,   back_left_speed);
  wb_motor_set_velocity(back_right_wheel,  back_right_speed);
    
  // control loop
  while (wb_robot_step(TIME_STEP) != -1 && count < 32*5) { 

    // set actuators
    wb_motor_set_velocity(front_left_wheel,  front_left_speed);
    wb_motor_set_velocity(front_right_wheel, front_right_speed);
    wb_motor_set_velocity(back_left_wheel,   back_left_speed);
    wb_motor_set_velocity(back_right_wheel,  back_right_speed);
    
    
    count = count+1;
   }

  wb_motor_set_velocity(front_left_wheel,  0);
  wb_motor_set_velocity(front_right_wheel, 0);
  wb_motor_set_velocity(back_left_wheel,   0);
  wb_motor_set_velocity(back_right_wheel,  0);
  wb_robot_cleanup();
  
  return 0;
}
