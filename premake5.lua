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
		"%{prj.name}/Source/**.cpp",
		"%{prj.name}/Source/**.c"
	}

	includedirs
	{
		"ThirdParty/spdlog/include",
		"ThirdParty/glfw/include",
		"ThirdParty/glad/**"
	}

	links
	{
		"ThirdParty/glfw/lib-vc2022/glfw3.lib",
		"opengl32.lib",
		"dwmapi.lib",

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
		buildoptions "/MDd"

	filter "configurations:Release"
		defines "SYN_RELEASE"
		symbols "On"
		buildoptions "/MD"

	filter "configurations:Dist"
		defines "SYN_DIST"
		symbols "On"
		buildoptions "/MD"
	
project "GameProj"
	location "GameProj"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("Intermediate/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp",
		"%{prj.name}/Source/**.c"
	}

	includedirs
	{
		"ThirdParty/spdlog/include",
		"ThirdParty/glfw/include",
		"ThirdParty/glad/**",
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
		buildoptions "/MDd"

	filter "configurations:Release"
		defines "SYN_RELEASE"
		symbols "On"
		buildoptions "/MD"

	filter "configurations:Dist"
		defines "SYN_DIST"
		symbols "On"
		buildoptions "/MD"