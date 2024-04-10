// Copyright Epic Games, Inc. All Rights Reserved.

#include "CPPTestsGameMode.h"
#include "CPPTestsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACPPTestsGameMode::ACPPTestsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
