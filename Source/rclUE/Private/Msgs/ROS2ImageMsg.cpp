// Copyright 2021 Rapyuta Robotics Co., Ltd.
// This code has been autogenerated from sensor_msgs/Image.msg - do not modify

#include "Msgs/ROS2ImageMsg.h"

#include "Kismet/GameplayStatics.h"

void UROS2ImageMsg::Init()
{
	sensor_msgs__msg__Image__init(&image_msg);
}

void UROS2ImageMsg::Fini()
{
	// prevent the fini function from trying to deallocate the buffer
	image_msg.data.data = nullptr;
	image_msg.data.size = 0;
	image_msg.data.capacity = 0;
	sensor_msgs__msg__Image__fini(&image_msg);
}

const rosidl_message_type_support_t* UROS2ImageMsg::GetTypeSupport() const
{
	return ROSIDL_GET_MSG_TYPE_SUPPORT(sensor_msgs, msg, Image);
}

void UROS2ImageMsg::SetMsg(const FROSImage& Inputs)
{
    Inputs.SetROS2(image_msg);
}

void UROS2ImageMsg::GetMsg(FROSImage& Outputs) const
{
    Outputs.SetFromROS2(image_msg);
}

void* UROS2ImageMsg::Get()
{
	return &image_msg;
}

FString UROS2ImageMsg::MsgToString() const
{
    /* TODO: Fill here */
	checkNoEntry();
	return FString();
}