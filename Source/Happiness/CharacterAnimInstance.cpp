// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAnimInstance.h"

#include "HappinessCharacter.h"

void UCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	HappinessCharacter=Cast<AHappinessCharacter>(TryGetPawnOwner());
}

void UCharacterAnimInstance::UpdateAnimationProperties()
{
	if(HappinessCharacter==nullptr)
	{
		HappinessCharacter=Cast<AHappinessCharacter>(TryGetPawnOwner());
	}
	if(HappinessCharacter==nullptr)
		return;
	FVector Velocity = HappinessCharacter->GetVelocity();
	Velocity.Z = 0.f;
	Speed = Velocity.Size();

	bIsThrowing=HappinessCharacter->IsThrowing();
}
