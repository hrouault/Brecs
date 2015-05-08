add_subdirectory(3rdParty)

file(GLOB SRCS *.c *.h)

add_library(platform STATIC ${SRCS})
target_link_libraries(platform Ole32.lib OleAut32.lib)
set(PLATFORM_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}
    CACHE PATH "Path to platform specific source"
    FORCE)
show(PLATFORM_SOURCE_DIR)
set_property(TARGET platform APPEND PROPERTY INCLUDE_DIRECTORIES ${PLATFORM_SOURCE_DIR})
set_property(TARGET platform APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${PLATFORM_SOURCE_DIR})
