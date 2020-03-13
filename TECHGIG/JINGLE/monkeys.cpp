#include<stdio.h>
#include<string.h>
#include<bits/stdc++.h>

using namespace std;

int traveltime(int input1[],int input2)
{
	//Write code here
	int max=0;
	for(int i=0;i<input2-1;i++){
	    for(int j=i+1;j<input2;j++){
	        int temp;
	        (abs(i-j)<abs(input2-1-j+i+1))?temp=abs(i-j):temp=abs(input2-1-j+i+1);
	        if(input1[i]+input1[j]+temp>max)
	            max=input1[i]+input1[j]+temp;
	    }
	}
	return max;
}
