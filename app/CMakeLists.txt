add_executable(Executable main.c)
target_link_libraries(Executable PUBLIC testLib)
target_link_libraries(Executable PUBLIC cMemoryPoolLib)
