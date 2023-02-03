/****************************************************************
 * @file: cMemoryPool.h
 *
 * A simple implmentation of a memory pool manager.
****************************************************************/

#ifndef C_MEMORYPOOL_H
#define C_MEMORYPOOL_H
#include <stdint.h>
#include "eMemoryPoolErrorCodes.h"
#include "cMemoryPoolConfig.h"
#if defined(__cplusplus)
extern "C" { // Access code from C++
#endif /* __cplusplus */


/** Init Memory Pools */
extern uint16_t initMemoryPool( void );


#if defined(__cplusplus)
}
#endif

#endif /* End define C_MEMORYPOOL_H*/
