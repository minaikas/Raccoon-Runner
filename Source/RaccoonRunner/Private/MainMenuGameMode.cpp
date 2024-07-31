

#include "MainMenuGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"

void AMainMenuGameMode::BeginPlay()
{
   UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = true;

    // Проверяем, действителен ли класс виджета
    if (IsValid(MainMenuWidgetClass))
    {
        // Создаём виджет из класса
        UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), MainMenuWidgetClass);

        // Проверяем, что виджет успешно создан
        if (Widget)
        {
            // Добавляем на экран
            Widget->AddToViewport();
        }
    }

     SetupMainMenuCharacter();
}

void AMainMenuGameMode::SetupMainMenuCharacter()
{
    if (MainMenuCharacterClass)
    {
        AMainMenuCharacter* MainMenuCharacter = GetWorld()->SpawnActor<AMainMenuCharacter>(MainMenuCharacterClass);

        if (MainMenuCharacter)
        {
            MainMenuCharacter->SetIdlePose(); 
            
            MainMenuCharacter->SetActorLocation(FVector(0, 0, 0)); 
            MainMenuCharacter->SetActorRotation(FRotator(0, 0, 0)); 
        }
    }
}