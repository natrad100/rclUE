// Copyright 2021 Rapyuta Robotics Co., Ltd.
// This code has been autogenerated from sensor_msgs/PointCloud2.msg - do not modify

#pragma once

#include <CoreMinimal.h>

#include "sensor_msgs/msg/point_cloud2.h"

#include "Msgs/ROS2GenericMsg.h"
#include "rclcUtilities.h"

#include "ROS2PointCloud2Msg.generated.h"

USTRUCT(Blueprintable)
struct RCLUE_API FROSPointCloud2
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int header_stamp_sec;

	unsigned int header_stamp_nanosec;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString header_frame_id;

	unsigned int height;

	unsigned int width;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> fields_name;

	TArray<unsigned int> fields_offset;

	TArray<uint8> fields_datatype;

	TArray<unsigned int> fields_count;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool is_bigendian;

	unsigned int point_step;

	unsigned int row_step;

	TArray<uint8> data;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool is_dense;

	

	void SetFromROS2(const sensor_msgs__msg__PointCloud2& in_ros_data)
	{
    	header_stamp_sec = in_ros_data.header.stamp.sec;

		header_stamp_nanosec = in_ros_data.header.stamp.nanosec;

		header_frame_id.AppendChars(in_ros_data.header.frame_id.data, in_ros_data.header.frame_id.size);

		height = in_ros_data.height;

		width = in_ros_data.width;

		for (int i = 0; i < in_ros_data.fields.size; i++)
		{
			fields_name[i].AppendChars(in_ros_data.fields.data[i].name.data,in_ros_data.fields.data[i].name.size);
		}

		for (int i = 0; i < in_ros_data.fields.size; i++)
		{
			fields_offset[i] = in_ros_data.fields.data[i].offset;
		}

		for (int i = 0; i < in_ros_data.fields.size; i++)
		{
			fields_datatype[i] = in_ros_data.fields.data[i].datatype;
		}

		for (int i = 0; i < in_ros_data.fields.size; i++)
		{
			fields_count[i] = in_ros_data.fields.data[i].count;
		}

		is_bigendian = in_ros_data.is_bigendian;

		point_step = in_ros_data.point_step;

		row_step = in_ros_data.row_step;

		for (int i = 0; i < in_ros_data.data.size; i++)
		{
			data[i] = in_ros_data.data.data[i];
		}

		is_dense = in_ros_data.is_dense;

		
	}

	void SetROS2(sensor_msgs__msg__PointCloud2& out_ros_data) const
	{
    	out_ros_data.header.stamp.sec = header_stamp_sec;

		out_ros_data.header.stamp.nanosec = header_stamp_nanosec;

		{
			FTCHARToUTF8 strUtf8( *header_frame_id );
			int32 strLength = strUtf8.Length();
			if (out_ros_data.header.frame_id.data != nullptr)
		{
			free(out_ros_data.header.frame_id.data);
		}
		out_ros_data.header.frame_id.data = (decltype(out_ros_data.header.frame_id.data))malloc((strLength+1)*sizeof(decltype(*out_ros_data.header.frame_id.data)));
		memcpy(out_ros_data.header.frame_id.data, TCHAR_TO_UTF8(*header_frame_id), (strLength+1)*sizeof(char));
			out_ros_data.header.frame_id.size = strLength;
			out_ros_data.header.frame_id.capacity = strLength + 1;
		}

		out_ros_data.height = height;

		out_ros_data.width = width;

		if (out_ros_data.fields.data != nullptr)
		{
			free(out_ros_data.fields.data);
		}
		out_ros_data.fields.data = (decltype(out_ros_data.fields.data))malloc(fields_name.Num() * (sizeof(fields_name) + sizeof(fields_offset) + sizeof(fields_datatype) + sizeof(fields_count)));
		out_ros_data.fields.size = fields_name.Num();
		out_ros_data.fields.capacity = fields_name.Num();
		for (int i = 0; i < fields_name.Num(); i++)
		{
			{
				FTCHARToUTF8 strUtf8( *fields_name[i] );
			int32 strLength = strUtf8.Length();
				out_ros_data.fields.data[i].name.data = (decltype(out_ros_data.fields.data[i].name.data))malloc((strLength+1)*sizeof(decltype(*out_ros_data.fields.data[i].name.data)));
		memcpy(out_ros_data.fields.data[i].name.data, TCHAR_TO_UTF8(*fields_name[i]), (strLength+1)*sizeof(char));
				out_ros_data.fields.data[i].name.size = strLength;
				out_ros_data.fields.data[i].name.capacity = strLength + 1;
			}

			out_ros_data.fields.data[i].offset = fields_offset[i];

			out_ros_data.fields.data[i].datatype = fields_datatype[i];

			out_ros_data.fields.data[i].count = fields_count[i];

			}
	out_ros_data.is_bigendian = is_bigendian;

		out_ros_data.point_step = point_step;

		out_ros_data.row_step = row_step;

		if (out_ros_data.data.data != nullptr)
		{
			free(out_ros_data.data.data);
		}
		out_ros_data.data.data = (decltype(out_ros_data.data.data))malloc((data.Num())*sizeof(decltype(*out_ros_data.data.data)));
		
		for (int i = 0; i < data.Num(); i++)
		{
			out_ros_data.data.data[i] = data[i];
		}

		out_ros_data.data.size = data.Num();
		out_ros_data.data.capacity = data.Num();

		out_ros_data.is_dense = is_dense;

		
	}
};

UCLASS()
class RCLUE_API UROS2PointCloud2Msg : public UROS2GenericMsg
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	virtual void Fini() override;

	virtual const rosidl_message_type_support_t* GetTypeSupport() const override;
	
  	UFUNCTION(BlueprintCallable)
	void SetMsg(const FROSPointCloud2& Input);
	
  	UFUNCTION(BlueprintCallable)
	void GetMsg(FROSPointCloud2& Output) const;
	
	virtual void* Get() override;

private:
	virtual FString MsgToString() const override;

	sensor_msgs__msg__PointCloud2 point_cloud2_msg;
};