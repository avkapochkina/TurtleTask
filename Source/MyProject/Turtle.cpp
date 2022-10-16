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
	if (TimelineComponent != NULL)
	{
		TimelineComponent->TickComponent(DeltaTime, ELevelTick::LEVELTICK_TimeOnly, NULL);
	}
}

void ATurtle::Movement()
{
	TimelineValue = TimelineComponent->GetPlaybackPosition();
	//CurveFloatValue = RotateValue*DoorCurve->GetFloatValue(TimelineValue);

	//FQuat NewRotation = FQuat(FRotator(0.f, CurveFloatValue, 0.f));

	//this->SetActorLocation();
}

void ATurtle::StopMovement()
{
}

