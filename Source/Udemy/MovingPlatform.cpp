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
	//������ ��ġ�� �������µ� �߿�
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

	//True: ����, 
	if (HasAuthority()) {
		SetActorLocation(Location);
	}
	else {

	}
}