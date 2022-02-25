// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Pawn.h"
#include "Collider.generated.h"

UCLASS()
class COMBAT_API ACollider : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACollider();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	UPROPERTY(VisibleAnywhere, Category= "Mesh")
	class UStaticMeshComponent* StaticMeshComponent;
	UPROPERTY(VisibleAnywhere, Category= "Mesh")
	class USphereComponent* SphereComponent;

public:

	
	
    FORCEINLINE UStaticMeshComponent* GetMeshComponent() {return StaticMeshComponent;}
	FORCEINLINE void SetMeshComponent(UStaticMeshComponent* Mesh) {StaticMeshComponent = Mesh;}
	FORCEINLINE USphereComponent* GetSphereComponent() {return SphereComponent;}
	FORCEINLINE void SetSphereComponent(USphereComponent* Sphere) {SphereComponent = Sphere;}

};
