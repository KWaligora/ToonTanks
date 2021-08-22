#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"

void APawnTurret::BeginPlay()
{
	Super::BeginPlay();
	
	// Create timer for shooting
	GetWorld()->GetTimerManager().SetTimer(fireRateTimerHandle, this, &APawnTurret::CheckFireCondition, fireRate, true);

	playerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Handle turret rotation
	if(!playerPawn) return;
	if(GetDistanceToPlayer() <= fireRange)
	{
		RotateTurret(playerPawn->GetActorLocation());
	}
}

// Check fire condition and shoot if possible
void APawnTurret::CheckFireCondition()
{
	if(!playerPawn) return;

	if(GetDistanceToPlayer() <= fireRange)
	{
		UE_LOG(LogTemp, Warning, TEXT("Fire!"));
	}
}

float APawnTurret::GetDistanceToPlayer()
{
	if(!playerPawn) return 0.0f;

	return  FVector::Distance(playerPawn->GetActorLocation(), GetActorLocation());
}

void APawnTurret::HandleDestruction()
{
	Super::HandleDestruction();
}