#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"

void APawnTurret::BeginPlay()
{
	Super::BeginPlay();
	
	// Create timer for shooting
	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);

	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Handle turret rotation
	if(!PlayerPawn) return;
	if(GetDistanceToPlayer() <= FireRange)
	{
		RotateTurret(PlayerPawn->GetActorLocation());
	}
}

// Check fire condition and shoot if possible
void APawnTurret::CheckFireCondition()
{
	if(!PlayerPawn || !PlayerPawn->GetIsPlayerAlive()) return;

	if(GetDistanceToPlayer() <= FireRange)
	{
		Fire();
	}
}

float APawnTurret::GetDistanceToPlayer()
{
	if(!PlayerPawn) return 0.0f;

	return  FVector::Distance(PlayerPawn->GetActorLocation(), GetActorLocation());
}

void APawnTurret::HandleDestruction()
{
	Super::HandleDestruction();
}