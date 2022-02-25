// Fill out your copyright notice in the Description page of Project Settings.


#include "Floater.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AFloater::AFloater()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CustomStaticMesh"));

	InitialLocation = FVector(0.0f);
	PlacedLocation = FVector(0.0f);
	WorldOrigin = FVector(0.0f, 0.0f, 0.0f);
	InitialDirection = FVector(0.0f, 0.0f, 0.0f);
	
	bInitializeFloaterLocation = false;
	bShouldFloat = false;
	InitialForce  = FVector(2000.0f, 0.0f, 0.0f);
	InitialTorque  = FVector(2000.0f, 0.0f, 0.0f);

	RunningTime = 0.f;

	A = 0.f;
	B = 0.f;
	C = 0.f;
	D = 0.f;
	
	
	Flame = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Flame"));
	Flame->SetupAttachment(StaticMesh);

}

// Called when the game starts or when spawned
void AFloater::BeginPlay()
{
	Super::BeginPlay();

	float  InitialX = FMath::FRandRange(-500.f, 500.f);
	float  InitialY = FMath::FRandRange(-500.f, 500.f);
	float  InitialZ = FMath::FRandRange(0.f, 500.f);

	InitialLocation.X = InitialX;
	InitialLocation.Y = InitialY;
	InitialLocation.Z = InitialZ;

	


	

	PlacedLocation = GetActorLocation();
	if(bInitializeFloaterLocation)
	{
		SetActorLocation(InitialLocation);
	}
	BaseZLocation = PlacedLocation.Z;
	//FHitResult HitResult;
	// ReSharper disable once CppDeclaratorNeverUsed

	//StaticMesh->AddForce(InitialForce);
	//StaticMesh->AddTorqueInRadians(InitialTorque);
	//FRotator Rotation = FRotator(40.0f, 30.0f, 0.0f);
	//AddActorLocalRotation(Rotation);
	//AddActorWorldOffset(InitialDirection, false, &HitResult);
	
	
}

// Called every frame
void AFloater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(bShouldFloat)
	{
		/*FHitResult HitResult;
		AddActorLocalOffset(InitialDirection, false, &HitResult);
		// ReSharper disable once CppDeclaratorNeverUsed
		FVector HitLocation = HitResult.Location;*/
        FVector NewLocation = GetActorLocation();
		NewLocation.Z = BaseZLocation + A * FMath::Sin(B * RunningTime - C) + D; // period = 2 * PI /ABS(B)

		SetActorLocation(NewLocation);
		RunningTime += DeltaTime;
	}

	

}

