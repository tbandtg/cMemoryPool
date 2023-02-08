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

/** Array of Info structures for the small pool */
static cMemoryPoolInfo_t smallPoolInfo[SMALL_POOL_BLOCK_COUNT];

#if ( USE_STARTING_ADDRESSES == DEF_FALSE )
    /** Statically allocated array for the small pool */
    static uint8_t           smallPoolData[ SMALL_POOL_BLOCK_COUNT * SMALL_POOL_BLOCK_SIZE_BYTES ] = { 0x00 };
#elif( USE_STARTING_ADDRESSES == DEF_TRUE )
    #if( USE_LINKER_FOR_ADDRESSES == DEF_FALSE )
    static uint8_t           __attribute__((address (SMALL_POOL_STARTING_ADDRESS)))smallPoolData[ SMALL_POOL_BLOCK_COUNT * SMALL_POOL_BLOCK_SIZE_BYTES ] = { 0x00 };
    #else
    /* 
        In the linker file the following needs to be defined 
        ExternalSmallPool (w) : ORIGIN = 0xNNNNN, LENGTH = SMALL_POOL_BLOCK_COUNT * SMALL_POOL_BLOCK_SIZE_BYTES    
    */
    static uint8_t           __attribute__((section ("ExternalSmallPool")))smallPoolData[ SMALL_POOL_BLOCK_COUNT * SMALL_POOL_BLOCK_SIZE_BYTES ] = { 0x00 };
    #endif
#endif
/** Array of Info Structures for the medium pool */
static cMemoryPoolInfo_t mediumPoolInfo[MEDIUM_POOL_BLOCK_COUNT];

uint16_t initMemoryPool( void )
{
    
    eMemoryPoolErrorCodes_t retValue = MEMORY_POOL_ERROR_NONE;
    /* Ensure that the Small Pool Info is blank */
    (void)memset( smallPoolInfo, 0, sizeof( cMemoryPoolInfo_t ) * SMALL_POOL_BLOCK_COUNT );

    /* Initialize the data pointers in the small pool array */
    for( int i = 0; i < SMALL_POOL_BLOCK_COUNT; i++ )
    {
        smallPoolInfo->_pData = (void*)&smallPoolData[ i * SMALL_POOL_BLOCK_SIZE_BYTES ];
    }

    return ( (uint16_t)retValue );
}