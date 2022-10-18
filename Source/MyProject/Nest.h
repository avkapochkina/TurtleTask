// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Nest.generated.h"

UCLASS()
class MYPROJECT_API ANest : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ANest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* MeshComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector EndPoint;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> SpawnBP;
	// Массив черепашек
	// Одновременно в каждом гнезде существует не более TurtlesMax черепашек
	UPROPERTY()
	TArray<AActor*> Turtles;
	unsigned TurtlesMax = 10;
	
	UFUNCTION(BlueprintCallable)
	void Spawn();
};
