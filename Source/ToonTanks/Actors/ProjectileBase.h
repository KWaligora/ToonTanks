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
	UProjectileMovementComponent* ProjectileMovement;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Components", meta = (AllowPrivateAccess = "true"))
	UParticleSystemComponent* ParticleTrail;
	
	// Variables
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Movement", meta = (AllowPrivateAccess = "true"))
	float MovementSpeed = 1300.0f;
	
	UPROPERTY(EditDefaultsOnly, Category="Damage")
	TSubclassOf<UDamageType> DamageType;	
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category="Damage", meta = (AllowPrivateAccess = "true"))
	float Damage = 50.0f;

	UPROPERTY(EditAnywhere, Category="Effects")
	UParticleSystem* HitParticle;
	
// Delegates
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpuls, const FHitResult &Hit);
	
public:	
	// Sets default values for this actor's properties
	AProjectileBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
