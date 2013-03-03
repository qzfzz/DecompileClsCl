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
#define MAX_THREAD 512


#define FZQ_DEBUG

pthread_mutex_t mut;

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

int iThreadCount = 0;

void decompileThread( char *pCmd )
{
	//pthread_mutex_lock( &mut );
	system( pCmd );
	//pthread_mutex_unlock( &mut );
	free( pCmd );
	pthread_exit( NULL );
}

int main( int argc, char *argv[] )
{	
	time_t lStartTime, lStopTime;
	time( &lStartTime );
	
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
	else if( 2 == sParamInfo.iRet || 4 == sParamInfo.iRet )
	{
		
		long lLen = 0;
		
		sFileInfo *pFileList = NULL;
		
		if( 2 == sParamInfo.iRet )
		{
			pFileList = getDirFileList( argv[1], ".class", &lLen );
		}
		else
		{
			pFileList = getDirFileList( argv[ sParamInfo.iFilePos ], ".class", &lLen );
		}
		
		if( !pFileList )
			return -1;
			
		char *path = NULL;
		
		//pthread_mutex_init( &mut, NULL );
		pthread_t *pThreadList = (pthread_t*)calloc( sizeof( pthread_t ), lLen );
		long l = 0;
		int iThreadRet = 0;
		
		for( ; l < lLen; l++ )
		{
			path = (char*)calloc( sizeof( char ), MAX_PATH );
			
			if( !path )
				return -1;
				
			strcpy( path, sParamInfo.strJadParam );
			strcat( path, " " );
			strcat( path, (pFileList + l)->name );
			//system( path );
			
			iThreadRet = pthread_create( pThreadList + l, NULL, (void*)decompileThread, path );
			
			if( iThreadRet )
			{
				puts( "Create Thread Err!\n" );
				
				return -1;
			}
			//if( pid.p )
			//	pthread_join( pid, NULL );
			
			if( l != 0 && l % MAX_THREAD ==  0 )
			{
				int i = l - MAX_THREAD;
				//int iCount = l;
				for( ; i < l; i++ )
				{
					if( ( pThreadList + l )->p )
					{
						pthread_join( *( pThreadList + i ), NULL );
					}
				}
			}
		}
		
		for( l = lLen - lLen % MAX_THREAD; l < lLen && l > 0 ; l++ )
		{
			if( ( pThreadList + l )->p )
			{
				pthread_join( *( pThreadList + l ), NULL );
			}
		}
		
		if( lLen < MAX_THREAD )
		{
			for( l = 0; l < lLen; l++ )
				pthread_join( *( pThreadList + l ), NULL );
		}
		
		
		free( pFileList );
		
		time( &lStopTime );
		
		printf( "Cost Time:\t = %ld", lStopTime - lStartTime );
	}
	else if( 1 == sParamInfo.iRet )
	{
		system( sParamInfo.strJadParam );
	}
	else if( 3 == sParamInfo.iRet )
	{
		system( sParamInfo.strJadParam );
	}

	puts( "反编译结束!" );

	return 0;
}