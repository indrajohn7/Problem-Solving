#include<bits/stdc++.h>

using namespace std;
#define MAX 1000
#define PTRLEN 100


int diff(char* user,char* ptr)
{
	int count=0;
	for(int i=0;i<strlen(ptr);i++){
		if(user[i]!=ptr[i])
			count++;
	}
	return count;
}

void change_diff(char* user,char* ptr, int pos)
{
	for(int i=pos,j=0;i<(pos+strlen(ptr));i++,j++){
		user[i]=ptr[j];
	}
}

int change_palin(char* user,int pos)
{
	int count=0;
	for(int i=strlen(user)/2;i<strlen(user);i++){
		if(user[strlen(user)-i-1]!=user[i]){
			count++;
			if(pos>=strlen(user)/2)
				user[strlen(user)-i-1]=user[i];
			else
				user[i]=user[strlen(user)-i-1];
		}
	}
	return count;
}

int main()
{
	int Num_Test;
	ifstream fin;
	freopen("linked.in","r",stdin);
	cin>>Num_Test;
	for(int iter=0;iter<Num_Test;iter++){
	char* user=new char[MAX];
	char* ptr=new char[PTRLEN];
	memset(user,'\0',MAX);
	memset(ptr,'\0',PTRLEN);
//	fin>>user>>ptr;
	
	cin>>user;
	cout<<"USER INPUT STRING:"<<user<<endl;
	cin>>ptr;
	cout<<"DYNAMIC STRING:"<<ptr<<endl;
	if(strlen(user)<2*strlen(ptr))
		cout<<"	STRING IS: "<<user<<endl<<"	MIN CHANGE: "<<"INVALID CASE"<<endl;
	
	else{
		int min=9999,pos=0;
		for(int i=0;i<=(strlen(user)-strlen(ptr));i++){
			char* temp=user;
			if(i<(strlen(user)/2) && (i+strlen(ptr)>(strlen(user)/2)))
				continue;
			if(!strncmp(&temp[i],ptr,strlen(ptr))){
				min=0;
				pos=i;
				break;
			}	
			int max_diff=diff(&temp[i],ptr);
			if(min>max_diff){
				pos=i;
				min=max_diff;
			}
		}
		change_diff(user,ptr,pos);
		min+=change_palin(user,pos);
		cout<<"CASE #"<<iter+1<<":\n";
		cout<<"	STRING IS: "<<user<<endl<<"	MIN CHANGE: "<<min<<endl;
	}
	}
	return 0;
}