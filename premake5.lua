workspace "Lemon"
    architecture "x64"
    
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Lemon"
    location "Lemon"
    kind "SharedLib"
    language "C++"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        buildoptions { "/utf-8" }
        
        defines
        {
            "LEM_PLATFORM_WINDOWS",
            "LEM_BUILD_DLL",
        }

        postbuildcommands
        {
            ("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "LEM_DEBUG"
        symbols "On"
        
    filter "configurations:Release"
        defines "LEM_RELEASE"
        optimize "On"
        
    filter "configurations:Dist"
        defines "LEM_DIST"
        optimize "On"
        
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
        
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Lemon/vendor/spdlog/include",
        "Lemon/src"
    }

    links
    {
        "Lemon"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        buildoptions { "/utf-8" }
        
        defines
        {
            "LEM_PLATFORM_WINDOWS",
        }
    
    filter "configurations:Debug"
        defines "LEM_DEBUG"
        symbols "On"
        
    filter "configurations:Release"
        defines "LEM_RELEASE"
        optimize "On"
        
    filter "configurations:Dist"
        defines "LEM_DIST"
        optimize "On"