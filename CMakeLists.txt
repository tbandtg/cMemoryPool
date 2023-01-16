# 0.) Create Source and CMakeFile
# 1.) mkdir build
# 2.) cd build
# 3.) cmake ..   -  Generting the Build Files / Configure the Project
# 4.) cmake --build .
# 5.) ./Executable
# 6.) To onlyu build a library do --build . --target Library
cmake_minimum_required(VERSION 3.10)

project(MemoryPool VERSION 1.0.0 LANGUAGES C CXX)

add_subdirectory(testLib)
add_subdirectory(app)
