#include<bits/stdc++.h>
#include <vector>
#include <map>

using namespace std;

#define infi -999999

int monkeys(int r,int c,int d,int** input)
{
	int count=0;
	for(int i=0;i<d-1;i++){
		typedef map<float,int> vmap;
		vmap work;
		for(int j=i+1;j<d;j++){
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
	int** co_or=new int*[c];
	for(int i=0;i<c;i++)
		co_or[i]=new int[2];
	cout<<"Enter the co-ordinate:\n";
	for(int i=0;i<c;i++){
		for(int j=0;j<2;j++)
			fin>>co_or[i][j];
	}
	int res=monkeys(a,b,c,co_or);
	cout<<"ANSWER: "<<res<<endl;
	return 0;
}