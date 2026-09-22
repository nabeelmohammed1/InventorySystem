// Fill out your copyright notice in the Description page of Project Settings.
#include "InventorySystem/Equipment/EquipmentInstance.h"
#include "InventorySystem/Fragments/InventoryFragment_Equippable.h"
#include "InventorySystem/Items/ItemInstance.h"
#include "InventorySystem/Equipment/EquipmentDefinition.h"
#include "GameFramework/Character.h"

void UEquipmentInstance::Initalize(UItemInstance* ItemInstance, ACharacter* Character)
{
	if (!ItemInstance) return;

	SourceItemInstance = ItemInstance;

	const UInventoryFragment_Equippable* EquippableFragment = Cast<UInventoryFragment_Equippable>(
		ItemInstance->FindFragmentByClass(UInventoryFragment_Equippable::StaticClass())
	);

	if (!EquippableFragment) return;
	EquipmentDefinition = EquippableFragment->EquipmentDefinition;
	SpawnEquipmentActor(Character);
}

void UEquipmentInstance::SpawnEquipmentActor(ACharacter* Character)
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

	//Can add gameplay effects and stats in this function.
}

void UEquipmentInstance::DestroyEquipmentActor(ACharacter* Character)
{
	if (SpawnedEquipmentActor)
	{
		SpawnedEquipmentActor->Destroy();
		SpawnedEquipmentActor = nullptr;
	}

	//remove gameplay effects and stats in this function.
}
