#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum abc {a,b,c} ABC;
ABC l;
//l=c;
int main(int argc,char* argv[])
{
	l=c;
	if(memcmp(argv[1],"IN",sizeof(argv[1]))==0)
		l=a;
	if(l==a)
		printf("GOT IT:\n");
	l="b";
	printf("%d";l+1);
	return 0;

}
