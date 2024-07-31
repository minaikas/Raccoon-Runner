

#include "CoinItem.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "RRCharacterMovement.h"


ACoinItem::ACoinItem()
{
    SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
    RootComponent = SceneComponent;

    SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
    SphereCollider->SetupAttachment(SceneComponent);
    SphereCollider->SetCollisionProfileName(TEXT("OverlapOnlyPawn"));

    CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CoinMesh"));
    CoinMesh->SetupAttachment(SphereCollider);
    CoinMesh->SetCollisionProfileName(TEXT("OverlapOnlyPawn"));

    RotatingMovement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingMovement"));
    RotatingMovement->RotationRate = FRotator(0, 180, 0);
}

// Called when the game starts or when spawned
void ACoinItem::BeginPlay()
{
    Super::BeginPlay();

    SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ACoinItem::OnSphereOverlap);
}

void ACoinItem::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    ARRCharacterMovement* RRCharacterMovement = Cast<ARRCharacterMovement>(OtherActor);

    if (RRCharacterMovement)
    {
        if(OverlapSound)
        {
            UGameplayStatics::PlaySoundAtLocation(GetWorld(), OverlapSound, GetActorLocation());
        }
        RRCharacterMovement->AddCoin();
        Destroy();
    }

}
 
 