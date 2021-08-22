// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileBase.generated.h"

class UProjectileMovementComponent;

UCLASS()
class TOONTANKS_API AProjectileBase : public AActor
{
	GENERATED_BODY()

private:
// Exposed Variables
	// Components
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Components", meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* projectileMovement;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* projectileMesh;
	
	// Variables
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Movement", meta = (AllowPrivateAccess = "true"))
	float movementSpeed = 1300.0f;
	
	UPROPERTY(EditDefaultsOnly, Category="Damage")
	TSubclassOf<UDamageType> damageType;	
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category="Damage", meta = (AllowPrivateAccess = "true"))
	float damage = 50.0f;
	
public:	
	// Sets default values for this actor's properties
	AProjectileBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
