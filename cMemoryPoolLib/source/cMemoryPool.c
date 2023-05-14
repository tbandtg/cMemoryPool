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
#include "../public include/cMemoryPoolConfig.h"
#include "../public include/cMemoryPool.h"
#include "cMemoryPoolPrivate.h"

/** Array of controls */
static sMemoryPoolControl_t controlArray[ MEMORY_POOLS_COUNT ];

typedef struct
{
    sMemoryPoolControl_t ** _controlArray;
    uint8_t _poolCount;
    bool  _driverInitialized;
    int8_t _poolsInUseCount;
} sMemoryPoolDriverControl_t;

/** THIS pointer to Array of Memory Pool controls */
static sMemoryPoolDriverControl_t THIS = { NULL, MEMORY_POOLS_COUNT, false, 0 };

/** Has the The Memory Pool Driver been initialized */
/**
 * @brief Initialized overall control for the memory pool driver
 * 
 * @return uint16_t 
 */
uint16_t initMemoryPools( sMemoryPoolControl_t ** poolControls, 
                          uint32_t const poolCount )
{
    
    eMemoryPoolErrorCodes_t retValue = MEMORY_POOL_ERROR_NONE;
    if( false == THIS._driverInitialized )
    {
        if( NULL != poolControls )
        {
            THIS._controlArray = poolControls;
            THIS._poolCount = poolCount;
            THIS._poolsInUseCount = 0;            
        }
        else
        {
            THIS._controlArray = &controlArray;
        }
        THIS._driverInitialized = true;
    }

    return ( (uint16_t)retValue );
}


uint16_t initMemoryPool( void * const poolData, 
                         uint32_t const poolBlockSize,
                         uint32_t const poolBlockCount )
{
    uint16_t retValue = MEMORY_POOL_NULL_PTR_ERROR;
    int32_t indexToPlace;
    /* Sanity check incoming data pointer to not be NULL */
    if( NULL != poolData )
    {
        retValue = MEMORY_POOL_DRIVER_NOT_INIT;
        /* Do not initalize a pool if the pool control has not been initialized */
        if ( true == THIS._driverInitialized )
        {
            retValue = MEMORY_POOL_NO_FREE_POOL_LOCATION;
            /* Sanity Check the Pool Count */
            if( 0 < THIS._poolCount )
            {
                /* Enssure that there is an available que slot */
                if( false == THIS._controlArray[ THIS._poolCount - 1 ]->_poolInfo._inUse ) 
                {          
                    (void)memset( poolData, 0x00, ( poolBlockSize * poolBlockCount ) );    
            
                    for( int32_t i = 0; i < THIS._poolCount; i++ )
                    {
                        if( false == THIS._controlArray[i]->_poolInfo._inUse )
                        {
                            retValue = MEMORY_POOL_ERROR_NONE;
                            /* This is the proper place for this new QUEUE*/
                            THIS._controlArray[i]->_poolBlockCount = poolBlockCount;
                            THIS._controlArray[i]->_poolBlockSizeBytes = poolBlockSize;
                            THIS._controlArray[i]->_poolFreeCount = poolBlockCount;
                            THIS._controlArray[i]->_poolInfo._inUse = true;
                            THIS._controlArray[i]->_poolInfo._pData = poolData;
                            THIS._poolsInUseCount++;
                            break;
                        }
                        else
                        {
                            if( THIS._controlArray[i]->_poolBlockSizeBytes < poolBlockSize )
                            {
                                for( int32_t j = ( THIS._poolCount - 2 ); j > i; j++ )
                                {
                                    if( true == THIS._controlArray[j]->_poolInfo._inUse )
                                    {
                                        (void)memcpy( ( void* )THIS._controlArray[j + 1], 
                                                    ( void* )THIS._controlArray[j], 
                                                    sizeof( sMemoryPoolControl_t ) );
                                    }
                                    
                                }
                                retValue = MEMORY_POOL_ERROR_NONE;
                                /* This is the proper place for this new QUEUE*/
                                THIS._controlArray[i]->_poolBlockCount = poolBlockCount;
                                THIS._controlArray[i]->_poolBlockSizeBytes = poolBlockSize;
                                THIS._controlArray[i]->_poolFreeCount = poolBlockCount;
                                THIS._controlArray[i]->_poolInfo._inUse = true;
                                THIS._controlArray[i]->_poolInfo._pData = poolData;
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

