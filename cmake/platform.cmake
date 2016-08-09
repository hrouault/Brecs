if (UNIX)
    option(USE_SSE2_INSTRUCTIONS
           "Compile your program with SSE2 instructions" OFF)
    option(USE_SSE4_INSTRUCTIONS
           "Compile your program with SSE4 instructions" OFF)
    option(USE_AVX_INSTRUCTIONS
           "Compile your program with AVX instructions" ON)
    if (USE_AVX_INSTRUCTIONS)
        add_definitions(-mavx)
        message(STATUS "Enabling AVX instructions")
    elseif (USE_SSE4_INSTRUCTIONS)
        add_definitions(-msse4)
        message(STATUS "Enabling SSE4 instructions")
    elseif(USE_SSE2_INSTRUCTIONS)
        add_definitions(-msse2)
        message(STATUS "Enabling SSE2 instructions")
    endif()
elseif (MSVC OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    # Use SSE2 by default when using Visual Studio.
    option(USE_SSE2_INSTRUCTIONS
           "Compile your program with SSE2 instructions" ON)
    # Visual Studio 2005 didn't support SSE4 
    if (NOT MSVC80)
        option(USE_SSE4_INSTRUCTIONS
               "Compile your program with SSE4 instructions" OFF)
    endif()
    # Visual Studio 2005 and 2008 didn't support AVX
    if (NOT MSVC80 AND NOT MSVC90)
        option(USE_AVX_INSTRUCTIONS
               "Compile your program with AVX instructions"  OFF)
    endif() 
    include(CheckTypeSize)
    check_type_size( "void*" SIZE_OF_VOID_PTR)
    if(USE_AVX_INSTRUCTIONS)
        add_definitions(/arch:AVX)
        message(STATUS "Enabling AVX instructions")
    elseif (USE_SSE4_INSTRUCTIONS)
        # Visual studio doesn't have an /arch:SSE2 flag when building in 64 bit
        # modes.
        # So only give it when we are doing a 32 bit build.
        if (SIZE_OF_VOID_PTR EQUAL 4)
            add_definitions(/arch:SSE2)  
        endif()
        message(STATUS "Enabling SSE4 instructions")
        add_definitions(-DDLIB_HAVE_SSE2)
        add_definitions(-DDLIB_HAVE_SSE3)
        add_definitions(-DDLIB_HAVE_SSE41)
    elseif(USE_SSE2_INSTRUCTIONS)
        # Visual studio doesn't have an /arch:SSE2 flag when building in 64 bit
        # modes.
        # So only give it when we are doing a 32 bit build.
        if (SIZE_OF_VOID_PTR EQUAL 4)
            add_definitions(/arch:SSE2)
        endif()
        message(STATUS "Enabling SSE2 instructions")
        add_definitions(-DDLIB_HAVE_SSE2)
    endif()
endif()

if(WIN32)
    include_directories(SYSTEM "$ENV{UniversalCRTSdkDir}Include/ucrt")
    include_directories(SYSTEM
                        "$ENV{UniversalCRTSdkDir}Include/10.0.10056.0/ucrt")
endif()

if (UNIX)
    include(FindPkgConfig)
    pkg_check_modules(FFTW REQUIRED fftw3f)
elseif (MSVC)
else()
    message(FATAL_ERROR "Your system is not supported! Please mention to the "
            "developers if you would like you system to be supported in the "
            "future.")
endif()
