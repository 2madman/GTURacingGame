// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#if defined(_WIN32) || defined(_WIN64)
#include <Windows.h>
#elif defined(_linux_)
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#endif

#include "SendVibrationSystem.generated.h"

struct VibData {
    bool isActive;
};

UCLASS()
class MYPROJECT_API ASendVibrationSystem : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ASendVibrationSystem();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

#if defined(_WIN32) || defined(_WIN64)
    HANDLE hMapFile;
#elif defined(_linux_)
    // Linux-specific variables if needed
#endif

    VibData* s_data_shared;

    UFUNCTION(BlueprintCallable, Category = "BoranCategory")
    void Vibrate();

    void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
