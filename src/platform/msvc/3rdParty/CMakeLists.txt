add_subdirectory(fftw)
add_subdirectory(libtiff)

function(target_add_3rdParty tgt)
    target_add_fftw(${tgt})
    target_add_libtiff(${tgt})
endfunction()
