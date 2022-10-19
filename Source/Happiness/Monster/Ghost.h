// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Ghost.generated.h"


UENUM(BlueprintType)
enum class GhostState : uint8
{
	Idle=0 UMETA(DisplayName="Idle"),
	Walk=1 UMETA(DisplayName="Walk"),
	Attack=2 UMETA(DisplayName="Attack"),
};
UCLASS()
class HAPPINESS_API AGhost : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGhost();
	UPROPERTY(VisibleAnywhere,Category="Ghost",BlueprintReadOnly)
	GhostState Ghost_State;

	UFUNCTION(BlueprintCallable,Category="Ghost")
	FORCEINLINE GhostState GetGhostState() const{return Ghost_State;}
	
	UFUNCTION(BlueprintCallable,Category="Ghost")
	FORCEINLINE void SetGhostState(GhostState state) {Ghost_State=state;}
	
	UFUNCTION(BlueprintCallable,Category="Ghost")
	void MovetoTarget(class AHappinessCharacter* Character);

	UFUNCTION(BlueprintCallable,Category="Ghost")
	void AttackTarget(class AHappinessCharacter* Character);
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
	UFUNCTION()
	virtual void OnCombatSphereOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnSphereEndlap(
	UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

	UFUNCTION()
	virtual void OnCombatSphereEndlap(
	UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere,Category="Ghost")
	class USphereComponent* GhostSphereComponent;

	UPROPERTY(VisibleAnywhere,Category="Ghost")
    class AAIController* AIController;

	UPROPERTY(EditAnywhere,Category="Ghost")
	class USphereComponent* GhostCombatComponent;
private:

	UPROPERTY(VisibleAnywhere,Category="Ghost")
	class UGhostAnimInstance* GhostAnimInstance;

	
	
};
