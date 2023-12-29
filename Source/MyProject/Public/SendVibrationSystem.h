// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <winsock2.h>
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

	HANDLE hMapFile;

	VibData* s_data_shared;

	UFUNCTION(BlueprintCallable, Category = "BoranCategory")
		void Vibrate();

	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};