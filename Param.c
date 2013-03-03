/************************************************************************/
/*
 * Param.c
 * main函数参数处理  
 *
*/
/************************************************************************/
#include "Param.h"
#include "string.h"
#include "FileUt.h"
#include "CommonHeader.h"

/************************************************************************/
/*
取参数
SParamInfo用于取main传递过来的参数

*/
/************************************************************************/
const char DEF_JAD_PARAM[] = "jad.exe -o -8 -r -ff -noctor -s .java ";
static char strJadParam[PARAM_LEN];

void extractExtraParam( int *pArgc, char* argv[] )
{

}

int getParamInfo( SParamInfo *sParamInfo, int argc, char *argv[] )
{
	getFileConfig( sParamInfo );

	if( 1 == argc )
		return sParamInfo->iRet = 0;

	if( argc > 2 )
	{//这里有两种情况　
		//一种是使用jad.exe对字节码文件反编译　
		//另一种是对文件夹中的字节码文件进行反编译
		strcpy( sParamInfo->strJadParam, "jad.exe " );
		int j = 1;
		for( ; j < argc; j++ )
		{
			if( j + 1 == argc )
			{
				if( !strcmp( argv[j], ".class" ) || !strcmp( argv[j], ".CLASS" ) )
				{
					strcat( sParamInfo->strJadParam, argv[j] );	
					strcat( sParamInfo->strJadParam, " " );
					return sParamInfo->iRet = 3;
				}

			}
			else
			{
				strcat( sParamInfo->strJadParam, argv[j] );	
				strcat( sParamInfo->strJadParam, " " );
			}
		}

		//对字节码文件夹进行反编译
		sParamInfo->iFilePos = argc - 1;
		return sParamInfo->iRet = 4;

	}

	//for( int i = 1; i < argc; i++ )
	//{
	if( !strcmp( argv[1], "-h" ) || !strcmp( argv[1], "-H" ) ||
		!strcmp( argv[1], "/h" ) || !strcmp( argv[1], "/H" ) )
	{
		return sParamInfo->iRet = 0;
	}
	else if( strstr( argv[1], ".class" ) || strstr( argv[1], ".CLASS" ) )
	{//使用软件默认的参数反编译类文件

		strcpy( sParamInfo->strJadParam, strJadParam );

		strcat( sParamInfo->strJadParam, argv[1] );

		return sParamInfo->iRet = 1;
	}
	//}

	if( 1 != sParamInfo->iRet && 0 != sParamInfo->iRet )
	{//使用软件默认的参数反编译文件夹中的类文件

		strcat( sParamInfo->strJadParam, strJadParam );

		return sParamInfo->iRet = 2;
	}
	else
	{
		return sParamInfo->iRet = 0;
	}

}

void showHelp()
{
	puts( "Usage:" );
	puts( "DeCompileCls 帮助文档" );
	puts( "DecompileCls.exe Directory 使用默认参数反编译Directory内的所有class文件" );
	puts( "DecompileCls.exe DeCompileCls classfilename 使用默认参数反编译指定的class文件" );
	puts( "示例:" );
	puts( "DecompileCls.exe C:/Java" );
	puts( "对C:/Java文件夹中的所有.class文件进行反编译" );
	puts( "DecompileCls.exe C:/Java/HelloWorld.exe" );
	puts( "对C:/Java/HelloWorld.exe进行反编译" );
	puts( "DecompileCls.exe -o -8 -r C:/Java" );
	puts( "使用用户自定义参数对C:/Java文件夹内的.class文件进行反编译" );
	puts( "DecompileCls.exe -o -8 -r C:/Java/HelloWorld.class" );
	puts( "使用用户自定义的参数对C:/Java/HelloWorld.class文件进行反编译" );
	puts( "以上自定义参数参照jad.exe" );
	puts( "其它参数可参看jad.exe的帮助文档" );
	puts( "注本程序依赖于jad.exe" );
	puts( "用户也可以把参数写到一个名为config.conf的文件里以做避免重复输入参数" );
	puts( "Author:fzq" );
}

bool checkParam( int argc, char *argv[] )
{
	char path[MAX_PATH];

	path[0] = '\0';

	getcwd( path, MAX_PATH );

	strcat( path, "\\jad.exe" );

	if( !existFile( path ) )
	{
		puts( "执行程序目录下无jad.exe，请先复制一份到可执行程序的目录下!" );

		return false;	
	}

	return true;
}

bool getFileConfig( SParamInfo *pSParamInfo )
{
	memset( strJadParam, 0, PARAM_LEN );

	if( existFile( "config.conf" ) )
	{
		FILE *pFile = fopen( "config.conf", "r" );

		char strConf[PARAM_LEN];

		if( pFile )
		{
// 			fseek( pFile, 0, SEEK_END );
// 			long lLen = ftell( pFile );

		// 	rewind( pFile );
			fgets( strConf, PARAM_LEN, pFile );

			fclose( pFile );

			strcpy( strJadParam, "jad.exe " );
			strcat( strJadParam, strConf );

		}
		else
		{
			strcpy( strJadParam, DEF_JAD_PARAM );
		}

		return true;

	}
	else
	{
		strcpy( strJadParam, DEF_JAD_PARAM );
	}

	return false;
}