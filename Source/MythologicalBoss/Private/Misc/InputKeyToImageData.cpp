// Copyright Overthrone Studios 2019

#include "InputKeyToImageData.h"

UTexture2D* UInputKeyToImageData::GetTextureFromKey(const FKey Key)
{
	for (auto It = InputKeys.CreateIterator(); It; ++It)
	{
		if (It.Key() == Key)
			return It.Value();
	}

	return nullptr;
}

UTexture2D* UInputKeyToImageData::GetTextureGlowFromKey(const FKey Key)
{
	for (auto It = InputKeysGlow.CreateIterator(); It; ++It)
	{
		if (It.Key() == Key)
			return It.Value();
	}

	return DefaultGlow;
}
