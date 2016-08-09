set(LIBTIFF_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR} CACHE PATH "Path to libtiff source" FORCE)
set(arch x86)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(arch w64)
endif()

set(incdir ${LIBTIFF_SOURCE_DIR}/${arch})
set(libdir ${LIBTIFF_SOURCE_DIR}/${arch})

if(NOT TARGET libtiff)
    add_library(libtiff SHARED IMPORTED GLOBAL)
    set_target_properties(libtiff PROPERTIES IMPORTED_LOCATION "${libdir}/tiff.dll"
                                             INCLUDE_DIRECTORIES  "${incdir}"
                                             IMPORTED_IMPLIB "${libdir}/tiff.lib"
                                             INTERFACE_INCLUDE_DIRECTORIES  "${incdir}")
endif()

function(target_add_libtiff tgt)
    target_link_libraries(${tgt} libtiff)

    set(arch x86)
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(arch w64)
    endif()
    install(FILES "${LIBTIFF_SOURCE_DIR}/${arch}/tiff.dll" DESTINATION bin)
endfunction()
