/*******************************************************************************
 * @file cMemoryPoolConfig.h
 * @brief Configuration of the memory pool library.
*******************************************************************************/
#ifndef C_MEMORYPOOL_CONFIG_H
#define C_MEMORYPOOL_CONFIG_H

#if defined(__cplusplus)
extern "C" { // Access code from C++
#endif /* __cplusplus */

#ifndef DEF_TRUE
    #define DEF_TRUE                                                       0x01
#endif

#ifndef DEF_FALSE
    #define DEF_FALSE                                                      0x00
#endif


/** How many bytes are in each small pool block */
#define SMALL_POOL_BLOCK_SIZE_BYTES                                           32

/** How many small blocks are in the pool */
#define SMALL_POOL_BLOCK_COUNT                                               100 


/** How many bytes are in a medium memory pool block */
#define MEDIUM_POOL_BLOCK_SIZE_BYTES                                         128

/** How many medium pool blocks */
#define MEDIUM_POOL_BLOCK_COUNT                                               16 

/** How many bytes in each large memory block */
#define LARGE_POOL_BLOCK_SIZE_BYTES                                         1024

/** How many Large Memroy Blocks */
#define LARGE_POOL_BLOCK_COUNT                                                16

/** Is the starting address assigned for each pool */
#define USE_STARTING_ADDRESSES                                          DEF_FALSE

/** Whether the Starting addresses are going to be in the linker or this file */
#define USE_LINKER_FOR_ADDRESSES                                        DEF_FALSE

/** Large Pool Starting Addres if it is 0x00 then will not be specified by the library */
#define LARGE_POOL_STARTING_ADDRESS                                          0x00

/** Medium Pool Starting Address if it is not defined then the library will not specifiy */
#define MEDIUM_POOL_STARTING_ADDRESS                                         0x00

/** Small Pool Starting Address if it is not defined then the library will not specify it. */
#define SMALL_POOL_STARTING_ADDRESS                                          0x00

/** Define Error Code Starting Number */
#define MEMORY_POOL_STARTING_ERROR_CODE                                     0x100

#if defined(__cplusplus)
}
#endif

#endif /* C_MEMORYPOOL_CONFIG_H */

