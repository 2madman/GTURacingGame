// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Platform.generated.h"

UCLASS()
class MYPROJECT_API ACPP_Platform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_Platform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//virtual void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor) override;
	
	int minutes;
	int seconds;
	FTimerHandle TimerHandle;

};
