#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <week2_homework/laserpoint.h>
double a,b,c;

void laserpointCallback(const week2_homework::laserpointPtr &msg)
{
    a = msg->x;
    b = msg->y;
    c = msg->z;
}
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "tflistener");
    ros::NodeHandle node;
    ros::Publisher pub = node.advertise<week2_homework::laserpoint>("/base_link/point",10);
    ros::Subscriber sub = node.subscribe("/base_laser/point",10,&laserpointCallback);

    tf::TransformListener listener;

    ros::Rate rate(10.0);

    while(node.ok())
    {
        tf::StampedTransform transform;
        try
        {
            listener.waitForTransform("/base_laser","/base_link",ros::Time(0),ros::Duration(3.0));
            listener.lookupTransform("/base_laser","/base_link",ros::Time(0),transform);

        }
        catch (tf::TransformException &ex)
        {
            ROS_ERROR("%s",ex.what());
            ros::Duration(1.0).sleep();
            continue;
        }
        ros::spinOnce();
        week2_homework::laserpoint point;
        point.x = a + transform.getOrigin().x();
        point.y = b + transform.getOrigin().y();
        point.z = c + transform.getOrigin().z();
        ROS_INFO("base_laser: %f %f %f -------> base_link: %f %f %f ",a,b,c,point.x,point.y,point.z);
        pub.publish(point);

        rate.sleep();

    }

    return 0;
}