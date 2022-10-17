// Fill out your copyright notice in the Description page of Project Settings.


#include "Turtle.h"

#include "Components/TimelineComponent.h"


// Sets default values
ATurtle::ATurtle()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;
}

// Called when the game starts or when spawned
void ATurtle::BeginPlay()
{
	Super::BeginPlay();
	if (SpeedCurve)
	{
		FOnTimelineFloat TimelineCallback;
		FOnTimelineEventStatic TimelineFinishedCallback;

		TimelineCallback.BindUFunction(this, FName("Movement"));
		TimelineFinishedCallback.BindUFunction(this, FName("StopMovement"));

		TimelineComponent = NewObject<UTimelineComponent>(this, FName("TimelineComponent"));
		TimelineComponent->AddInterpFloat(SpeedCurve, TimelineCallback);
		TimelineComponent->SetTimelineFinishedFunc(TimelineFinishedCallback);        
		TimelineComponent->RegisterComponent();
	}
}

// Called every frame
void ATurtle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (TimelineComponent != nullptr)
	{
		TimelineComponent->TickComponent(DeltaTime, ELevelTick::LEVELTICK_TimeOnly, nullptr);
	}
	else
	{
		printf("error");
	}
}

void ATurtle::Movement()
{
	TimelineValue = TimelineComponent->GetPlaybackPosition();
	//delta = Speed*SpeedCurve->GetFloatValue(TimelineValue);
	//this->SetActorLocation(this->GetActorLocation() + Speed*MovementDirection*SpeedCurve->GetFloatValue(TimelineValue));
	this->SetActorLocation(this->GetActorLocation() + Speed*MovementDirection);
}

void ATurtle::StopMovement()
{
	//
}

