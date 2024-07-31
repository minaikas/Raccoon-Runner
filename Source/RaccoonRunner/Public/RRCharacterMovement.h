// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"


#include "RRCharacterMovement.generated.h"

UCLASS()
class RACCOONRUNNER_API ARRCharacterMovement : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARRCharacterMovement();

	UFUNCTION(BlueprintCallable)
	void Death();
	
	UFUNCTION()
	void AddCoin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Camera")
	USpringArmComponent* CameraBoom;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Camera")
	UCameraComponent* FollowCamera;
	
	class ARRGameMode* RRGameMode;

	void MoveForward(float value);
	void MoveLeftRight(float value);

	void TurnLeftRight(float value);
	void TurnUpDown(float value);

	void OnStartJump();
	void OnStopJump();

	UFUNCTION()
	void OnDeath();

	UFUNCTION()
	void ResetLevel();

	// UFUNCTION(BlueprintCallable, Category = "SaveResults")
	// void SaveResults();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Assets")
	class UParticleSystem* DeathParticleSystem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sounds")
	class USoundBase* DeathSound;

	UPROPERTY()
	FTimerHandle RestartTimerHandle;

	UPROPERTY()
	class APlayerStart* PlayerStart;

	UPROPERTY()
	bool bIsDead = false;


	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

