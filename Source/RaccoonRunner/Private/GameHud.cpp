

#include "GameHud.h"
#include "Components/TextBlock.h"
#include "RRGameMode.h"
#include "Kismet/GameplayStatics.h"

void UGameHud::InitializeHUD(ARRGameMode* RRGameMode)
{
    if (RRGameMode)
    {
        CoinsCount->SetText(FText::AsNumber(0));
        RRGameMode->OnCoinsCountChanged.AddDynamic(this, &UGameHud::SetCoinsCount);

        LivesCount->SetText(FText::AsNumber(RRGameMode->MaxLives));
        RRGameMode->OnLivesCountChanged.AddDynamic(this, &UGameHud::SetLivesCount);
        
    }
}

void UGameHud::SetCoinsCount(const int Count)
{
    CoinsCount->SetText(FText::AsNumber(Count));
}

void UGameHud::SetLivesCount(const int Count)
{
    UE_LOG(LogTemp, Warning, TEXT("Setting Lives Count in HUD: %d"), Count);
    LivesCount->SetText(FText::AsNumber(Count));
}

