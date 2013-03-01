/**
 * StringUt.h
 * 字符串工具函数头文件
 */ 
#ifndef STRINGUT_H
#define STRINGUT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>


#include "CommonHeader.h"


char* trim( char *pStrSrc );


bool endWith( const char* pStrSrc, const char* pStrMatch );
bool startWith( const char* pStrSrc, const char* pStrMatch );
int strIndexOf( const char* pStrSrc, const char* pStrMatch );
int strLastIndexOf( const char* pStrSrc, const char* pStrMatch );

#endif