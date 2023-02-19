add_executable(${EXECUTABLE_NAME}  source/main.c source/memoryPoolImplementation.c)

target_include_directories(${EXECUTABLE_NAME}   PRIVATE .)
target_include_directories(${EXECUTABLE_NAME}   PRIVATE include)
target_include_directories(${EXECUTABLE_NAME}   PRIVATE source)
target_link_libraries(${EXECUTABLE_NAME}   PUBLIC ${TEST_LIBRARY_NAME} )
target_link_libraries(${EXECUTABLE_NAME}   PUBLIC ${MEMORY_POOL_LIBRARY_NAME} )
