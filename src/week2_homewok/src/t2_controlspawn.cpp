#include <ros/ros.h>
#include <turtlesim/Spawn.h> //类似于自己写的msgs
#include <turtlesim/Pose.h>
#include <geometry_msgs/Twist.h>
 


int main(int argc ,char **argv){
    //Inital Ros node
    ros::init(argc,argv,"TurtleOut");
    //create node handle
    ros::NodeHandle node;

    //通过服务调用，产生第二只海龟turtle2
    ros::service::waitForService("spawn");
    ros::ServiceClient new_turtle = node.serviceClient<turtlesim::Spawn>("spawn"); //创建一个客户但，请求的服务为spawn，仿真起提供
    turtlesim::Spawn srv;
    srv.request.x = 5;//postion
    srv.request.y = 5;
    srv.response.name = "turtle2"; 
    new_turtle.call(srv); //call接口来调用请求服务

    ROS_INFO("Turtle2 has been spawn!"); 


    //定义速度发布控制器
    ros::Publisher turtle_vel = node.advertise<geometry_msgs::Twist>("turtle2/cmd_vel", 10); //声明了一个发布者
    
    ros::Rate rate(10.0);

    while (node.ok())
    {
        geometry_msgs::Twist vel_msg;
        vel_msg.angular.z = 1;
        vel_msg.linear.x = 1;
        turtle_vel.publish(vel_msg);

        ros::spinOnce();
        rate.sleep();
        
    }
    return 0;
}