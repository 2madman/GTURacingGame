// Fill out your copyright notice in the Description page of Project Settings.

#include "SendVibrationSystem.h"

// Sets default values
ASendVibrationSystem::ASendVibrationSystem()
{
	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

#if defined(_WIN32) || defined(_WIN64)
	hMapFile = CreateFileMappingA(
		INVALID_HANDLE_VALUE,
		NULL,
		PAGE_READWRITE,
		0,
		1024,
		"Local\\vibDataSharedMemory");

	s_data_shared = (VibData*)MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, 1024);
#elif defined(_linux_)
	// Linux-specific code for shared memory creation
	int shm_fd = shm_open("/vibDataSharedMemory", O_CREAT | O_RDWR, 0666);
	ftruncate(shm_fd, 1024);
	s_data_shared = (VibData*)mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
	close(shm_fd);
#endif
}

void ASendVibrationSystem::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// Your cleanup code here

	// Call the parent class's EndPlay function
	Super::EndPlay(EndPlayReason);

	// Unmap shared memory
#if defined(_WIN32) || defined(_WIN64)
	UnmapViewOfFile(s_data_shared);

	// Close file mapping object
	CloseHandle(hMapFile);
#elif defined(_linux_)
	munmap(s_data_shared, 1024);
	// You may need to unlink the shared memory object on Linux
	// shm_unlink("/vibDataSharedMemory");
#endif
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

void ASendVibrationSystem::Vibrate()
{
	s_data_shared->isActive = true;
}
