#include "TankGameModeBase.h"
#include "ToonTanks/Pawns/PawnTank.h"
#include "ToonTanks/Pawns/PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "ToonTanks/PlayerControllers/PlayerControllerBase.h"

void ATankGameModeBase::BeginPlay()
{
	Super::BeginPlay();		

	HandleGameStart();
}

int32 ATankGameModeBase::GetTargetTurretCount()
{
	TArray<AActor*> TurretActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APawnTurret::StaticClass(), TurretActors);
	return TurretActors.Num();
}

void ATankGameModeBase::HandleGameStart()
{
	// Get player tank, player controller and turrets count
	PlayerTank = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));	
	PlayerControllerRef = Cast<APlayerControllerBase>(UGameplayStatics::GetPlayerController(this, 0));
	TargetTurrets = GetTargetTurretCount();
	
	GameStart();
	// Enable input
	if(PlayerControllerRef)
	{
		PlayerControllerRef->SetPlayerEnableState(true);
	}
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon)
{
	GameOver(PlayerWon);
}

void ATankGameModeBase::ActorDied(AActor* DeadActor)
{
	// handle player loss
	if(DeadActor == PlayerTank)
	{
		PlayerTank->HandleDestruction();
		HandleGameOver(false);
		
		// disable input
		if(PlayerControllerRef)
		{
			PlayerControllerRef->SetPlayerEnableState(false);

			FTimerHandle PlayerEnableHandle;
			FTimerDelegate PlayerEnableDelegate = FTimerDelegate::CreateUObject(
				PlayerControllerRef,
				&APlayerControllerBase::SetPlayerEnableState,
				true);
			GetWorld()->GetTimerManager().SetTimer(PlayerEnableHandle, PlayerEnableDelegate, StartDelay, false);
		}
	}
	// destroy turret and check if player won
	else if(APawnTurret* DestroyedTurret = Cast<APawnTurret>(DeadActor))
	{
		DestroyedTurret->HandleDestruction();
		TargetTurrets--;
		if(TargetTurrets == 0) HandleGameOver(true);
	}
}
