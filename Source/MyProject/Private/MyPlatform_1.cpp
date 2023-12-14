// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlatform_1.h"
// #include "../../../../../../Epic Games/UE_5.2/Engine/Plugins/Media/BlackmagicMedia/Source/BlackmagicCore/Public/BlackmagicLib.h"
#include "TimerManager.h"

// Sets default values
AMyPlatform_1::AMyPlatform_1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
// Called every frame
void AMyPlatform_1::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    Seconds++;

    if (Seconds >= 60)
    {
        Seconds = 0;
        Minutes++;
    }

}

// Called when the game starts or when spawned
void AMyPlatform_1::BeginPlay()
{

    Super::BeginPlay();

    // Set a timer to call the CheckSeconds function every second
    // GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, 1.0f, true);

}


