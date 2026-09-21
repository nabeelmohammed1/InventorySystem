// Fill out your copyright notice in the Description page of Project Settings.


#include "HelperFunctions.h"

FText UHelperFunctions::GetReadableStatName(FGameplayTag Tag)
{
	FString TagName = Tag.GetTagName().ToString();

	//Finding the last segement of the Gameplay Tag to use for the UI
	int32 LastDotIndex;
	FString LastSegment = TagName.FindLastChar('.', LastDotIndex) ? TagName.RightChop(LastDotIndex + 1) : TagName;

	//Inserting a Space between Capital Letters
	FString ReadableName;
	for(int32 i = 0; i < LastSegment.Len(); ++i)
	{
		const TCHAR CurrentChar = LastSegment[i];
		const bool bNewWord = i > 0 && FChar::IsUpper(CurrentChar) && !FChar::IsUpper(LastSegment[i - 1]);

		if (bNewWord)
		{
			ReadableName += TEXT(" ");
		}
		ReadableName += CurrentChar;
	}

	return FText::FromString(ReadableName);
}
