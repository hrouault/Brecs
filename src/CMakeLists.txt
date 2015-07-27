include(cmake/show.cmake)
include(cmake/ide.cmake)
include(cmake/platform.cmake)

add_subdirectory(platform)


add_library(brecs-static STATIC
            Brecs.h Brecs.c
            error.c error.h)
        set_property(TARGET brecs-static APPEND PROPERTY INCLUDE_DIRECTORIES ${TIFF_INCLUDE_DIRS} ${FFTW_INCLUDE_DIRS})
    set_property(TARGET brecs-static APPEND PROPERTY LINK_DIRECTORIES ${FFTW_LIBRARY_DIRS} ${TIFF_LIBRARY_DIRS})
set_property(TARGET brecs-static PROPERTY POSITION_INDEPENDENT_CODE TRUE)
target_add_platform(brecs-static)
install(TARGETS brecs-static DESTINATION lib)

add_library(brecs SHARED
               Brecs.h Brecs.c
               error.c error.h)
    set_property(TARGET brecs APPEND PROPERTY LINK_DIRECTORIES ${FFTW_LIBRARY_DIRS} ${TIFF_LIBRARY_DIRS})
set_property(TARGET brecs APPEND PROPERTY INCLUDE_DIRECTORIES ${TIFF_INCLUDE_DIRS} ${FFTW_INCLUDE_DIRS})
target_add_platform(brecs)
install(TARGETS brecs DESTINATION lib)
install(FILES Brecs.h DESTINATION include)

if (JNI_FOUND)
    include_directories(${JNI_INCLUDE_DIRS})
    add_library(fiji-brecs SHARED Brecs.h Brecs.c error.c error.h
                Brecs_wrap.c Brecssimp.c Brecssimp.h)
    target_add_platform_static(fiji-brecs)
    target_link_libraries (fiji-brecs ${JNI_LIBRARIES})
endif (JNI_FOUND)

add_executable(brecs-reconsparse 
               brecs.main.c
               parameter.io.h parameter.io.c
               sqlite3.c sqlite3.h
               cmdline.h cmdline.c)
target_link_libraries(brecs-reconsparse brecs-static)
install(TARGETS brecs-reconsparse DESTINATION bin)
