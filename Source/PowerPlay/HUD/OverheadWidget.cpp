// Fill out your copyright notice in the Description page of Project Settings.


#include "OverheadWidget.h"
#include "GameFramework/PlayerState.h"
#include "Components/TextBlock.h"

void UOverheadWidget::SetDisplayText(FString TextToDisplay)
{
	if (DisplayText)
	{
		DisplayText->SetText(FText::FromString(TextToDisplay));
	}
}

void UOverheadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	APlayerState* PlayerState = InPawn->GetPlayerState();
	FString PlayerName;
	if (PlayerState)
	{
		PlayerName = PlayerState->GetPlayerName();
	}

	ENetRole LocalRole = InPawn->GetRemoteRole();
	FString Role;

	switch (LocalRole)
	{
	case ROLE_None:
		Role = FString("None");
		break;
	case ROLE_SimulatedProxy:
		Role = FString("Simulated Proxy");
		break;
	case ROLE_AutonomousProxy:
		Role = FString("Autonomous Proxy");
		break;
	case ROLE_Authority:
		Role = FString("Authority");
		break;
	case ROLE_MAX:
		Role = FString("Max");
		break;
	default:
		break;
	}

	FString RoleString = FString::Printf(TEXT("Remote Role: %s || Player Name: %s"), *Role, *PlayerName);
	SetDisplayText(RoleString);
}

void UOverheadWidget::NativeDestruct()
{
	RemoveFromParent();
	Super::NativeDestruct();
}
