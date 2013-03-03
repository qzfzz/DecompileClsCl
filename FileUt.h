/**
 * FileUt.h
 * 文件工具类头文件
*/
#ifndef FILEUT_H
#define FILEUT_H

#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
#include <io.h>
#include <time.h>
#include <direct.h>
#include "StringUt.h"
#include "CommonHeader.h"

typedef struct _fileName 
{
	char name[MAX_PATH];
}sFileInfo;


sFileInfo* getDirFileList( char* pPath, const char* pStrExt, long *pRetLen );
char* checkPath( const char* pPath );

bool existFile( const char* pStrFile );
bool copyFile( const char* pStrSrc, const char* pStrDest );
bool copyDir( const char* pStrSrc, const char* pStrDest );
bool makeDir( const char* pPath );
bool delDir( const char* pPath );
bool delFile( const char* pPath );
bool renameFile( const char* pStrName, const char* pStrNewName );
//static void _find( char * lpPath, const char* pStrExt );

#endif