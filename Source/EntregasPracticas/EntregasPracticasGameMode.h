// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EntregasPracticasGameMode.generated.h"

/**
 *  Simple GameMode for a third person game
 */
UCLASS(abstract)
class AEntregasPracticasGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	/** Constructor */
	AEntregasPracticasGameMode();
};



