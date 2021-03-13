#include<stdio.h>
#define BOARD(x) (board[x.r][x.c])
#define ACCPACE {acc.r+=pace[i].r;acc.c+=pace[i].c;}
typedef char ord;
typedef struct
{
	ord r,c;
}dot;
typedef dot vec;
ord board[19][20];
vec pace[4]={{1,-1},{1,0},{1,1},{0,1}};
int main()
{
	for(int i=0;i<19;i++)
		for(int j=0;j<19;j++)
			scanf(" %c",&board[i][j]);
	dot ergo={0,0},acc;
	for(ergo.r=0;ergo.r<16;ergo.r++)
		for(ergo.c=0;ergo.c<16;ergo.c++)
			if(BOARD(ergo)!='0')
			{
				for(int i=0;i<4;i++)
				{
					acc.r=ergo.r;
					acc.c=ergo.c;
					BOARD(ergo);
					for(int j=1;j<4;j++)
					{
						ACCPACE;
						if(BOARD(ergo)!=BOARD(acc))
							goto brkctn;
					}
					ACCPACE;
					if(acc.r>=19||BOARD(acc)!='0')
					{
						acc.r=ergo.r-pace[i].r;
						acc.c=ergo.c-pace[i].c;
						if(acc.r<0||acc.c<0||BOARD(acc)!='0')
							goto brkctn;
					}
					printf("%c:%d,%d\n",BOARD(ergo),ergo.r+1,ergo.c+1);
					goto mainret;
					brkctn:;
				}
			}
	printf("No");
	mainret:
		return 0;
}