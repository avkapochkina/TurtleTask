// Fill out your copyright notice in the Description page of Project Settings.


#include "Nest.h"


// Sets default values
ANest::ANest()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;
}

// Called when the game starts or when spawned
void ANest::BeginPlay()
{
	Super::BeginPlay();
	SpawnPoint = GetActorLocation();
}

void ANest::Spawn()
{
	
}

// Called every frame
void ANest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

