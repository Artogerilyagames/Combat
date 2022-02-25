// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Floater.generated.h"

UCLASS()
class COMBAT_API AFloater : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloater();


    UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category= "ActorMeshComponents")
	UStaticMeshComponent* StaticMesh;
	// Location used by SetActorLocation() when BeginPlay() is called
	UPROPERTY(EditInstanceOnly,BlueprintReadWrite, Category= "Floater Variables")
	FVector InitialLocation;
	// Location of the Actor when dragged in from the editor
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category= "Floater Variables")
	FVector PlacedLocation;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category= "Floater Variables")
	FVector WorldOrigin;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Floater Variables")
	FVector InitialDirection;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Floater Variables")
	bool bShouldFloat;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=  "Floater Variables")
	bool bInitializeFloaterLocation;
    UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category= "Floater Variables")
	FVector InitialForce;
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category= "Floater Variables")
	FVector InitialTorque;

	

	
	UPROPERTY(VisibleAnywhere, Category= "ActorMeshComponents")
	UParticleSystemComponent* Flame;

private:
	
	float RunningTime;
	float BaseZLocation;

public:
	//Amplitude - how much we oscillate up and down
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Floater Variable")
	float A;
	//Period is 2 * PI (absolute value of B)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Floater Variable")
	float B;
	//Phase Shift id (C/D)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Floater Variable")
	float C;
	// Vertical Shift is D
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Floater Variable")
	float D;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
