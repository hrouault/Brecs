configure_file(${CMAKE_CURRENT_SOURCE_DIR}/version.c.in
               ${CMAKE_CURRENT_BINARY_DIR}/version.c)
set(version_file "${CMAKE_CURRENT_BINARY_DIR}/version.c")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(platform)

include(GenerateExportHeader)
add_library(brecs SHARED
            Brecs.h Brecs.c
            inoutimg.h inoutimg.c
            error.c error.h)
target_add_platform(brecs)
generate_export_header(brecs)

install(TARGETS brecs DESTINATION lib)
install(FILES Brecs.h DESTINATION include)

add_executable(brecs-genpsf
               genpsf.c genpsf.h genpsf_main.c)
target_link_libraries(brecs-genpsf brecs)
install(TARGETS brecs-genpsf DESTINATION bin)

add_executable(brecs-reconsparse
               brecs.main.c
               parameter.io.h parameter.io.c
               cmdline.h cmdline.c)
target_link_libraries(brecs-reconsparse brecs)
install(TARGETS brecs-reconsparse DESTINATION bin)

if (JNI_FOUND)
    include_directories(${JNI_INCLUDE_DIRS})
    SWIG_ADD_MODULE(javainterf java javainterf.i javainterf.c error.c Brecs.c
        genpsf.c)
    SWIG_LINK_LIBRARIES(javainterf platform ${FFTW_LIBRARIES})
endif (JNI_FOUND)
