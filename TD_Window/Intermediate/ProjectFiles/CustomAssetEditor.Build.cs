using UnrealBuildTool;

public class CustomAssetEditor : ModuleRules
{
    public CustomAssetEditor(ReadOnlyTargetRules _target) : base(_target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "InputCore"
            });

        PrivateDependencyModuleNames.AddRange(
            new[]
            {
                "TD_Window"
            });

        PublicIncludePaths.AddRange(
            new string[]
            {
                "CustomAssetEditor/Public"
            });

        PrivateIncludePaths.AddRange(
            new string[]
            {
                "CustomAssetEditor/Private"
            });

        
    }
}