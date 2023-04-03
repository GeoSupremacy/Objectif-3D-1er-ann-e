// Copyright Epic Games, Inc. All Rights Reserved.

#include "Mario_CorrectionGameMode.h"
#include "Mario_CorrectionCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMario_CorrectionGameMode::AMario_CorrectionGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
