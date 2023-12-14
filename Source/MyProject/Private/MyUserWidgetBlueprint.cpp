// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidgetBlueprint.h"


void UMyUserWidgetBlueprint::GetUserNameFunction()
{
    UGameInstance* GameInstance = GetGameInstance();
    if (GameInstance)
    {
        UBP_GameInstance* BPGameInstance = Cast<UBP_GameInstance>(GameInstance);
        if (BPGameInstance)
        {
            Username = BPGameInstance->Username;
        }
    }
}

void UMyUserWidgetBlueprint::OnOpenWorldButtonClicked()
{
    // Open the "OpenWorld" level
    UGameplayStatics::OpenLevel(this, FName("OpenWorld"));

    // Show the mouse cursor
    APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
    if (PlayerController)
    {
        PlayerController->bShowMouseCursor = true;
    }

    // Set input mode to game only
    UGameplayStatics::SetInputMode_GameOnly(PlayerController);
}

void UMyUserWidgetBlueprint::OnClicked_RacingButton()
{
    // Open Level by Object Reference
    UWorld* World = GetWorld();
    if (World)
    {
        FString LevelName = TEXT("VehicleExample");
        World->ServerTravel(LevelName);
    }

    // Get Player Controller
    APlayerController* PlayerController = World->GetFirstPlayerController();

    if (PlayerController)
    {
        // Set Show Mouse Cursor
        PlayerController->bShowMouseCursor = false;

        // Set Input Mode Game Only
        FInputModeGameOnly InputMode;
        PlayerController->SetInputMode(InputMode);

        // Flush Input (optional depending on your needs)
        PlayerController->FlushPressedKeys();
    }


    if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
    {
        FGenericPlatformMisc::RequestExit(false);
    }
}

void UMyUserWidgetBlueprint::QuitGame()
{
    if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
    {
        FGenericPlatformMisc::RequestExit(false);
    }

}
