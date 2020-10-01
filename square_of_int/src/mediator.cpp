#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <sstream>
#include <boost/bind.hpp>

ros::NodeHandle* n;
ros::Publisher pub;

void processCallback(const std_msgs::Int32::ConstPtr& msg)
{
  ROS_INFO("Squaring the number: [%d]", msg->data*msg->data);
  std_msgs::Int32 msg2;
  msg2.data = msg->data*msg->data;
  pub = n->advertise<std_msgs::Int32>("chatter", 1000);
  pub.publish(msg2);
  ros::spinOnce(); 
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "mediator");
  n = new ros::NodeHandle;
  ros::Subscriber sub = n->subscribe<std_msgs::Int32>("process", 1000, processCallback);
  ros::spin();

  return 0;
}
