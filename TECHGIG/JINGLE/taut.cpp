#include<bits/stdc++.h>

using namespace std;

#define AND(a,b) (a=='1'&& b=='1')?'1':'0'
#define OR(a,b)	 (a=='0' && b=='0')?'0':'1'
#define NOT(a)	 (a=='0')?'1':'0'
#define IMPLIES(a,b)	(a=='1' && b=='0')?'0':'1'
#define IFF(a,b)	(a==b)?'1':'0'

void calculate(char c,char sol[],int i,char val,int offset)
{
	if(c=='A'){
		sol[i+offset]=AND(sol[i],val);
	//	stream.pop_front();
	}else if(c=='O'){
		sol[i+offset]=OR(sol[i],val);
	//	stream.pop_front();
	}else if(c=='F'){
		sol[i+offset]=IFF(sol[i],val);
	//	stream.pop_front();
	}else if(c=='I'){
		if(offset=='1')
			sol[i+offset]=IMPLIES(sol[i],val);
		else
			sol[i]=IMPLIES(val,sol[i]);
	//	stream.pop_front();
	}
}

//Pls do the iteration twice with both 0 and 1 value.
char* iteration(char* input1)
{
    //Write code here
	list<char> stream;
    char sol[200];
    int i=0,j=0,T;
	memset(sol,'\0',200);
	memcpy(sol,input1,strlen(input1));
	char val[2]={'0','1'};
	char op1,op2;
	op1=op2='0';
	for(int p=0;p<2;p++){
	i=0;
	while(sol[i]!='\0'){
		if(!(sol[i]=='N' || sol[i]=='O' || sol[i]=='A' || sol[i]=='I' || sol[i]=='F'))
			sol[i]=val[p];
		i++;
	}

	vector<char> v;
	v.clear();
	for( i=0;i<strlen(sol);i++){
		if(sol[i]=='N' || sol[i]=='A' || sol[i]=='O' || sol[i]=='I' ||sol[i]=='F')
			stream.push_front(sol[i]);
		
		else{
			if(stream.front()=='N'){
				(sol[i]=='0')?sol[i]='1':sol[i]='0';
				stream.pop_front();
				if(v.size()){
					calculate(stream.front(),sol,i,v.back(),0);
					stream.pop_front();
					v.pop_back();
					--i; //cautious
				}else{
					v.push_back(sol[i]);
				}
			}else if((sol[i]=='0'||sol[i]=='1') && (sol[i+1]=='0'||sol[i+1]=='1')){
				calculate(stream.front(),sol,i,sol[i+1],1);
				stream.pop_front();
				
			}else if((sol[i]=='0' || sol[i]=='1') && (sol[i+1]!='0'||sol[i+1]!='1')){
				if(sol[i+1]=='\0'){
					calculate(stream.front(),sol,i,v.back(),0);
					stream.pop_front();
					v.pop_back();
				}/*
				else if(v.size()){
					calculate(stream.front(),sol,i,v.back(),0);
					stream.pop_front();
					v.pop_back();
					--i;
				}*/else
					v.push_back(sol[i]);
			}
		}
		if(stream.size()==0)
			break;
	}
	if(stream.front()=='N'){
		(sol[strlen(sol)-1]=='0')?(sol[strlen(sol)-1]='1'):(sol[strlen(sol)-1]='0');
		stream.pop_front();
	}
	//Need to check the invalid cases once
	if(stream.size()!=0 || (sol[strlen(sol)-1]!='0' && sol[strlen(sol)-1]!='1'))
		return "Invalid";
	if(p==0)
		op1=sol[strlen(sol)-1];
	else
		op2=sol[strlen(sol)-1];
	}
	if(stream.size()!=0 || (sol[strlen(sol)-1]!='0' && sol[strlen(sol)-1]!='1'))
		return "Invalid";
	else if(op1=='1' && op2=='1')
		return "Yes";
	else
		return "No";
	
}


int main(int argc,char* argv[])
{
	char* res=new char[10];
    memset(res,'\0',10);
    res=iteration(argv[1]);
    cout<<res<<endl;
    return 0;

}