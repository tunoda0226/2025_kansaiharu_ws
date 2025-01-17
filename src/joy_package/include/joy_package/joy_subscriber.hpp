#ifndef JOY_PACKAGE_JOY_SUBSCRIBER_HPP_
#define JOY_PACKAGE_JOY_SUBSCRIBER_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class JoySubscriber : public rclcpp::Node
{
public:
    JoySubscriber();

private:
    void joy_callback(const std_msgs::msg::String::SharedPtr msg);

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

#endif  // JOY_PACKAGE_JOY_SUBSCRIBER_HPP_

