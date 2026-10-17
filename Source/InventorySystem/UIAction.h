// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UIAction.generated.h"

class UWidget;
class UInventoryManager;
class UItemInstance;
/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, Abstract, DefaultToInstanced, EditInlineNew)
class INVENTORYSYSTEM_API UUIAction : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	bool Exectue(UInventoryManager* InventoryManagerComponent,UItemInstance* ItemInstance, UWidget* Widget);
	
	
	
};
