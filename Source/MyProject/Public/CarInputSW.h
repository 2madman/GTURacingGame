// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <iostream>
#include <Windows.h>
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
	float last_gas = 955;
	float last_brake = 1025;


	UFUNCTION(BlueprintCallable, Category = "BoranCategory")
	void PrintSomething();

	UFUNCTION(BlueprintCallable, Category = "BoranCategory")
	float getBrake();

	UFUNCTION(BlueprintCallable, Category = "BoranCategory")
	float getGas();

	UFUNCTION(BlueprintCallable, Category = "BoranCategory")
	float getAngle();

	float map(float min_x, float max_x, float x, float a, float b);

	SensorData* s_data_shared;

	HANDLE hMapFile;

	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

};

