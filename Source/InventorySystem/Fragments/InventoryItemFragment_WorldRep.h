// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventorySystem/Fragments/InventoryItemFragment.h"
#include "InventoryItemFragment_WorldRep.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API UInventoryItemFragment_WorldRep : public UInventoryItemFragment
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory Item")
	TObjectPtr<UStaticMesh> ItemMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Options")
	bool bCanBeDropped = true;
};
