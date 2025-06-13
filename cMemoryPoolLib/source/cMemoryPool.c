/** ***********************************************
 * @file cMemoryPool.c
 * @brief Implementation of the memory pools
 * @author Anthony Garza
 * @copyright All rights reserved 2024
*************************************************/
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "eMemoryPoolErrorCodes.h"
#include "../public include/cMemoryPoolConfig.h"
#include "../public include/cMemoryPool.h"
#include "cMemoryPoolPrivate.h"
#include <stdio.h>
/** Array of controls */
static sMemoryPoolControl_t controlArray[ MEMORY_POOLS_COUNT ];

typedef struct
{
    sMemoryPoolControl_t * _controlArray; /* Array of control sturctures for the pools */
    int8_t _poolCount;                     /* Number of pools in the control array. */
    bool  _driverInitialized;              /* Whether or not this driver has been initialized */
    int8_t _poolsInUseCount;               /* How many pools have been initialized*/
} sMemoryPoolDriverControl_t;

/** THIS pointer to Array of Memory Pool controls */
static sMemoryPoolDriverControl_t THIS = { NULL, MEMORY_POOLS_COUNT, false, 0 };

/** Has the The Memory Pool Driver been initialized */
/**
 * @brief Initialized overall control for the memory pool driver
 * 
 * @param poolControls Pointer to the array of pool controls.
 * @param poolCount Number of pools to be initialized.
 * @return an error uint16_t code if successfull;
 */ 
uint16_t initMemoryPools( sMemoryPoolControl_t ** poolControls, 
                          uint32_t const poolCount )
{
    
    eMemoryPoolErrorCodes_t retValue = MEMORY_POOL_ERROR_NONE;
    printf("Init called \r\n");
    // Only initialize if the driver is not currently initialized.
    if( false == THIS._driverInitialized )
    {
        // If a valid poolControl structure is passed initialize that.
        if( NULL != poolControls )
        {
            THIS._controlArray = *poolControls;
            THIS._poolCount = poolCount;
            THIS._poolsInUseCount = 0;
            THIS._driverInitialized = true;            
        }
        else
        {
            // If Null is passed use the internal control Array. 
            if( ( MEMORY_POOLS_COUNT > poolCount ) && ( poolCount > 0 ) )
            {
                THIS._controlArray = (sMemoryPoolControl_t*)controlArray;
                THIS._driverInitialized = true;
                THIS._poolCount = poolCount;
                THIS._poolsInUseCount = 0;
            }
            else
            {
                retValue = MEMORY_POOL_INVALID_POOL_COUNT;
            }            
        }        
    }

    return ( (uint16_t)retValue );
}

/**
 * @brief Initialize a memory pool with a given data array and size. Memory pools should be in 
 * smallest pool to largest pool order. 
 * 
 * @param poolData Pointer to the data array to be used for the pool
 * @param poolBlockSize Size of each block in the pool
 * @param poolBlockCount Number of blocks in the pool
 * @return an error uint16_t code if successfull;
*/
uint16_t initMemoryPool( void * const poolData, 
                         uint32_t const poolBlockSize,
                         uint32_t const poolBlockCount )
{
    uint16_t retValue = MEMORY_POOL_NULL_PTR_ERROR;
    int32_t indexToPlace = 0;
    /* Sanity check incoming data pointer to not be NULL */
    if( NULL != poolData )
    {
        retValue = MEMORY_POOL_DRIVER_NOT_INIT;
        /* Do not initalize a pool if the pool control has not been initialized */
        if ( true == THIS._driverInitialized )
        {
            retValue = MEMORY_POOL_NO_FREE_POOL_LOCATION;
            /* Sanity Check the Pool Count */
            if( THIS._poolsInUseCount < THIS._poolCount )
            {
                /* Enssure that there is an available pool slot */
                if( false == THIS._controlArray[ THIS._poolCount - 1 ]._poolInfo._inUse ) 
                {          
                    (void)memset( poolData, 0x00, ( poolBlockSize * poolBlockCount ) );    
            
                    /* Loop through and find the place for the new pool */
                    for( int32_t i = 0; i < THIS._poolCount; i++ )
                    {
                        /* Found a free spot. */
                        if( false == THIS._controlArray[i]._poolInfo._inUse )
                        {
                            retValue = MEMORY_POOL_ERROR_NONE;
                            /* This is the proper place for this new pool*/
                            THIS._controlArray[i]._poolBlockCount = poolBlockCount;
                            THIS._controlArray[i]._poolBlockSizeBytes = poolBlockSize;
                            THIS._controlArray[i]._poolFreeCount = poolBlockCount;
                            THIS._controlArray[i]._poolInfo._inUse = true;
                            THIS._controlArray[i]._poolInfo._pData = poolData;
                            THIS._poolsInUseCount++;
                            break;
                        }
                        else
                        {
                            if( THIS._controlArray[i]._poolBlockSizeBytes > poolBlockSize )
                            {
                                for( int32_t j = ( THIS._poolCount - 2 ); j >= i; j--)
                                {
                                    if( true == THIS._controlArray[j]._poolInfo._inUse )
                                    {
                                        (void)memcpy( ( void* )&THIS._controlArray[j + 1], 
                                                    ( void* )&THIS._controlArray[j], 
                                                    sizeof( sMemoryPoolControl_t ) );
                                    }
                                    
                                }
                                retValue = MEMORY_POOL_ERROR_NONE;
                                /* This is the proper place for this new memory pool*/
                                THIS._controlArray[i]._poolBlockCount = poolBlockCount;
                                THIS._controlArray[i]._poolBlockSizeBytes = poolBlockSize;
                                THIS._controlArray[i]._poolFreeCount = poolBlockCount;
                                THIS._controlArray[i]._poolInfo._inUse = true;
                                THIS._controlArray[i]._poolInfo._pData = poolData;
                                THIS._poolsInUseCount++;
                                break;
                            } 
                        }
                    }
                }
            }
        }
    }

    return( retValue );
}

/**
 * @brief Helper function to read the current pool count
 * 
 * @return Overall pool count
 */ 
int8_t getPoolCount( void )
{
    int8_t retValue = -1;
    if( true == THIS._driverInitialized )
    {
        retValue = THIS._poolCount;
    }
    return ( retValue );
}

/** 
 * @brief Helper function that gives the number of pools in the system that have been initialzied.
 * 
 * @return int8 initialized pool count
 */
int8_t getUninitializedPoolCount( void )
{
    int8_t retValue = -1;
    if( true == THIS._driverInitialized )
    {
        retValue = THIS._poolsInUseCount;
  
    }
    return( retValue );
}

/**
 * @brief function to malloc a block of memory from the pool. Will only use multiple if there are
 * no single blocks available that will fit the requested space. 
 * 
 * @param pData Pointer to the data that is to be malloced
 * @param sizeInBytes Size of the data to be malloced
 * @param useMultiple Whether or not to use multiple blocks
 * @param preferLargerSpace Whether or not to prefer larger space
 * @return an error uint16_t code if unsuccessfull or NO_ERROR if successfull.
 */
uint16_t memoryPoolMalloc( void ** pData, 
                           uint32_t const sizeInBytes, 
                           bool const useMultiple )
{
    uint16_t retValue = MEMORY_POOL_NULL_PTR_ERROR;
    bool singleBlockFound = false;
    uint32_t blocksNeeded = 0;
    if( NULL != pData )
    {
        retValue = MEMORY_POOL_DRIVER_NOT_INIT;
        if( true == THIS._driverInitialized )
        {
            retValue = MEMORY_POOL_NO_FREE_POOL_LOCATION;
            // Loop through and see if one is available with a larger block size.
            for( int32_t i = 0; i < THIS._poolCount; i++ )
            {
                if( true == THIS._controlArray[i]._poolInfo._inUse )
                {
                    if( THIS._controlArray[i]._poolBlockSizeBytes >= sizeInBytes )
                    {
                        if( THIS._controlArray[i]._poolFreeCount > 0 )
                        {
                            *pData = THIS._controlArray[i]._poolInfo._pData;
                            THIS._controlArray[i]._poolFreeCount--;
                            singleBlockFound = true;
                            retValue = MEMORY_POOL_ERROR_NONE;
                            break;
                        }
                    }
                }
            }

            // If no single larger block size is available. 
            if( ( false == singleBlockFound ) && ( true == useMultiple ) )
            {
                // Loop through and see if one is available with a smaller block size.
                for( int32_t i = 0; i < THIS._poolCount; i++ )
                {
                    if( true == THIS._controlArray[i]._poolInfo._inUse )
                    {
                        if( THIS._controlArray[i]._poolBlockSizeBytes < sizeInBytes )
                        {
                            // determine how many blocks are needed. 
                            blocksNeeded = sizeInBytes / THIS._controlArray[i]._poolBlockSizeBytes;
                            // Need at least as many pools as it takes and they must be contiguous.
                            if( THIS._controlArray[i]._poolFreeCount > blocksNeeded )
                            {
                                *pData = THIS._controlArray[i]._poolInfo._pData;
                                THIS._controlArray[i]._poolFreeCount--;
                                singleBlockFound = true;
                                retValue = MEMORY_POOL_ERROR_NONE;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    return( retValue );
}