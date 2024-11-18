/****************************************************************
 * @file commonMacros.h
 * @brief provides macros used by the project.
 * @author Anthony Garza
**************************************************************/
#ifndef COMMON_MACROS_H
#define COMMON_MACROS_H
#include <stdint.h>
#include <stdbool.h>
#ifndef TRUE
/**
 * Ensure that TRUE is defined as true
*/
#define TRUE                                                               true
#endif

#ifndef FALSE  
/**
 * Ensure that FALSE is defined as false*/     
#define FALSE                                                             false
#endif

#ifndef DEF_TRUE
    #define DEF_TRUE                                                       0x01
#endif

#ifndef DEF_FALSE
    #define DEF_FALSE                                                      0x00
#endif

/**
 * \brief macro to give an array length.
*/
#ifndef ARRAY_LENGTH
#define ARRAY_LENGTH(X)                                  (sizeof(X)/sizeof((X)[0]))
#endif

#endif  // COMMON_MACROS_H