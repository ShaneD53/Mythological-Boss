// Copyright Ali El Saleh 2019

#pragma once

#include "Widgets/Settings/VideoSetting.h"
#include "DisplayModeSetting.generated.h"

/**
 * Manages the window mode setting
 */
UCLASS()
class MENUSYSTEM_API UDisplayModeSetting final : public UVideoSetting
{
	GENERATED_BODY()
	
public:
	void Init() override;
	void Apply() override;
	void Reset() override;

	bool HasChanged() override;
	void RevertChange() override;

protected:
	UFUNCTION(BlueprintCallable, Category = "Display Mode Setting")
		void PopulateDisplayModeList(class UComboBoxString* DropDownList);

	UFUNCTION(BlueprintCallable, Category = "Display Mode Setting")
		void SetSelectedOption(class UComboBoxString* DropDownList);

	UFUNCTION(BlueprintCallable, Category = "Display Mode Setting")
		void ChangeDisplayMode(const FString& SelectedItem);

	UPROPERTY(EditInstanceOnly, Category = "Video Setting")
		TEnumAsByte<EWindowMode::Type> DisplayMode;

	FString SelectedOption;

	TEnumAsByte<EWindowMode::Type> DefaultDisplayMode;
	TEnumAsByte<EWindowMode::Type> PreviousDisplayMode;
};
