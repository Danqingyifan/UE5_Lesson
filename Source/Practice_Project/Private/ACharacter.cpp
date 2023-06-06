// Fill out your copyright notice in the Description page of Project Settings.
#include "ACharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AACharacter::AACharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->bUsePawnControlRotation = true;


	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);

	GetCharacterMovement()->bOrientRotationToMovement = true;

	bUseControllerRotationYaw = false;
}

// Called when the game starts or when spawned
void AACharacter::BeginPlay()
{
	Super::BeginPlay();
	
}
void AACharacter::MoveForward(float value)
{
	FRotator ControlBot = GetControlRotation();
	ControlBot.Roll = 0.0f;
	ControlBot.Pitch = 0.0f;
	AddMovementInput(ControlBot.Vector(), value);
	
}

void AACharacter::MoveRight(float value)
{
	FRotator ControlBot = GetControlRotation();
	ControlBot.Roll = 0.0f;
	ControlBot.Pitch = 0.0f;

	//FVector RightVector = UKismetMathLibrary::GetRightVector(ControlBot);
	FVector RightVector = FRotationMatrix(ControlBot).GetScaledAxis(EAxis::Y);

	AddMovementInput(RightVector, value);
}

void AACharacter::PrimaryAttack()
{
	FVector headLocation = GetMesh()->GetSocketLocation("head");

	FTransform SpawnTM = FTransform(GetActorRotation(), GetActorLocation());

	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnTM, SpawnParameters);
}


// Called every frame
void AACharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AACharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AACharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AACharacter::MoveRight);

	PlayerInputComponent->BindAxis("TurnCameraRight", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnCameraUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("PrimaryAttack", IE_Pressed, this, &AACharacter::PrimaryAttack);
}


