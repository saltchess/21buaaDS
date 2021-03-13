#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char name[52],
	author[22],
	press[32],
	date[12];
}book;
typedef struct __item{
	book * book;
	struct __item * next;
}item;
FILE * output;
char * outFormat="%.50s%.20s%.30s%.10s\n";
item * buildLib(FILE*);
book * fscanBook(FILE*);
void fprintBook(FILE*,book*);
void delBook(item*,item*);
// Delete an item, in fact
void insBook(item*,book*);
void findBook(item*,char*,int);
void ruinLib(item*);
int main()
{
	item * library=buildLib(fopen("books.txt","r"));
	int operation;
	char key[55];
	while(1)
	{
		scanf("%d ",&operation);
		switch(operation)
		{
			case 0:
				ruinLib(library);
				return 0;
			case 1:
				insBook(library,fscanBook(stdin));
				break;
			default:
				scanf(" %s",key);
				findBook(library,key,operation);
		}
	}
}
item * buildLib(FILE * input)
{
	item * ret=calloc(1,sizeof(item));
	for(book * i;i=fscanBook(input);insBook(ret,i));
	fclose(input);
	output=stdout;
	return ret;
}
book * fscanBook(FILE * src)
{
	book * ret=malloc(sizeof(book));
	if(fscanf(src," %s %s %s %s",ret->name,ret->author,ret->press,ret->date)!=EOF)
		return ret;
	free(ret);
	return NULL;
}
void fprintBook(FILE * dst,book * ware)
{
	fprintf(dst,outFormat,ware->name,ware->author,ware->press,ware->date);
	return;
}
void delBook(item * former,item * target)
{
	former->next=target->next;
	free(target->book);
	free(target);
	return;
}
void insBook(item * lib,book * src)
{
	item * former=lib, * acc=lib->next;
	for(;acc&&strcmp(src->name,acc->book->name)<0;acc=acc->next,former=former->next);
	former->next=malloc(sizeof(item));
	former->next->book=src;
	former->next->next=acc;
	return;
}
void findBook(item * lib,char * key,int operation)
{
	item * former=lib, * acc=lib->next;
	for(;acc;acc=acc->next,former=former->next)
		if(strstr(acc->book->name,key))
			operation==2?fprintBook(output,acc->book):delBook(former,acc);
	return;
}
void ruinLib(item * lib)
{
	output=fopen("ordered.txt","w");
	// have to move out if packaged
	outFormat="%s %s %s %s\n";
	item * tmp;
	goto ruinItem;
	while(lib)
	{
		fprintBook(output,lib->book);
		free(lib->book);
		ruinItem:
			tmp=lib;
			lib=lib->next;
			free(tmp);
	}
	return;
}