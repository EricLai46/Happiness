// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class HAPPINESS_API UCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	UFUNCTION(BlueprintCallable)
	void UpdateAnimationProperties();



private:
	
	UPROPERTY(BlueprintReadOnly,Category="HappinessCharacter",meta=(AllowPrivateAccess="true"))
	class AHappinessCharacter* HappinessCharacter;

	UPROPERTY(BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	float Speed;
	
	UPROPERTY(BlueprintReadOnly, Category = Action, meta = (AllowPrivateAccess = "true"))
	bool bIsThrowing;
};
