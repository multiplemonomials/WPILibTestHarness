
#ifndef VXWORKS_H
#define VXWORKS_H

#include <iostream>

// misc definitions
typedef int STATUS;
typedef void (*FUNCPTR)(void*);


// this sucks

#if (!defined(WIN32) || defined( _MSC_VER)) 

//get size_t
#include <cstring>

typedef unsigned long			UINT64;
typedef signed long			INT64;
typedef unsigned int			UINT32;
typedef signed int			INT32;
typedef unsigned short			UINT16;
typedef signed short			INT16;
typedef unsigned char			UINT8;
typedef signed char			INT8;

typedef size_t				SIZE_T;

#endif

typedef int			SEM_ID;

#include <cassert>
#define wpi_assert assert
#define wpi_fatal(x) std::cerr << "WPILib: Fatal Error: " << #x << std::endl

#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <time.h>

#include <algorithm>

#ifndef TRUE
#	define TRUE 1
#endif

#define OK		0


#define bzero(s, n) { memset(s, n, 0); }


#endif
