include(cmake/show.cmake)
include(cmake/ide.cmake)
include(cmake/platform.cmake)

add_subdirectory(platform)

add_executable(brecs 
               Brecs.h bBrecs.c
               cmdline.h cmdline.c
               parameter.io.h parameter.io.c
               sqlite3.c sqlite3.h
               error.c error.h)
target_add_platform(brecs)
install(TARGETS brecs DESTINATION ".")
