// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "ExorcismItem.generated.h"

/**
 * 
 */
UCLASS()
class HAPPINESS_API UExorcismItem : public UItem
{
	GENERATED_BODY()

protected:

	virtual void Use(class AHappinessCharacter* Character) override;
};
