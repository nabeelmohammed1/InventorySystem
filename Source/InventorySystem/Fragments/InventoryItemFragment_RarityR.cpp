// Fill out your copyright notice in the Description page of Project Settings.

#include "InventorySystem/Items/ItemInstance.h"
#include "InventorySystem/Fragments/InventoryItemFragment_RarityR.h"

void UInventoryItemFragment_RarityR::OnInstanceCreated_Implementation(UItemInstance* ItemInstance)
{
	if (!ItemInstance || RarityWeights.IsEmpty()) return;

	ItemInstance->SetItemRarity(RollRarity());
}

EItemRarity UInventoryItemFragment_RarityR::RollRarity() const
{
	float TotalWeight = 0.0f;

	for(const FRarityWeightedEntry& Entry : RarityWeights)
	{
		TotalWeight += FMath::Max(Entry.Weight, 0.f);
	}

	if(TotalWeight <= 0.f)
	{
		return EItemRarity::None;
	}

	const float Roll = FMath::FRandRange(0.f, TotalWeight);
	float AccumulatedWeight = 0.f;

	for (const FRarityWeightedEntry& Entry : RarityWeights)
	{
		AccumulatedWeight += FMath::Max(Entry.Weight, 0.f);
		if(Roll <= AccumulatedWeight)
		{
			return Entry.Rarity;
		}
	}

	return RarityWeights.Last().Rarity;
}
