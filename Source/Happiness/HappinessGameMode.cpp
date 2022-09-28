// Copyright Epic Games, Inc. All Rights Reserved.

#include "HappinessGameMode.h"
#include "HappinessCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHappinessGameMode::AHappinessGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
