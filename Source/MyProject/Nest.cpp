// Fill out your copyright notice in the Description page of Project Settings.


#include "Nest.h"
#include "Turtle.h"

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
	if(GetWorld() && SpawnBP)
	{
		Spawn();
	}
}

void ANest::Spawn()
{
	UE_LOG(LogActor, Warning, TEXT("Spawn begin"));
	FActorSpawnParameters SpawnParameters = FActorSpawnParameters();
	SpawnParameters.Owner = this->GetOwner();
	ATurtle* Turtle = GetWorld()->SpawnActor<ATurtle>(SpawnBP, GetActorLocation(), GetActorRotation(), SpawnParameters);
	UE_LOG(LogActor, Warning, TEXT("Spawn completed"));
	if(SpawnQueue.Add(Turtle))
	{
		UE_LOG(LogActor, Warning, TEXT("SpawnQueue.Add(Turtle)"));
	}
	Turtle->Init(GetActorLocation(), EndPoint);
	UE_LOG(LogActor, Warning, TEXT("%f, %f"), Turtle->SpawnPoint.Length(), Turtle->SpawnPoint.Length());
}

// Called every frame
void ANest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

