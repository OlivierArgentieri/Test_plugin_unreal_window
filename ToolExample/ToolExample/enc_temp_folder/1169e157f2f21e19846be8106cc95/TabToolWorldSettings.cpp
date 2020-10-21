
#include "TabToolWorldSettings.h"

#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Input/SSpinBox.h"
#include "Components/SkyLightComponent.h"
#include "Engine/SkyLight.h"


void TabToolWorldSettings::Construct(const FArguments& _inArgs)
{
	tool = _inArgs._Tool;
	
		//world.
	if (tool.IsValid())
	{
		// action from tool object
	}

	


	
	
	ChildSlot
		[
			SNew(SScrollBox)
			+ SScrollBox::Slot()
		.VAlign(VAlign_Top)
		.Padding(5)
		[
			SNew(SBorder)
			.BorderBackgroundColor(FColor(192, 192, 192, 255))
		.Padding(15.0f)
		[
			SNew(SSpinBox<float>)
			.Value(0)
			.OnValueChanged(this, &TabToolWorldSettings::OnIntensityChanged)
			//.Text(FText::FromString(TEXT("This is a tab example aaaasdasdasdsad.")))
		]
		]

		];
}

void TabToolWorldSettings::OnIntensityChanged(float NewValue)
{
	auto world = GEditor->GetEditorWorldContext().World();


	AActor* _testLight = nullptr;
	for (AActor* _actor : world->GetCurrentLevel()->Actors)
	{
		if (_actor->GetName() == FString("SkyLight_1"))
			_testLight = _actor;
	}
	if (!_testLight) return;


	ASkyLight* _test = Cast<ASkyLight>(_testLight);
	_test->GetLightComponent()->Intensity = NewValue;
}