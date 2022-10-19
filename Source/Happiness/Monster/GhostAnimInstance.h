// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GhostAnimInstance.generated.h"

/**
 * 
*/

UCLASS()
class HAPPINESS_API UGhostAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	UFUNCTION(BlueprintCallable)
	void UpdateAnimationProperties();

	UPROPERTY(BlueprintReadOnly,Category="Ghost",meta=(AllowPrivateAccess="true"))
	class AGhost* Ghost;

private:
	UPROPERTY(BlueprintReadOnly,Category="Ghost",meta=(AllowPrivateAccess="true"))
	float speed;
	UPROPERTY(BlueprintReadOnly,Category="Ghost",meta=(AllowPrivateAccess="true"))
	bool bIsAttacking;
	UPROPERTY(BlueprintReadOnly,Category="Ghost",meta=(AllowPrivateAccess="true"))
	bool bIsWalking;
	UPROPERTY(BlueprintReadOnly,Category="Ghost",meta=(AllowPrivateAccess="true"))
	bool bIsIdleing;
};
