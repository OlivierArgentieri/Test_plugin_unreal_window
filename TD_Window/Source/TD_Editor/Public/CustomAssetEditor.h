#pragma once

#include "CoreMinimal.h"
#include "Toolkits/IToolkitHost.h"
#include "Toolkits/AssetEditorToolkit.h"
#include "ICustomAssetEditor.h"

class IDetailsView;
class SDockableTab;
class UMyCustomAsset;


/**
 *
 */
class TD_EDITOR_API  FCustomAssetEditor : public ICustomAssetEditor
{
private:
	// Create The properties tab and its content
	TSharedRef<SDockTab> SpawnPropertiesTab(const FSpawnTabArgs& _args);

	// Dockable tab for properties
	TSharedPtr<SDockableTab> PropertiesTab;

	// Details in view
	TSharedPtr<class IDetailsView> DetailsView;

	// tab id for all the tabs used
	static const FName PropertiesTabId;

	// The custom asset within this editor
	UMyCustomAsset* CustomAsset;

public:
	/** The name given to all instances of this type of editor */
	static const FName ToolkitFName;


	// destructor
	virtual ~FCustomAssetEditor();

	
	// create tab spawners on editor initialization
	virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& _tabManager) override;

	// unregister tab spawner editor initialization
	virtual void UnregisterTabSpawners(const TSharedRef<FTabManager>& _tabManager) override;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="_mode"> mode </param>  	Asset editing mode (standalone or world-centric)
	///											When Mode is worldCentric, this is th level editor instance
	///											to spawn this editor within The custom mode Asset to Edit
	///							
	/// <param name="_initToolkitHost"> InitToolKiHost </param>
	/// <param name="_inCustomAsset"> InCustomAsset </param>
	void InitCustomAssetEditor(const EToolkitMode::Type _mode, const TSharedPtr<class IToolkitHost>& _initToolkitHost, UMyCustomAsset* _inCustomAsset);


	/* Begin IToolKit interface */
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FText GetToolkitName() const override;
	virtual FText GetToolkitToolTipText() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	virtual bool IsPrimaryEditor() const override { return true; }
	/* End IToolKit interface */

	/** Begin ICustomAssetEditor interface */
	virtual UMyCustomAsset* GetCustomAsset() override;
	virtual void SetCustomAsset(UMyCustomAsset* _InCustomAsset);
	/** End ICustomAssetEditor interface */
};