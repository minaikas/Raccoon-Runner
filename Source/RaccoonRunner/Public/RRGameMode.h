// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/GameMode.h"
#include "RRGameMode.generated.h"

class UUserWidget;

/**макрос для создания события FOnCoinsChanged для привязки изменения текста на экране,
 * пользовательское, многоадресное событие, к которому привязан класс Widget
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCoinsCountChanged, int, CoinsCount);   
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLivesCountChanged, int, LivesCount);
//
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLevelReset);


UCLASS()
class RACCOONRUNNER_API ARRGameMode : public AGameMode
{
	GENERATED_BODY()

	public:

		UPROPERTY(EditAnywhere, Category = "Widget")
    	TSubclassOf<UUserWidget> GameHudClass;

    	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
    	class UGameHud* GameHud;

		UPROPERTY(EditAnywhere, Category = "Config")
		TSubclassOf<UUserWidget> GameOverScreenClass;

    	UPROPERTY(VisibleAnywhere)
    	int TotalCoins = 0;

		UPROPERTY(VisibleAnywhere)
		int NumberOfLives = 0;

		UPROPERTY(EditAnywhere)
    	int MaxLives = 3;

    	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Delegates")
    	FOnCoinsCountChanged OnCoinsCountChanged;

		UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Delegates")
    	FOnLivesCountChanged OnLivesCountChanged;

		//
		UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Delegates")
    	FOnLevelReset OnLevelReset;
		
		UFUNCTION(BlueprintCallable)
		void GameOver();

    	UFUNCTION(BlueprintCallable)
    	void AddCoin();

		UFUNCTION(BlueprintCallable)
    	void PlayerDied();

		UFUNCTION(BlueprintCallable, Category = "SaveResults")
		void SaveResults();

	protected:
    	virtual void BeginPlay() override;
	
};

