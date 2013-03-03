/**
 * FileUt.c
 * 文件工具类
 */
#include "FileUt.h"



sFileInfo *pFileList;
static unsigned long iFindRes = 0;
static const int INT_EXT_LEN = sizeof( sFileInfo ) * 1024;

char* checkPath( const char* pPath )
{
	char strPath[MAX_PATH] = {0};
	char *path = NULL;
	
	strcpy( strPath, pPath );
	if( -1 == access( pPath, 0 ) )
	{//不存在
		return NULL;
	}
	
	path = strrev( strPath );
	
	if( ( NULL != strstr( path, "/" ) && 0 == strcmp( path, strstr( path, "/" )) ) || 
		((NULL != strstr( path, "\\" )) && 0 == strcmp( path, strstr( path, "\\" )) ))
	{
		memset( strPath, 0, MAX_PATH );
		strncpy( strPath, pPath, strlen( pPath ) - 1 );
		
		return strPath;
	}
	else
	{
		char str[MAX_PATH] = {0};
		if( NULL != strstr( path, "/" ) )
		{
			strcpy( str, path );
		}
		else if( NULL != strstr( path, "\\" ) )
		{
			strcpy( str, pPath );	
		}
		
		return str;
	}
	
}

static void _find( char * lpPath, const char* pStrExt )
{
	char szFind[MAX_PATH],szFile[MAX_PATH];
	WIN32_FIND_DATA FindFileData;
	strcpy(szFind,lpPath);
	strcat(szFind,"\\*.*");
	
	HANDLE hFind=FindFirstFile(szFind,&FindFileData);
	if(INVALID_HANDLE_VALUE == hFind)
		return;
	
	unsigned long iTest = 0;
	while(TRUE)
	{
		if(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			if(FindFileData.cFileName[0]!='.')
			{
				strcpy(szFile,lpPath);
				strcat(szFile,"\\");
				strcat(szFile,FindFileData.cFileName);
				
				_find( szFile, pStrExt );
			}
		}
		else
		{	

			iTest = ( iFindRes / 1024 + 1 ) * INT_EXT_LEN;
			if( iFindRes * sizeof( sFileInfo ) >= iTest - MAX_PATH )
			{
				pFileList = (sFileInfo*)realloc( pFileList, sizeof( sFileInfo ) * ( ( iFindRes / 1024 ) + 2 ) * 1024 );
			}
			
			if( strstr( FindFileData.cFileName, pStrExt ) && endWith( FindFileData.cFileName, pStrExt ))
			{
				strcpy( (pFileList+iFindRes)->name, lpPath );
				strcat( (pFileList+iFindRes)->name, "\\" );
				strcat( (pFileList+iFindRes)->name, FindFileData.cFileName );
				iFindRes++;
			}
			//printf("%s\n",FindFileData.cFileName);
			
		}
		if(!FindNextFile(hFind,&FindFileData))
		{
			//CloseHandle(hFind);
			break;
		}
		
	}
}


/************************************************************************/
/* 
param:	pPath
ret:	0:true
-1:false
*/
/************************************************************************/
sFileInfo* getDirFileList( char* pPath, const char* pStrExt, long *pRetLen )
{
	if( !pPath || !pStrExt )
	{
		*pRetLen = 0;
		return NULL;
	}
	
	char strPath[MAX_PATH] = {0};
	
	strcpy( strPath, checkPath(pPath) );
	
	if( NULL == strPath )
	{
		puts( "Err\n" );
		*pRetLen = 0;

		return NULL;
	}
	
	pFileList = (sFileInfo*)malloc( sizeof( sFileInfo ) * 1024 );
	
	memset( pFileList, 0, sizeof( sFileInfo ) * 1024 );
	
	if( NULL != strPath )
		_find( strPath, pStrExt );
	
	if( !iFindRes )
	{
		free( pFileList );
		pFileList = NULL;
		*pRetLen = 0;

		return NULL;
	}

	*pRetLen = iFindRes;

	return pFileList;
}



bool existFile( const char* pStrFile )
{
	if( -1 == access( pStrFile, 0 ) )
	{
		return false;
	}

	return true;
}



bool copyDir( const char* pStrSrc, const char* pStrDest )
{

	return false;
}

bool copyFile( const char* pStrSrc, const char* pStrDest )
{
	if( !existFile( pStrSrc ))
		return false;
	
	time_t endTime = 0;
	time_t startTime = time(&startTime);
	
	//声明两个为文件类型
	FILE *pFileSrc = NULL;
	FILE *pFileDest = NULL;
	const long BUF_LEN = 10240000;
	//以读的方式打开文件
	pFileSrc= fopen( pStrSrc, "rb");
	//以读写的方式重新打开一个文件，没有就生成，注意：每次使用都会用空白文件覆盖
	pFileDest = fopen( pStrDest, "wb+");
	//如果打开为NULL说明打开错误
	if ( pFileSrc == NULL || pFileDest == NULL) 
	{
		//输出错误
		perror("file is not open");
		//输出错误代码
		printf("errno:%d",errno);
		//程序退出
		exit(1);
	}
	//移动指针到文件最后
	fseek( pFileSrc, 0, SEEK_END);
	//取得文件长度
	long int len = ftell( pFileSrc );
	//移动指针到文件头
	fseek( pFileSrc, 0, SEEK_SET);
	//定义缓冲区长度，虽然fgets第一个参数是：char *;
	//但是这里需要给这个参数指定长度，所以只能用char buffer[len]来声明，否则会报段错误
	
	
	char *pBuf = (char*)malloc( BUF_LEN );
	//char *pStr = NULL;
	//读取文件按行读取遇到\n停止
	long int lCur = 0;
	while( ( fgets( pBuf, len, pFileSrc ) ) != NULL)
	{
		
		//将读取的每行写入文件中
		fputs( pBuf, pFileDest );
		memset( pBuf, 0, BUF_LEN );
		lCur += BUF_LEN;
		fseek( pFileSrc, lCur, SEEK_SET );
		fseek( pFileDest, lCur, SEEK_SET );
	}
	
	free( pBuf );
	pBuf = NULL;
	
	//关闭打开的文件释放资源
	fclose( pFileSrc );
	fclose( pFileDest );
	
	endTime = time( &endTime );
	
	printf( "CostTime:%ld\n", endTime - startTime );
	
	return 0;
}

bool makeDir( const char* pPath )
{
	int iRet = mkdir( pPath );

	if( !iRet )
	{	
		return true;
	}

	return false;

}

bool delDir( const char* pPath )
{
	return false;
}

bool delFile( const char* pPath )
{
	if( existFile( pPath ) )
	{
		if( !remove( pPath ) )
		{
			return true;
		}

		return false;
	}
	else
	{
		return true;
	}

}

bool renameFile( const char* pStrName, const char* pStrNewName )
{
	if( existFile( pStrName ) )
	{
		if( !rename( pStrName, pStrNewName ))
		{
			return true;
		}

	}

	return false;
	
}

// void main()
// {
// 	char filepath[MAX_PATH]="C:\\";
// 
// 	getDirFileList(filepath, ".dll");
// 
// 	for( long i = 0; i < iFindRes; i++ )
// 	{
// 		puts( (pFileList + i)->name );
// 	}
// 
// 	printf( "%d\n", iFindRes );
// 
// 	free( pFileList );
// }  