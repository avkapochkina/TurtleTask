// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Turtle.generated.h"

class UTimelineComponent;

// Базовый класс черепашек
// Характер движения задаётся в BP
UCLASS()
class MYPROJECT_API ATurtle : public AActor
{
	GENERATED_BODY()

public:
	ATurtle();
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
	void Init(const FVector Spawn, const FVector End);
	UFUNCTION()
	void StopMovement();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* MeshComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAudioComponent* AudioComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundBase* StartSound;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundBase* MovementSound;
	
	FVector SpawnPoint;
	FVector EndPoint;
	FVector MovementDirection;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed = 5.0;
};
