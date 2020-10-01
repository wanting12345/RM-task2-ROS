#include"ros/ros.h"
#include"std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("recieve: [%s]",msg->data.c_str());
}

int main(int argc,char **argv)
{
    ros::init(argc,argv,"node2");
    ros::NodeHandle m;
    ros::Subscriber sub=m.subscribe("message",1000,chatterCallback);
    ros::spin();
    return 0;
}