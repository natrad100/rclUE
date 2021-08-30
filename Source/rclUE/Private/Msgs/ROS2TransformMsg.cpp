// Copyright 2021 Rapyuta Robotics Co., Ltd.
// This code has been autogenerated from geometry_msgs/Transform.msg - do not modify

#include "Msgs/ROS2TransformMsg.h"

#include "Kismet/GameplayStatics.h"

void UROS2TransformMsg::Init()
{
	geometry_msgs__msg__Transform__init(&transform_msg);
}

void UROS2TransformMsg::Fini()
{
	geometry_msgs__msg__Transform__fini(&transform_msg);
}

const rosidl_message_type_support_t* UROS2TransformMsg::GetTypeSupport() const
{
	return ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Transform);
}

void UROS2TransformMsg::SetMsg(const FROSTransform& Inputs)
{
    Inputs.SetROS2(transform_msg);
}

void UROS2TransformMsg::GetMsg(FROSTransform& Outputs) const
{
    Outputs.SetFromROS2(transform_msg);
}

void* UROS2TransformMsg::Get()
{
	return &transform_msg;
}

FString UROS2TransformMsg::MsgToString() const
{
    /* TODO: Fill here */
	checkNoEntry();
	return FString();
}