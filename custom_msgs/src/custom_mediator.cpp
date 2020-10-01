#include "ros/ros.h"
#include "custom_msgs/Employee.h"
#include <sstream>
#include <boost/bind.hpp>

ros::NodeHandle* n;
ros::Publisher pub;

void processCallback(const custom_msgs::Employee::ConstPtr& msg)
{
  ROS_INFO("Reducing base by 30%: [%d]", 0.7*(msg->base));
  custom_msgs::Employee msg2;
  msg2.base = msg->base*0.7;
  pub = n->advertise<custom_msgs::Employee>("custom_chatter", 1000);
  pub.publish(msg2);
  ros::spinOnce(); 
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "custom_mediator");
  n = new ros::NodeHandle;
  ros::Subscriber sub = n->subscribe<custom_msgs::Employee>("custom_process", 1000, processCallback);
  ros::spin();

  return 0;
}
