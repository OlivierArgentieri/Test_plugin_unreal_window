#include "IExampleModuleInterface.h"
#include "Modules/ModuleManager.h"

class FToolExampleEditor : public IExampleModuleInterface
{
public:
	/* IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	virtual void AddModuleListeners() override;

	static FToolExampleEditor& Get()
	{
		return FModuleManager::LoadModuleChecked<FToolExampleEditor>("ToolExampleEditor");
	}


	static bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("ToolExampleEditor");
	}
};
