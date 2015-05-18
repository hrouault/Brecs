file(GLOB SRCS *.c *.h)

add_library(platform STATIC ${SRCS})
set(PLATFORM_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}
    CACHE PATH "Path to platform specific source"
    FORCE)
set_property(TARGET platform APPEND PROPERTY INCLUDE_DIRECTORIES ${PLATFORM_SOURCE_DIR})
set_property(TARGET platform APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${PLATFORM_SOURCE_DIR})

include(FindPkgConfig)
pkg_check_modules(TIFF REQUIRED libtiff-4)
pkg_check_modules(FFTW REQUIRED fftw3f)

function(target_add_3rdParty tgt)
    target_link_libraries(${tgt} m ${FFTW_STATIC_LIBRARIES} ${TIFF_STATIC_LIBRARIES})
endfunction()
