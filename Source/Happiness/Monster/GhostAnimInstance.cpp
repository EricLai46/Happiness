// Fill out your copyright notice in the Description page of Project Settings.


#include "GhostAnimInstance.h"

#include "Ghost.h"
#include "GameFramework/CharacterMovementComponent.h"

void UGhostAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	Ghost=Cast<AGhost>(TryGetPawnOwner());
}

void UGhostAnimInstance::UpdateAnimationProperties()
{
	if(Ghost==nullptr)
	{
		Ghost=Cast<AGhost>(TryGetPawnOwner());
	}
	if(Ghost==nullptr)
	return;
	FVector Velocity=Ghost->GetVelocity();
	Velocity.Z=0.f;
	speed=Velocity.Size();

	bIsWalking=(Ghost->GetGhostState()==GhostState::Walk) ? true : false;
	bIsAttacking=(Ghost->GetGhostState()==GhostState::Attack) ? true : false;
	bIsIdleing=(Ghost->GetGhostState()==GhostState::Idle) ? true : false;
}
