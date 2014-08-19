
#ifndef VXWORKS_H
#define VXWORKS_H

#include <iostream>

// misc definitions
typedef int STATUS;
typedef void (*FUNCPTR)(void*);

//stuff to properly export stuff
//see https://gcc.gnu.org/wiki/Visibility
#ifdef WIN32
	//use Win32 dllimport and dllexport
	#ifdef BUILDING_WPIHARNESS_DLL
		#define DLLTRANSPORT __declspec(dllexport)
	#else
		#define DLLTRANSPORT __declspec(dllimport)
	#endif
	#define DLLIMPORT __declspec(dllimport)
	#define DLLPRIVATE
#else
	//use gcc visibility
	#ifdef BUILDING_WPIHARNESS_DLL
		#define DLLTRANSPORT __attribute__ ((visibility ("default")))
	#else
		#define DLLTRANSPORT
	#endif
	#define DLLIMPORT
	#define DLLPRIVATE __attribute__ ((visibility ("hidden")))
#endif
	



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

#elif defined(WIN32) && !defined(_MSC_VER) //MinGW

#define UINT64 uint64_t
#define INT64 int64_t
#define UINT32 uint32_t
#define INT32 int32_t
#define UINT16 uint16_t
#define INT16 int16_t
#define UINT8 uint8_t
#define INT8 int8_t

#else //Visual C++

//you can't define SIZE_T as size_t in MinGW because SIZE_T is used in some MinGW headers 
#define size_t SIZE_T


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
