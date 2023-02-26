// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class UDEMY_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
public:
	AMovingPlatform();
	UPROPERTY(EditAnywhere)
	float speed=5.0f;
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
};
