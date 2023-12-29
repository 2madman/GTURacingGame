// Fill out your copyright notice in the Description page of Project Settings.


#include "CarInputSW.h"
#include <iostream>
#include <Windows.h>

// Sets default values
ACarInputSW::ACarInputSW()
{

	UE_LOG(LogTemp, Warning, TEXT("HEREEEEEEEEEEEEEEEEEEEEEEEEEEEEEKJ S"));
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	hMapFile = OpenFileMappingA(
		FILE_MAP_READ,
		FALSE,
		"Local\\MySharedMemory");

	s_data_shared = (SensorData*)MapViewOfFile(hMapFile, FILE_MAP_READ, 0, 0, 1024);
}


// Called when the game starts or when spawned
void ACarInputSW::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACarInputSW::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACarInputSW::PrintSomething() {
	// Read shared data
	UE_LOG(LogTemp, Warning, TEXT("Gas: %f, Brake: %f, Angle: %f"), s_data_shared->gas, s_data_shared->brake, s_data_shared->angle);

	// Unmap shared memory
}

void ACarInputSW::EndPlay(const EEndPlayReason::Type EndPlayReason) {
	// Your cleanup code here

	// Call the parent class's EndPlay function
	Super::EndPlay(EndPlayReason);

	// Unmap shared memory
	UnmapViewOfFile(s_data_shared);

	// Close file mapping object
	CloseHandle(hMapFile);
}

float ACarInputSW::getGas() {
	// if(s_data_shared->brake) implement is valid check here and call recursively
	const float MAX_VAL = 900.0f;
	const float MIN_VAL = 160.0f;

	float input_gas = s_data_shared->gas;

	if (input_gas > MAX_VAL || input_gas < MIN_VAL)
		return last_gas;

	float to_return = map(MIN_VAL, MAX_VAL, input_gas, 1 , 0);

	if (to_return < 0.1f)
		to_return = 0.0f;

	last_gas = to_return;

	return to_return;
}

float ACarInputSW::getBrake() {
	// if(s_data_shared->brake) implement is valid check here and call recursively
	const float MAX_VAL = 750.0f;
	const float MIN_VAL = 0.0f;

	float input_brake = s_data_shared->brake;

	if (input_brake > MAX_VAL || input_brake < MIN_VAL)
		return last_brake;

	float to_return = map(MIN_VAL, MAX_VAL, input_brake, 1, 0);

	if (to_return < 0.1f)
		to_return = 0.0f;

	last_brake = to_return;

	return to_return;
}

float ACarInputSW::getAngle() {
	// if(s_data_shared->brake) implement is valid check here and call recursively

	const float MAX_VAL = 360.0f;
	const float MIN_VAL = -360.0f;

	float input_angle = s_data_shared->angle;

	if (input_angle > MAX_VAL)
		input_angle = MAX_VAL;

	else if (input_angle < MIN_VAL)
		input_angle = MIN_VAL;
		
	float to_return = map(MIN_VAL, MAX_VAL, input_angle, -1, 1);

	return to_return;
}

float ACarInputSW::map(float min_x, float max_x, float x, float a, float b) {
	return a + (((x - min_x) * (b - a)) / (max_x - min_x));
}
