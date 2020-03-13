#include<stdio.h>
#include<stdlib.h>

typedef struct list
	{
		int a;
		char *b;
	}List;

int main()
{
	FILE *f=fopen("tmp.txt","wb");
	List ls;
	ls.a=9;
	ls.b=(char*) malloc(sizeof(char)*6);
	ls.b="INDRA";

	char* ls1 = "INDRA";
	fwrite((char*)&(ls.b),1,sizeof(List),f);
	fclose(f);
	return 0;
}
