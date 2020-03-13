#include<stdio.h>
#include<string.h>
#include<bits/stdc++.h>

using namespace std;

long long int facto(int n)
{
    if(n==0 || n==1)
        return 1;
    else
        return (n*facto(n-1));
}

long long int combo(int n , int r)
{
    return (facto(n)/(facto(r)*facto(n-r)));
}

bool check_odd(int arr[],int t,int len)
{
    for(int i=0;i<len;i++){
        if(arr[i]==t)
            return false;
    }
    return true;
}

bool check_row(int** arr,int row, int parr[],int ch)
{
    int match=0;
    for(int i=0;i<row;i++){
        match=0;
        for(int j=0;j<ch;j++){
            if(arr[i][j]==parr[j])
                match++;
        }
        if(match==ch)
            return false;
    }
    return true;
}


void create_combo(int** arr,int iter, int ch,int in[],int len)
{
    for(int i=0;i<iter;i++){
        int parr[ch];
        memset(parr,0,ch*sizeof(int));
        for(int j=0;j<ch;j++){
            int t=rand()%len;
            if(check_odd(parr,t,j)){
                parr[j]=t;
            }else{
                --j;
                continue;
            }
        }
        sort(parr,parr+ch);
        if(check_row(arr,i,parr,ch)){
            memcpy(arr[i],parr,ch*sizeof(int));
        }else{
            --i;
            continue;
        }
    }   
}

int sum_find(int** arr,int in[], int len,int input3,int input2)
{
	bool flag=false;
	int mini=999999;
    for(int i=0;i<len;i++){
        int res=0;
        for(int j=0;j<input3;j++){
            res+=in[arr[i][j]];
        }
        if(res%input2==0){
			if(res<mini)
				mini=res;
            flag=true;;
		}
    }
	if(flag)
		return mini;
	else
		return -1;
}


template<typename T, size_t size>
size_t GetSize(T (&)[size])
{
     return size;
}


int ball_count(int len,int input1[],int input2,int input3)
{
	//Write code here
	
	sort(input1,input1+len);
	long long int iter=combo(len,input3);
	int** selects=new int*[iter];
	for(int i=0;i<iter;i++)
	    selects[i]=new int[input3];
	create_combo(selects,iter,input3,input1,len);
	cout<<"ITER:"<<iter<<endl;
	for(int i=0;i<iter;i++){
			for(int j=0;j<input3;j++)
				cout<<selects[i][j]<<"\t";
			cout<<endl;
	}
	int res=sum_find(selects,input1,iter,input3,input2);
	return res;
	    
}

int main()
{
	cout<<"Give array size:";
	int i,N,ch,mul;
	cin>>N;
	cout<<"Give array element:";
	int* arr=new int[N];
	memset(arr,0,N);
	for(i=0;i<N;i++)
		cin>>arr[i];
	cout<<"Give MUL and CHOICE NUM:";
	cin>>mul>>ch;
	int res=ball_count(N,arr,mul,ch);
	cout<<"Result: "<<res<<endl;
	return 0;
	
}


