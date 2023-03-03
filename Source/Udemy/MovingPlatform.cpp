// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	//액터의 위치를 갖고오는데 중요
	if (HasAuthority()) {

		SetReplicates(true);
		SetReplicateMovement(true);
	}
	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (ActiveTriggers > 0) {
		if (HasAuthority()) {
			FVector Location = GetActorLocation();
			float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
			float JourneyTravelled = (Location - GlobalStartLocation).Size();
			if (JourneyTravelled >= JourneyLength) {
				FVector t = GlobalTargetLocation;
				GlobalTargetLocation = GlobalStartLocation;
				GlobalStartLocation = t;
			}
			FVector tmp = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
			Location += tmp * speed * DeltaTime;

			SetActorLocation(Location);
		}
		else {

		}
	}
	//True: 서버, 
	
}

void AMovingPlatform::AddActiveTrigger()
{
	ActiveTriggers +=1;
}

void AMovingPlatform::RemoveActiveTrigger()
{
	if(ActiveTriggers>0)
		ActiveTriggers -=1;
}
