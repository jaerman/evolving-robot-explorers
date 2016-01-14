/*
TODO: Change the code in that way that if the robot found a local minima
the supervisor will start removing nodes under the robot

Nodes to be removed should be smaller than the robot (robot is drilling)
After drilling is done: release some robot which searches for life
in the water
 */
#include <webots/supervisor.h>
#include <webots/robot.h>
#include <math.h>
#include <stdio.h>


int main(int argc, char **argv)
{
  wb_robot_init();
  //Find Node:
  
  
   //Test Stuff
   WbNodeRef test;
   WbNodeRef test2;
   test = wb_supervisor_node_get_from_def("Test-1-2-1");
   test2 = wb_supervisor_node_get_from_def("Test-1-1-1");
   
   //get position of the nodes
     // wb_supervisor_node_get_position()
     //
   //get position of robot
   
   wb_supervisor_node_remove(test);   
   wb_supervisor_node_remove(test2);
   
   wb_robot_step(32);
      
   wb_robot_cleanup();
   return 0;
}
