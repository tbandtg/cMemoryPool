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

#include "eMemoryPoolErrorCodes.h"
#include "cMemoryPoolConfig.h"

/** Data Structure for a memory Pool control object */
typedef struct 
{
    /* data */
    void * _pData;
    bool _inUse;
} sMemoryPoolInfo_t;

/** Init Memory Pools */
extern uint16_t initMemoryPool( uint8_t * const pSmallPoolData, 
                          uint32_t const smallPoolBlockSize, 
                          uint32_t const smallPoolBlockCount, 
                          sMemoryPoolInfo_t * const pSmallPoolInfo );


#if defined(__cplusplus)
}
#endif

#endif /* End define C_MEMORYPOOL_H*/
