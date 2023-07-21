/****************************************************************
 * @file memoryPoolImplementation.h
 * @brief provides defines and prototypes used to implement and test cMemoryPoolLib
 * @author Anthony Garza
**************************************************************/
#ifndef MEMORY_POOL_IMPLEMENTATION_H
#define MEMORY_POOL_IMPLEMENTATION_H
#include <stdint.h>

#define SMALL_POOL_ARRAY_COUNT                                  2048
#define SMALL_POOL_UNIT_SIZE_BYTES                                 1
#define MEDIUM_POOL_ARRAY_COUNT                                 1024
#define MEDIUM_POOL_UNIT_SIZE_BYTES                               4
#define LARGE_POOL_ARRAY_COUNT                                    32
#define LARGE_POOL_UNIT_SIZE_BYTES                               128
#define EXTRA_LARGE_POOL_ARRAY_COUNT                               4
#define EXTRA_LARGE_POOL_UNIT_SIZE_BYTES                        1024
#define TEST_INTENTIIONALLY_TO_LARGE                            DEF_FALSE
#define TEST_INTENTIONALLY_NULL                                 DEF_FALSE
extern uint16_t testMemoryPool( void );

#endif