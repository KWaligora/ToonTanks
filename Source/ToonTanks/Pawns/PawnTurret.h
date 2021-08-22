#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTurret.generated.h"

class APawnTank;

UCLASS()
class TOONTANKS_API APawnTurret : public APawnBase
{
	GENERATED_BODY()

private:	
// Variables
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta=(AllowPrivateAccess = "true"))
	float fireRate = 2.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Combat", meta = (AllowPrivateAccess = "true"))
	float fireRange = 500.0f;

	FTimerHandle fireRateTimerHandle;
	APawnTank* playerPawn;

// Functions
	
	void CheckFireCondition();
	float GetDistanceToPlayer();
	
public:

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
protected:	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void HandleDestruction() override;
};
