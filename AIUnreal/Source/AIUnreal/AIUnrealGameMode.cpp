// Copyright Epic Games, Inc. All Rights Reserved.

#include "AIUnrealGameMode.h"
#include "AIUnrealCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAIUnrealGameMode::AAIUnrealGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
