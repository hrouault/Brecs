add_subdirectory(msvc)

function(target_add_platform tgt)
    showprop(DIRECTORY ${CMAKE_CURRENT_LIST_DIR} INCLUDE_DIRECTORIES)
    target_link_libraries(${tgt} platform)
endfunction()
