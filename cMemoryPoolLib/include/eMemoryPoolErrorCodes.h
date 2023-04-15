/****************************************************************
 * @file eMemoryPoolErrorCodes.h
 * @brief provides error codes for this library.
 * @author Anthony Garza
**************************************************************/
#ifndef E_MEMORY_POOL_ERROR_CODES_H
#define E_MEMORY_POOL_ERROR_CODES_H
#if defined(__cplusplus)
extern "C" { // Access code from C++
#endif /* __cplusplus */
#include "../public include/cMemoryPoolConfig.h"
typedef enum
{
    MEMORY_POOL_ERROR_NONE                       = 0x00,
    MEMORY_POOL_NO_FREE_POOL_LOCATION            = MEMORY_POOL_STARTING_ERROR_CODE,
    MEMORY_POOL_DRIVER_NOT_INIT,
    MEMORY_POOL_NULL_PTR_ERROR,
    MEMORY_POOL_INVALID_BLOCK_SIZE
} eMemoryPoolErrorCodes_t;

#if defined(__cplusplus)
}
#endif 

#endif /* E_MEMORY_POOL_ERROR_CODES_H */