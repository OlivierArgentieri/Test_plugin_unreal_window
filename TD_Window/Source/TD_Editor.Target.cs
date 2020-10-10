// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class TD_EditorTarget : TargetRules
{
    public TD_EditorTarget(TargetInfo _target) : base(_target)
    {
        Type = TargetType.Editor;
        ExtraModuleNames.AddRange(new string[] { "TD_Window", "TD_Editor" });
    }
}