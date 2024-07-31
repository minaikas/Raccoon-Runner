
#include "RRGameMode.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "GameHud.h"


void ARRGameMode::BeginPlay()
{

    Super::BeginPlay();

    GameHud = Cast<UGameHud>(CreateWidget(GetWorld(), GameHudClass));
    check(GameHud);

    GameHud->InitializeHUD(this);

    GameHud->AddToViewport();

    NumberOfLives = MaxLives;

    OnLivesCountChanged.Broadcast(NumberOfLives); 


}


void ARRGameMode::AddCoin()
{
    TotalCoins += 10;

    OnCoinsCountChanged.Broadcast(TotalCoins);
}

void ARRGameMode::PlayerDied()
{
    NumberOfLives -= 1;

    OnLivesCountChanged.Broadcast(NumberOfLives);

    if(NumberOfLives > 0)
    {
        
        // Broadcast level reset event
        
        OnLevelReset.Broadcast();
        
    }
    else
    {
        GameOver();
        UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = true;
    }

}

void ARRGameMode::GameOver()
{
    if(IsValid(GameOverScreenClass))
    {
        UUserWidget* Widget = CreateWidget(GetWorld(), GameOverScreenClass);

        if(Widget)
        {
            Widget->AddToViewport();
        }
    }
}

void ARRGameMode::SaveResults()
{
    
}