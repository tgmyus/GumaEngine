workspace "GumaEngine"
	configurations { "Debug", "Release", "Dist" }
	architecture "x86_64"

outputdir = "%{cfg.buildcfg}/%{cfg.architecture}"

include "GumaEngine/Plugins/GLFW"

project "GumaEngine"
	location "GumaEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("Intermediate/" .. outputdir .. "/%{prj.name}")

	pchheader "Precompiled.h"
	pchsource "GumaEngine/Source/Precompiled.cpp"

	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp"
	}

	includedirs
	{
		"GumaEngine/Source",
		"GumaEngine/Source/Runtime/Core/Public",
		"GumaEngine/Source/Runtime/Engine/Public",
		"GumaEngine/Source/Runtime/RHI/Public",

		"GumaEngine/Plugins/spdlog/include",
		"GumaEngine/Plugins/GLFW/include"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GUMA_PLATFORM_WINDOWS",
			"GUMA_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../Binaries/" .. outputdir .. "/App")
		}

		filter "configurations:Debug"
			defines "GUMA_DEBUG"
			runtime "Debug"
			symbols "On"

		filter "configurations:Release"
			defines "GUMA_RELEASE"
			runtime "Release"
			optimize "On"

		filter "configurations:Dist"
			defines "GUMA_DIST"
			runtime "Release"
			optimize "On"

project "App"
	location "App"
	kind "ConsoleApp"
	language "C++"

	targetdir ("Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("Intermediate/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp"
	}

	includedirs
	{
		"GumaEngine/Source",
		"GumaEngine/Source/Runtime/RHI/Public",

		"GumaEngine/Plugins/spdlog/include"
	}

	links
	{
		"GumaEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GUMA_PLATFORM_WINDOWS"
		}

		filter "configurations:Debug"
			defines "GUMA_DEBUG"
			runtime "Debug"
			symbols "On"

		filter "configurations:Release"
			defines "GUMA_RELEASE"
			runtime "Release"
			optimize "On"

		filter "configurations:Dist"
			defines "GUMA_DIST"
			runtime "Release"
			optimize "On"
