#include<bits/stdc++.h>
#include<string.h>

using namespace std;
char* fun()
{
	char *a=(char*)malloc(10);
	strcpy(a,"Hallo");
	return a;

}

int main()
{
	char* f=fun();//(char*)malloc(10);
//	f=fun();
	cout<<f<<"\n";
	return 0;
}
