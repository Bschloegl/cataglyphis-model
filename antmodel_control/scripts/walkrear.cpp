#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include "std_msgs/String.h"
#include <iostream>
#include <fstream>

#include <sstream>
using namespace std;

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   * For programmatic remappings you can use a different version of init() which takes
   * remappings directly, but for most command-line programs, passing argc and argv is
   * the easiest way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
  ros::init(argc, argv, "talker");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle n;

  /**
   * The advertise() function is how you tell ROS that you want to
   * publish on a given topic name. This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing. After this advertise() call is made, the master
   * node will notify anyone who is trying to subscribe to this topic name,
   * and they will in turn negotiate a peer-to-peer connection with this
   * node.  advertise() returns a Publisher object which allows you to
   * publish messages on that topic through a call to publish().  Once
   * all copies of the returned Publisher object are destroyed, the topic
   * will be automatically unadvertised.
   *
   * The second parameter to advertise() is the size of the message queue
   * used for publishing messages.  If messages are published more quickly
   * than we can send them, the number here specifies how many messages to
   * buffer up before throwing some away.
   */
  ros::Publisher joint1_pub = n.advertise<std_msgs::Float64>("robot_joint1/command", 1000);
  ros::Publisher joint2_pub = n.advertise<std_msgs::Float64>("robot_joint2/command", 1000);
  ros::Publisher joint3_pub = n.advertise<std_msgs::Float64>("robot_joint3/command", 1000);
  ros::Publisher joint4_pub = n.advertise<std_msgs::Float64>("robot_joint4/command", 1000);
  
  ros::Publisher joint1d_pub = n.advertise<std_msgs::Float64>("robot_joint1_delayed/command", 1000);
  ros::Publisher joint2d_pub = n.advertise<std_msgs::Float64>("robot_joint2_delayed/command", 1000);
  ros::Publisher joint3d_pub = n.advertise<std_msgs::Float64>("robot_joint3_delayed/command", 1000);
  ros::Publisher joint4d_pub = n.advertise<std_msgs::Float64>("robot_joint4_delayed/command", 1000);

  ros::Rate loop_rate(10);

  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */

    std_msgs::Float64 msg1;
    std_msgs::Float64 msg2;
    std_msgs::Float64 msg3;
    std_msgs::Float64 msg4;
    
    std_msgs::Float64 msg1d;
    std_msgs::Float64 msg2d;
    std_msgs::Float64 msg3d;
    std_msgs::Float64 msg4d;

   ifstream joint1_delayed;
   ifstream joint2_delayed;
   ifstream joint3_delayed;
   ifstream joint4_delayed;

   ifstream joint1;
   ifstream joint2;
   ifstream joint3;
   ifstream joint4;
   
 // int counter = 0;
  while (ros::ok())
  { 
	 /* ROS_INFO("%i",counter);
	  counter++;*/
   joint1_delayed.open("/home/barbara/Dokumente/Forschen/ROS/Auswertung/current3/joint1_delayed.txt");
   joint2_delayed.open("/home/barbara/Dokumente/Forschen/ROS/Auswertung/current3/joint2_delayed.txt");
   joint3_delayed.open("/home/barbara/Dokumente/Forschen/ROS/Auswertung/current3/joint3_delayed.txt");
   joint4_delayed.open("/home/barbara/Dokumente/Forschen/ROS/Auswertung/current3/joint4_delayed.txt");
   
   joint1.open("/home/barbara/Dokumente/Forschen/ROS/Auswertung/current3/joint1_inphase.txt");
   joint2.open("/home/barbara/Dokumente/Forschen/ROS/Auswertung/current3/joint2_inphase.txt");
   joint3.open("/home/barbara/Dokumente/Forschen/ROS/Auswertung/current3/joint3_inphase.txt");
   joint4.open("/home/barbara/Dokumente/Forschen/ROS/Auswertung/current3/joint4_inphase.txt");

int count = 0;
    while ((joint1 >> msg1.data)
    && (joint2 >> msg2.data)
    && (joint3 >> msg3.data)
    && (joint4 >> msg4.data)
    && (joint1_delayed >> msg1d.data)
    && (joint2_delayed >> msg2d.data)
    && (joint3_delayed >> msg3d.data)
    && (joint4_delayed >> msg4d.data)
     )
    {	 
    joint1_pub.publish(msg1);
    joint2_pub.publish(msg2);
    joint3_pub.publish(msg3);
    joint4_pub.publish(msg4);
    
    joint1d_pub.publish(msg1d);
    joint2d_pub.publish(msg2d);
    joint3d_pub.publish(msg3d);
    joint4d_pub.publish(msg4d);
      
    ros::spinOnce();

    loop_rate.sleep();
    }
    
  joint1.close();
  joint2.close();
  joint3.close();
  joint4.close();
  
  joint1_delayed.close();
  joint2_delayed.close();
  joint3_delayed.close();
  joint4_delayed.close();
	  
  }
  

  return 0;
}
