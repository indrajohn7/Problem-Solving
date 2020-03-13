#include<bits/stdc++.h>

using namespace std;


int digits(int a, int pos)
{
	int res=-1;
	char buff[10];
	sprintf(buff,"%d",a);
	pos=strlen(buff)-pos+1;
	while(strlen(buff)>=pos && pos!=0){
		res=a%10;
		a=a/10;
	    sprintf(buff,"%d",a);
		pos--;
	}
	return res;
}

int main()
{
	int arr[11]={1,5,98,21,67,78,191,193,4,65,212};
	int i,j,k,max=0,sum=0;
	for(i=0;i<11;i++){
		char buff[10];
		sprintf(buff,"%d",arr[i]);
		if(max<strlen(buff))
			max=strlen(buff);
	}
	for(k=1;k<=max;k++){
		for(i=0;i<11;i++){
			for(j=0;j<10;j++){
				if(digits(arr[j],k)<digits(arr[j+1],k)){
					int temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
			}		
		}
	}
	for(i=10;i>=0;i--)
		sum+=arr[i]*pow(10,i);
	cout<<"MAX: "<<sum<<endl;
	return 0;
}