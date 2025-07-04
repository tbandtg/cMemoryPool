

if( COMPILE_MEMORY_POOL_LIBRARY_STATIC )
    add_library( ${MEMORY_POOL_LIBRARY_NAME} STATIC 
                                            source/cMemoryPool.c )
    add_subdirectory(include)
    add_subdirectory("publicInclude")
    target_include_directories(${MEMORY_POOL_LIBRARY_NAME} PRIVATE "include")
    target_include_directories(${MEMORY_POOL_LIBRARY_NAME} PUBLIC "publicInclude")
    target_include_directories(${MEMORY_POOL_LIBRARY_NAME} PRIVATE "source")
else()
    cmake_minimum_required(VERSION 3.10)
    set ( MEMORY_POOL_LIBRARY_NAME cMemoryPoolLib )
    project(MemoryPoolSharedLib VERSION 1.0.0 LANGUAGES C CXX DESCRIPTION "Shared portion of the memory pool Libarary ")

    set ( CMAKE_CXX_STANDARD 11)
    set ( CMAKE_CXX_STANDARD_REQUIRED ON )
    set ( CMAKE_CXX_EXTENSIONS ON )
    include(GNUInstallDirs)
    add_library( ${MEMORY_POOL_LIBRARY_NAME} SHARED 
                                            source/cMemoryPool.c )
    set_target_properties(${MEMORY_POOL_LIBRARY_NAME} PROPERTIES SOVERSION 1)
    set_target_properties(${MEMORY_POOL_LIBRARY_NAME} PROPERTIES PUBLIC_HEADER cMemoryPool.h)
    target_include_directories(${MEMORY_POOL_LIBRARY_NAME} PRIVATE .)
    target_include_directories(${MEMORY_POOL_LIBRARY_NAME} PRIVATE include)
    target_include_directories(${MEMORY_POOL_LIBRARY_NAME} PRIVATE source)
endif()

if( UNIT_TESTS )
    add_executable(
        cMemoryTest
        unittest/cMemoryPool_test.cpp
        source/cMemoryPool.c
    )
    target_include_directories(cMemoryTest PRIVATE .)
    target_include_directories(cMemoryTest PRIVATE include)
    target_include_directories(cMemoryTest PRIVATE source)
    target_link_libraries(
        cMemoryTest
        GTest::gtest_main
    )

    include(GoogleTest)
    gtest_discover_tests(cMemoryTest)
endif()