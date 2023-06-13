// Fill out your copyright notice in the Description page of Project Settings.

#include "ACInteractionComponent.h"
#include "GamePlayInterface.h"
#include "DrawDebugHelpers.h"


// Sets default values for this component's properties
UACInteractionComponent::UACInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UACInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UACInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UACInteractionComponent::PrimaryInteract()
{
	FVector Start, End;

	FHitResult Hit;
	TArray<FHitResult> Hits;

	FCollisionObjectQueryParams QueryParams;
	QueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);

	AActor* TheOwner = GetOwner();

	FVector EyeLocation;
	FRotator EyeRotation;
	TheOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation);

	Start = EyeLocation;
	End = EyeLocation + (EyeRotation.Vector()) * 300;

	float Radius = 30.0f;
	FCollisionShape Shape;
	Shape.SetSphere(Radius);

	bool bHitBlocking1 = GetWorld()->LineTraceSingleByObjectType(Hit, Start, End, QueryParams);

	bool bHitBlocking2 = GetWorld()->SweepMultiByObjectType(Hits, Start, End, FQuat::Identity, QueryParams, Shape);

	FColor LineColor = bHitBlocking1 ? FColor::Yellow : FColor::Blue;

	for (FHitResult hit : Hits)
	{
		AActor* HitActor = hit.GetActor();
		if (HitActor)
		{
			if (HitActor->Implements<UGamePlayInterface>())
			{
				IGamePlayInterface::Execute_Interact(HitActor, Cast<APawn>(TheOwner));
			}
			DrawDebugSphere(GetWorld(), hit.ImpactPoint, Radius, 16, FColor::Green, false, 2.0f);
		}
		break;  //hit the first chest then break.Otherwise it will open several chest ONCE.
	}
	DrawDebugLine(GetWorld(), Start, End, LineColor, false, 2.0f, 0, 1.0);
}



