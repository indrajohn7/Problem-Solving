#include<bits/stdc++.h>
#define SIZE 12345
using namespace std;

int main()
{
	int iter,NUM;
	freopen(stdin,"palin.in","r");
	cin>>NUM;
	for(iter=0;iter<NUM;iter++){
		char* str=new char[SIZE];
		memset(str,'\0',SIZE);
		cin>>str;
		bool flag=true;
		for(int i=0;i<strlen(str)/2;i++){
			if(str[i]==str[strlen(str)-i-1] || str[i]=='.' || str[strlen(str)-1-i]=='.'){
				if(str[i]==str[strlen(str)-1-i] && str[i]=='.')
					str[i]=str[strlen(str)-1-i]='a';
				else if(str[i]=='.')
					str[i]=str[strlen(str)-1-i];
				else if(str[strlen(str)-1-i]=='.')
					str[strlen(str)-1-i]=str[i];
			}
			else{
				flag=false;
				break;
			}
		}
		if(strlen(str)%2==1 && str[strlen(str)/2]=='.')
			str[strlen(str)/2]='a';
		if(!flag)
			cout<<-1<<endl;
		else
			cout<<str;
	}
	return 0;
}