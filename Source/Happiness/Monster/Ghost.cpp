// Fill out your copyright notice in the Description page of Project Settings.


#include "Ghost.h"

#include "AIController.h"
#include "GhostAnimInstance.h"
#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"
#include "Happiness/HappinessCharacter.h"

// Sets default values
AGhost::AGhost()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    GhostSphereComponent=CreateDefaultSubobject<USphereComponent>(TEXT("GhostNavigationSphereComponent"));
	GhostSphereComponent->SetupAttachment(GetRootComponent());
	GhostAnimInstance =Cast<UGhostAnimInstance>(GetMesh()->GetAnimInstance());

	GhostCombatComponent=CreateDefaultSubobject<USphereComponent>(TEXT("GhostCombatComponent"));
	GhostCombatComponent->SetupAttachment(GetRootComponent());
}



// Called when the game starts or when spawned
void AGhost::BeginPlay()
{
	Super::BeginPlay();

	GhostSphereComponent->OnComponentBeginOverlap.AddDynamic(this,&AGhost::OnSphereOverlap);
    GhostCombatComponent->OnComponentBeginOverlap.AddDynamic(this,&AGhost::OnCombatSphereOverlap);
	GhostCombatComponent->OnComponentEndOverlap.AddDynamic(this,&AGhost::OnCombatSphereEndlap);
	GhostSphereComponent->OnComponentEndOverlap.AddDynamic(this,&AGhost::OnSphereEndlap);
	AIController=Cast<AAIController>(GetController());
}

void AGhost::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor)
	{
		AHappinessCharacter* HappinessCharacter=Cast<AHappinessCharacter>(OtherActor);
	
		if(HappinessCharacter)
		{
			/*if(GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Red,FString("hhh"),true,FVector2d(3.4,6.3));
			}*/
			MovetoTarget(HappinessCharacter);
		}
	}
}

void AGhost::OnCombatSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AHappinessCharacter* HappinessCharacter=Cast<AHappinessCharacter>(OtherActor);
	if(HappinessCharacter)
	{
		/*if(GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Red,FString("hhh"),true,FVector2d(3.4,6.3));
		}*/
		AttackTarget(HappinessCharacter);
	}
}

void AGhost::OnSphereEndlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AHappinessCharacter* HappinessCharacter=Cast<AHappinessCharacter>(OtherActor);
	if(HappinessCharacter)
	{
		/*if(GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Red,FString("hhh"),true,FVector2d(3.4,6.3));
		}*/
		SetGhostState(GhostState::Idle);
	}
}

void AGhost::OnCombatSphereEndlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
AHappinessCharacter* HappinessCharacter=Cast<AHappinessCharacter>(OtherActor);
	if(HappinessCharacter)
	{
		/*if(GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Red,FString("hhh"),true,FVector2d(3.4,6.3));
		}*/
		if(Ghost_State==GhostState::Attack)
		{
			return;
		}
		else
		{
			SetGhostState(GhostState::Walk);
		}
	}
	
}

// Called every frame
void AGhost::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGhost::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void AGhost::MovetoTarget(AHappinessCharacter* Character)
{
	SetGhostState(GhostState::Walk);
	
	FAIMoveRequest MoveRequest;
	MoveRequest.SetGoalActor(Character);
	MoveRequest.SetAcceptanceRadius(5.0f);

	FNavPathSharedPtr NavPath;

	AIController->MoveTo(MoveRequest,&NavPath);
	
}

void AGhost::AttackTarget(AHappinessCharacter* Character)
{
	
	SetGhostState(GhostState::Attack);
}
