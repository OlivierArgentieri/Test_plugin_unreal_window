#include "ToolExampleEditor.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_GAME_MODULE(FToolExampleEditor, ToolExampleEditor)

void FToolExampleEditor::AddModuleListeners()
{
	
}


void FToolExampleEditor::StartupModule()
{
	FMessageDialog::Open(EAppMsgType::Ok, FText::FromString("Enchantier"));
}

void FToolExampleEditor::ShutdownModule()
{
	
}
