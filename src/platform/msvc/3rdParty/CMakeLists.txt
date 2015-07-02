add_subdirectory(fftw)

function(target_add_3rdParty tgt)
    target_add_fftw(${tgt})
endfunction()
