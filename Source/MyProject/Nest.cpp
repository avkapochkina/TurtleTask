// Fill out your copyright notice in the Description page of Project Settings.


#include "Nest.h"

#include "Turtle.h"

// Sets default values
ANest::ANest()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;
}

// Called when the game starts or when spawned
void ANest::BeginPlay()
{
	Super::BeginPlay();
	SpawnPoint = GetActorLocation();
	Spawn();
}

void ANest::Spawn()
{
	if(GetWorld() && SpawnBP)
	{
		FActorSpawnParameters SpawnParameters = FActorSpawnParameters();
		SpawnParameters.Owner = this->GetOwner();
		ATurtle* Turtle = GetWorld()->SpawnActor<ATurtle>(SpawnBP, this->GetActorLocation(), this->GetActorRotation(), SpawnParameters);
		SpawnQueue.Add(Turtle);
		Turtle->MovementDirection = EndPoint - SpawnPoint;
		//Turtle->SpawnPoint = SpawnPoint;
	}
}

// Called every frame
void ANest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

