/** ***********************************************
 * @file cMemoryPool_test.cpp
 * @brief Unit tests for cMemoryPool.c
 * @author Anthony Garza
 * @copyright All rights reserved 2024
*************************************************/

#include <gtest/gtest.h>
#include "../publicInclude/cMemoryPool.h"
#include "../publicInclude/cMemoryPoolConfig.h"
#include "../include/eMemoryPoolErrorCodes.h"

TEST( cMemoryPool, initMemoryPools )
{
    sMemoryPoolControl_t controlArray[ MEMORY_POOLS_COUNT ];
    sMemoryPoolControl_t * controlArrayPtr = controlArray;
    uint16_t retValue = initMemoryPools( &controlArrayPtr, MEMORY_POOLS_COUNT );
    EXPECT_EQ( MEMORY_POOL_ERROR_NONE, retValue );
}