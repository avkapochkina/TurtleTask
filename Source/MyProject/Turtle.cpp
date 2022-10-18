// Fill out your copyright notice in the Description page of Project Settings.


#include "Turtle.h"

// Sets default values
ATurtle::ATurtle()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;
	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComponent"));
}

// Called when the game starts or when spawned
void ATurtle::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogActor, Warning, TEXT("ATurtle::BeginPlay()"));
}

// Called every frame
void ATurtle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// Проверяем оставшееся до EndPoint расстояние
	// Если оно больше одного шага - продолжаем движение
	
	const FVector Delta = EndPoint - GetActorLocation();
	if(Delta.Length() > Speed)
	{
		SetActorLocation(GetActorLocation() + Speed * MovementDirection);
		if (AudioComponent && !AudioComponent->IsActive())
		{
			AudioComponent = UGameplayStatics::SpawnSound2D(this, MovementSound);
		}
	}
	else
	{
		if (AudioComponent)
			AudioComponent->Stop();
		StopMovement();
	}
}

void ATurtle::Init(const FVector Spawn, const FVector End)
{
	SpawnPoint = Spawn;
	EndPoint = End;
	
	MovementDirection = EndPoint - SpawnPoint;
	MovementDirection.Normalize();
	
	UE_LOG(LogActor, Warning, TEXT("Turtle: %f, %f"), EndPoint.Length(), SpawnPoint.Length());
	UE_LOG(LogActor, Warning, TEXT("MovementDirection.Length %f"), MovementDirection.Length());
	
	if (AudioComponent)
	{
		AudioComponent = UGameplayStatics::SpawnSound2D(this, StartSound);
	}
}

void ATurtle::StopMovement()
{
	SetActorTickEnabled(false);
	UE_LOG(LogActor, Error, TEXT("ATurtle::StopMovement()"));
	
	if (AudioComponent)
	{
		AudioComponent = UGameplayStatics::SpawnSound2D(this, StartSound);
	}
}

