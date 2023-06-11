// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <iostream>
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExploringUECode.generated.h"

UCLASS()
class PRACTICE_PROJECT_API AExploringUECode : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExploringUECode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Transient, Category = "TestProperty")
		int VA;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Transient, Category = "TestProperty")
		int VB;

	UFUNCTION(BlueprintCallable, Category = "TestFunction")
		int PrintMyValue();

	UFUNCTION(BlueprintImplementableEvent, Category = "TestFunction")
		void OnValueCalculate(int a,int b);

	UFUNCTION(BlueprintNativeEvent, Category = "TestFunction")
		void Countdown();
	
public:	
	// Called every frame

	virtual void Tick(float DeltaTime) override;
};
