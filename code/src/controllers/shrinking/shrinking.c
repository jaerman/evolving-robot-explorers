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

   //Test Stuff
   WbNodeRef test;
   test = wb_supervisor_node_get_from_def("geometryTest");
   //wb_supervisor_node_remove(test);
   
   // do this once only
   WbFieldRef trans_field = wb_supervisor_node_get_field(test, "size");

   while (1)
    {
      const double *trans = wb_supervisor_field_get_sf_vec3f(trans_field);
      double test1 = trans[1]-0.01; 
      double test2[3] = {1,test1,0.25};
      wb_supervisor_field_set_sf_vec3f(trans_field,test2);
      printf("%g sdfsdfds \n",trans[1]);
      //check if size is zero
      wb_robot_step(32);
    }
      
   wb_robot_cleanup();
   return 0;
}
