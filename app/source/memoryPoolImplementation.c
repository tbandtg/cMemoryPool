/*****************************************************************
 * @file:  memoryPoolImplementation.c
 * @brief Implements the memory Pool Library.
 * @author Anthony Garza
 * @copyright Copyright 2023 All Rights Reserved.
****************************************************************/
#include "memoryPoolImplementation.h"
#include "cMemoryPool.h"

#include <stdint.h>
#include <stdio.h>

/**
 * /brief Test harness for the memory pool implementation.
*/
uint16_t testMemoryPool( void )
{
    uint16_t retValue = initMemoryPools( NULL, 0 );
    if( 0u  == retValue  )
    {
        printf("Initialize successfull");
    }
    else
    {
        printf("Initialization failee!");
    }
}
