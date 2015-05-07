include(cmake/show.cmake)
include(cmake/ide.cmake)
include(cmake/platform.cmake)

add_subdirectory(3rdParty)
add_subdirectory(platform)

add_executable(brecs brecs.h brecs.c parameters.h)
target_add_3rdParty(brecs)
target_add_platform(brecs)
