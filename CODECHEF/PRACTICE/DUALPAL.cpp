#include<bits/stdc++.h>

using namespace std;
#define NUM pow(2,10)

const char lookup[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

void calculate(char* str,int num,int b)
{
	int max_p,temp;
	for(int i=0;i<100;i++){
		int t= pow(b,i);
		if((num/t)==0){
			max_p=i-1;
			break;
		}
	}
	temp=max_p;
	for(int i=0;i<=max_p;i++){
		int t=(pow(b,temp));
		int quotient=num/t;
		str[i]=lookup[quotient];
		num=num-quotient*t;
		temp--;
	}
}


bool is_palindrome(char* str1,char*str2)
{
	int j=0;
	for(int i=0;i<strlen(str1);i++){
		str2[strlen(str1)-1-i]=str1[i];
	}
	str2[strlen(str1)]='\0';
	if(!strncmp(str1,str2,strlen(str1)))
		return true;
	else
		return false;
}


int main()
{
	int iter,Num_Test;
	freopen("dual.in","r",stdin);
	cin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int B1,B2,i,j,k;
		i=NUM;
		cin>>B1>>B2;
		cout<<"CASE #"<<iter+1<<": ";
		if((B1<B2) && (B1>=2) && (B2<=16)){
			for(i=3;i<NUM;i++){
				char* str1=new char[100];
				char* str2=new char[100];
				calculate(str1,i,B1);
				calculate(str2,i,B2);
				char* rev1=new char[strlen(str1)];
				char* rev2=new char[strlen(str2)];
				if(is_palindrome(str1,rev1) && is_palindrome(str2,rev2))
					cout<<i<<"\t";
			}
			cout<<"\n";
		}
	}
	return 0;
}