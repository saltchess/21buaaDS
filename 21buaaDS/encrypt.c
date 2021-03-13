#include<stdio.h>
#include<ctype.h>
#define ltoi(x) ((x)-'a')
int main()
{
	FILE * encrypt=fopen("encrypt.txt","r");
	freopen("output.txt","w",stdout);
	char appeared[26]={0},code[26],buf[55];
	scanf("%s",buf);
	int acc=0;
	for(int i=0;buf[i];i++)
	{
		if(!appeared[ltoi(buf[i])])
		{
			code[acc++]=buf[i];
			appeared[ltoi(buf[i])]=1;
		}
	}
	for(char i='z';i>='a';i--)
	{
		if(!appeared[ltoi(i)])
			code[acc++]=i;
	}
	char tmp;
	while((tmp=fgetc(encrypt))!=EOF)
		putchar(islower(tmp)?code[ltoi(tmp)]:tmp);
	fclose(encrypt);
	fclose(stdout);
	return 0;
}