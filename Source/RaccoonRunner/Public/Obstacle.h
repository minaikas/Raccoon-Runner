// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RRCharacterMovement.h"
#include "Obstacle.generated.h"

UCLASS()
class RACCOONRUNNER_API AObstacle : public AActor
{
    GENERATED_BODY()
    
public:    
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
    class USceneComponent* SceneComponent;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
    class UStaticMeshComponent* StaticMesh;

    // Sets default values for this actor's properties
    AObstacle();

    UFUNCTION()
    void OnObstacleHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:    
    // Called every frame
    virtual void Tick(float DeltaTime) override;
};
