// Copyright Ali El Saleh 2019

#include "ResolutionSetting.h"
#include "WidgetTree.h"
#include "ComboBoxString.h"

void UResolutionSetting::ChangeResolution(const FString& SelectedItem)
{
	SelectedOption = SelectedItem;

	// Get the selected resolution string and split it up
	FString XRes;
	FString YRes;
	SelectedItem.Split(FString("x"), &XRes, &YRes);

	// Once split, convert strings into integers
	const int32 X = FCString::Atoi(*XRes);
	const int32 Y = FCString::Atoi(*YRes);

	// Set the new resolution
	NewResolution = FIntPoint(X, Y);
}

void UResolutionSetting::PopulateResolutionList(UComboBoxString* DropDownList)
{
	// Get every resolution supported
	RHIGetAvailableResolutions(ScreenResolutions, true);

	// Populate the combo box
	for (int32 i = ScreenResolutions.Num() - 1; i >= 0; i--)
	{
		FString Option = FString::FromInt(ScreenResolutions[i].Width) + "x" + FString::FromInt(ScreenResolutions[i].Height);

		DropDownList->AddOption(Option);
	}
}

void UResolutionSetting::SetSelectedOption(UComboBoxString* DropDownList)
{
	// Set the default resolution as the selected option
	DropDownList->SetSelectedOption(SelectedOption);
}

TArray<FString> UResolutionSetting::GetAllSupportedResolutions()
{
	TArray<FString> Resolutions;

	for (int32 i = ScreenResolutions.Num() - 1; i >= 0; i--)
	{
		FString Option = FString::FromInt(ScreenResolutions[i].Width) + "x" + FString::FromInt(ScreenResolutions[i].Height);

		Resolutions.Add(Option);
	}

	return Resolutions;
}

void UResolutionSetting::Init()
{
	Super::Init();

	DefaultOption = SelectedOption;
	PreviousSelectedOption = SelectedOption;

	DropDownList = Cast<UComboBoxString>(WidgetTree->FindWidget(FName("DropDown")));
}

void UResolutionSetting::Apply()
{
	SelectedOption = PreviousSelectedOption;
	GameUserSettings->SetScreenResolution(NewResolution);
}

void UResolutionSetting::Reset()
{
	SelectedOption = DefaultOption;

	ChangeResolution(SelectedOption);
	SetSelectedOption(DropDownList);

	Apply();
}

bool UResolutionSetting::HasChanged()
{
	return SelectedOption != PreviousSelectedOption;
}

void UResolutionSetting::RevertChange()
{
	SelectedOption = PreviousSelectedOption;
	ChangeResolution(SelectedOption);
	SetSelectedOption(DropDownList);
}
