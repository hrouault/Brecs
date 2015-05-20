include(cmake/show.cmake)
include(cmake/ide.cmake)
include(cmake/platform.cmake)

add_subdirectory(platform)

add_executable(brecs 
               brecs.h brecs.c 
               parser.h parser.c
               sqlite3.c sqlite3.h
               parameters.h 
               error.c error.h)
target_add_platform(brecs)
install(TARGETS brecs DESTINATION ".")