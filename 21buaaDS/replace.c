#include<stdio.h>
#include<ctype.h>
#define LEN 100
int main()
{
	char in[LEN],out[LEN],buf[LEN],inL[LEN];
	scanf("%s %s",in,out);
	int lIn;
	for(lIn=0;inL[lIn]=tolower(in[lIn]);lIn++);
	FILE * filein=fopen("filein.txt","r");
	freopen("fileout.txt","w",stdout);
	char tmp,tmpL;
	int new=0,raw=0;
	while((tmp=fgetc(filein))!=EOF)
	{
		if(inL[raw]==0)
		{
			printf(out);
			raw=new=0;
		}
		tmpL=tolower(tmp);
		if(inL[raw++]==tmpL)
			buf[new++]=tmp;
		else
		{
			buf[new]=0;
			printf(buf);
			raw=new=0;
		}
	}
	buf[new]=0;
	printf(inL[raw]?buf:out);
	fclose(filein);
	fclose(stdout);
	return 0;
}