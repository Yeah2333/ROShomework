#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <week2_homework/laserpoint.h>

void pointCallback(const week2_homework::laserpointConstPtr& msg)
{
    //tf广播器
    static tf::TransformBroadcaster br;

    //从base_laser到base_link的  平移变换
    
    tf::Quaternion q;
    q.setRPY(0,0,0);  //通过y p r构建四元数  旋转变换
    tf::Transform transform(q,tf::Vector3(0.1,0,0.2)); //调用构造函数 quaternion，vector3
    //发布坐标转换   一个话题的名字，另一个话题的名字，好像不需要制定到特定话题
    br.sendTransform(tf::StampedTransform(transform,ros::Time::now(),"base_laser","base_link"));
}

int main(int argc,char** argv)
{
    //初始化
    ros::init(argc, argv, "t4_tfbroadcaster");
    ros::NodeHandle node;
    ros::Subscriber sub = node.subscribe("base_laser/point",10,&pointCallback);//和chatter的区别是只修改了回调函数

    ros::spin();

    return 0;
}