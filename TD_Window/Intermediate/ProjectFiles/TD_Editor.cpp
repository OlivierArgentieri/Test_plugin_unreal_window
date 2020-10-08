#include "TD_Editor.h"
#include "Modules/ModuleManager.h"
#include "Modules/ModuleInterface.h"

IMPLEMENT_GAME_MODULE(FTD_EditorModule, TD_Editor);

#define LOCTEXT_NAMESPACE "TutorialEditor"

void FTD_EditorModule::StartupModule()
{
    UE_LOG(TD_Editor, Warning, TEXT("TD_Editor: Log Started"));
}

void FTD_EditorModule::ShutdownModule()
{
    UE_LOG(TD_Editor, Warning, TEXT("TD_Editor: Log Ended"));
}

#undef LOCTEXT_NAMESPACE