#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include "week2_homework/postionAction.h"//ROS_INFO 不是 ROS：：info！！！1

typedef actionlib::SimpleActionClient<week2_homework::postionAction> Client;

//action完成后调用一次这个函数
void doneCb(const actionlib::SimpleClientGoalState& state,
        const week2_homework::postionResultConstPtr& result)
{
    ROS_INFO("Move Complete!");
    ros::shutdown();
}

//当action激活后会掉用该会掉函数一次
void activeCb()
{
    ROS_INFO("Start move to postion!");
}

//收到feedback后调用该函数
void feedbackCb(const week2_homework::postionFeedbackConstPtr& feedback)
{
    ROS_INFO(" percent move : %f ",feedback->percent);
}


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "move_client");
    
    Client client("move",true);

    ROS_INFO("Waiting fo action server to start.");
    client.waitForServer();
    ROS_INFO("Action server started,sending goal.");

    week2_homework::postionGoal goal;
    goal.x = 2.00;
    goal.y = 3.00;

    client.sendGoal(goal,&doneCb,&activeCb,&feedbackCb);

    ros::spin();

    return 0;
}
