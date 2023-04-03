// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Mario_Correction : ModuleRules
{
	public Mario_Correction(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
