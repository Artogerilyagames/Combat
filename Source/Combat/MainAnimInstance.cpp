// Fill out your copyright notice in the Description page of Project Settings.


#include "MainAnimInstance.h"

#include "GameFramework/PawnMovementComponent.h"

void UMainAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	if(Pawn == nullptr)
	{
	}
}

void UMainAnimInstance::UpdateAnimationProperties()
{
	if(Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
	}
	if(Pawn)
	{
		FVector Speed = Pawn->GetVelocity();
		FVector LateralSpeed = FVector(Speed.X, Speed.Y, 0.f);
		MovementSpeed = LateralSpeed.Size();
		bIsInAir = Pawn->GetMovementComponent()->IsFalling();
	}
}
