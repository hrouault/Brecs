include(FindPkgConfig)
pkg_check_modules(TIFF REQUIRED libtiff-4)
pkg_check_modules(FFTW REQUIRED fftw3f)

file(GLOB SRCS *.c *.h)

add_library(platform STATIC ${SRCS})
set(PLATFORM_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}
    CACHE PATH "Path to platform specific source"
    FORCE)
set_property(TARGET platform APPEND PROPERTY INCLUDE_DIRECTORIES ${PLATFORM_SOURCE_DIR} ${TIFF_INCLUDE_DIRS})
set_property(TARGET platform APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${PLATFORM_SOURCE_DIR})

set_property(TARGET platform PROPERTY POSITION_INDEPENDENT_CODE TRUE)

add_library(platform_static STATIC brecs_memory.c afloat.h brecs_memory.h platform.h)
set(PLATFORM_STATIC_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}
    CACHE PATH "Path to platform specific source"
    FORCE)
set_property(TARGET platform_static APPEND PROPERTY INCLUDE_DIRECTORIES ${PLATFORM_SOURCE_DIR})
set_property(TARGET platform_static APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${PLATFORM_SOURCE_DIR})

set_property(TARGET platform_static PROPERTY POSITION_INDEPENDENT_CODE TRUE)

function(target_add_3rdParty tgt)
    set_property(TARGET ${tgt} APPEND PROPERTY INCLUDE_DIRECTORIES ${FFTW_INCLUDE_DIRS} ${TIFF_INCLUDE_DIRS})
    target_link_libraries(${tgt} m ${FFTW_LIBRARIES} ${TIFF_LIBRARIES} ${BZIP2_LIBRARIES})
endfunction()

function(target_add_3rdParty_static tgt)
    set_property(TARGET ${tgt} APPEND PROPERTY INCLUDE_DIRECTORIES ${FFTW_INCLUDE_DIRS} ${TIFF_INCLUDE_DIRS})
    target_link_libraries(${tgt} m ${CMAKE_SOURCE_DIR}/src/platform/osx/libfftw3f.a)
endfunction()
