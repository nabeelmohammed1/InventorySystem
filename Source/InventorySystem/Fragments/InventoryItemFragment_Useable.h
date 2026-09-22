// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventorySystem/Fragments/InventoryItemFragment.h"
#include "InventoryItemFragment_Useable.generated.h"

class UItemAction;
class UItemInstance;
/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API UInventoryItemFragment_Useable : public UInventoryItemFragment
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable)
	bool Use(AActor* ItemOwner,UItemInstance* ItemInstance);	

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Options")
	bool bComsumeOnUse = true;	

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly,Instanced ,Category = "Actions")
	TArray<TObjectPtr<UItemAction>> ItemActions;
};
