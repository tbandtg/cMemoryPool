/*****************************************************************
 * @file:  memoryPoolImplementation.c
 * @brief Implements the memory Pool Library.
 * @author Anthony Garza
 * @copyright Copyright 2023 All Rights Reserved.
****************************************************************/
#include "memoryPoolImplementation.h"
#include "cMemoryPool.h"

#include <stdint.h>
#include <stdio.h>

uint8_t smallPoolArray[SMALL_POOL_ARRAY_COUNT * SMALL_POOL_UNIT_SIZE_BYTES] = { 0x00 };
uint8_t mediumPoolArray[MEDIUM_POOL_ARRAY_COUNT * MEDIUM_POOL_UNIT_SIZE_BYTES] = { 0x00 };
uint8_t largePoolArray[LARGE_POOL_ARRAY_COUNT * LARGE_POOL_UNIT_SIZE_BYTES] = { 0x00 };
uint8_t extraLargePoolArray[EXTRA_LARGE_POOL_ARRAY_COUNT * EXTRA_LARGE_POOL_UNIT_SIZE_BYTES] = { 0x00 }; 


/** Can be configured to be different sizes for test. */
sMemoryPoolControl_t  poolArrays[] = { 
    {
        ._poolInfo._inUse    = false,
        ._poolInfo._pData    = smallPoolArray,
        ._poolBlockSizeBytes = SMALL_POOL_UNIT_SIZE_BYTES,
        ._poolBlockCount     = SMALL_POOL_ARRAY_COUNT,
        ._poolFreeCount      = 0,
    },
#if ( TEST_INTENTIONALLY_NULL == DEF_TRUE ) 
    {
        ._poolInfo._inUse    = false,
        ._poolInfo._pData    = NULL,
        ._poolBlockSizeBytes = MEDIUM_POOL_UNIT_SIZE_BYTES,
        ._poolBlockCount     = MEDIUM_POOL_ARRAY_COUNT,
        ._poolFreeCount      = 0,
    },
#endif
    {
        ._poolInfo._inUse    = false,
        ._poolInfo._pData    = mediumPoolArray,
        ._poolBlockSizeBytes = MEDIUM_POOL_UNIT_SIZE_BYTES,
        ._poolBlockCount     = MEDIUM_POOL_ARRAY_COUNT,
        ._poolFreeCount      = 0,
    },
    {
        ._poolInfo._inUse    = false,
        ._poolInfo._pData    = largePoolArray,
        ._poolBlockSizeBytes = LARGE_POOL_UNIT_SIZE_BYTES,
        ._poolBlockCount     = LARGE_POOL_ARRAY_COUNT,
        ._poolFreeCount      = 0,
    },
    {
        ._poolInfo._inUse    = false,
        ._poolInfo._pData    = extraLargePoolArray,
        ._poolBlockSizeBytes = EXTRA_LARGE_POOL_UNIT_SIZE_BYTES,
        ._poolBlockCount     = EXTRA_LARGE_POOL_ARRAY_COUNT,
        ._poolFreeCount      = 0,
    },
#if ( TEST_INTENTIIONALLY_TO_LARGE == DEF_TRUE )
    {
        ._poolInfo._inUse    = false,
        ._poolInfo._pData    = smallPoolArray,
        ._poolBlockSizeBytes = SMALL_POOL_UNIT_SIZE_BYTES,
        ._poolBlockCount     = SMALL_POOL_ARRAY_COUNT,
        ._poolFreeCount      = 0,
    },
    {
        ._poolInfo._inUse    = false,
        ._poolInfo._pData    = smallPoolArray,
        ._poolBlockSizeBytes = SMALL_POOL_UNIT_SIZE_BYTES,
        ._poolBlockCount     = SMALL_POOL_ARRAY_COUNT,
        ._poolFreeCount      = 0,
    },
    {
        ._poolInfo._inUse    = false,
        ._poolInfo._pData    = smallPoolArray,
        ._poolBlockSizeBytes = SMALL_POOL_UNIT_SIZE_BYTES,
        ._poolBlockCount     = SMALL_POOL_ARRAY_COUNT,
        ._poolFreeCount      = 0,
    },
    {
        ._poolInfo._inUse    = false,
        ._poolInfo._pData    = smallPoolArray,
        ._poolBlockSizeBytes = SMALL_POOL_UNIT_SIZE_BYTES,
        ._poolBlockCount     = SMALL_POOL_ARRAY_COUNT,
        ._poolFreeCount      = 0,
    },
#endif
    
};

/**
 * /brief Test harness for the memory pool implementation.
*/
uint16_t testMemoryPool( void )
{
    uint16_t retValue = initMemoryPools( NULL, ARRAY_LENGTH(poolArrays) );
    if(   == retValue  )
    {
        for( int i = 0; i < ARRAY_LENGTH(poolArrays); i++ )
        { 
            retValue = initMemoryPool( poolArrays[i]._poolInfo._pData, poolArrays[i]._poolBlockSizeBytes, poolArrays[i]._poolBlockCount );
        }
        printf("Initialize successfull");
        if

    }
    else
    {
        printf("Initialization failed!");
    }
}
