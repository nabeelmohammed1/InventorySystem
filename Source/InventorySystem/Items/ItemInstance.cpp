// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySystem/Items/ItemInstance.h"
#include "InventorySystem/Fragments/InventoryItemFragment.h"
#include "InventorySystem/Items/ItemDefinition.h"

float UItemInstance::GetStatValue(FGameplayTag StatTag)
{
	return StatsMap.FindRef(StatTag);
}

void UItemInstance::SetStatValue(FGameplayTag StatTag, float StatValue)
{
	StatsMap.Add(StatTag, StatValue);
}

void UItemInstance::Initialzie(TSubclassOf<UItemDefinition> ItemDef, const TMap<FGameplayTag, float>& InitalStats)
{
	if (!ItemDef) return;

	ItemDefinition = ItemDef;

	UItemDefinition* ItemCDO = ItemDefinition.GetDefaultObject();

	for (const TObjectPtr<UInventoryItemFragment>& Fragment : ItemCDO->Fragments)
	{
		Fragment->OnInstanceCreated(this);
	}

	if(!InitalStats.IsEmpty())
	{
		StatsMap = InitalStats;
	}
}

const UInventoryItemFragment* UItemInstance::FindFragmentByClass(const TSubclassOf<UInventoryItemFragment> FragmentClass)
{
	if (!FragmentClass) return nullptr;

	UItemDefinition* ItemCDO = ItemDefinition.GetDefaultObject();

	return ItemCDO->FindFragmentByClass(ItemDefinition,FragmentClass);
}

void UItemInstance::SetItemRarity(EItemRarity NewRarity)
{
	// Set the rarity of the item instance
	Rarity = NewRarity;
}

EItemRarity UItemInstance::GetItemRarity() const
{
	if(Rarity != EItemRarity::None)
	{
		return Rarity;
	}

	if (ItemDefinition)
	{
		return ItemDefinition.GetDefaultObject()->ItemRarity;
	}
	
	return EItemRarity();
}
