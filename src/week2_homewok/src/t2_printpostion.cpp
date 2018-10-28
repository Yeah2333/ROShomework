#include <ros/ros.h>
#include <turtlesim/Spawn.h>
#include <turtlesim/Pose.h>
#include <geometry_msgs/Twist.h>
 

void TurtleOutputCallback(const turtlesim::PoseConstPtr msg)
{
    ROS_INFO("Turtle2 postion: (%f,%f)",msg->x,msg->y);
}

int main(int argc ,char **argv){
    //Inital Ros node
    ros::init(argc,argv,"TurtleOut");
    //create node handle
    ros::NodeHandle node;

    ros::Subscriber sub = node.subscribe("/turtle2/pose",10,&TurtleOutputCallback); //订阅姿态
   
    ros::spin(); //
    return 0;
}