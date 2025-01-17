#include "joy_package/joy_subscriber.hpp"

JoySubscriber::JoySubscriber()
    : Node("joy_subscriber")
{
    subscription_ = this->create_subscription<std_msgs::msg::String>(
        "joy_data", 10, std::bind(&JoySubscriber::joy_callback, this, std::placeholders::_1));
}

void JoySubscriber::joy_callback(const std_msgs::msg::String::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "Received: %s", msg->data.c_str());
}

