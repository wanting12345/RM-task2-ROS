/***********接收端**********/
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sstream"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "node1"); //初始化節點
    ros::NodeHandle n;
    //消息發送頻率爲10hz，消息池最大容量爲1000
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("message", 1000);
    ros::Rate loop_rate(10);
    while (ros::ok())
    {
        std_msgs::String msg; //初始化消息
        std::stringstream ss;
        ss << "hello word!";
        msg.data = ss.str();
        //發布消息
        chatter_pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}