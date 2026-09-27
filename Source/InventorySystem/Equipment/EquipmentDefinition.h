// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameplayTagContainer.h"
#include "GameplayEffect.h"	
#include "EquipmentDefinition.generated.h"

class UBaseGameplayAbility;
/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, Abstract, Const)
class INVENTORYSYSTEM_API UEquipmentDefinition : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equipment Actor")
	TSubclassOf<AActor> EquipmentActorClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equipment Actor")
	FName EquipmentSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equipment Slot", meta = (Categories = "Equipment.Slot"))
	FGameplayTag SlotTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equipment | Effects")
	TArray<TSubclassOf<UGameplayEffect>> EffectsToApply;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equipment | Abilities")
	TArray<TSubclassOf<UBaseGameplayAbility>> AbilitiesToGrant;
	
};
