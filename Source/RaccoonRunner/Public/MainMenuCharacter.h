#pragma once

#include "CoreMinimal.h"
#include "RRCharacterMovement.h"
#include "MainMenuCharacter.generated.h"

/**
 * 
 */
UCLASS()
class RACCOONRUNNER_API AMainMenuCharacter : public ARRCharacterMovement
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    AMainMenuCharacter();

    // Позы персонажа
    void SetIdlePose();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

private:
    UPROPERTY(EditAnywhere, Category = "Animation")
    class UAnimMontage* IdleMontage;

};