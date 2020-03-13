#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int Test,iter;
	ifstream fin;
	fin.clear();
	fin.open("M-large.in");
	fin>>Test;
	for(iter=0;iter<Test;iter++)
	{
		int i,Num,any,fix,count;
		count=0;
		Num=0;
		any=fix=0;
		fin>>Num;
		int mush[Num];
		for(i=0;i<Num;i++)
			fin>>mush[i];
		for(i=0;i<Num-1;i++)
		{
			if(mush[i]>mush[i+1])
			{
				any=any+mush[i]-mush[i+1];
			}
		}
		i=0;
		while(i<Num-1)
		{
			if(mush[i+1]>=mush[i]-count)
			{
				if(mush[i]-count>=0)
					fix=fix+count;
				else
					fix=fix+mush[i];
				i++;
			}
			else
			{
				fix=0;
				i=0;
				count++;
			}
		}
		cout<<"case #"<<iter+1<<": "<<any<<" "<<fix<<"\n";
	
	}
	return 0;
}

