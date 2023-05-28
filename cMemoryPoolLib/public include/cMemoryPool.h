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

/** Data Structure for a memory Pool control object */
typedef struct 
{
    /* data */
    void * _pData;
    bool _inUse;
} sMemoryPoolInfo_t;

/** Memory Pool Control Strucure */
typedef struct
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
                                  bool const useMultiple, 
                                  bool const preferLargerSpace );

/** Free up a given block */
extern uint16_t memoryPoolFree( void ** pData );
#if defined(__cplusplus)
}
#endif

#endif /* End define C_MEMORYPOOL_H*/
