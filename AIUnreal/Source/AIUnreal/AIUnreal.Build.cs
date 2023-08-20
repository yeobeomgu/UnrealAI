// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AIUnreal : ModuleRules
{
	public AIUnreal(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "NavigationSystem", "AIModule", "GameplayTasks" });
	}
}
