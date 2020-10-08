#include "CustomAssetEditor.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"


IMPLEMENT_GAME_MODULE(FCustomAssetEditor, CustomAssetEditor);


#define LOCTEXT_NAMESPACE "CustomAssetEditor"
void FCustomAssetEditor::StartupModule()
{
	UE_LOG(CustomAssetEditor, Warning, TEXT("CustomAssetEditor: Log Started"));
}

void FCustomAssetEditor::ShutdownModule()
{
	UE_LOG(CustomAssetEditor, Warning, TEXT("CustomAssetEditor: Log ended"));
}

#undef LOCTEXT_NAMESPACE