#include "MainMenuCharacter.h"
#include "Animation/AnimMontage.h"


AMainMenuCharacter::AMainMenuCharacter()
{

    IdleMontage = nullptr;
}

// Called when the game starts or when spawned
void AMainMenuCharacter::BeginPlay()
{

    SetIdlePose();
}

void AMainMenuCharacter::SetIdlePose()
{
    if (IdleMontage)
    {
        PlayAnimMontage(IdleMontage);
    }
}


