#include "ICustomAssetEditorModule.h"
#include "Modules/ModuleManager.h"
#include "IToolkit.h"
#include "CustomAssetEditor.h"
#include "IAssetTools.h"
#include "AssetToolsModule.h"


const FName CustomAssetEditorAppIdentifier = FName(TEXT("StaticMeshEditorApp"));

#define LOCTEXT_NAMESPACE "FTD_CustomAssetEditorModule"
/**
 * Custom Asset Editor Module
 */

class FCustomAssetEditorModule : public ICustomAssetEditorModule
{
private:
	TSharedPtr<FExtensibilityManager> MenuExtensibilityManager;
	TSharedPtr<FExtensibilityManager> ToolBarExtensibilityManager;


public:
	
	/* constructor */
	
	FCustomAssetEditorModule(){}

	/** Gets the extensibility managers for outside entities to extend custom asset editor's menus and toolbars */
	virtual TSharedPtr<FExtensibilityManager> GetMenuExtensibilityManager() override { return MenuExtensibilityManager; }
	virtual TSharedPtr<FExtensibilityManager> GetToolBarExtensibilityManager() override { return ToolBarExtensibilityManager; }

	/**
* Called right after the module DLL has been loaded and the module object has been created
*/
	virtual void StartupModule() override
	{
		// Create new extensibility managers for our menu and toolbar
		MenuExtensibilityManager = MakeShareable(new FExtensibilityManager);
		ToolBarExtensibilityManager = MakeShareable(new FExtensibilityManager);
	}

	/**
	* Called before the module is unloaded, right before the module object is destroyed.
	*/
	virtual void ShutdownModule() override
	{
		// Reset our existing extensibility managers
		MenuExtensibilityManager.Reset();
		ToolBarExtensibilityManager.Reset();
	}

	/**
	* Creates a new custom asset editor for a MyCustomAsset
	*/
	virtual TSharedRef<ICustomAssetEditor> CreateCustomAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UMyCustomAsset* CustomAsset) override
	{
		// Initialize and spawn a new custom asset editor with the provided parameters
		TSharedRef<FCustomAssetEditor> NewCustomAssetEditor(new FCustomAssetEditor());
		NewCustomAssetEditor->InitCustomAssetEditor(Mode, InitToolkitHost, CustomAsset);
		return NewCustomAssetEditor;
	}
};
#undef LOCTEXT_NAMESPACE
IMPLEMENT_GAME_MODULE(FCustomAssetEditorModule, CustomAssetEditor);

