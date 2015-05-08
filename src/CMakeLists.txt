include(cmake/show.cmake)
include(cmake/ide.cmake)
include(cmake/platform.cmake)

add_subdirectory(platform)

add_executable(brecs brecs.h brecs.c parameters.h error.c error.h)
target_add_platform(brecs)
