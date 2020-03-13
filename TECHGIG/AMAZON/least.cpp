#include<bits/stdc++.h>

using namespace std;

typedef struct _node{
	int start_time;
	int end_time;
	int price;
}node;


vector<node> nd;
vector<node> out;

int verify(int* arr,int a,int b)
{
	int res=0;
	for(int i=a;i<=b;i++){
		if(arr[i]==0)
			res++;
	}
	return res;
}

int main()
{
	int N;
	cin>>N;
	int min=9999999,max=0;
	for(int i=0;i<N;i++){
		int start,end,price;
		cin>>start>>end>>price;
		if(min>start)
			min=start;
		if(max<end)
			max=end;
		node n;
		n.start_time=start;
		n.end_time=end;
		n.price=price;
		nd.push_back(n);
	}
	int* time=new int[max];
	memset(time,0,max*sizeof(int));
	for(int i=0;i<nd.size();i++){
		for(int j=0;j<nd.size()-1;j++){
			if(nd[j].price>nd[j+1].price){
				node n;
				n=nd[j];
				nd[j]=nd[j+1];
				nd[j+1]=n;
			}
		}
	}
	
	for(int i=0;i<nd.size();i++){
		
		if(verify(time,nd[i].start_time-1,nd[i].end_time-1)==(nd[i].end_time-nd[i].start_time+1)){
			node n;
			n.start_time=nd[i].start_time;
			n.end_time=nd[i].end_time;
			n.price=nd[i].price;
			out.push_back(n);
			memset(time+nd[i].start_time-1,1,(nd[i].end_time-nd[i].start_time+1)*sizeof(int));
		}else if(verify(time,nd[i].start_time-1,nd[i].end_time-1)!=0){ 
			int len,max,idx=nd[i].start_time-1;
			len=max=0;
			for(int j=nd[i].start_time-1;j<nd[i].end_time;j++){
				max=0;
				if(time[j]==0){
					idx=j;
					while(time[j]==0 && j<nd[i].end_time){
						j++;
						max++;
					}
				}
				if(len<max)
					len=max;
			}
			node n;
			n.start_time=(idx+1);
			n.end_time=idx+len;
			n.price=nd[i].price;
			out.push_back(n);
			memset(time+idx,1,len*sizeof(int));
		}
	}
	for(int i=0;i<max;i++){
		int len,max,idx;
		len=max=idx=0;
		if(time[i]==0){
			idx=i;
			while(time[i]==0 && i<max){
				i++;
				len++;
			}
		}
		if(len!=0){
			node n;
			n.start_time=idx+1;
			n.end_time=idx+len;
			n.price=0;
			out.push_back(n);
		}
	}
	for(int i=0;i<out.size();i++){
		for(int j=0;j<out.size()-1;j++){
			if(out[j].start_time>out[j+1].start_time){
				node n;
				n=out[j];
				out[j]=out[j+1];
				out[j+1]=n;
			}
		}
	}
	
	
	for(int i=0;i<out.size();i++){
		cout<<out[i].start_time<<" "<<out[i].end_time<<" "<<out[i].price<<endl;
	}
	
	return 0;
}
