#pragma once
using UnrealBuildTool;

public class TD_Editor : ModuleRules
{

    public TD_Editor(ReadOnlyTargetRules _target) : base(_target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new []{"Core", "CoreUObject", "Engine", "InputCore"});

        PublicDependencyModuleNames.AddRange(new string[] {"TD_Window"});

        PrivateDependencyModuleNames.AddRange(new string[] { });

        // public / private files
        PublicIncludePaths.AddRange(new []{"TD_Editor/Public"});

        PrivateIncludePaths.AddRange(new[] { "TD_Editor/Private" });
    }
}