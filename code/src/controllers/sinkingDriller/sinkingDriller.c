/*

 */
#include <webots/supervisor.h>
#include <webots/robot.h>
#include <math.h>
#include <stdio.h>


int main(int argc, char **argv)
{
	wb_robot_init();

	//Block Shrinking Init Stuff
	WbNodeRef shrinkBlock;
	shrinkBlock = wb_supervisor_node_get_from_def("geometryTest");
	WbFieldRef size_field = wb_supervisor_node_get_field(shrinkBlock, "size");
	
	//Driller resizing Init stuff
	//double heightValue = 0;
	//WbNodeRef drillerNode;
	//drillerNode = wb_supervisor_node_get_from_def("drillerGeometry");
	//WbFieldRef height_field = wb_supervisor_node_get_field(drillerNode, "height");
	
	//Driller sinking stuff
	WbNodeRef drillerTransNode;
	drillerTransNode = wb_supervisor_node_get_from_def("Driller");
	WbFieldRef trans_field = wb_supervisor_node_get_field(drillerTransNode, "translation");
	
	int testcounter = 0;
	
	//Wait the time the robot needs to arrive at the spot
	int count = 0;
	while (count < 32*5) {
		wb_robot_step(32);    
		count = count+1;
	}
	while (1)
    {	
		//for shrinking the block
		const double *size = wb_supervisor_field_get_sf_vec3f(size_field);
		double ySize = size[1]-0.01; 
		double sizeArray[3] = {size[0],ySize,size[2]};
		//check if size is zero
		if(ySize <= 0.1){
			break;
		}
		//for resizing the driller
		//double height = wb_supervisor_field_get_sf_float(height_field);
		
		//if(height < 0.2){
		//	heightValue = height+0.01;
		//}
		//for sinking the driller if the block is sinking
		const double *trans = wb_supervisor_field_get_sf_vec3f(trans_field);
		if(testcounter > 30){
			double ytranslation = trans[1]-0.005;
			double transArray[3] = {trans[0],ytranslation,trans[2]};
			wb_supervisor_field_set_sf_vec3f(trans_field,transArray);
		}

		
		//setting the values for driller and block
		wb_supervisor_field_set_sf_vec3f(size_field,sizeArray);
		//wb_supervisor_field_set_sf_float(height_field,heightValue);
		
		
		testcounter = testcounter+1;
		
		wb_robot_step(32);
    }    
	wb_supervisor_node_remove(shrinkBlock);
	wb_robot_cleanup();
	return 0;
}
