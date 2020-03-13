#include<stdio.h>
#include<string.h>
#include<bits/stdc++.h>

int gcd(int a,int b)
{
    if(a%b==0)
        return b;
    else
        gcd(b,a%b);
    
}

int lcm(int a, int b)
{
    if(a<b){
        int temp;
        temp=a;a=b;b=temp;
    }
    int t=gcd(a,b);
    return((a*b)/t);
}

int nochange_bits(char* input1,int input2,int input3)
{
	//Write code here
	if(input2==0 || input3==0)
	    return -1;
	int res=strlen(input1)-(strlen(input1)/input3)-(strlen(input1)/input2)+(strlen(input1)/lcm(input2,input3));
	    return res;
}
