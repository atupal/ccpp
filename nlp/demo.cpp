#include <stdlib.h>
using namespace std;


#include "ICTCLAS50.h"
#include <stdio.h>
#include <string.h>
bool ICTCLAS_Init(const char* pszInitDir);
int main(int argc, char* argv[])
{
    char* sResult;
	if(!ICTCLAS_Init())
	{
		printf("Init fails\n");
        	return -1;
	}
	else
	{
		printf("ok\n");
	}
	const char *sParagraph ="今天参加比赛的选手有六百名";
	int nPaLen=strlen(sParagraph);
	char* sRst=0;
	int nRstLen=0;
	sRst=(char *)malloc(nPaLen*6);
	nRstLen=ICTCLAS_ParagraphProcess(sParagraph,nPaLen,sRst ,CODE_TYPE_GB,1);
	printf("%s\n",sRst);
	free(sRst);
	ICTCLAS_Exit();
	system("pause");
	return 0;
}
