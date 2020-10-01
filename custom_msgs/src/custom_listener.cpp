#include "ros/ros.h"
#include "custom_msgs/Employee.h"

void chatterCallback(const custom_msgs::Employee::ConstPtr& msg)
{
  ROS_INFO("Name is: [%s]", msg->name);
  ROS_INFO("CTC is: [%d]", msg->ctc);
  ROS_INFO("Reduced base pay is: [%d]", msg->base);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "custom_listener");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("custom_chatter", 1000, chatterCallback);
  ros::spin();

  return 0;
}
