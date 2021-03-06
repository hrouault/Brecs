set(FFTW_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR} CACHE PATH "Path to FFTW source" FORCE)
set(arch x86)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(arch w64)
endif()

set(incdir ${FFTW_SOURCE_DIR}/${arch})
set(libdir ${FFTW_SOURCE_DIR}/${arch})

if(NOT TARGET fftw)
    add_library(fftw SHARED IMPORTED GLOBAL)
    set_target_properties(fftw PROPERTIES IMPORTED_LOCATION "${libdir}/libfftw3f-3.dll"
                                          INCLUDE_DIRECTORIES  "${incdir}"
                                          IMPORTED_IMPLIB "${libdir}/libfftw3f-3.lib"
                                          INTERFACE_INCLUDE_DIRECTORIES  "${incdir}")
endif()

function(target_add_fftw tgt)
    target_link_libraries(${tgt} fftw)

    set(arch x86)
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(arch w64)
    endif()
    install(FILES "${FFTW_SOURCE_DIR}/${arch}/libfftw3f-3.dll" DESTINATION bin)
endfunction()
