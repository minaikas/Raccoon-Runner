// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameHud.generated.h"

/**
 * 
 */
UCLASS()
class RACCOONRUNNER_API UGameHud : public UUserWidget
{
	GENERATED_BODY()

	public:
		UFUNCTION(BlueprintCallable)
		void InitializeHUD(ARRGameMode* RRGameMode);

		UFUNCTION(BlueprintCallable)
		void SetCoinsCount(const int Count);

		UFUNCTION(BlueprintCallable)
		void SetLivesCount(const int Count);

	protected:
		UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* CoinsCount;

		UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* LivesCount;
};

