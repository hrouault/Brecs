cmake_minimum_required(VERSION 3.0)
project(brecs)
set_property(GLOBAL PROPERTY USE_FOLDERS TRUE) # Organize Visual Studio and XCode projects

add_definitions(/arch:AVX2) # compile with AVX2

add_subdirectory(src)

