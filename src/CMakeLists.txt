include(cmake/show.cmake)
include(cmake/ide.cmake)
include(cmake/platform.cmake)

add_subdirectory(platform)


add_library(libbrecs STATIC
               Brecs.h Brecs.c
               parameter.io.h parameter.io.c
               sqlite3.c sqlite3.h
               error.c error.h)
target_add_platform(libbrecs)
install(TARGETS libbrecs DESTINATION lib)
install(FILES Brecs.h DESTINATION include)


add_library(libbrecs-shared SHARED
               Brecs.h Brecs.c
               parameter.io.h parameter.io.c
               sqlite3.c sqlite3.h
               error.c error.h)
target_add_platform(libbrecs-shared)
install(TARGETS libbrecs-shared DESTINATION lib)

add_executable(brecs 
               brecs.main.c
               cmdline.h cmdline.c)
target_link_libraries(brecs libbrecs)
install(TARGETS brecs DESTINATION bin)
