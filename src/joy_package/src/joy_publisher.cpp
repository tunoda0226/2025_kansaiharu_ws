#include "joy_package/joy_publisher.hpp"

JoyPublisher::JoyPublisher()
    : Node("joy_publisher")
{
    publisher_ = this->create_publisher<std_msgs::msg::String>("joy_data", 10);
    subscription_ = this->create_subscription<sensor_msgs::msg::Joy>(
        "joy", 10, std::bind(&JoyPublisher::joy_callback, this, std::placeholders::_1));
}

void JoyPublisher::joy_callback(const sensor_msgs::msg::Joy::SharedPtr msg)
{
    std::stringstream ss;
    ss << "Axes: [";
    for (size_t i = 0; i < msg->axes.size(); ++i)
    {
        ss << msg->axes[i];
        if (i < msg->axes.size() - 1)
            ss << ", ";
    }
    ss << "], Buttons: [";
    for (size_t i = 0; i < msg->buttons.size(); ++i)
    {
        ss << msg->buttons[i];
        if (i < msg->buttons.size() - 1)
            ss << ", ";
    }
    ss << "]";

    auto message = std_msgs::msg::String();
    message.data = ss.str();
    publisher_->publish(message);

    RCLCPP_INFO(this->get_logger(), "Published: %s", message.data.c_str());
}

