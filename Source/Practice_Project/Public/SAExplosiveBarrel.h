// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "SAExplosiveBarrel.generated.h"

class UStaticMeshComponent;
class URadialForceComponent;
/**
 * 
 */
UCLASS()
class PRACTICE_PROJECT_API ASAExplosiveBarrel : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASAExplosiveBarrel();

protected:

	UPROPERTY(VisibleAnywhere)
		TObjectPtr<UStaticMeshComponent> MeshComp;

	UPROPERTY(VisibleAnywhere)
		TObjectPtr<URadialForceComponent> ForceComp;

	virtual void PostInitializeComponents() override;

	// Must be marked with ufunction in order to 'bind' the event
	UFUNCTION()
		void OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	
};
