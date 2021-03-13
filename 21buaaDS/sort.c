#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	name[24];
	phone[16];
}item;
int main()
{
	int n;
	int part,len;
	int l,m,r;
	int i,j,k;
	scanf("%d",&n);
	item ** buf=malloc(n*sizeof(item*)),
	** out=malloc(n*sizeof(item*));
	for(int i=0;i<n;i++)
	{
		buf[i]=malloc(sizeof(item));
		scanf(" %s %s",buf[i]->name,buf[i]->phone);
	}
	for(part=1;part<n;part=len)
	{
		len=part<<1;
		for(l=0;(m=l+part)<n;l=r)
		{
			r=l+len;
			r=r<n?r:n;
			i=l;
			j=m;
			k=l;
			while(i<m&&j<r)
				out[k++]=strcmp(buf[i]->name,buf[j]->name)<0?buf[i++]:buf[j++];
			while(i<m)
				out[k++]=buf[i++];
			while(j<r)
				out[k++]=buf[j++];
		}
		item **swap=buf;
		buf=out;
		out=swap;
	}
	k=0;
	out[0]=buf[0];
	for(i=1;i<n;i++)
	{
		if(strcmp(buf[i]->name,out[k]->name))
		{
			printf("%s %s\n",out[0]->name,out[0]->phone);
			free(out[0]);
			for(j=1;j<=k;j++)
			{
				printf("%s_%d %s\n",out[j]->name,j,out[j]->phone);
				free(out[j]);
			}
			k=0;
			out[0]=buf[i];
		}
		else
		{
			for(j=0;j<=k;j++)
				if(!strcmp(buf[i]->phone,out[j]->phone))
				{
					free(buf[i]);
					goto brkctn;
				}
			out[++k]=buf[i];
			brkctn:;
		}
	}
	printf("%s %s\n",out[0]->name,out[0]->phone);
	free(out[0]);
	for(j=1;j<=k;j++)
	{
		printf("%s_%d %s\n",out[j]->name,j,out[j]->phone);
		free(out[j]);
	}
	free(buf);
	free(out);
	return 0;
}