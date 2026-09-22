// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BasicAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API UBasicAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

	UBasicAttributeSet();
	
public:

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS_BASIC(UBasicAttributeSet, Health)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS_BASIC(UBasicAttributeSet, MaxHealth)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS_BASIC(UBasicAttributeSet, Armor)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS_BASIC(UBasicAttributeSet, Strength)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData MovementSpeedMultiplier;
	ATTRIBUTE_ACCESSORS_BASIC(UBasicAttributeSet, MovementSpeedMultiplier)

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData CarryingCapacityMultiplier;
	ATTRIBUTE_ACCESSORS_BASIC(UBasicAttributeSet, CarryingCapacityMultiplier)
};
