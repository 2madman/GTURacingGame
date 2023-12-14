// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidgetBlueprint.h"
#include "MyUserWidgetBlueprint.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UMyUserWidgetBlueprint : public UUserWidgetBlueprint
{
	GENERATED_BODY()
public:
	GetUserNameFunction();

	OnOpenWorldButtonClicked();

	OnClicked_RacingButton();

	QuitGame();
};
