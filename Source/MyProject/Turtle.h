// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Turtle.generated.h"

class UTimelineComponent;

UCLASS()
class MYPROJECT_API ATurtle : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATurtle();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComponent;
	UPROPERTY(EditAnywhere)
	USoundWave* MovementSound;
	
	FVector SpawnPoint;
	FVector EndPoint;
	float Speed;
	
	UPROPERTY(EditAnywhere)
	UCurveFloat* SpeedCurve;
	UPROPERTY()
	float CurveFloatValue;
	UPROPERTY()
	float TimelineValue;
	UPROPERTY()
	UTimelineComponent* TimelineComponent;

	UFUNCTION()
	void Movement();
	UFUNCTION()
	void StopMovement();
};
