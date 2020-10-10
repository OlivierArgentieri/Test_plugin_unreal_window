using UnrealBuildTool;

public class TD_Editor : ModuleRules
{

    public TD_Editor(ReadOnlyTargetRules _target) : base(_target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(
            new []
            {
                "Core",
                "CoreUObject",
                "Json",
                "Slate",
                "InputCore",
                "UnrealEd",
                "KismetWidgets",
                "Kismet",
                "PropertyEditor",
                "RenderCore",
                "ContentBrowser",
                "WorkspaceMenuStructure",
                "EditorStyle",
                "EditorWidgets",
                "Projects",
                "AssetRegistry",
                "Engine",
                "InputCore",

            });

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "TD_Window",
                "Settings",
                "AssetTools",
                "LevelEditor"
            });

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "AssetTools"
            });

        // public / private files
        PublicIncludePaths.AddRange(new string[]{"TD_Editor/Public"});

        PrivateIncludePaths.AddRange(new string[] { "TD_Editor/Private" });
    }
}