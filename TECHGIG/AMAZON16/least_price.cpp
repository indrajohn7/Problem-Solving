#include<bits/stdc++.h>

struct node{
	int start_time;
	int end_time;
	int price;
	node(int a,b,price){
		start_time=a;
		end_time=b;
		price=c;
	}
};

class time{
	public:
		typedef map<int,vector<node*>> vmap;
		vmap work;
		void addnode(int,int,int);
};

void addnode(int st,int en,int pr)
{
	vmap::iterator itr=work.begin();
    itr=work.find(st);
	if(itr==work.end()){
        vertex *v;
        v= new vertex(st,en,pr);
        work[name].push_back(v);//=v;
        return;
    }
	else{
		vertex *v;
        v= new vertex(st,en,pr);
		itr->second.push_back(v);
		return;
	}
}

int main()
{
	int N;
	cin>>N;
	node n;
	for(int i=0;i<N;i++){
		int start,end,price;
		cin>>start>>end>>price;
		n.addnode(start,end,price);
	}
	
}