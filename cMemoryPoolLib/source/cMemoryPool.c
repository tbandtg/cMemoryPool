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

/** Array of controls */
static sMemoryPoolControl_t controlArray[ MEMORY_POOLS_COUNT ];

typedef struct
{
    sMemoryPoolControl_t ** controlArray;
    uint8_t poolCount;
    int8_t poolsInUseCount;
} sMemoryPoolDriverControl_t;

/** THIS pointer to Array of Memory Pool controls */
static sMemoryPoolDriverControl_t THIS = { &controlArray, MEMORY_POOLS_COUNT, 0 };

/** Has the The Memory Pool Driver been initialized */
/**
 * @brief Initialized the Memory Pools.
 * 
 * @return uint16_t 
 */
uint16_t initMemoryPools( sMemoryPoolControl_t * const * const poolControls, 
                          uint32_t poolCount )
{
    
    eMemoryPoolErrorCodes_t retValue = MEMORY_POOL_ERROR_NONE;


    return ( (uint16_t)retValue );
}


uint16_t initMemoryPool( void * const poolData, 
                         uint32_t const poolBlockSize,
                         uint32_t const poolBlockCount )
{
    uint16_t retValue = MEMORY_POOL_NULL_PTR_ERROR;

    /* Sanity check incoming data pointer to not be NULL */
    if( NULL != poolData )
    {
        retValue = MEMORY_POOL_ERROR_NONE;
        for( int32_t i =0; i < )
        poolControl->_poolBlockCount = poolBlockCount;
        poolControl->_poolBlockSizeBytes = poolBlockSize;
        poolControl->_poolInfo._pData = poolData;
        /* Sanity check length, size and data */
        if( ( NULL != poolData ) && ( 0U < poolBlockCount ) && ( 0U < poolBlockSize ) )
        {
            poolControl->_poolInfo._inUse = true;

            // Add it to the array of pool controls if the overall driver has been initialized

        }
        poolInfo.
    }
    /* A zero size pool is not an error */
    if( ( 0 < poolBlockCount ) && ( 0 < poolBlockSize ) )
    {
        /* Sanity check incoming pointers if */
    }

    return( retValue );
}