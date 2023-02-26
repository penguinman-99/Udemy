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
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector Location = GetActorLocation();
	Location += FVector(speed * DeltaTime, 0.0f, 0.0f);

	//True: 서버, 
	if (HasAuthority()) {
		SetActorLocation(Location);
	}
	else {

	}
}
