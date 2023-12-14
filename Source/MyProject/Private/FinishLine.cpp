// Fill out your copyright notice in the Description page of Project Settings.


#include "FinishLine.h"
#include "SportsCar_Pawn.h"

// Sets default values
AFinishLine::AFinishLine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
virtual void NotifyActorBeginOverlap(AActor* OtherActor) override
{
    Super::NotifyActorBeginOverlap(OtherActor);

    // Increment total collisions
    TotalCollisions++;

    // Check if TotalCollisions is greater than or equal to 6
    if (TotalCollisions >= 6 && !bGameWon)
    {
        bGameWon = true;

        // Get the player controller
        APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
        if (PlayerController)
        {
            // Create and display the game win widget
            UUserWidget* GameWinWidget = CreateWidget<UUserWidget>(PlayerController, UYourGameWinWidgetClass::StaticClass());
            if (GameWinWidget)
            {
                GameWinWidget->AddToViewport();

                // Pause the game
                PlayerController->SetPause(true);

                // Show the mouse cursor
                PlayerController->bShowMouseCursor = true;

                // Set input mode to UI only
                FInputModeUIOnly InputModeData;
                InputModeData.SetWidgetToFocus(GameWinWidget->TakeWidget());
                InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
                PlayerController->SetInputMode(InputModeData);
            }
        }
    }
}

// Assume this is within an AActor class:

// Declare this variable in your header file (.h)
bool bGameWon = false;

// Declare a variable to track total collisions, initialized to 0
int32 TotalCollisions = 0;

// The function that is called when another actor begins to overlap with this actor

// Called when the game starts or when spawned
void AFinishLine::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFinishLine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


