add_subdirectory(3rdParty)

add_library(platform STATIC brecs_memory.c brecs_memory.h getopt.c getopt.h
                            platform.h rand.c rand.h afloat.h)

set(PLATFORM_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}
    CACHE PATH "Path to platform specific source"
    FORCE)
set_property(TARGET platform APPEND PROPERTY INCLUDE_DIRECTORIES ${PLATFORM_SOURCE_DIR})
set_property(TARGET platform APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${PLATFORM_SOURCE_DIR})
