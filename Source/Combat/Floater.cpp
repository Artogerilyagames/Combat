// Fill out your copyright notice in the Description page of Project Settings.


#include "Floater.h"

#include "Particles/ParticleSystemComponent.h"

// Sets default values
AFloater::AFloater()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CustomStaticMesh"));
	Flame = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Flame"));
	Flame->SetupAttachment(StaticMesh);

}

// Called when the game starts or when spawned
void AFloater::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

