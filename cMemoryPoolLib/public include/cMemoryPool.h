/** **************************************************************
 * @file: cMemoryPool.h
 * @brief Main Include file for the memory pool library.
 * @author Anthony Garza
 * @copyright Copyright 2023 All Rights Reserved.
****************************************************************/

#ifndef C_MEMORYPOOL_H
#define C_MEMORYPOOL_H

#if defined(__cplusplus)
extern "C" { // Access code from C++
#endif /* __cplusplus */

#include <stdint.h>
#include <stdbool.h>

#include "cMemoryPoolConfig.h"

/**
 * @brief  Union of flags for the memory pool
 */
typedef union {
    uint16_t _inUse: 1;
    uint16_t _isMultiple: 1;
    uint16_t _isFirst :1;
    uint16_t _count : 13;
} sMemoryPoolFlags_t;
/**
 *  Data structure ofr each member of the pool
 * */
typedef struct 
{
    /* pointer to one piece of data */
    void * _pData;
    sMemoryPoolFlags_t _flags;
} sMemoryPoolMember_t;

/** Data Structure for a memory Pool control object */
typedef struct 
{
    /* pointer to an array of data */
    sMemoryPoolMember_t * _pData;
    bool _inUse;
} sMemoryPoolInfo_t;

/** Memory Pool Control Strucure */
typedef struct sMemoryPoolControl_s
{
    /** Info Struct for the Pool */
    sMemoryPoolInfo_t _poolInfo;

    /** Block Count of the Pool */
    uint32_t _poolBlockCount;

    /** Pool Block Size in bytes */
    uint32_t _poolBlockSizeBytes;

    /** Pool Free Count */
    uint32_t _poolFreeCount;
} sMemoryPoolControl_t;

#define EMPTY_CONTROL_STRUCT { { NULL, false }, 0U, 0U, 0U, }

/** Initialize a single memory pool  */
extern uint16_t initMemoryPool( void * const poolData, 
                         uint32_t const poolBlockSize,
                         uint32_t const poolBlockCount );

/** Initalize the controls for all of the pools */
extern uint16_t initMemoryPools( sMemoryPoolControl_t * *  poolControls, 
                                 uint32_t const poolCount );

/** Grab a block */
extern uint16_t memoryPoolMalloc( void ** pData, 
                                  uint32_t const sizeInBytes, 
                                  bool const useMultiple );

/** Free up a given block */
extern uint16_t memoryPoolFree( void ** pData ); 

/** Get the count of pools in the system */
extern int8_t getPoolCount( void );

/** Get the count of uninitialized pools in the system */
extern int8_t getUninitializedPoolCount( void );

#if defined(__cplusplus)
}
#endif

#endif /* End define C_MEMORYPOOL_H*/
