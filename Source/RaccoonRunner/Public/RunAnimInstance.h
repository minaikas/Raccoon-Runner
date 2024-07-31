// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "RunAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class RACCOONRUNNER_API URunAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
	public:

		UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Movement")
		float Speed;

		UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Movement")
		bool bIsInAir;

		UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Movement")
		class APawn* Pawn;

		UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Movement")
		class UPawnMovementComponent* MovementComponent;

		virtual void NativeInitializeAnimation() override;
		virtual void NativeUpdateAnimation(float DeltaSeconds) override;

};
