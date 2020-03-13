#include<stdio.h>
#include<string.h>
#include<bits/stdc++.h>


#define N 100

typedef struct _cost_mat
{
  int cost;
  char Route[10];
} Cost_mat;


using namespace std;

char* minimumCost(char* input1[],int input2)
{
	//Write code here
	int mat[input2][1000];
	int col;
	for(int i=0;i<input2;i++){
	    int a=0,k=0;
	    for(int j=0;j<strlen(input1[i]);j++){
	        a=0;
	        if(isdigit(input1[i][j])){
	            while(isdigit(input1[i][j])){
	                a=(a*10)+input1[i][j]-'0';
	                j++;
	            }
	        }
	        mat[i][k++]=a;
	        if(input1[i][j]=='#')
	            col++;
	    }
	}
	int i,j,k;
	col=(col+input2)/input2;
	vector<Cost_mat> vec(input2*col);
	const int R=input2;
  const int C=col;
  for(i=0;i<R;i++)
  {
    for(j=0;j<C;j++)
    {
    	cout<<mat[i][j]<<"\t";
    }
    cout<<"\n";
  }
  
  for(i=0;i<R;i++)
  {
    for(j=0;j<C;j++)
    {
      if(i==0 && j==0)
      {
        vec[i].cost=mat[0][0];
       // strcpy(vec[i].Route,"NA,");
      }
      else if(i==0)
      {
        vec[j].cost=vec[j-1].cost+mat[0][j];
        strcpy(vec[j].Route,vec[j-1].Route);
        strcat(vec[j].Route,"R");
      }  
      else if(j==0)
      {
        vec[C*i].cost=vec[C*i-C].cost+mat[i][0];
        strcpy(vec[C*i].Route,vec[C*i-C].Route);
        strcat(vec[C*i].Route,"B");
      }
      else
      {
        int min=0,flag=0;
        vec[C*i+j].cost=vec[C*i+j-1].cost+mat[i][j];
        min=vec[C*i+j].cost;
        vec[C*i+j].cost=vec[C*i+j-C].cost+mat[i][j];
        if(vec[C*i+j].cost<min)
        {
           min=vec[C*i+j].cost;
           flag=1;
        }
        vec[C*i+j].cost=vec[C*(i-1)+j-1].cost+mat[i][j];
        if( min>vec[C*i+j].cost)
        {
           min=vec[C*i+j].cost;
           flag=2;
        }
        vec[C*i+j].cost=min;
        if(flag==0)
        {
          strcpy(vec[C*i+j].Route,vec[C*i+j-1].Route);
          strcat(vec[C*i+j].Route,"R");
        }
        if(flag==1)
        {
          strcpy(vec[C*i+j].Route,vec[C*i+j-C].Route);
          strcat(vec[C*i+j].Route,"B");
        }
        if(flag==2)
        {
          strcpy(vec[C*i+j].Route,vec[C*i-C+j-1].Route);
          strcat(vec[C*i+j].Route,"D");
        }
      }
        
    }
  }
  
  char* Final=(char*)malloc(sizeof(int)+sizeof(char)+((R-1)+(C-1)));
      char buff[4];
      sprintf(buff,"%d",vec[R*C-1].cost);
      strcpy(Final,buff);
      strcat(Final,",");
      strcat(Final,vec[R*C-1].Route);
      cout<<Final<<"\n";
      
     return Final;
}



int main()
{
	char* str[]={"5#3#1#2","9#6#7#1","5#13#2#1","16#1#3#2"};
	char* res=new char[100];
	res=minimumCost(str,4);
	cout<<res<<endl;
	return 0;
}