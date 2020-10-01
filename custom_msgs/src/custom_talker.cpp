#include "ros/ros.h"
#include "custom_msgs/Employee.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "custom_talker");

  ros::NodeHandle n;
  ros::Publisher process_pub = n.advertise<custom_msgs::Employee>("custom_process", 1000);

  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {
    custom_msgs::Employee msg;
    
    std::stringstream ss;
    ss << "Amlan Sahoo" << count;
    msg.name = ss.str();
    msg.ctc = 900000;
    msg.base = 750000;

    ROS_INFO("%s", msg.name);
    ROS_INFO("%d", msg.ctc);
    ROS_INFO("%d", msg.base);
    process_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }

  return 0;
}
