// Copyright 2021 Rapyuta Robotics Co., Ltd.
// This code has been autogenerated from ue4_interfaces/Fibonacci.action - do not modify

#pragma once

#include "CoreMinimal.h"

#include "unique_identifier_msgs/msg/uuid.h"
#include "ue4_interfaces/action/fibonacci.h"
#include "action_msgs/srv/cancel_goal.h"

#include "Actions/ROS2GenericAction.h"
#include "rclcUtilities.h"

#include "ROS2FibonacciAction.generated.h"

USTRUCT(Blueprintable)
struct RCLUE_API FROSFibonacci_SendGoal_Request
{
	GENERATED_BODY()

public:
  	TArray<uint, TFixedAllocator<16>> goal_id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int order;

	

	void SetFromROS2(const ue4_interfaces__action__Fibonacci_SendGoal_Request& in_ros_data)
	{
		for (int i=0; i<16; i++)
		{
			goal_id[i] = in_ros_data.goal_id.uuid[i];
		}

    	order = in_ros_data.goal.order;

		
	}

	void SetROS2(ue4_interfaces__action__Fibonacci_SendGoal_Request& out_ros_data) const
	{
		for (int i=0; i<16; i++)
		{
			out_ros_data.goal_id.uuid[i] = goal_id[i];
		}

    	out_ros_data.goal.order = order;

		
	}
};

USTRUCT(Blueprintable)
struct RCLUE_API FROSFibonacci_SendGoal_Response
{
	GENERATED_BODY()

public:
	bool accepted;
	int stamp_sec;
	uint stamp_nanosec;

	void SetFromROS2(const ue4_interfaces__action__Fibonacci_SendGoal_Response& in_ros_data)
	{
    	accepted = in_ros_data.accepted;
		stamp_sec = in_ros_data.stamp.sec;
		stamp_nanosec = in_ros_data.stamp.nanosec;
	}

	void SetROS2(ue4_interfaces__action__Fibonacci_SendGoal_Response& out_ros_data) const
	{
    	out_ros_data.accepted = accepted;
		out_ros_data.stamp.sec = stamp_sec;
		out_ros_data.stamp.nanosec = stamp_nanosec;
	}
};

USTRUCT(Blueprintable)
struct RCLUE_API FROSFibonacci_GetResult_Request
{
	GENERATED_BODY()

public:
  	TArray<uint, TFixedAllocator<16>> goal_id;

	void SetFromROS2(const ue4_interfaces__action__Fibonacci_GetResult_Request& in_ros_data)
	{
		for (int i=0; i<16; i++)
		{
			goal_id[i] = in_ros_data.goal_id.uuid[i];
		}

	}

	void SetROS2(ue4_interfaces__action__Fibonacci_GetResult_Request& out_ros_data) const
	{
		for (int i=0; i<16; i++)
		{
			out_ros_data.goal_id.uuid[i] = goal_id[i];
		}
	}
};

USTRUCT(Blueprintable)
struct RCLUE_API FROSFibonacci_GetResult_Response
{
	GENERATED_BODY()

public:
	int8 status;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> sequence;

	

	void SetFromROS2(const ue4_interfaces__action__Fibonacci_GetResult_Response& in_ros_data)
	{
		status = in_ros_data.status;
    	for (int i = 0; i < in_ros_data.result.sequence.size; i++)
		{
			sequence[i] = in_ros_data.result.sequence.data[i];
		}

		
	}

	void SetROS2(ue4_interfaces__action__Fibonacci_GetResult_Response& out_ros_data) const
	{
		out_ros_data.status = status;
    	if (out_ros_data.result.sequence.data != nullptr)
		{
			free(out_ros_data.result.sequence.data);
		}
		out_ros_data.result.sequence.data = (decltype(out_ros_data.result.sequence.data))malloc((sequence.Num())*sizeof(decltype(*out_ros_data.result.sequence.data)));
		
		for (int i = 0; i < sequence.Num(); i++)
		{
			out_ros_data.result.sequence.data[i] = sequence[i];
		}

		out_ros_data.result.sequence.size = sequence.Num();
		out_ros_data.result.sequence.capacity = sequence.Num();

		
	}
};

USTRUCT(Blueprintable)
struct RCLUE_API FROSFibonacci_FeedbackMessage
{
	GENERATED_BODY()

public:
  	TArray<uint, TFixedAllocator<16>> goal_id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> partial_sequence;

	

	void SetFromROS2(const ue4_interfaces__action__Fibonacci_FeedbackMessage& in_ros_data)
	{
		for (int i=0; i<16; i++)
		{
			goal_id[i] = in_ros_data.goal_id.uuid[i];
		}

    	for (int i = 0; i < in_ros_data.feedback.partial_sequence.size; i++)
		{
			partial_sequence[i] = in_ros_data.feedback.partial_sequence.data[i];
		}

		
	}

	void SetROS2(ue4_interfaces__action__Fibonacci_FeedbackMessage& out_ros_data) const
	{
		for (int i=0; i<16; i++)
		{
			out_ros_data.goal_id.uuid[i] = goal_id[i];
		}
		
    	if (out_ros_data.feedback.partial_sequence.data != nullptr)
		{
			free(out_ros_data.feedback.partial_sequence.data);
		}
		out_ros_data.feedback.partial_sequence.data = (decltype(out_ros_data.feedback.partial_sequence.data))malloc((partial_sequence.Num())*sizeof(decltype(*out_ros_data.feedback.partial_sequence.data)));
		
		for (int i = 0; i < partial_sequence.Num(); i++)
		{
			out_ros_data.feedback.partial_sequence.data[i] = partial_sequence[i];
		}

		out_ros_data.feedback.partial_sequence.size = partial_sequence.Num();
		out_ros_data.feedback.partial_sequence.capacity = partial_sequence.Num();

		
	}
};

UCLASS()
class RCLUE_API UROS2FibonacciAction : public UROS2GenericAction
{
	GENERATED_BODY()
	
public:
	virtual void Init() override;

	virtual void Fini() override;

	virtual const rosidl_action_type_support_t* GetTypeSupport() const override;

  	UFUNCTION(BlueprintCallable)
	void SetGoalRequest(const FROSFibonacci_SendGoal_Request& Goal);

  	UFUNCTION(BlueprintCallable)
	void GetGoalRequest(FROSFibonacci_SendGoal_Request& Goal) const;
	
  	UFUNCTION(BlueprintCallable)
	void SetGoalResponse(const FROSFibonacci_SendGoal_Response& Goal);

  	UFUNCTION(BlueprintCallable)
	void GetGoalResponse(FROSFibonacci_SendGoal_Response& Goal) const;
	
  	UFUNCTION(BlueprintCallable)
	void SetResultRequest(const FROSFibonacci_GetResult_Request& Result);

  	UFUNCTION(BlueprintCallable)
	void GetResultRequest(FROSFibonacci_GetResult_Request& Result) const;
	
  	UFUNCTION(BlueprintCallable)
	void SetResultResponse(const FROSFibonacci_GetResult_Response& Result);

  	UFUNCTION(BlueprintCallable)
	void GetResultResponse(FROSFibonacci_GetResult_Response& Result) const;



  	UFUNCTION(BlueprintCallable)
	void SetFeedback(const FROSFibonacci_FeedbackMessage& Feedback);

  	UFUNCTION(BlueprintCallable)
	void GetFeedback(FROSFibonacci_FeedbackMessage& Feedback) const;
	
	virtual void* GetGoalRequest() override;
	virtual void* GetGoalResponse() override;
	virtual void* GetResultRequest() override;
	virtual void* GetResultResponse() override;
	virtual void* GetFeedbackMessage() override;

private:
	ue4_interfaces__action__Fibonacci_SendGoal_Request Fibonacci_goal_request;
	ue4_interfaces__action__Fibonacci_SendGoal_Response Fibonacci_goal_response;
	ue4_interfaces__action__Fibonacci_GetResult_Request Fibonacci_result_request;
	ue4_interfaces__action__Fibonacci_GetResult_Response Fibonacci_result_response;
	ue4_interfaces__action__Fibonacci_FeedbackMessage Fibonacci_feedback_message;
};