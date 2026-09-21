// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include <GameplayTagContainer.h>
#include "HelperFunctions.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API UHelperFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintPure, Category = "UI")
	static FText GetReadableStatName(FGameplayTag Tag);
};
