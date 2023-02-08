add_library( ${TEST_LIBRARY_NAME} STATIC my_lib.c)
target_include_directories( ${TEST_LIBRARY_NAME}  PUBLIC "./")
