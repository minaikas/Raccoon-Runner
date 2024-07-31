// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"
#include "RRCharacterMovement.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AObstacle::AObstacle()
{
    SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    RootComponent = SceneComponent;

    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMesh->SetupAttachment(SceneComponent);
    StaticMesh->SetCollisionProfileName(TEXT("BlockAll"));
}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
    Super::BeginPlay();

    StaticMesh->OnComponentHit.AddDynamic(this, &AObstacle::OnObstacleHit);
}

// Called every frame
void AObstacle::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AObstacle::OnObstacleHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

	ARRCharacterMovement* CharacterMovement = Cast<ARRCharacterMovement>(OtherActor);
	if(CharacterMovement)
	{
		CharacterMovement->Death();
	}

}

