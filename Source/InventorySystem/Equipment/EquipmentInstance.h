// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameplayEffect.h"
#include "ActiveGameplayEffectHandle.h"
#include "EquipmentInstance.generated.h"

class UItemInstance;
class UEquipmentDefinition;
/**
 * 
 */
UCLASS(BlueprintType)
class INVENTORYSYSTEM_API UEquipmentInstance : public UObject
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(BlueprintReadOnly, Category = "Equipment Instance")
	TSubclassOf<UEquipmentDefinition> EquipmentDefinition;

	UPROPERTY(BlueprintReadOnly, Category = "Equipment Instance")
	TObjectPtr<UItemInstance> SourceItemInstance;

	UPROPERTY(BlueprintReadOnly, Category = "Equipment Instance")
	TObjectPtr<AActor> SpawnedEquipmentActor;

	UPROPERTY(BlueprintReadOnly, Category = "GAS")
	TArray<FActiveGameplayEffectHandle> AppliedGEHandles;


	UFUNCTION(BlueprintCallable, Category = "Equipment Instance")
	void Initalize(UItemInstance* ItemInstance, ACharacter* Character, TSubclassOf<UGameplayEffect> EquipmentGE);


	UFUNCTION(BlueprintCallable, Category = "Equipment Instance")
	void SpawnEquipmentActor(ACharacter* Character, TSubclassOf<UGameplayEffect> EquipmentGE);

	UFUNCTION(BlueprintCallable, Category = "Equipment Instance")
	void DestroyEquipmentActor(ACharacter* Character);
};
