#include<bits/stdc++.h>

using namespace std;


int calculate_cost(int** arr,int row,int col)
{
	//TODO
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<arr[i][j]<<"\t";
		}
		cout<<endl;
	}
	return 0;
}

int minimumpossiblecost(char* input1)
{
	//Write code here
	int row,col;
	row=col=0;
	char* str=new char[strlen(input1)];
	memcpy(str,input1,strlen(input1));
	for(int i=0;i<strlen(str);i++){
		if(row==0 && str[i]=='@')
			col++;
		if(str[i]=='#')
			row++;
	}
	row+=1;
	col+=1;
	int** st=new int*[row];
	for(int i=0;i<row;i++)
		st[i]=new int[col];
	int p=0,q=0,i=0;
	while(str[i]!='\0'){
		if(str[i]=='#'){
			i++;
			p++;
			q=0;
		}
	l1:	if(str[i]=='-'){
			i++;
			int num=0;
			while(str[i]!='\0' && isdigit(str[i])){
				num=num*10+(str[i]-'0');
				i++;
			}
			st[p][q++]=num*(-1);
		}
		else if(isdigit(str[i])){
			goto l2;
		//	st[p][q]*=(-1);
		}
		if(str[i]=='@'){
			i++;
			if(str[i]=='-')
				goto l1;
			else{
		l2:		int num=0;
			while(str[i]!='\0' && isdigit(str[i])){
				num=num*10+(str[i]-'0');
				i++;
			}
			st[p][q++]=num;
			}
		}
	}
	int cost = calculate_cost(st,row,col);
	return cost;
}

int main()
{
	int iter,Num;
	ifstream fin;
	fin.open("cost.in");
	fin>>Num;
	for(iter=0;iter<Num;iter++){
		char* str=new char[1000];
		fin>>str;
		int cost=minimumpossiblecost(str);
		cout<<"CASE #"<<iter+1<<": "<<cost<<endl;
	}
	return 0;
}