include_directories(SYSTEM "$ENV{UniversalCRTSdkDir}Include/10.0.10056.0/ucrt")

if(0)
    # This helps avoid dependence on the standard c runtime library
    # The Pro: avoid the need for msvcrt*.dll 
    # The Con: no CRT and a little bit of missing OS-dependent initialization
    #          that gets injected before main.
    set(CMAKE_C_FLAGS                "/W3 /GS-"                          CACHE STRING "docstring" FORCE)
    set(CMAKE_C_FLAGS_DEBUG          "/Ob0 /Od /Z7 /GR"                  CACHE STRING "docstring" FORCE)
    set(CMAKE_C_FLAGS_MINSIZEREL     "/Ob1 /O1"                          CACHE STRING "docstring" FORCE)
    set(CMAKE_C_FLAGS_RELEASE        "/Ob2 /Ox"                          CACHE STRING "docstring" FORCE)
    set(CMAKE_C_FLAGS_RELWITHDEBINFO "/Ob1 /Ox /Z7"                      CACHE STRING "docstring" FORCE)

    set(CMAKE_C_STANDARD_LIBRARIES "kernel32.lib user32.lib"             CACHE STRING "docstring" FORCE)

    set(CMAKE_CXX_FLAGS                "${CMAKE_C_FLAGS} /EHsc"          CACHE STRING "docstring" FORCE)
    set(CMAKE_CXX_FLAGS_DEBUG          "${CMAKE_C_FLAGS_DEBUG}"          CACHE STRING "docstring" FORCE)
    set(CMAKE_CXX_FLAGS_MINSIZEREL     "${CMAKE_C_FLAGS_MINSIZEREL}"     CACHE STRING "docstring" FORCE)
    set(CMAKE_CXX_FLAGS_RELEASE        "${CMAKE_C_FLAGS_RELEASE}"        CACHE STRING "docstring" FORCE)
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_C_FLAGS_RELWITHDEBINFO}" CACHE STRING "docstring" FORCE)

    set(CMAKE_CXX_STANDARD_LIBRARIES ""                                  CACHE STRING "docstring" FORCE)

    set(CMAKE_EXE_LINKER_FLAGS    "/machine:x64 /nodefaultlib /entry:main")
    set(CMAKE_SHARED_LINKER_FLAGS "/machine:x64 /nodefaultlib")

endif()
