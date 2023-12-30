#include <ros/ros.h>
#include <bluerov_control/bluerov_subs.hpp>
#include <geometry_msgs/TwistStamped.h>
#include <Eigen/Dense>

std::list<float> wavepoints = {
    {1, 0, 0},
    {3, 0, 0},
    {5, 0, 0},
    {5, 0, -1},
    {5, 0, -3},
    {5, 0, -5}
    {5, 3, -5},
    {5, 6, -5},
    {5, 9, -5},
};

float tol = 0.1

void lqr(){
    x(t) = A*x(t) + B*u(t)
    y(t) = C*x(t) + D*u(t)

    J(x,u)=∫[xTQx+uTRu]dt 
    //integrated from 0 to infinity


}

void ricatti_eqn(){
    (AT)P+PA−PB(R−1)(BT)P+Q=0
    K=(R−1)(BT)P
    u= -Kx 
}
int main(int argc, char **argv) {
    ros::init(argc, argv, "subscriber");
    ros::NodeHandle nh;
    ros::Rate rate(1);
    ros::Publisher twistPub = nh.advertise<geometry_msgs::TwistStamped>("/mavros/setpoint_velocity/cmd_vel", 1);

    Subscriber sub(nh);        
    
    sub.connect();
    
    

    while(ros::ok()){
        
        // step 2 - move to guided mode & arm throttle
        sub.guided_armed();

        geometry_msgs::TwistStamped twistMsg;
        twistMsg.twist.linear.x = 0.0;  
        twistMsg.twist.linear.y = 0.0;  
        twistMsg.twist.linear.z = 0.0;  

        twistPub.publish(twistMsg);
        ros::spinOnce();
        rate.sleep();
    }
}