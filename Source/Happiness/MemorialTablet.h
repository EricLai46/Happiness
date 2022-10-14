// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "HappinessCharacter.h"
#include "MemorialTablet.generated.h"

UCLASS()
class HAPPINESS_API AMemorialTablet : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMemorialTablet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION()
	virtual void OnSphereOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere,Category="MemorialTablet")
	class UStaticMeshComponent* MemorialStaticMeshComponent;
	UPROPERTY(VisibleAnywhere,Category="MemorialTablet")
	class UBoxComponent* MemorialTabletBoxComponent;

	UPROPERTY(EditAnywhere,Category="MemorialTablet")
	class UParticleSystem* MemorialTabletParticleSystem;

	
	class UParticleSystemComponent* MemorialtabletParticleSystemComponent;
};
