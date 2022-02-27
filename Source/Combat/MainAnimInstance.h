// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MainAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class COMBAT_API UMainAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
    UFUNCTION(BlueprintCallable, Category= AnimationProperties)
	void UpdateAnimationProperties();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Movement, meta = (AllowPrivateAccess= "true"))
	float MovementSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Movement, meta = (AllowPrivateAccess= "true"))
	bool bIsInAir;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Movement, meta = (AllowPrivateAccess= "true"))
	class APawn*Pawn;
	
};
