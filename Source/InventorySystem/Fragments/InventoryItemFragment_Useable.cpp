// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySystem/Fragments/InventoryItemFragment_Useable.h"
#include "InventorySystem/ItemAction.h"

bool UInventoryItemFragment_Useable::Use(AActor* ItemOwner)
{
	bool bAnySucceeded = false;

	for (const TObjectPtr<UItemAction>& Action : ItemActions)
	{
		if (Action && Action->Exectue(ItemOwner))
		{
			bAnySucceeded = true;
		}
	}
	return bAnySucceeded;
}
