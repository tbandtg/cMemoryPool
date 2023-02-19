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

typedef enum
{
    MEMORY_POOL_ERROR_NONE                       = 0x00,
    MEMORY_POOL_NULL_PTR_ERROR
} eMemoryPoolErrorCodes_t;

#if defined(__cplusplus)
}
#endif

#endif /* E_MEMORY_POOL_ERROR_CODES_H */