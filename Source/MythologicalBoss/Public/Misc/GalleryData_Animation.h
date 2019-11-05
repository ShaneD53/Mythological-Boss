// Copyright Overthrone Studios 2019

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Animation/AnimationAsset.h"
#include "GalleryData_Animation.generated.h"

/**
 * Stores an array of animations that can be used in the gallery menu
 */
UCLASS(BlueprintType)
class MYTHOLOGICALBOSS_API UGalleryData_Animation final : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gallery")
		TArray<UAnimationAsset*> Animations;
};
