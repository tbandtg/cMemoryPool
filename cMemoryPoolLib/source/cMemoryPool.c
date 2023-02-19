/** ***********************************************
 * @file cMemoryPool.c
 * @brief Implementation of the memory pools
 * @author Anthony Garza
*************************************************/


#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "eMemoryPoolErrorCodes.h"
#include "cMemoryPoolConfig.h"
#include "cMemoryPool.h"
#include "cMemoryPoolPrivate.h"
#include "cSmallPool.h"
#include "cMediumPool.h"

/** Array of Info Structures for the medium pool */
static sMemoryPoolInfo_t mediumPoolInfo[MEDIUM_POOL_BLOCK_COUNT];

/**
 * @brief Initialized the Memory Pools.
 * 
 * @return uint16_t 
 */
uint16_t initMemoryPools( uint8_t * const pSmallPoolData, 
                          uint32_t const smallPoolBlockSize, 
                          uint32_t const smallPoolBlockCount, 
                          sMemoryPoolInfo_t * const pSmallPoolInfo )
{
    
    eMemoryPoolErrorCodes_t retValue = MEMORY_POOL_ERROR_NONE;
    retValue = smallPoolInit( pSmallPoolData, smallPoolBlockSize, smallPoolBlockCount, pSmallPoolInfo );

    return ( (uint16_t)retValue );
}