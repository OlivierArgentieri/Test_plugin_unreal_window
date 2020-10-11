#include "CustomAssetEditor.h"
#include "Modules/ModuleManager.h"
#include "EditorStyleSet.h"
#include "Widgets/Docking/SDockTab.h"
#include "PropertyEditorModule.h"
#include "IDetailsView.h"
#include "Editor.h"
#include "AssetEditorToolkit.h"
#include "ICustomAssetEditorModule.h"


#define LOCTEXT_NAMESPACE "FTD_CustomAssetEditor"

const FName FCustomAssetEditor::ToolkitFName(TEXT("CustomAssetEditor"));
const FName FCustomAssetEditor::PropertiesTabId(TEXT("CustomAssetEditor_Properties"));

void FCustomAssetEditor::RegisterTabSpawners(const TSharedRef<class FTabManager>& _inTabManager)
{
	// Add a new workspace menu category to the tab manager
	WorkspaceMenuCategory = _inTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("Workspace_CustomAssetEditor", "Custom Asset Editor"));

	// register the tab manager to the asset editor toolkit
	FAssetEditorToolkit::RegisterTabSpawners(_inTabManager);



	// Register the properties tab spawner within our tab manager
	// We provide the function with the identifier for this tab and a shared pointer to the
	// SpawnPropertiesTab function within this editor class
	// Additionaly, we provide a name to be displayed, a category and the tab icon
	_inTabManager->RegisterTabSpawner(PropertiesTabId, FOnSpawnTab::CreateSP(this, &FCustomAssetEditor::SpawnPropertiesTab))
		.SetDisplayName(LOCTEXT("PropertiesTab", "Details"))
		.SetGroup(WorkspaceMenuCategory.ToSharedRef())
		.SetIcon(FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.Tabs.Details"));

}

void FCustomAssetEditor::UnregisterTabSpawners(const TSharedRef<class FTabManager>& _inTabManager)
{
	// Unregister the tab manager from the asset editor toolkit
	FAssetEditorToolkit::UnregisterTabSpawners(_inTabManager);

	// Unregister our custom tab from the tab manager, making sure it is cleaned up when the editor gets destroyed
	_inTabManager->UnregisterTabSpawner(PropertiesTabId);
}


void FCustomAssetEditor::InitCustomAssetEditor(const EToolkitMode::Type _mode, const TSharedPtr<IToolkitHost>& _initToolkitHost, UMyCustomAsset* _inCustomAsset)
{
	// Cache some values that will be used for our details view arguments
	const bool bIsUpdatable = false;
	const bool bAllowFavorites = true;
	const bool bIsLockable = false;

	// Set this InCustomAsset as our editing asset
	SetCustomAsset(_inCustomAsset);

	// Retrieve the property editor module and assign to DetailsView
	FPropertyEditorModule& _propertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	const FDetailsViewArgs DetailsViewArgs(bIsUpdatable, bIsLockable, true, FDetailsViewArgs::ObjectsUseNameArea, false);
	DetailsView = _propertyEditorModule.CreateDetailView(DetailsViewArgs);

	const TSharedRef<FTabManager::FLayout> StandaloneDefaultLayout = FTabManager::NewLayout("Standalone_CustomAssetEditor_Layout_v1")
		->AddArea
		(
			FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.1f)
				->SetHideTabWell(true)
				->AddTab(GetToolbarTabId(), ETabState::OpenedTab)
			)
			->Split
			(
				FTabManager::NewSplitter()
				->Split
				(
					FTabManager::NewSplitter()
					->Split
					(
						FTabManager::NewStack()
						->AddTab(PropertiesTabId, ETabState::OpenedTab)
					)
				)
			)
		);

	const bool bCreatedDefaultStandaloneMenu = true;
	const bool bCreateDefaultToolbar = true;

	FAssetEditorToolkit::InitAssetEditor
	(
		_mode,
		_initToolkitHost,
		CustomAssetEditorAppIdentifier,
		StandaloneDefaultLayout,
		bCreatedDefaultStandaloneMenu,
		bCreateDefaultToolbar,
		(UObject*)_inCustomAsset);

	if (DetailsView.IsValid())
	{
		DetailsView->SetObject((UObject*)CustomAsset);
	}
}

FCustomAssetEditor::~FCustomAssetEditor()
{
	// On destruction we reset our tab and details view 
	DetailsView.Reset();
	PropertiesTab.Reset();
}

FName FCustomAssetEditor::GetToolkitFName() const
{
	return ToolkitFName;
}

FText FCustomAssetEditor::GetBaseToolkitName() const
{
	return LOCTEXT("AppLabel", "Custom Asset Editor");
}

FText FCustomAssetEditor::GetToolkitToolTipText() const
{
	return LOCTEXT("ToolTip", "Custom Asset Editor");
}

FString FCustomAssetEditor::GetWorldCentricTabPrefix() const
{
	return LOCTEXT("WorldCentricTabPrefix", "AnimationDatabase ").ToString();
}

FLinearColor FCustomAssetEditor::GetWorldCentricTabColorScale() const
{
	return FColor::Red;
}

UMyCustomAsset* FCustomAssetEditor::GetCustomAsset()
{
	return CustomAsset;
}


void FCustomAssetEditor::SetCustomAsset(UMyCustomAsset* _inCustomAsset)
{
	CustomAsset = _inCustomAsset;
}


TSharedRef<SDockTab> FCustomAssetEditor::SpawnPropertiesTab(const FSpawnTabArgs& Args)
{
	// Make sure we have the correct tab id
	check(Args.GetTabId() == PropertiesTabId);

	// Return a new slate dockable tab that contains our details view
	return SNew(SDockTab)
		.Icon(FEditorStyle::GetBrush("GenericEditor.Tabs.Properties"))
		.Label(LOCTEXT("GenericDetailsTitle", "Details"))
		.TabColorScale(GetTabColorScale())
		[
			// Provide the details view as this tab its content
			DetailsView.ToSharedRef()
		];
}

#undef LOCTEXT_NAMESPACE
