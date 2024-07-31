

#include "RRCharacterMovement.h"
#include "RRGameMode.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerStart.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ARRCharacterMovement::ARRCharacterMovement()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);

    CameraBoom->TargetArmLength = 300.0f;
    CameraBoom->bUsePawnControlRotation = true;

    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    FollowCamera->bUsePawnControlRotation = false;
}

// Called when the game starts or when spawned
void ARRCharacterMovement::BeginPlay()
{
    Super::BeginPlay();
    
    RRGameMode = Cast<ARRGameMode>(UGameplayStatics::GetGameMode(GetWorld()));


    if (!RRGameMode)
    {
    UE_LOG(LogTemp, Error, TEXT("Failed to get RRGameMode"));
    }
    else
    {
    RRGameMode->OnLevelReset.AddDynamic(this, &ARRCharacterMovement::ResetLevel);
    }


    PlayerStart = Cast<APlayerStart>(UGameplayStatics::GetActorOfClass(GetWorld(), APlayerStart::StaticClass()));
}


void ARRCharacterMovement::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FRotator ControlRot = GetControlRotation();
    ControlRot.Roll = 0.f;
    ControlRot.Pitch = 0.f;

    AddMovementInput(ControlRot.Vector());
}

// Called to bind functionality to input
void ARRCharacterMovement::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (!PlayerInputComponent)
    {
        return;
    }

    PlayerInputComponent->BindAxis("TurnLeftRight", this, &ARRCharacterMovement::TurnLeftRight);
    PlayerInputComponent->BindAxis("TurnUpDown", this, &ARRCharacterMovement::TurnUpDown);
    PlayerInputComponent->BindAxis("MoveForward", this, &ARRCharacterMovement::MoveForward);
    PlayerInputComponent->BindAxis("MoveLeftRight", this, &ARRCharacterMovement::MoveLeftRight);
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ARRCharacterMovement::OnStartJump);
    PlayerInputComponent->BindAction("Jump", IE_Released, this, &ARRCharacterMovement::OnStopJump);
}

void ARRCharacterMovement::TurnLeftRight(float value)
{
    AddControllerYawInput(value);
}

void ARRCharacterMovement::TurnUpDown(float value)
{
    AddControllerPitchInput(value);
}

void ARRCharacterMovement::MoveForward(float value)
{
    const FRotator ControllerRotation = GetControlRotation();
    const FRotator YawControllerRotation(0.0, ControllerRotation.Yaw, 0.0);
    const FRotationMatrix RotationYawMatrix = FRotationMatrix(YawControllerRotation);
    const FVector DirectionVec = RotationYawMatrix.GetUnitAxis(EAxis::X);

    AddMovementInput(DirectionVec, value);
}

void ARRCharacterMovement::MoveLeftRight(float value)
{
    const FRotator ControllerRotation = GetControlRotation();
    const FRotator YawControllerRotation(0.0, ControllerRotation.Yaw, 0.0);
    const FRotationMatrix RotationYawMatrix = FRotationMatrix(YawControllerRotation);
    const FVector DirectionVec = RotationYawMatrix.GetUnitAxis(EAxis::Y);

    AddMovementInput(DirectionVec, value);
}

void ARRCharacterMovement::OnStartJump()
{
    Jump();
}

void ARRCharacterMovement::OnStopJump()
{
    StopJumping();
}

void ARRCharacterMovement::Death()
{
    if (!bIsDead)
    {
        const FVector Location = GetActorLocation();
        UWorld* World = GetWorld();

        if (World)
        {
            bIsDead = true;
            DisableInput(nullptr);

            if (DeathParticleSystem)
            {
                UGameplayStatics::SpawnEmitterAtLocation(World, DeathParticleSystem, Location);
            }

            if (DeathSound)
            {
                UGameplayStatics::PlaySoundAtLocation(World, DeathSound, Location);
            }

            GetMesh()->SetVisibility(false);

            World->GetTimerManager().SetTimer(RestartTimerHandle, this, &ARRCharacterMovement::OnDeath, 1.f);
        }
    }
    
}

void ARRCharacterMovement::OnDeath()
{


    if (RestartTimerHandle.IsValid())
    {
        GetWorldTimerManager().ClearTimer(RestartTimerHandle);
    }


    RRGameMode->PlayerDied();
}

//
void ARRCharacterMovement::ResetLevel()
{

    bIsDead = false;
    EnableInput(nullptr);
    GetMesh()->SetVisibility(true);

    if(PlayerStart)
    {
        SetActorLocation(PlayerStart->GetActorLocation());
        SetActorRotation(PlayerStart->GetActorRotation());
    }

    //UE_LOG(LogTemp, Warning, TEXT("After reset: %d"), NumberOfLives);
}

void ARRCharacterMovement::AddCoin()
{
    UE_LOG(LogTemp, Warning, TEXT("V Character Movement without game mode"));
    ARRGameMode* GameMode = Cast<ARRGameMode>(UGameplayStatics::GetGameMode(this));
    if (GameMode)
    {
        UE_LOG(LogTemp, Warning, TEXT("V Character Movement:"));
        GameMode->AddCoin();
    }
}

// void ARRCharacterMovement::SaveResults()
// {
    
// }