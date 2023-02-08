add_executable(Executable main.c)
target_link_libraries(Executable PUBLIC ${TEST_LIBRARY_NAME} )
target_link_libraries(Executable PUBLIC cMemoryPoolLib)
