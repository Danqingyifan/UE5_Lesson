// Fill out your copyright notice in the Description page of Project Settings.

#include "ExploringUECode.h"

// Sets default values
AExploringUECode::AExploringUECode()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AExploringUECode::BeginPlay()
{
	Super::BeginPlay();
	
}

void AExploringUECode::Countdown_Implementation()
{

}

// Called every frame
void AExploringUECode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
int AExploringUECode::PrintMyValue()
{
	OnValueCalculate(VA,VB);
	return VA + VB;
}





