#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
long int maxSubArraySum(long int a[], int size)
{
   long int max_so_far = a[0];
   long int curr_max = a[0],first_ptr,last_ptr,flag=0;
   first_ptr=last_ptr=0;
   for (int i = 1; i < size; i++)
   {
	    if(abs(a[i])>abs(curr_max+a[i]) && flag==0){
			first_ptr=i;
			flag=1;
		}
		else if(abs(a[i])<abs(curr_max+a[i]) && flag==0){
			first_ptr=i-1;
			flag=1;
		}
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
		if(max_so_far==curr_max && flag==1){
			last_ptr=i;
		}
		if(max_so_far<curr_max)
			flag=0;
   }
   if(first_ptr==last_ptr)
		return max_so_far;
	else{
		sort(a+first_ptr,a+last_ptr);
		if(a[first_ptr]<0)
			max_so_far-=a[first_ptr];
		return max_so_far;
	}
}
 
/* Driver program to test maxSubArraySum */
int main()
{
  // freopen("msum.in","r",stdin);
   int Num_Test,iter;
   cin>>Num_Test;
   for(int iter=0;iter<Num_Test;iter++){
	int N;
	cin>>N;
	long int* a=new long int[N];
	for(int i=0;i<N;i++)
		cin>>a[i];
	long int max_sum = maxSubArraySum(a, N);
	cout << max_sum<<endl;
   }   
   return 0;
}