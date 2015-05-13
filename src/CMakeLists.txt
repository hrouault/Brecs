include(cmake/show.cmake)
include(cmake/ide.cmake)
include(cmake/platform.cmake)

add_subdirectory(platform)

add_executable(brecs Brecs.h Brecs.c parameters.h error.c error.h)
target_add_platform(brecs)
install(TARGETS brecs DESTINATION ".")
