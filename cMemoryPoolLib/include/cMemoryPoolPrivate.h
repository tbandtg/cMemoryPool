/** **************************************************************
 * @file: cMemoryPoolPrivate.h
 * @brief Structures that are used prvately by the memory pool library.
 * @author Anthony Garza
 * @copyright Copyright 2023 All Rights Reserved.
****************************************************************/

#ifndef C_MEMORYPOOL_PRIVATE_H
#define C_MEMORYPOOL_PRIVATE_H

#if defined(__cplusplus)
extern "C" { // Access code from C++
#endif /* __cplusplus */

#include <stdint.h>
#include <stdbool.h>

#include "eMemoryPoolErrorCodes.h"
#include "cMemoryPoolConfig.h"
#include "cMemoryPool.h"

/** Memory Pool Control Strucure */
typedef struct
{
    /** Info Struct for the Pool */
    sMemoryPoolInfo_t * _pPoolInfo;

    /** Pointer to the actual pool */
    uint8_t * _pPoolData;

    /** Block Count of the Pool */
    uint32_t _poolBlockCount;

    /** Pool Block Size in bytes */
    uint32_t _poolBlockSizeBytes;

    /** Pool Free Count */
    uint32_t _poolFreeCount;
} sMemoryPoolControl_t;


#if defined(__cplusplus)
}
#endif

#endif /* End define C_MEMORYPOOL_PRIVATE_H */
