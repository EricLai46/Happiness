// Fill out your copyright notice in the Description page of Project Settings.


#include "MemorialTablet.h"

#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
AMemorialTablet::AMemorialTablet()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	MemorialStaticMeshComponent=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MemorialTabletMeshComponent"));
    MemorialTabletBoxComponent=CreateDefaultSubobject<UBoxComponent>(TEXT("MemorialTabletSphereComponent"));
	SetRootComponent(MemorialStaticMeshComponent);
	MemorialTabletBoxComponent->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AMemorialTablet::BeginPlay()
{
	Super::BeginPlay();
	MemorialTabletBoxComponent->OnComponentBeginOverlap.AddDynamic(this,&AMemorialTablet::OnSphereOverlap);
}

void AMemorialTablet::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AHappinessCharacter* MainCharacter=Cast<AHappinessCharacter>(OtherActor);
		if(GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Red,FString("Collision"),true,FVector2d(3.4,6.3));
		}
	UE_LOG(LogTemp, Warning, TEXT("Line Hit is %f"), 3.02f);
}

// Called every frame
void AMemorialTablet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMemorialTablet::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

