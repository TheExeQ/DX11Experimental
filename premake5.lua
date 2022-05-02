workspace "DXExperiments"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Retail"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Engine/"