using UnrealBuildTool;

public class CustomAssetEditor : ModuleRules
{

    public CustomAssetEditor(ReadOnlyTargetRules _target) : base(_target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new []
            {
                "Core",
            });

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Json",
                "Slate",
                "SlateCore",
                "Engine",
                "InputCore",
                "UnrealEd", // for FAssetEditorManager
                "KismetWidgets",
                "Kismet",  // for FWorkflowCentricApplication
                "PropertyEditor",
                "RenderCore",
                "ContentBrowser",
                "WorkspaceMenuStructure",
                "EditorStyle",
                "MeshPaint",
                "EditorWidgets",
                "Projects",
                "AssetRegistry",
              //  "AssetEditorTutorial"
            });

        // public / private files
        PublicIncludePaths.AddRange(new string[]{"TD_Editor/Public"});

        PrivateIncludePaths.AddRange(new string[] { "TD_Editor/Private" });


        PrivateIncludePathModuleNames.AddRange(
            new string[]
            {
                "Settings",
                "IntroTutorials",
                "AssetTools",
                "LevelEditor"
            }
        );

        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
                "AssetTools"
            }
        );
    }
}