// Fill out your copyright notice in the Description page of Project Settings.
#include "ACharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AACharacter::AACharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->SetupAttachment(RootComponent);
	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);
}

// Called when the game starts or when spawned
void AACharacter::BeginPlay()
{
	Super::BeginPlay();
	
}
void AACharacter::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector(), value*1000);
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
	PlayerInputComponent->BindAxis("TurnCamera", this, &APawn::AddControllerYawInput);
}

