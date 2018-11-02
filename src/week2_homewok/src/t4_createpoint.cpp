/*本程序将会发布一个laserpoint点。
*
*/
#include <ros/ros.h>
#include <week2_homework/laserpoint.h>

int main(int argc, char **argv)
{
    //ROS初始化
    ros::init(argc,argv,"createpoint");
    ros::NodeHandle node;

    //创建一个消息发布器，消息名称/laser_link/point，消息类型laserpoint
    ros::Publisher pub = node.advertise<week2_homework::laserpoint>("/base_laser/point",10);
    //设置循环的频率
    ros::Rate loop_rate(10);

    int count = 0;
    while (ros::ok())
    {
        //创建一个消息
        week2_homework::laserpoint point;
        point.x = 0.3;
        point.y = 0.0;
        point.z = 0.0;
        
        //发布消息
        pub.publish(point);
        
        //回调函数
        ros::spinOnce();
        
        //按照循环频率延时
        loop_rate.sleep();
        ++count;
    }
    return 0;
}