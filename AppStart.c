/************************************************************************/
/* 
 * AppStart.c
 * 程序启动         
 *                                                           
 */
/************************************************************************/
#include "AppStart.h"
#include "Debug.h"
#include "FileUt.h"

#define FZQ_DEBUG

void cbExit( void )
{
	//puts( "do something cleaning work...\n" );
}


SParamInfo sParamInfo;

void initParm()
{
	memset( &sParamInfo, 0, sizeof( SParamInfo ) );

	sParamInfo.iRet = -1;

	sParamInfo.iFilePos = -1;

}

int main( int argc, char *argv[] )
{
	puts( "Starting Application ...\n" );

	if( !checkParam( argc, argv ))
		return -1;

	atexit( cbExit );

	initParm();

	getParamInfo( &sParamInfo, argc, argv );

	if( !sParamInfo.iRet )
	{
		showHelp();
		return -1;
	}
	else if( 2 == sParamInfo.iRet )
	{
		
		long lLen = 0;
		
		sFileInfo *pFileList = getDirFileList( argv[1], ".class", &lLen );
		
		char path[MAX_PATH];
		
		long l = 0;
		for( ; l < lLen; l++ )
		{
			strcpy( path, sParamInfo.strJadParam );
			strcat( path, " " );
			strcat( path, (pFileList + l)->name );
			system( path );
		}
		
		free( pFileList );
	}
	else if( 1 == sParamInfo.iRet )
	{
		system( sParamInfo.strJadParam );
	}
	else if( 3 == sParamInfo.iRet )
	{
		system( sParamInfo.strJadParam );
	}
	else if( 4 == sParamInfo.iRet )
	{
		long lLen = 0;
		
		sFileInfo *pFileList = getDirFileList( argv[ sParamInfo.iFilePos ], ".class", &lLen );
		
		char path[MAX_PATH];
		long l = 0;
		
		for( ; l < lLen; l++ )
		{
			strcpy( path, sParamInfo.strJadParam );
			strcat( path, " " );
			strcat( path, (pFileList + l)->name );
			system( path );
		}
		
		free( pFileList );
	}

	puts( "反编译结束!" );

	return 0;
}