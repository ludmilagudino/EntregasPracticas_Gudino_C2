// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EntregasPracticas : ModuleRules
{
	public EntregasPracticas(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"EntregasPracticas",
			"EntregasPracticas/Variant_Platforming",
			"EntregasPracticas/Variant_Platforming/Animation",
			"EntregasPracticas/Variant_Combat",
			"EntregasPracticas/Variant_Combat/AI",
			"EntregasPracticas/Variant_Combat/Animation",
			"EntregasPracticas/Variant_Combat/Gameplay",
			"EntregasPracticas/Variant_Combat/Interfaces",
			"EntregasPracticas/Variant_Combat/UI",
			"EntregasPracticas/Variant_SideScrolling",
			"EntregasPracticas/Variant_SideScrolling/AI",
			"EntregasPracticas/Variant_SideScrolling/Gameplay",
			"EntregasPracticas/Variant_SideScrolling/Interfaces",
			"EntregasPracticas/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
