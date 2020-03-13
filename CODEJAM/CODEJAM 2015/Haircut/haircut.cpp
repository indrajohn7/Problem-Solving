#include <cstdio>
#include <cstdlib>
//#include <cassert>
#include <iostream>
#include <string>
#include<bits/stdc++.h>
#include<list>
#include <fstream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
	int Test,iter;
	ifstream fin;
	fin.clear();
	fin.open("H-large.in");
	fin>>Test;
	for(iter=0;iter<Test;iter++)
	{
		int Bur,NumQ,j,k;
		fin>>Bur;
		fin>>NumQ;
		list<int> B;
		int i,BurB[Bur],temp[Bur],min_pos,min,count=0;
		for(i=0;i<Bur;i++)
		{
			fin>>BurB[i];
			temp[i]=0;
			B.push_back(BurB[i]);
		}
	//	B.sort();
	//	min= B.front();
	//	for(i=0;i<Bur;i++)
	//	{
	//		if(min==BurB[i])
	//			min_pos=i;
	//	}
		for(i=0;i<NumQ;i=i+count)
		{
			count=0;
			for(j=0;j<Bur;j++)
			{
				if(temp[j]==0)
				{
					temp[j]=BurB[j];
			//		j++;
					count++;
				}
				else
				{
					for(k=0;k<Bur;k++)
						B.push_back(temp[k]);
					B.sort();
					min=B.front();
					for(k=0;k<Bur;k++)
					{
						if(min==temp[k])
						{
							min_pos=k;
							break;
						}
					}
					while(temp[min_pos]!=0)
					{
						for(k=0;k<Bur;k++)
							temp[k]=temp[k]-min;
					}
					j=min_pos-1;
				}
				if(i==NumQ-1)
					break;
			}
		}
		if(j<Bur)
			cout<<"case #"<<iter+1<<": "<<j+1<<"\n";
		else
			cout<<"case #"<<iter+1<<": "<<j<<"\n";

	}
	return 0;
}
