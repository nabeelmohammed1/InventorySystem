// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventorySystem/Fragments/InventoryItemFragment.h"
#include "InventorySystem/Items/ItemDefinition.h"
#include "InventoryItemFragment_RarityR.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FRarityWeightedEntry
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Rarity")
	EItemRarity Rarity = EItemRarity::Common;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Rarity", meta = (ClampMin = "0.0"))
	float Weight = 1.0f;
};

UCLASS(meta = (DisplayName = "Random Rarity"))
class INVENTORYSYSTEM_API UInventoryItemFragment_RarityR : public UInventoryItemFragment
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Rarity")
	TArray<FRarityWeightedEntry> RarityWeights;

	virtual void OnInstanceCreated_Implementation(UItemInstance* ItemInstance) override;


protected:

	UFUNCTION(BlueprintPure, Category = "Rarity")
	EItemRarity RollRarity() const;
};
