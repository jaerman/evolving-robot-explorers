/*
 * Description:
 Example showing how to use wb_supervisor_node_get_from_def
 to remove a node
 frame
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
   test = wb_supervisor_node_get_from_def("SOLID");
   wb_supervisor_node_remove(test);
      
   wb_robot_cleanup();
   return 0;
}
