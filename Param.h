/************************************************************************/
/* 
 * Param.h
 * main参数处理                                                                     */
/************************************************************************/
#ifndef PARAM_H
#define PARAM_H
#include "CommonHeader.h"
#define PARAM_LEN 256
typedef struct _sParamInfo
{
	//返回参数
	int iRet;
	int iFilePos;
	char **argv;
	char strJadParam[PARAM_LEN];
	int iThreadCount;
}SParamInfo;

int getParamInfo( SParamInfo* sParamInfo, int agc, char *argv[] );
void showHelp();

bool checkParam( int argc, char *argv[] );
bool getFileConfig( SParamInfo *pSParamInfo );
void extractExtraParam( int *pArgc, char* argv[] );


#endif
