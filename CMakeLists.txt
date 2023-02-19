# 0.) Create Source and CMakeFile
# 1.) mkdir build
# 2.) cd build
# 3.) cmake ..   -  Generting the Build Files / Configure the Project
# 4.) cmake --build .
# 5.) ./Executable
# 6.) To onlyu build a library do --build . --target Library
cmake_minimum_required(VERSION 3.10)

project(MemoryPool VERSION 1.0.0 LANGUAGES C CXX)

set ( CMAKE_CXX_STANDARD 11)
set ( CMAKE_CXX_STANDARD_REQUIRED ON )
set ( CMAKE_CXX_EXTENSIONS ON )

set ( TEST_LIBRARY_NAME testLib )
set ( COMPILE_MEMORY_POOL_LIBRARY_STATIC ON )
set ( MEMORY_POOL_LIBRARY_NAME cMemoryPoolLib )
set ( EXECUTABLE_NAME Executable )

option(COMPILE_EXECUTABLE "Whether to compile the executable" ON)
add_subdirectory(testLib)
add_subdirectory(cMemoryPoolLib)


if( COMPILE_EXECUTABLE )
    add_subdirectory(app)
else()
    message("W/o exe. compiling ")
endif()
