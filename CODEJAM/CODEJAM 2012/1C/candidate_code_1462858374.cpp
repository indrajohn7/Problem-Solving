
#include<stdio.h>
#include<string.h>
#include<bits/stdc++.h>
#include<map>

#define infi -999999
#define Num 9999

using namespace std;

int maxTreeDestroyed(int input1,int input2,int input3,char* input4)
{
	//Write code here
	int arr[Num],input[input3][2];
	int l=0;
	for(int i=0;i<strlen(input4);i++){
	    if(isdigit(input4[i])){
	        //char buf=new[100];
	        int val=0;
	        while(input4[i]!='0'&& isdigit(input4[i])){
	            val=(val*10)+(input4[i++]-'0');
	        }
	        arr[l++]=val;
	    }
	}
	for(int i=0;i<input3;i++){
		input[i][0]=arr[2*i];
		input[i][1]=arr[2*i+1];
	}
	if(l!=2*input3)
	    return -1;
	for(int i=0;i<input3;i++){
		if(input[i][0]<1 || input[i][0]>input1 || input[i][1]<1 || input[i][1]>input2)
	        return -1;
		cout<<input[i][0]<<"\t"<<input[i][1]<<endl;
	}
	int count=0;
	for(int i=0;i<input3-1;i++){
		typedef map<float,int> vmap;
		vmap work;
		for(int j=i+1;j<input3;j++){
			if(input[i][0]==input[j][0]){
				vmap::iterator it=work.begin();
				it=work.find(infi);
				if(it==work.end()){
					work[infi]=1;
				}
				else{
					it->second++;
				}
			}
			else{
				float slope=(float)(input[j][1]-input[i][1])/(input[j][0]-input[i][0]);
				vmap::iterator it=work.begin();
				it=work.find(slope);
				if(it==work.end()){
					work[slope]=1;
				}
				else{
					it->second++;
				}
			}
		}
		for(vmap::iterator it=work.begin();it!=work.end();it++){
			if(it->second>count)
				count=it->second;
		}
	}
	return (count+1);
}






int main()
{
	int a,b,c;
	ifstream fin;
	fin.open("monkey.in");
//	cout<<"ROW: ";
	fin>>a;
//	cout<<"COLUMN: ";
	fin>>b;
//	cout<<"plant: ";
	fin>>c;
	char* co_or=new char[1000];
//	for(int i=0;i<c;i++)
//		co_or[i]=new int[2];
	cout<<"Enter the co-ordinate:\n";
	for(int i=0;i<c;i++){
		fin>>co_or;
	}
	int res=maxTreeDestroyed(a,b,c,co_or);
	cout<<"ANSWER: "<<res<<endl;
	return 0;
}