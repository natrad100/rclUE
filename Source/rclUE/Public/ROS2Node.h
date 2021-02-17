// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Containers/Map.h"

#include "ROS2Context.h"
#include "ROS2Topic.h"

#include "ROS2Node.generated.h"

/**
 * ROS2 Node that additionally acts as a factory for Publishers, Subscribers, Clients, Services
 */
UCLASS(Blueprintable)
class RCLUE_API AROS2Node : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AROS2Node();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
public:
	UFUNCTION(BlueprintCallable)
	void Init();

	UFUNCTION(BlueprintCallable)
	FName GetName() const;
	
	UFUNCTION(BlueprintCallable)
	FName GetNamespace() const;

	rcl_node_t* GetNode();

	UFUNCTION(BlueprintCallable)
	void SetName(FName NodeName);

	UFUNCTION(BlueprintCallable)
	void SetNamespace(FName NodeNamespace);

	UFUNCTION(BlueprintCallable)
	void Subscribe(FName TopicName, TSubclassOf<UROS2GenericMsg> MsgClass);

	UPROPERTY(EditAnywhere)
	FName Name = TEXT("node");
	
	UPROPERTY(EditAnywhere)
	FName Namespace = TEXT("ros_global");

	UPROPERTY(EditAnywhere)
	int NSubscriptions = 0;

	UPROPERTY(VisibleAnywhere)
	int NGuardConditions = 0;

	UPROPERTY(VisibleAnywhere)
	int NTimers = 0;

	UPROPERTY(VisibleAnywhere)
	int NClients = 0;

	UPROPERTY(VisibleAnywhere)
	int NServices = 0;

	UPROPERTY(VisibleAnywhere)
	int NEvents = 0;

private:
	UFUNCTION()
	UROS2Context* GetContext();

	UFUNCTION() // uint64 is apparently not supported by BP - might need some changes here
	void SpinSome(const uint64 timeout_ns);

	UPROPERTY(VisibleAnywhere)
	UROS2Context* context;

	rcl_node_t node;
	
	TMap<UROS2Topic*, rcl_subscription_t> subs; // map topic to sub to avoid double subs
	
	rcl_wait_set_t wait_set;
};
