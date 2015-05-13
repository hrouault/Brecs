
if(WIN32)
    add_subdirectory(msvc)
elseif(APPLE)
    add_subdirectory(osx)
else() # linux
    add_subdirectory(linux)
endif()

function(target_add_platform tgt)
    target_link_libraries(${tgt} platform)
    target_add_3rdParty(${tgt})
endfunction()
