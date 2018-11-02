#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include "week2_homework/postionAction.h" //自定义的action文件文件名后要跟Action

typedef actionlib::SimpleActionServer<week2_homework::postionAction> Server;
//ros的action使用时会分成goal feedback等
//收到action的goal后调用该函数
void execute(const week2_homework::postionGoalConstPtr& goal,Server* as) //目标
{
    ros::Rate r(1);
    week2_homework::postionFeedback feedback;

    ROS_INFO("Now move to x: %f  y: %f",goal->x,goal->y);

    //行走的速度，按照1hz发布进度feedback
    for (int i=0; i <=10; i++)
    {
        feedback.percent = i*10;
        as->publishFeedback(feedback);
        r.sleep();
        
    }

    //当action完成后，向客户段发布完成
    ROS_INFO("Postion x: %f y: %f Move complete!",goal->x,goal->y);
    as->setSucceeded();
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "move_server");
    ros::NodeHandle node;//初始化

    //定义一个服务器
    Server server(node,"move",boost::bind(&execute, _1, &server), false);

    //服务器开始运行
    server.start();
    //等待
    ros::spin();

    return 0;
}