/** **************************************
 *  @file cSmallPool.c
 *  @brief implementation of the small memory pool
 *  @author Anthony Garza
*******************************************/

#if defined(__cplusplus)
extern "C" { // Access code from C++
#endif /* __cplusplus */
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "cMemoryPool.h"
#include "cMemoryPoolPrivate.h"
#include "cSmallPool.h"
#include "eMemoryPoolErrorCodes.h"

/** Structure for Controlling the Small Pool*/
static sMemoryPoolControl_t _pSmallPoolControl = 
{
    ._poolBlockCount     = 0U,
    ._poolBlockSizeBytes = 0U,
    ._poolFreeCount      = 0U,
    ._pPoolData          = NULL,
    ._pPoolInfo          = NULL,
};

static sMemoryPoolControl_t * const THIS = &_pSmallPoolControl;

/**
 * @brief Initialization of the small memory pool, note a zero size pool is acceptable. 
 * 
 * @param pSmallPoolData 
 * @param smallPoolBlockSize 
 * @param smallPoolBlockCount 
 * @param pSmallPoolInfo 
 * @return uint16_t error code 
 */
uint16_t smallPoolInit( uint8_t * const pSmallPoolData, 
                        uint32_t const smallPoolBlockSize, 
                        uint32_t const smallPoolBlockCount, 
                        sMemoryPoolInfo_t * const pSmallPoolInfo )
{
    uint16_t retValue = MEMORY_POOL_ERROR_NONE;
    /* A Zero Size pool is acceptable */
    if( ( 0 < smallPoolBlockCount ) && ( 0 < smallPoolBlockSize ) )
    {
        /* Sanity Check incoming pointers cant have a pool without data or info */
        if( ( NULL == pSmallPoolData ) || 
            ( NULL == pSmallPoolInfo ) ) 
        {
            retValue = MEMORY_POOL_NULL_PTR_ERROR;
        }
        else
        {
            if( ( 0 < smallPoolBlockCount ) && 
                ( 0 < smallPoolBlockSize ) )
            {
                /* Ensure that the Small Pool Info is blank */
                (void)memset( pSmallPoolInfo, 0, sizeof( sMemoryPoolInfo_t ) * smallPoolBlockCount );

                /* Ensure that the pool itself is intialized to zero */
                (void)memset( pSmallPoolData, 0, ( smallPoolBlockCount * smallPoolBlockSize ) );

                /* Initialize the data pointers in the small pool array */
                for( int i = 0; i < smallPoolBlockCount; i++ )
                {
                    pSmallPoolInfo->_pData = &pSmallPoolData[ i * smallPoolBlockSize ];
                }
                /* Assign the Local Structure */
                THIS->_poolBlockCount = smallPoolBlockCount;
                THIS->_poolBlockSizeBytes = smallPoolBlockSize;
                THIS->_poolFreeCount = THIS->_poolBlockCount;
                THIS->_pPoolData = pSmallPoolData;
                THIS->_pPoolInfo = pSmallPoolInfo;
            }
        }
    }

    return( retValue );
}

/**
 * @brief Get the Small Block Count object
 * 
 * @return uint32_t 
 */
uint32_t getSmallBlockCount( void )
{
    return ( THIS->_poolBlockCount );
}

#if defined(__cplusplus)
}
#endif
