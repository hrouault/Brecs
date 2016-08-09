add_library(platform STATIC brecs_memory.c brecs_memory.h platform.h afloat.h)
set(PLATFORM_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}
    CACHE PATH "Path to platform specific source"
    FORCE)
set_property(TARGET platform APPEND PROPERTY
             INCLUDE_DIRECTORIES ${PLATFORM_SOURCE_DIR} ${TIFF_INCLUDE_DIRS})
set_property(TARGET platform APPEND PROPERTY
             INTERFACE_INCLUDE_DIRECTORIES ${PLATFORM_SOURCE_DIR})
set_property(TARGET platform PROPERTY POSITION_INDEPENDENT_CODE TRUE)

function(target_add_3rdParty tgt)
    set_property(TARGET ${tgt} APPEND PROPERTY
                 INCLUDE_DIRECTORIES ${FFTW_INCLUDE_DIRS} ${TIFF_INCLUDE_DIRS})
    target_link_libraries(${tgt} m ${FFTW_LIBRARIES} ${TIFF_LIBRARIES})
endfunction()
