// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Platform.h"
#include "Engine/World.h"


// Sets default values
ACPP_Platform::ACPP_Platform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_Platform::BeginPlay()
{
	Super::BeginPlay();
	seconds = 0;
	minutes = 0;
	
}

// Called every frame
void ACPP_Platform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ACPP_Platform::Tick, 1, false);
	if (seconds != 60) {
		seconds++;
	}
	else if (seconds == 60) {
		minutes++;
		seconds = 0;
	}


}

