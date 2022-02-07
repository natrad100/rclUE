// Copyright 2021 Rapyuta Robotics Co., Ltd.
// This code has been autogenerated from example_interfaces/SetBool.srv - do not modify

#pragma once

#include <CoreMinimal.h>

#include "Srvs/ROS2GenericSrv.h"
#include "rclcUtilities.h"
#include "example_interfaces/srv/set_bool.h"

#include "ROS2SetBoolSrv.generated.h"

// potential problem: if this struct is defined multiple times!
USTRUCT(Blueprintable)
struct RCLUE_API FROSSetBool_Request
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool data;

	

	void SetFromROS2(const example_interfaces__srv__SetBool_Request& in_ros_data)
	{
    	data = in_ros_data.data;

		
	}

	void SetROS2(example_interfaces__srv__SetBool_Request& out_ros_data) const
	{
    	out_ros_data.data = data;

		
	}
};

USTRUCT(Blueprintable)
struct RCLUE_API FROSSetBool_Response
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool success;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString message;

	

	void SetFromROS2(const example_interfaces__srv__SetBool_Response& in_ros_data)
	{
    	success = in_ros_data.success;

		message.AppendChars(in_ros_data.message.data, in_ros_data.message.size);

		
	}

	void SetROS2(example_interfaces__srv__SetBool_Response& out_ros_data) const
	{
    	out_ros_data.success = success;

		{
			FTCHARToUTF8 strUtf8( *message );
			int32 strLength = strUtf8.Length();
			if (out_ros_data.message.data != nullptr)
		{
			free(out_ros_data.message.data);
		}
		out_ros_data.message.data = (decltype(out_ros_data.message.data))malloc((strLength+1)*sizeof(decltype(*out_ros_data.message.data)));
		memcpy(out_ros_data.message.data, TCHAR_TO_UTF8(*message), (strLength+1)*sizeof(char));
			out_ros_data.message.size = strLength;
			out_ros_data.message.capacity = strLength + 1;
		}

		
	}
};

UCLASS()
class RCLUE_API UROS2SetBoolSrv : public UROS2GenericSrv
{
	GENERATED_BODY()

public:
  	UFUNCTION(BlueprintCallable)
	virtual void Init() override;

  	UFUNCTION(BlueprintCallable)
	virtual void Fini() override;

	virtual const rosidl_service_type_support_t* GetTypeSupport() const override;
	
	// used by client
  	UFUNCTION(BlueprintCallable)
	void SetRequest(const FROSSetBool_Request& Request);
	
	// used by service
  	UFUNCTION(BlueprintCallable)
	void GetRequest(FROSSetBool_Request& Request) const;
	
	// used by service
  	UFUNCTION(BlueprintCallable)
	void SetResponse(const FROSSetBool_Response& Response);
	
	// used by client
  	UFUNCTION(BlueprintCallable)
	void GetResponse(FROSSetBool_Response& Response) const;
	
	virtual void* GetRequest() override;
	virtual void* GetResponse() override;

private:
	virtual FString SrvRequestToString() const override;
	virtual FString SrvResponseToString() const override;

	example_interfaces__srv__SetBool_Request SetBool_req;
	example_interfaces__srv__SetBool_Response SetBool_res;
};