// Fill out your copyright notice in the Description page of Project Settings.


#include "SendVibrationSystem.h"

// Sets default values
ASendVibrationSystem::ASendVibrationSystem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	hMapFile = CreateFileMappingA(
		INVALID_HANDLE_VALUE,
		NULL,
		PAGE_READWRITE,
		0,
		1024,
		"Local\\vibDataSharedMemory");

	s_data_shared = (VibData*)MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, 1024);
}

void ASendVibrationSystem::EndPlay(const EEndPlayReason::Type EndPlayReason) {
	// Your cleanup code here

	// Call the parent class's EndPlay function
	Super::EndPlay(EndPlayReason);

	// Unmap shared memory
	UnmapViewOfFile(s_data_shared);

	// Close file mapping object
	CloseHandle(hMapFile);
}


// Called when the game starts or when spawned
void ASendVibrationSystem::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASendVibrationSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASendVibrationSystem::Vibrate() {
	s_data_shared->isActive = true;
}