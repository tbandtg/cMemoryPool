/** **************************************
 *  @file cSmallPool.h
 *  @brief Definition of the small memory pool
 *  @author Anthony Garza
*******************************************/
#ifndef C_SMALLPOOL_H
#define C_SMALLPOOL_H

#if defined(__cplusplus)
extern "C" { // Access code from C++
#endif /* __cplusplus */

#include <stdint.h>
#include "cMemoryPoolPrivate.h"

/* Small Pool Init */
extern uint16_t smallPoolInit( uint8_t * const pSmallPoolData, 
                               uint32_t const smallPoolBlockSize, 
                               uint32_t const smallPoolBlockCount, 
                               sMemoryPoolInfo_t * const pSmallPoolInfo );

extern uint32_t getSmallBlockCount( void );

#if defined(__cplusplus)
}
#endif

#endif

