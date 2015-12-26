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
   //wb_supervisor_node_remove(test);
   
   // do this once only
   WbNodeRef robot_node = wb_supervisor_node_get_from_def("MY_ROBOT");
   WbFieldRef trans_field = wb_supervisor_node_get_field(robot_node, "translation");
   WbFieldRef trans_solid = wb_supervisor_node_get_field(test, "translation");
   while (1) {
   // this is done repeatedly
   const double *trans = wb_supervisor_field_get_sf_vec3f(trans_field);
   const double *solid = wb_supervisor_field_get_sf_vec3f(trans_solid);
   
   double diffx = trans[0] - solid[0];
   double diffy = trans[1] - solid[1];
   double diffz = trans[2] - solid[2];
   double diffx_sqr = diffx*diffx;
   double diffy_sqr = diffy*diffy;
   double diffz_sqr = diffz*diffz;
   double distance = sqrt (diffx_sqr + diffy_sqr + diffz_sqr);   

    printf("Abstand: %g\n", distance);
    if(distance < 0.2){
      wb_supervisor_node_remove(test);
      break;
    }
    wb_robot_step(32);
   }
      
   wb_robot_cleanup();
   return 0;
}
