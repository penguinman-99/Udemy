// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Udemy : ModuleRules
{
	public Udemy(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
