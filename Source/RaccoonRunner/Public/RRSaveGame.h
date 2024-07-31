// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "RRSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class RACCOONRUNNER_API URRSaveGame : public USaveGame
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, Category = "Basic")
    int CurrentCoins;

	// UPROPERTY(VisibleAnywhere, Category = "Basic")
    // float Time;
};
