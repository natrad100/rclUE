// Copyright 2021 Rapyuta Robotics Co., Ltd.
// This code has been autogenerated from geometry_msgs/Vector3.msg - do not modify

#pragma once

#include "CoreMinimal.h"

#include "geometry_msgs/msg/vector3.h"

#include "Msgs/ROS2GenericMsg.h"
#include "rclcUtilities.h"

#include "ROS2Vector3Msg.generated.h"

USTRUCT(Blueprintable)
struct RCLUE_API FROSVector3
{
	GENERATED_BODY()

public:
	double x;

	double y;

	double z;

	

	void SetFromROS2(const geometry_msgs__msg__Vector3& in_ros_data)
	{
    	x = in_ros_data.x;

		y = in_ros_data.y;

		z = in_ros_data.z;

		
	}

	void SetROS2(geometry_msgs__msg__Vector3& out_ros_data) const
	{
    	out_ros_data.x = x;

		out_ros_data.y = y;

		out_ros_data.z = z;

		
	}
};

UCLASS()
class RCLUE_API UROS2Vector3Msg : public UROS2GenericMsg
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	virtual void Fini() override;

	virtual const rosidl_message_type_support_t* GetTypeSupport() const override;
	
  	UFUNCTION(BlueprintCallable)
	void SetMsg(const FROSVector3& Input);
	
  	UFUNCTION(BlueprintCallable)
	void GetMsg(FROSVector3& Output) const;
	
	virtual void* Get() override;

private:
	virtual FString MsgToString() const override;

	geometry_msgs__msg__Vector3 vector3_msg;
};