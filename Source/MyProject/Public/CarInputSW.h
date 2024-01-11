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

#include "CarInputSW.generated.h"

struct SensorData {
    double angle;
    double brake;
    double gas;
};

UCLASS()
class MYPROJECT_API ACarInputSW : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ACarInputSW();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    float last_angle = 0;
    float last_gas = 0;
    float last_brake = 0;

    UFUNCTION(BlueprintCallable, Category = "BoranCategory")
    void PrintSomething();

    UFUNCTION(BlueprintCallable, Category = "BoranCategory")
    float getBrake();

    UFUNCTION(BlueprintCallable, Category = "BoranCategory")
    float getGas();

    UFUNCTION(BlueprintCallable, Category = "BoranCategory")
    float getAngle();

    UFUNCTION(BlueprintCallable, Category = "BoranCategory")
    float getAngleMapped();

    float map(float min_x, float max_x, float x, float a, float b);

    SensorData* s_data_shared;

#if defined(_WIN32) || defined(_WIN64)
    HANDLE hMapFile;
#elif defined(_linux_)
    int shm_fd;
#endif

    void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
