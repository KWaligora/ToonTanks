#include "PawnTank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

APawnTank::APawnTank()
{
	//Setup Components
	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	springArm->SetupAttachment(RootComponent);
	
	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	camera->SetupAttachment(springArm);
}

// Called when the game starts or when spawned
void APawnTank::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APawnTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Rotate();
	Move();
}

// Called to bind functionality to input
void APawnTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward",this, &APawnTank::CalculateMoveInput);
	PlayerInputComponent->BindAxis("Turn", this, &APawnTank::CalculateRotationInput);
}

// Calculate move direction
void APawnTank::CalculateMoveInput(float value)
{
	moveDirection = FVector(value * moveSpeed * GetWorld()->DeltaTimeSeconds, 0, 0);
}

// Calculate Tank rotation
void APawnTank::CalculateRotationInput(float value)
{
	float rotateAmount = value * rotateSpeed * GetWorld()->DeltaTimeSeconds;
	FRotator rotation = FRotator(0, rotateAmount, 0);
	rotationDirection = FQuat(rotation);
}

// Move Tank
void APawnTank::Move()
{
	AddActorLocalOffset(moveDirection, true);
}

// Rotate Tank
void APawnTank::Rotate()
{
	AddActorLocalRotation(rotationDirection, true);
}
