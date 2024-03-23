workspace "SynEngine"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "SynEngine"
	location "SynEngine"
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
		"ThirdParty/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SYN_PLATFORM_WINDOWS",
			"SYN_BUILD_DLL"
		}

		postbuildcommands
		{
			"{COPY} %{cfg.buildtarget.relpath} ../Binaries/" .. outputdir .. "/GameProj"
		}

	filter "configurations:Debug"
		defines "SYN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SYN_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "SYN_DIST"
		symbols "On"
	
project "GameProj"
	 location "GameProj"
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
		"ThirdParty/spdlog/include",
		"SynEngine/Source"
	}

	links
	{
		"SynEngine"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SYN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SYN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SYN_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "SYN_DIST"
		symbols "On"