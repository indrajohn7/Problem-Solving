#include<bits/stdc++.h>

using namespace std;

void convert(int to,int* a,int* b,int R,int C)
{
	if(to <=(C-2)){
		*a=0;
		*b=to;
	}
	else if(to>(C-2) && to<=(R+C-4)){
		*a=to-(C-2);
		*b=C-1;
	}
	else if(to>(R+C-4) && to <=(R+C-4+C-2)){
		*a=R-1;
		*b=(R+2*C-6)-to+1;
	}
	else{
		*a=2*(R+C-4)-to+1;
		*b=0;
	} 
}


void ride(int arr[][1000],int* r,int* c,char c,char d)
{
	char a,b;
	a='\';
	b='/';
	if(arr[*r][*c]=='0'){
		if(c==a) {
			arr[*r][*c]='\';
			if(d=='d'){			
				*r+=1;
			}
			else if(d=='r'){
				*c+=1;
			}
			else if(d=='u'){
				*r-=1;
			}		
		}
		else if(c==b){
			arr[*r][*c]='/';
			if(d=='d'){			
				*r+=1;
			}
			else if(d=='l'){
				*c-=1;
			}
			else if(d=='u'){
				*r-=1;
			}	
		}
	}
	else{
		if(d=='u')
			*r-=1;
		else if(d=='d')
			*r+=1;
		else if(d=='l')
			*c-=1;
		else if(d=='r')
			*c+=1;
	}
}

bool recursive(int arr[][1000],int R,int C,int f_r,int f_c,int t_r,int t_c)
{
	int temp_r,temp_c;
	temp_r=f_r;
	temp_c=f_c;
	bool possible=true;
	if(f_r==t_r && f_c-t_c==1)
		return true;
	else if(f_c==t_c && f_r-t_r==1)
		return true;
	while(temp_r<R && temp_c<C && temp_r!=t_r && temp_c!=t_c && possible){
		if(temp_r==t_r && temp_c==t_c)
			break;
		else{
			if(temp_r<t_r ){
				if(temp_c==t_c){
					ride(arr,&temp_r,&temp_c,'\','d');
				}
				else if(temp_c>t_c)
					ride(arr,&temp_r,&temp_c,'/','d');
				else
					ride(arr,&temp_r,&temp_c,'\','d');
			}else if (temp_r==t_r){
				else if(temp_c>t_c)
					ride(arr,&temp_r,&temp_c,'/','l');
				else
					ride(arr,&temp_r,&temp_c,'\','r');
			}
			else{
				if(temp_c==t_c){
					ride(arr,&temp_r,&temp_c,'/','u');
				}
				else if(temp_c>t_c)
					ride(arr,&temp_r,&temp_c,'\','u');
				else
					ride(arr,&temp_r,&temp_c,'/','u');
			}
		}
	}
	if(temp_r==t_r && temp_c==t_c)
		possible=true;
	else
		possible=false;
	return possible;
}


bool traverse(int arr[][1000],int R,int C,int from,int to)
{
	int from_row,from_col,to_row,to_col;
	convert(from,&from_row,&from_col,R,C);
	convert(to,&to_row,&to_col,R,C);
	if(recursive(arr,R,C,from_row,from_col,to_row,to_col))
		return true;
	else
		return false;
}


int main()
{
	int iter,Num_test;
	ifstream fin;
	fin.open("seville.in");
	fin>>Num_test;
	for(iter=0;iter<Num_test;iter++){
		int R,C,size;
		fin>>R>>C;
		size=2*(R+C);
		char** arr=new char*[R+2];
		for(int i=0;i<(R+2);i++){
			arr[i]=new char[C+2];
			memset(arr[i],'0',C+2);
		}
		int* match=new int[size];
		for(int i=0;i<size;i++)
			fin>>match[i];
		bool possible=true;
		for(int i=0;i<size;i+=2){
			int from,to;
			from=match[i];
			to=match[i+1];
			if(!traverse(arr,R+2,C+2,from,to)){
				possible=false;
				break;
			}
		}
		cout<<"CASE	#"<<iter+1<<":\n";
		if(possible){
			for(int i=1;i<(R+1);i++){
				for(int j=1;j<(C+1);j++)
					cout<<arr[i][j];
				cout<<endl;
			}
		}
		else{
			cout<<"IMPOSSIBLE\n";
		}
	}
	return 0;
}