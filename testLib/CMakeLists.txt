add_library(testLib STATIC my_lib.c)
target_include_directories(testLib PUBLIC "./")
