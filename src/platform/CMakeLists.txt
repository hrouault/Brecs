add_subdirectory(msvc)

function(target_add_platform tgt)
    target_link_libraries(${tgt} platform)
    target_add_3rdParty(${tgt})
endfunction()
