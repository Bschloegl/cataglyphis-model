#include <ros/ros.h>
#include <std_msgs/Float64.h>

ros::Publisher *pubPtr1;
ros::Publisher *pubPtr2;
ros::Publisher *pubPtr3;

void commandReceived1(
 const std_msgs::Float64& msgIn
){
 std_msgs::Float64 msgOut;
 msgOut.data = (2*3.1415)-msgIn.data;
 pubPtr1->publish(msgOut);
}
void commandReceived2(
 const std_msgs::Float64& msgIn
){
 std_msgs::Float64 msgOut;
 msgOut.data =  msgIn.data;
 pubPtr2->publish(msgOut);
}
void commandReceived3(
 const std_msgs::Float64& msgIn
){
 std_msgs::Float64 msgOut;
 msgOut.data =  msgIn.data;
 pubPtr3->publish(msgOut);
}

int main(int argc, char **argv){
 ros::init(argc, argv, "left_to_right");
 ros::NodeHandle nh;

 pubPtr1 = new ros::Publisher(
  nh.advertise<std_msgs::Float64>(
  "antmodel/joint1_rf_position_controller/command",
  1000));
   pubPtr2 = new ros::Publisher(
  nh.advertise<std_msgs::Float64>(
  "antmodel/joint2_rf_position_controller/command",
  1000));
     pubPtr3 = new ros::Publisher(
  nh.advertise<std_msgs::Float64>(
  "antmodel/joint3_rf_position_controller/command",
  1000));

 ros::Subscriber sub1 = nh.subscribe(
  "antmodel/joint1_rf_position_controller/command_right", 1000,
  &commandReceived1);
   ros::Subscriber sub2 = nh.subscribe(
  "antmodel/joint2_rf_position_controller/command_right", 1000,
  &commandReceived2);
     ros::Subscriber sub3 = nh.subscribe(
  "antmodel/joint3_rf_position_controller/command_right", 1000,
  &commandReceived3);


ros::spin();

delete pubPtr1;
delete pubPtr2;
delete pubPtr3;
} 
