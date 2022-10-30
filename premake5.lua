workspace "GumaEngine"
	configurations { "Debug", "Release" }
	architecture "x86_64"

outputdir = "%{cfg.buildcfg}/%{cfg.architecture}"

project "GumaEngine"
	location "GumaEngine"
	kind "SharedLib"
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
		"GumaEngine/Plugins/spdlog/include",
		"GumaEngine/Source/Runtime/Core/Public"
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
		symbols "On"

	filter "configurations:Release"
		defines "GUMA_RELEASE"
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
		"GumaEngine/Plugins/spdlog/include",
		"GumaEngine/Source"
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
		symbols "On"

	filter "configurations:Release"
		defines "GUMA_RELEASE"
		optimize "On"
