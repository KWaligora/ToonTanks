#include "PawnBase.h"
#include "Components/CapsuleComponent.h"

// Sets default values
APawnBase::APawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Sets Components
	capsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = capsuleComp;

	baseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	baseMesh->SetupAttachment(RootComponent);

	turretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	turretMesh->SetupAttachment(baseMesh);

	projectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	projectileSpawnPoint->SetupAttachment(turretMesh);
}

// Called when the game starts or when spawned
void APawnBase::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void APawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APawnBase::RotateTurret(FVector lookAtTarget)
{
	// simple subtraction of two vectors to find look direction
	FVector lookAtTargetCleaned = FVector(lookAtTarget.X, lookAtTarget.Y, turretMesh->GetComponentLocation().Z);
	FVector startLocation = turretMesh->GetComponentLocation();	
	FRotator turretRotation = FVector(lookAtTargetCleaned - startLocation).Rotation();

	// set this direction
	turretMesh->SetWorldRotation(turretRotation);
	
}

void APawnBase::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Bang!"));
}

void APawnBase::HandleDestruction()
{
}
