// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectileBase.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AProjectileBase::AProjectileBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Create and set default component
	projectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));	
	RootComponent = projectileMesh;	
	projectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	projectileMovement->InitialSpeed = movementSpeed;
	projectileMovement->MaxSpeed = movementSpeed;

	// How long this actor exist in scene 
	InitialLifeSpan = 3.0f;
}

// Called when the game starts or when spawned
void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	
	// delegate OnHit()
	projectileMesh->OnComponentHit.AddDynamic(this, &AProjectileBase::OnHit);
}

// On projectile hit
void AProjectileBase::OnHit(UPrimitiveComponent* hitComp, AActor* otherActor, UPrimitiveComponent* otherComp,
	FVector normalImpuls, const FHitResult& Hit)
{
	AActor* myOwner = GetOwner();
	if(!myOwner) return;

	// if the other actor ISN'T self or owner and exist, then apply damage
	if(otherActor && otherActor != this && otherActor != myOwner)
	{
		UGameplayStatics::ApplyDamage(otherActor, damage, myOwner->GetInstigatorController(), this, damageType);
	}
	Destroy();
}

