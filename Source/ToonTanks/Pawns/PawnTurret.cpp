#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"

void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(fireRateTimerHandle, this, &APawnTurret::CheckFireCondition, fireRate, true);

	playerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APawnTurret::CheckFireCondition()
{
	if(!playerPawn) return;

	if(ReturnDistanceToPlayer() <= fireRange)
	{
		UE_LOG(LogTemp, Warning, TEXT("Fire!"));
	}
}

float APawnTurret::ReturnDistanceToPlayer()
{
	if(!playerPawn) return 0.0f;

	return  FVector::Distance(playerPawn->GetActorLocation(), GetActorLocation());
}
