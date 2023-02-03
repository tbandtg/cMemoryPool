#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "eMemoryPoolErrorCodes.h"
#include "cMemoryPoolConfig.h"
#include "cMemoryPool.h"

typedef struct 
{
    /* data */
    void * _pData;
    bool _inUse;
}cMemoryPoolInfo_t;

/** Array of Info Pointers for each pool */
static cMemoryPoolInfo_t smallPoolInfo[SMALL_POOL_BLOCK_COUNT];
static uint8_t smallPoolData[ SMALL_POOL_BLOCK_COUNT * SMALL_POOL_BLOCK_SIZE_BYTES ] ={ 0x00 };

uint16_t initMemoryPool( void )
{
    
    eMemoryPoolErrorCodes_t retValue = ERROR_NONE;
    /* Ensure that the Small Pool Info is blank */
    (void)memset( smallPoolInfo, 0, sizeof( cMemoryPoolInfo_t ) * SMALL_POOL_BLOCK_COUNT );

    /* Initialize the data pointers in the small pool array */
    for( int i = 0; i < SMALL_POOL_BLOCK_COUNT; i++ )
    {
        smallPoolInfo->_pData = (void*)&smallPoolData[ i * SMALL_POOL_BLOCK_SIZE_BYTES ];
    }

    return ( (uint16_t)retValue + MEMORY_POOL_STARTING_ERROR_CODE );
}