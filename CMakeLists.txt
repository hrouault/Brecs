cmake_minimum_required(VERSION 3.0)
project(brecs)
set_property(GLOBAL PROPERTY USE_FOLDERS TRUE) # Organize Visual Studio and
                                               # XCode projects

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

# Versioning
message(${CMAKE_MODULE_PATH})
include(GetGitRevisionDescription)
git_describe(VERSION --tags --dirty=-dirty)

#parse the version information into pieces.
string(REGEX REPLACE "^v([0-9]+)\\..*" "\\1" VERSION_MAJOR "${VERSION}")
string(REGEX REPLACE "^v[0-9]+\\.([0-9]+).*" "\\1" VERSION_MINOR "${VERSION}")
string(REGEX REPLACE "^v[0-9]+\\.[0-9]+\\.([0-9]+).*" "\\1" VERSION_PATCH
       "${VERSION}")
string(REGEX REPLACE "^v[0-9]+\\.[0-9]+\\.[0-9]+(.*)" "\\1" VERSION_SHA1
       "${VERSION}")
set(VERSION_SHORT "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

# add_definitions(-DBRECS_DISPLAYPLOTS)

if (APPLE)
    include(FindPkgConfig)
    pkg_check_modules(TIFF REQUIRED libtiff-4)
    pkg_check_modules(FFTW REQUIRED fftw3f)
    find_package(BZIP2 REQUIRED)
    find_package(JNI REQUIRED)
endif()

find_package(Sphinx)

include(CPack)
include(InstallRequiredSystemLibraries)

add_subdirectory(src)
add_subdirectory(doc)
