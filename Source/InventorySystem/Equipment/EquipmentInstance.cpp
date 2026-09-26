// Fill out your copyright notice in the Description page of Project Settings.
#include "InventorySystem/Equipment/EquipmentInstance.h"
#include "InventorySystem/Fragments/InventoryFragment_Equippable.h"
#include "InventorySystem/Items/ItemInstance.h"
#include "InventorySystem/Equipment/EquipmentDefinition.h"
#include "GameFramework/Character.h"
#include "InventorySystem/AbilitySystem/BaseGameplayAbility.h"
#include "GameplayEffect.h"	
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"	
#include "GameplayAbilitySpec.h"
#include "GameFramework/CharacterMovementComponent.h"

void UEquipmentInstance::Initalize(UItemInstance* ItemInstance, ACharacter* Character, TSubclassOf<UGameplayEffect> EquipmentGE)
{
	if (!ItemInstance) return;

	SourceItemInstance = ItemInstance;

	const UInventoryFragment_Equippable* EquippableFragment = Cast<UInventoryFragment_Equippable>(
		ItemInstance->FindFragmentByClass(UInventoryFragment_Equippable::StaticClass())
	);

	if (!EquippableFragment) return;
	EquipmentDefinition = EquippableFragment->EquipmentDefinition;
	SpawnEquipmentActor(Character, EquipmentGE);
}

void UEquipmentInstance::SpawnEquipmentActor(ACharacter* Character,TSubclassOf<UGameplayEffect> EquipmentGE)
{
	UEquipmentDefinition* DefinitionCDO = EquipmentDefinition.GetDefaultObject();

	if (!DefinitionCDO) return;
	
	SpawnedEquipmentActor = GetWorld()->SpawnActor(DefinitionCDO->EquipmentActorClass);

	if (!SpawnedEquipmentActor) return;

	SpawnedEquipmentActor->AttachToComponent(
		Character->GetMesh(), 
		FAttachmentTransformRules::SnapToTargetIncludingScale,
		DefinitionCDO->EquipmentSocketName
	);

	UAbilitySystemComponent* OwnerASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Character);
	if (!OwnerASC) return;
	if(EquipmentGE)
	{
		FGameplayEffectContextHandle EffectContext = OwnerASC->MakeEffectContext();
		EffectContext.AddSourceObject(this); //Can also be sourceiteminstance depending on how you want to reference it.
		FGameplayEffectSpecHandle SpecHandle = OwnerASC->MakeOutgoingSpec(EquipmentGE, 1.f, EffectContext);

		if(SpecHandle.IsValid())
		{
			for (const auto& Pair : SourceItemInstance->StatsMap)
			{
				FGameplayTag StatTag = Pair.Key;
				float StatValue = Pair.Value;
				SpecHandle.Data->SetSetByCallerMagnitude(StatTag, StatValue);
			}
			const FActiveGameplayEffectHandle EffectHandle = OwnerASC->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data);

			AppliedGEHandles.Add(EffectHandle);
		}
	}

	if (DefinitionCDO->EffectsToApply.Num() > 0)
	{
		for (TSubclassOf<UGameplayEffect> EffectClass : DefinitionCDO->EffectsToApply)
		{
			FGameplayEffectContextHandle EffectContext = OwnerASC->MakeEffectContext();
			EffectContext.AddSourceObject(this);

			const FActiveGameplayEffectHandle EffectHandle = OwnerASC->ApplyGameplayEffectToSelf(
				EffectClass->GetDefaultObject<UGameplayEffect>(),
				1.f, EffectContext
			);

			AppliedGEHandles.Add(EffectHandle);

		}
	}

	if (DefinitionCDO->AbilitiesToGrant.Num() > 0)
	{
		for (TSubclassOf<UBaseGameplayAbility> AbilityClass : DefinitionCDO->AbilitiesToGrant)
		{
			if (!AbilityClass) continue;

			FGameplayAbilitySpec AbilitySpec(AbilityClass, 1, INDEX_NONE, this);
			const FGameplayAbilitySpecHandle AbilityHandle = OwnerASC->GiveAbility(AbilitySpec);

			GrantedAbilityHandles.Add(AbilityHandle);
		}
	}
}

void UEquipmentInstance::DestroyEquipmentActor(ACharacter* Character)
{
	if (SpawnedEquipmentActor)
	{
		SpawnedEquipmentActor->Destroy();
		SpawnedEquipmentActor = nullptr;
		UAbilitySystemComponent* OwnerASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Character);

		if(OwnerASC)
		{
			for (FActiveGameplayEffectHandle& EffectHandle : AppliedGEHandles)
			{
				OwnerASC->RemoveActiveGameplayEffect(EffectHandle);
				EffectHandle.Invalidate();

			}

			for (const FGameplayAbilitySpecHandle& AbilityHandle : GrantedAbilityHandles)
			{
				OwnerASC->ClearAbility(AbilityHandle);
			}
		}

		AppliedGEHandles.Empty();
		GrantedAbilityHandles.Empty();
	}

	//remove gameplay effects and stats in this function.
}
