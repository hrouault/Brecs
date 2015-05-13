cmake_minimum_required(VERSION 3.0)
project(brecs)
set_property(GLOBAL PROPERTY USE_FOLDERS TRUE) # Organize Visual Studio and XCode projects

include(CPack)
# include(InstallRequiredSystemLibraries)

add_subdirectory(src)

