#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "ModuleManager.h"
#include "Toolkits/AssetEditorToolkit.h"

class ITD_CustomAsserEditor;
class UMyCustomAsset;

extern const FName CustomAssetEditorAppIdentifier;

/**
 * Custom Asset editor module interface
 */
class ICustomAssetEditor : public IModuleInterface, public IHasMenuExtensibility, public IHasToolBarExtensibility
{
public:
	/**
	 * Creates a new custom asset editor.
	 */
	virtual TSharedRef<ICustomAssetEditor> CreateCustomAssetEditor(const EToolkitMode::Type _mode, const TSharedPtr<IToolkitHost>& _initToolkitHost, UMyCustomAsset* _customAsset) = 0;
	
};