// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainMenuCharacter.h" 
#include "MainMenuGameMode.generated.h"

/**
 * 
 */
UCLASS()
class RACCOONRUNNER_API AMainMenuGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
	public:
		//
		UPROPERTY(EditAnywhere, Category = "Config")
    	TSubclassOf<AMainMenuCharacter> MainMenuCharacterClass;




		UPROPERTY(EditAnywhere, Category = "Config")
		TSubclassOf<UUserWidget> MainMenuWidgetClass;

		virtual void BeginPlay() override;
	
	private:
    	void SetupMainMenuCharacter();
};
