#pragma once

#include "IExampleModuleInterface.h"
#include "ToolExampleEditor.h"
#include "Widgets/Docking/SDockTab.h"

class FExampleTabToolBase : public IExampleModuleListenerInterface, public TSharedFromThis<FExampleTabToolBase>
{

public:
	// IPixelopusToolBase
	virtual void OnStartupModule() override
	{
		Initialize();
		FGlobalTabmanager::Get()->RegisterNomadTabSpawner(TabName, FOnSpawnTab::CreateRaw(this, &FExampleTabToolBase::SpawnTab))
			.SetGroup(FToolExampleEditor::Get().GetMenuRoot())
			.SetDisplayName(TabDisplayName)
			.SetTooltipText(ToolTipText);
	};


	virtual void OnShutdownModule() override
	{
		FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(TabName);
	}

	// Init all attributes member
	virtual void Initialize(){}

	virtual TSharedRef<SDockTab> SpawnTab(const FSpawnTabArgs& _tabSpawnArgs)
	{
		return SNew(SDockTab);
	}
protected:
	FName TabName;
	FText TabDisplayName;
	FText ToolTipText;
};