// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "BaseGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API UBaseGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
public: 

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ability")
	FName AbilityName = "Default Ability";

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ability")
	float AttackPower = 10.f;
};
