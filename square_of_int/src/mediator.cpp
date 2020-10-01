#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <sstream>
#include <boost/bind.hpp>

void processCallback(ros::NodeHandle &n, const std_msgs::Int32::ConstPtr& msg)
{
  ROS_INFO("Squaring the number: [%d]", msg->data*msg->data);

  ros::Publisher pub = n.advertise<std_msgs::Int32>("chatter", 1000);
  ros::Rate loop_rate(10);
  ros::spinOnce();

  int count = 0;
  while (ros::ok())
  {
    std_msgs::Int32 msg;
    ROS_INFO("%d", msg.data*msg.data);
    pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "mediator");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe<std_msgs::Int32>("process", 1000, boost::bind(&processCallback, boost::ref(n), _1));
  ros::spin();

  return 0;
}
