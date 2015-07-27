# This file is for setting platform-dependent build properties that apply to the whole project tree.
#

if(WIN32)
    include_directories(SYSTEM "$ENV{UniversalCRTSdkDir}Include/ucrt")
    include_directories(SYSTEM "$ENV{UniversalCRTSdkDir}Include/10.0.10056.0/ucrt")

    add_definitions(/arch:AVX2)
elseif(APPLE)
    add_definitions(-std=c99 -mavx) # use of mm_hadd_ps makes this the minimum target
else() # linux
#    add_definitions(-std=c99 -mavx)
    add_definitions(-std=c99 -msse3) # use of mm_hadd_ps makes this the minimum target
endif()

