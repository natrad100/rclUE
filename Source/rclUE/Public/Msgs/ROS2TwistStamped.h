#pragma once

#include <CoreMinimal.h>
#include "Conversions.h"
#include "ROS2GenericMsg.h"

#include "geometry_msgs/msg/twist_stamped.h"


// Include directives for member types
#include "Msgs/ROS2Header.h"
#include "Msgs/ROS2Twist.h"

#include "ROS2TwistStamped.generated.h"


USTRUCT(Blueprintable)
struct RCLUE_API FROSTwistStamped
{
    GENERATED_BODY()

    using ros_msg_c_typename = geometry_msgs__msg__TwistStamped;

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FROSHeader header;
    // rclc type: std_msgs__msg__Header header

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FROSTwist twist;
    // rclc type: geometry_msgs__msg__Twist twist

    void SetFromROS2(const ros_msg_c_typename& in_ros_data)
    {
        header.SetFromROS2(in_ros_data.header);
        twist.SetFromROS2(in_ros_data.twist);
    }

    void SetROS2(ros_msg_c_typename& out_ros_data) const
    {
        header.SetROS2(out_ros_data.header);
        twist.SetROS2(out_ros_data.twist);
    }
};

UCLASS()
class RCLUE_API UROS2TwistStamped : public UROS2GenericMsg
{
    GENERATED_BODY()

    using ros_msg_c_typename = geometry_msgs__msg__TwistStamped;

public:
    virtual void Init() override
    {
        geometry_msgs__msg__TwistStamped__init(&twist_stamped_msg);
    }

    virtual void Fini() override
    {
        geometry_msgs__msg__TwistStamped__fini(&twist_stamped_msg);
    }

    virtual const rosidl_message_type_support_t* GetTypeSupport() const override
    {
        return ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, TwistStamped);
    }

    UFUNCTION(BlueprintCallable)
    void SetMsg(const FROSTwistStamped& Input)
    {
        Input.SetROS2(twist_stamped_msg);
    }

    UFUNCTION(BlueprintCallable)
    void GetMsg(FROSTwistStamped& Output) const
    {
        Output.SetFromROS2(twist_stamped_msg);
    }

    virtual void* Get() override
    {
        return &twist_stamped_msg;
    }

private:
    virtual FString ToString() const override
    {
        /* TODO: Fill here */

        checkNoEntry();
        return FString();
    }

    ros_msg_c_typename twist_stamped_msg;
};