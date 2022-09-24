-- Spark Engine config

workspace "Spark"
    architecture "x64"
    configurations
    {
        "Debug",   -- dev mode
        "Test",    -- release standard, with debugging tools
        "Release"
    }
    
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

startproject "Sparkle"
    
IncludeDirs = { }

IncludeDirs["GLFW"] = "Spark/vendor/glfw/include"
IncludeDirs["GLAD"] = "Spark/vendor/GLAD/include"

include "Spark/vendor/glfw"
include "Spark/vendor/GLAD"

project "Spark"
    location "Spark"
    kind "SharedLib"
    language "C++"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "sppch.h"
    pchsource "%{prj.name}/src/sppch.cpp"

    files
    {
        "%{prj.name}/**.h",
        "%{prj.name}/**.cpp"
    }

    includedirs
    {
        "%{prj.name}",
        "%{prj.name}/src",
        "%{prj.name}/src",
        "%{IncludeDirs.GLFW}",
        "%{IncludeDirs.GLAD}"
    }

    links
    {
        "GLFW",
        "GLAD",
        "opengl32.lib"
    }

    filter "system:Windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SP_PLATFORM_WINDOWS",
            "SP_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{MKDIR} ../bin/" .. outputdir .. "/Sparkle"),
            ("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sparkle/Spark.dll")
        }

    filter "configurations:Debug"
        defines "SP_DEBUG"
        buildoptions "/MDd"
        symbols "On"

        defines
        {
            "SP_ASSERT_ENABLED"
        }

    filter "configurations:Release"
        defines "SP_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "SP_DIST"
        buildoptions "/MD"
        optimize "On" 

project "Sparkle"
    location "Sparkle"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/**.h",
        "%{prj.name}/**.cpp"
    }

    includedirs
    {
        "Spark",
        "Spark/src",
        "Spark/lib/splog",
        "%{IncludeDirs.GLFW}",
        "%{IncludeDirs.GLAD}"
    }

    links
    {
        "Spark"
    }

    filter "system:Windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SP_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "SP_DEBUG"
        buildoptions "/MDd"
        symbols "On"

        defines
        {
            "SP_ASSERT_ENABLED"
        }

    filter "configurations:Release"
        defines "SP_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "SP_DIST"
        buildoptions "/MD"
        optimize "On" 

project "GLFW"