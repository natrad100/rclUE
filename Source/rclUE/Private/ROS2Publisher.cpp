// Copyright 2020-2021 Rapyuta Robotics Co., Ltd.

#include "ROS2Publisher.h"
#include "ROS2Support.h"

#include <Engine/World.h>
#include <TimerManager.h>

#include "ROS2Subsystem.h"

DEFINE_LOG_CATEGORY(LogROS2Publisher);

UROS2Publisher::UROS2Publisher()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UROS2Publisher::Init()
{
    UE_LOG(LogROS2Publisher, Verbose, TEXT("[%s] Initialising"), *GetName());

    check(ROSNode != nullptr);
    check(ROSNode->State == UROS2State::Initialized);

    if (State == UROS2State::Created)
    {
        if(TopicName.IsEmpty())
        {
            UE_LOG(LogROS2Publisher, Error, TEXT("[%s] Topic name not set. Initialisation failed."), *GetName());
            return;
        }

        if(TopicType == nullptr)
        {
            UE_LOG(LogROS2Publisher, Error, TEXT("[%s] Topic Type not set. Initialisation failed."), *GetName());
            return;
        }

        TopicMessage = NewObject<UROS2GenericMsg>(this, TopicType);
        check(IsValid(TopicMessage));
        TopicMessage->Init();

        UE_LOG(LogROS2Publisher, Display, TEXT("[%s] Creating topic %s"), *GetName(), *TopicName);
        RclPublisher = rcl_get_zero_initialized_publisher();
        
        rcl_publisher_options_t pub_opt = rcl_publisher_get_default_options();
        pub_opt.allocator = ROSNode->ROSSubsystem()->GetRclUEAllocator();
        
        if (bQosOverride) {
            pub_opt.qos = BuildQoSProfile(QosHistoryPolicy, QosDepth, QosReliabilityPolicy, QosDurabilityPolicy);
        } else {
            pub_opt.qos = QoSProfiles_LUT[QosProfilePreset];
        }

        RCSOFTCHECK(rcl_publisher_init(&RclPublisher, ROSNode->GetRCLNode(), TopicMessage->GetTypeSupport(), TCHAR_TO_UTF8(*TopicName), &pub_opt));

        if (bPublishOnTimer) {
            GetWorld()->GetTimerManager().SetTimer(
                TimerHandle, this, &UROS2Publisher::UpdateAndPublishMessage, 1.f / PublicationFrequencyHz, true);
        }

        State = UROS2State::Initialized;
    }
}

void UROS2Publisher::Destroy()
{
    UE_LOG(LogROS2Publisher, Verbose, TEXT("Publisher Destroy Start (%s)"), *__LOG_INFO__);
    if (TopicMessage != nullptr)
    {
        TopicMessage->Fini();
    }

    if (ROSNode != nullptr)
    {
        UE_LOG(LogROS2Publisher, Verbose, TEXT("Publisher Destroy - rcl_publisher_fini (%s)"), *__LOG_INFO__);
        RCSOFTCHECK(rcl_publisher_fini(&RclPublisher, ROSNode->GetRCLNode()));
    }
    UE_LOG(LogROS2Publisher, Display, TEXT("[%s] Publisher destroyed"), *GetName());
}

void UROS2Publisher::UpdateAndPublishMessage()
{
    check(State == UROS2State::Initialized);
    check(IsValid(ROSNode));
    
    {
        FScopeLock Lock(&Mutex);
        UpdateMessage(TopicMessage);
    }
    
    if(bPublish)
    {
        Publish();
    }
}

void UROS2Publisher::Publish()
{
    check(State == UROS2State::Initialized);
    check(ROSNode != nullptr);
    
    {
        FScopeLock Lock(&Mutex);
        PublishedMsg = TopicMessage->Get();
        RCSOFTCHECK(rcl_publish(&RclPublisher, PublishedMsg, nullptr));
    }
}
