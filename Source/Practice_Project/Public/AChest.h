// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GamePlayInterface.h"
#include "GameFramework/Actor.h"
#include "AChest.generated.h"
class UStaticMeshComponent;

UCLASS()
class PRACTICE_PROJECT_API AAChest : public AActor,public IGamePlayInterface
{
	GENERATED_BODY()
		void Interact_Implementation(APawn* InstigatorPawn) override;
	
public:	
	// Sets default values for this actor's properties
	AAChest();
	float TargetPitch = 0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* LidMesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
