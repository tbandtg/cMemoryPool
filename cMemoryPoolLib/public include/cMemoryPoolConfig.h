/*******************************************************************************
 * @file cMemoryPoolConfig.h
 * @brief Configuration of the memory pool library. These are the values used
 * for a dynamically built libary. If the library is built statically they can be
 * changed by replacing this file.
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

#ifndef MEMORY_POOLS_COUNT
    /** 
     * Configurable for a static library,
     * How many different sized pools are supported by the library.
    */
    #define MEMORY_POOLS_COUNT                                             0x05
#endif

#ifndef STATIC_LIBRARY_BUILD
    /** Whether or not the library is being built statically. */
    #define STATIC_LIBRARY_BUILD                                       DEF_TRUE
#endif

#ifndef MEMORY_POOL_STARTING_ERROR_CODE 
/** Define Error Code Starting Number */
#define MEMORY_POOL_STARTING_ERROR_CODE                                   0x100
#endif 

#if defined(__cplusplus)
}
#endif

#endif /* C_MEMORYPOOL_CONFIG_H */

