#ifndef JOY_PACKAGE_JOY_PUBLISHER_HPP_
#define JOY_PACKAGE_JOY_PUBLISHER_HPP_

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include "std_msgs/msg/string.hpp"

class JoyPublisher : public rclcpp::Node
{
public:
    JoyPublisher();

private:
    void joy_callback(const sensor_msgs::msg::Joy::SharedPtr msg);

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr subscription_;
};

#endif  // JOY_PACKAGE_JOY_PUBLISHER_HPP_

