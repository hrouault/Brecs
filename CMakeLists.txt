cmake_minimum_required(VERSION 3.0)
project(brecs)
set_property(GLOBAL PROPERTY USE_FOLDERS TRUE) # Organize Visual Studio and
                                               # XCode projects

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

include(cstd)
use_c99()

option(brecs_BUILD_DOC "Build the B-recs documentation" ON)
option(brecs_BUILD_IMAGEJ_PLUGIN "Build the ImageJ/Fiji plugin" ON)

# Versioning
find_package(Git REQUIRED)
include(GetGitRevisionDescription)
git_describe(VERSION --tags)

#parse the version information into pieces.
string(REGEX REPLACE "^v([0-9]+)\\..*" "\\1" VERSION_MAJOR "${VERSION}")
string(REGEX REPLACE "^v[0-9]+\\.([0-9]+).*" "\\1" VERSION_MINOR "${VERSION}")
string(REGEX REPLACE "^v[0-9]+\\.[0-9]+\\.([0-9]+).*" "\\1" VERSION_PATCH
       "${VERSION}")
string(REGEX REPLACE "^v[0-9]+\\.[0-9]+\\.[0-9]+(.*)" "\\1" VERSION_SHA1
       "${VERSION}")
set(VERSION_SHORT "${VERSION_MAJOR}.${VERSION_MINOR}")
message("Configuring B-recs version ${VERSION_SHORT}")

add_definitions(-DVERSION="${VERSION_SHORT}")
add_definitions(-DPACKAGE="Brecs")

add_definitions(-DBRECS_DISPLAYPLOTS)

include(platform)

find_package(TIFF REQUIRED)
find_package(BZip2 REQUIRED)

include(CPack)
include(InstallRequiredSystemLibraries)

add_subdirectory(src)

#if (brecs_BUILD_IMAGEJ_PLUGIN)
#    find_package(JNI)
#    find_package(SWIG)
#    if (NOT JNI_FOUND OR NOT SWIG_FOUND)
#        message(FATAL_ERROR "Package JNI or SWIG not found, the ImageJ plugin "
#                "can't be compiled! Set the variable BUILD_IMAGEJ_PLUGIN to "
#                "OFF if you don't want the plugin to be generated.")
#    endif()
#    include(${SWIG_USE_FILE})
#    add_subdirectory(fiji-plugin)
#endif()

if (brecs_BUILD_DOC)
    find_package(Sphinx)
    if (NOT Sphinx_FOUND)
        message(FATAL_ERROR "Package Sphinx not found, the documentation "
                "can't be compiled! Set the variable BUILD_DOC to OFF if you "
                "don't want the documentation to be generated.")
    endif()
    add_subdirectory(doc)
endif()
