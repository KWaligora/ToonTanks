// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TankGameModeBase.generated.h"

class APawnTurret;
class APawnTank;

UCLASS()
class TOONTANKS_API ATankGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

private:
// References
	APawnTank* PlayerTank;

// Variables
	int32 TargetTurrets = 0;

// Functions
	int32 GetTargetTurretCount();
	// Call GameStart
	void HandleGameStart();
	// Call GameOver
	void HandleGameOver(bool PlayerWon);
	
public:

	void ActorDied(AActor* DeadActor);
	
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Game Loop")
	int32 StartDelay;
	
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintImplementableEvent)
	void GameStart();
	
	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool PlayerWon);
};
