#include <ros/ros.h>
#include <std_msgs/Float64.h>

ros::Publisher *pubPtrrf;
ros::Publisher *pubPtrrm;
ros::Publisher *pubPtrrr;

void commandReceivedrf(
 const std_msgs::Float64& msgIn
){
 std_msgs::Float64 msgOut;
 msgOut.data = -msgIn.data;
 pubPtrrf->publish(msgOut);
}

void commandReceivedrm(
 const std_msgs::Float64& msgIn
){
 std_msgs::Float64 msgOut;
 msgOut.data = -msgIn.data;
 pubPtrrm->publish(msgOut);
}

void commandReceivedrr(
 const std_msgs::Float64& msgIn
){
 std_msgs::Float64 msgOut;
 msgOut.data = -msgIn.data;
 pubPtrrr->publish(msgOut);
}


int main(int argc, char **argv){
 ros::init(argc, argv, "left_to_right");
 ros::NodeHandle nh;

  pubPtrrf  = new ros::Publisher(
  nh.advertise<std_msgs::Float64>(
  "antmodel/joint2_rf_position_controller/command",
  1000));
    pubPtrrm  = new ros::Publisher(
  nh.advertise<std_msgs::Float64>(
  "antmodel/joint2_rm_position_controller/command",
  1000));
      pubPtrrr  = new ros::Publisher(
  nh.advertise<std_msgs::Float64>(
  "antmodel/joint2_rr_position_controller/command",
  1000));
  
  
 ros::Subscriber subrf = nh.subscribe(
  "antmodel/joint2_rf_position_controller/command_right", 1000,
  &commandReceivedrf);
   ros::Subscriber subrm = nh.subscribe(
  "antmodel/joint2_rm_position_controller/command_right", 1000,
  &commandReceivedrm);
     ros::Subscriber subrr = nh.subscribe(
  "antmodel/joint2_rr_position_controller/command_right", 1000,
  &commandReceivedrr);

ros::spin();


delete pubPtrrf;
delete pubPtrrm;
delete pubPtrrr;

} 
