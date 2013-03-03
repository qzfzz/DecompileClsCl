/************************************************************************/
/* 
 * Debug.h
 * Debug宏                                                                     */
/************************************************************************/
#ifndef DEBUG_H
#define DEBUG_H

#include "CommonHeader.h"

//printf current file current function and current line
#if IDE == VC6
	#define dPrintCurPos() \
		printf( "FileName:%s\nLineNum:%d\n", __FILE__, __LINE__ );
#else
	#define dPrintCurPos() \
		printf( "FileName:%s\nFunctionName:%s\nLineNum:%d\n", __FILE__, __FUNCTION__ ,__LINE__ );
#endif


//printf int
#if IDE == VC6
#define dIPrintf( expr ) printf( "%s = %d\n", #expr, expr )
#else
#define dIPrintf( expr ) printf( "func: %s: %s = %d\n", __FUNCTION__, #expr, expr )
#endif 

//printf float
#if IDE == VC6
#define dFPrintf( expr ) printf( "%s = %f\n", #expr, expr )
#else
#define dFPrintf( expr ) printf( "func: %s: %s = %f\n", __FUNCTION__, #expr, expr )
#endif

//printf char
#if IDE == VC6
#define dCPrintf( expr ) printf( "%s = %c\n",  #expr, expr )
#else
#define dCPrintf( expr ) printf( "func: %s: %s = %c\n", __FUNCTION__, #expr, expr )
#endif

//printf long int
#if IDE == VC6
#define dLPrintf( expr ) printf( "%s = %ld\n", #expr, expr )
#else
#define dLPrintf( expr ) printf( "func: %s: %s = %ld\n", __FUNCTION__, #expr, expr )
#endif

//printf string
#if IDE == VC6
#define dSPrintf( expr ) printf( "%s = %s\n", #expr, expr )
#else
#define dSPrintf( expr ) printf( "func: %s: %s = %s\n", __FUNCTION__, #expr, expr )
#endif


#endif