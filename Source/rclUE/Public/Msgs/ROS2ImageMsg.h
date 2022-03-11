// Copyright 2021 Rapyuta Robotics Co., Ltd.
// This code has been autogenerated from sensor_msgs/Image.msg - do not modify

#pragma once

#include <vector>

#include <CoreMinimal.h>

#include "sensor_msgs/msg/image.h"

#include "Msgs/ROS2GenericMsg.h"
#include "Msgs/ROS2HeaderMsg.h"
#include "rclcUtilities.h"

#include "ROS2ImageMsg.generated.h"

USTRUCT(Blueprintable)
struct RCLUE_API FROSImage
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FROSHeader header;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int height; // original uint32

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int width; // original uint32

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString encoding;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 is_bigendian; // original uint8

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int step; // original uint32 -- maybe this should be automatically populated

	UPROPERTY(BlueprintReadWrite)
	TArray<uint8> data; // original seq of uint8
	

	void SetFromROS2(const sensor_msgs__msg__Image& in_ros_data)
	{
    	header.SetFromROS2(in_ros_data.header);

		height = in_ros_data.height;

		width = in_ros_data.width;

		encoding.AppendChars(in_ros_data.encoding.data, in_ros_data.encoding.size);

		is_bigendian = in_ros_data.is_bigendian;

		step = in_ros_data.step;

		// TODO
		// for (int i = 0; i < in_ros_data.data.size; i++)
		// {
		// 	data.Add(in_ros_data.data.data[i]);
		// }

		
	}

	void SetROS2(sensor_msgs__msg__Image& out_ros_data) const
	{
    	header.SetROS2(out_ros_data.header);

		out_ros_data.height = height;

		out_ros_data.width = width;

		{
			FTCHARToUTF8 strUtf8( *encoding );
			int32 strLength = strUtf8.Length();
			if (out_ros_data.encoding.data != nullptr)
		{
			free(out_ros_data.encoding.data);
		}
		out_ros_data.encoding.data = (decltype(out_ros_data.encoding.data))malloc((strLength+1)*sizeof(decltype(*out_ros_data.encoding.data)));
		memcpy(out_ros_data.encoding.data, TCHAR_TO_UTF8(*encoding), (strLength+1)*sizeof(char));
			out_ros_data.encoding.size = strLength;
			out_ros_data.encoding.capacity = strLength + 1;
		}

		out_ros_data.is_bigendian = is_bigendian;
		out_ros_data.step = step;
		
		out_ros_data.data.data = const_cast<uint8_t*>(data.GetData());
		out_ros_data.data.size = data.Num();
		out_ros_data.data.capacity = data.Max();
	}
};

UCLASS()
class RCLUE_API UROS2ImageMsg : public UROS2GenericMsg
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	virtual void Fini() override;

	virtual const rosidl_message_type_support_t* GetTypeSupport() const override;
	
  	UFUNCTION(BlueprintCallable)
	void SetMsg(const FROSImage& Input);
	
  	UFUNCTION(BlueprintCallable)
	void GetMsg(FROSImage& Output) const;
	
	virtual void* Get() override;

private:
	virtual FString MsgToString() const override;

	sensor_msgs__msg__Image image_msg;
};