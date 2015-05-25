include(cmake/show.cmake)
include(cmake/ide.cmake)
include(cmake/platform.cmake)

add_subdirectory(platform)


add_library(brecs-static STATIC
               Brecs.h Brecs.c
               error.c error.h)
set_property(TARGET brecs-static PROPERTY POSITION_INDEPENDENT_CODE TRUE)
target_add_platform(brecs-static)
install(TARGETS brecs-static DESTINATION lib)

add_library(brecs SHARED
               Brecs.h Brecs.c
               error.c error.h)
target_add_platform(brecs)
install(TARGETS brecs DESTINATION lib)
install(FILES Brecs.h DESTINATION include)

add_executable(brecs-reconsparse 
               brecs.main.c
               parameter.io.h parameter.io.c
               sqlite3.c sqlite3.h
               cmdline.h cmdline.c)
target_link_libraries(brecs-reconsparse brecs-static)
install(TARGETS brecs-reconsparse DESTINATION bin)
