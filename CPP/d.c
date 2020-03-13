#include<stdio.h>
#include<stdlib.h>

void priint(int);

int main()
{
	priint(5);
	
	return 0;
}

void priint(int i)
{
	if(i>10)
		return;

	return priint(i++);

	printf("%d",i);
}
