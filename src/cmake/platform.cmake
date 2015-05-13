# This file is for setting platform-dependent build properties that apply to the whole project tree.

if(WIN32)
    include_directories(SYSTEM "$ENV{UniversalCRTSdkDir}Include/ucrt")
    include_directories(SYSTEM "$ENV{UniversalCRTSdkDir}Include/10.0.10056.0/ucrt")
    add_definitions(/arch:AVX2)
elseif(APPLE)
else() # linux
endif()

