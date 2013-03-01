/**
 * StringUt.c
 * 字符串工具函数
 */
#include "StringUt.h"

char* trim( char *pStrSrc )
{
	int iLen = strlen( pStrSrc );
	char *pOriBuf = (char*)malloc( iLen );
	char *pBuf = pOriBuf;
	
	memset((void*)pBuf, 0, iLen );
	
	int i = 0;
	for( ; i < iLen; i++ )
	{
		if( !isspace( *(pStrSrc + i )) )
		{
			*(pBuf++) = *(pStrSrc + i );
		}
	}
	
	memset( pStrSrc, 0, iLen );
	strcpy( pStrSrc, pOriBuf );
	pStrSrc[iLen] = '\0';
	
	free( pOriBuf );

	return pStrSrc;
	
}

bool endWith( const char* pStrSrc, const char* pStrMatch )
{
	if( strstr( pStrSrc, pStrMatch ) )
	{
		char strMatch[MAX_PATH] = {0};
		strcpy( strMatch, pStrMatch );
		strrev( strMatch);
		
		char strSrc[MAX_PATH] = {0};
		strcpy( strSrc, pStrSrc );
		strrev( strSrc );
		
		if( strncmp( strMatch, strSrc, strlen( strMatch )))
		{
			return false;
		}
		
		return true;
	}
	else
	{
		return false;
	}
}

bool startWith( const char* pStrSrc, const char* pStrMatch )
{
	if( strstr( pStrSrc, pStrMatch ) )
	{
		
		if( strncmp( pStrSrc, pStrMatch, strlen( pStrMatch )))
		{
			return false;
		}
		
		return true;
	}
	else
	{
		return false;
	}
}

int strIndexOf( const char* pStrSrc, const char* pStrMatch )
{
	if( !pStrSrc || !pStrMatch )
		return -1;

	if( strlen( pStrSrc ) < strlen( pStrMatch ) )
		return -1;

	const char *pRes = strstr( pStrSrc, pStrMatch );

	if( !pRes )
	{
		return -1;
	}
	
	if( pRes - pStrSrc >= 0 )
	{
		return pRes - pStrSrc;
	}

	return pStrSrc - pRes;

}


int strLastIndexOf( const char* pStrSrc, const char* pStrMatch )
{
	if( !pStrSrc || !pStrMatch )
		return -1;
	
	int iSrc = strlen( pStrSrc );
	int iMatch = strlen( pStrMatch );

	if( iSrc < iMatch )
		return -1;
	
	const char *pRes = strstr( pStrSrc, pStrMatch );
	
	if( !pRes )
	{
		return -1;
	}
	
	char bufSrc[MAX_PATH];
	char bufMatch[MAX_PATH];

	memcpy( bufSrc, pStrSrc, iSrc );
	memcpy( bufMatch, pStrMatch, iMatch );

	bufMatch[iMatch] = '\0';
	bufSrc[iSrc] = '\0';

	strrev( bufSrc );
	strrev( bufMatch );

	pRes = strstr( bufSrc, bufMatch );

	if( pRes - bufSrc >= 0 )
	{
		return iSrc - ( pRes - bufSrc ) - iMatch;
	}
	else
	{
		return iSrc - ( bufSrc - pRes ) - iMatch;
	}
	
}