#pragma once

#include "CoreMinimal.h"
#include "Toolkits/AssetEditorToolkit.h"

class UMyCustomAsset;

class ICustomAssetEditor : public FAssetEditorToolkit
{
	/* get current custom asset */
	virtual UMyCustomAsset* GetCustomAsset() = 0;

	/* set current custom asset */
	virtual void SetCustomAsset(UMyCustomAsset* _InCustomAsset) = 0;
};