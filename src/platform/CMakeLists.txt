
if(WIN32)
    add_subdirectory(msvc)
elseif(UNIX)
    add_subdirectory(unix)
endif()

function(target_add_platform tgt)
    target_link_libraries(${tgt} platform)
    target_add_3rdParty(${tgt})
endfunction()

function(target_add_platform_static tgt)
    target_link_libraries(${tgt} platform_static)
    target_add_3rdParty_static(${tgt})
endfunction()
