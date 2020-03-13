#include<bits/stdc++.h>

using namespace std;

#define inf  -99999999
#define infi  99999999

struct vertex{
    typedef pair<int,vertex*> ve;
    vector<ve> adj; //cost of edge, destination vertex
    int name;
    string colour;
    int distance;
    vertex* parent;
	int weight;
	bool block;
    vertex(int s,string c,int d,vertex* v,int w,bool b)
    {
        name=s;
        colour=c;
        parent=v;
        distance=d;
		weight=w;
		block=b;
    }
};

class graph
{
    public:
        typedef map<int, vertex *> vmap;
        vmap work;
        void addvertex(int ,const string&,int , vertex*,int,bool);
        void addedge(int from, int to, double cost);
                void display();
                vertex* Find_Node(int);
          //      void BFS(vertex*,int);
          //      void Print_Path(vertex*,vertex*);
				void dijkstra(vertex*);
				void obstruct(vertex*,int);
};

void graph::addvertex(int name,const string &colour,int distance,vertex* par,int weight,bool block)
{
    vmap::iterator itr=work.begin();
    itr=work.find(name);
    if(itr==work.end())
    {
        vertex *v;
        v= new vertex(name,colour,distance,par,weight,block);
        work[name]=v;
        return;
    }
        cout<<"\nVertex already exists!";
}

void graph::addedge(int from, int to, double cost)
{
    vertex *f=(work.find(from)->second);
    vertex *t=(work.find(to)->second);
    pair<int,vertex *> edge = make_pair(cost,t);
    f->adj.push_back(edge);
 }
 
 vertex* graph::Find_Node(int Node)
 {
         vertex *f=(work.find(Node)->second);
         return f;
 }

 
 void graph::dijkstra(vertex* Source)
{
	 //vmap::iterator it=work.begin();
	// vertex* Source=Find_Node(node);
	 Source->colour="GREY";
     Source->distance=0;
	 Source->weight=0;
	 if(Source->block==true)
		 Source->weight=1;
     Source->parent=NULL;
     list<vertex*> ver;
     ver.push_back(Source);       //ENQUEUE
     while(ver.size()>0){
		vertex* u=ver.front();
        ver.pop_front();     //DEQUEUE
        for(int i=0;i<u->adj.size();i++){
                if(u->adj[i].second->colour=="WHITE" || ((u->weight+u->adj[i].first) < u->adj[i].second->weight)){
                    u->adj[i].second->colour="GREY";
                    u->adj[i].second->distance=u->distance+1;
                    u->adj[i].second->parent=u;
					u->adj[i].second->weight = u->weight+u->adj[i].first;
					if(u->adj[i].second->block==true)
						u->adj[i].second->weight+=1;
                    ver.push_back(u->adj[i].second);       //ENQUEUE
                    }
                u->colour="BLACK";
        }

    }
	/*
	 for(vmap::iterator itr=work.begin(); itr!=work.end();itr++){
		 for(int i=0;i<itr->second->adj.size();i++){
			 if(itr->second->weight==infi)
				 itr->second->weight=0;
			 if((itr->second->adj[i].first + itr->second->weight) < itr->second->adj[i].second->weight){
				 itr->second->adj[i].second->weight = itr->second->adj[i].first + itr->second->weight;
				 itr->second->adj[i].second->parent=itr->second;
			 }
		 }
	 }
	 */
}
 
 void graph::obstruct(vertex* destination,int K)
 {
	// vertex* destination=Find_Node(N);
	 list<vertex*> ve;
	 ve.push_back(destination);
	 if(K>0)
	     destination->block=true;
	 int count=1;
	 while(ve.size()>0 && count<K){
		 vertex* u=ve.front();
		 ve.pop_front();
		 for(int i=0;i<u->adj.size()&& count<K;i++){
			 u->adj[i].second->block=true;
			 ve.push_back(u->adj[i].second);	
             count++;			 
		 }
	 }
 }
 
int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("world.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int N,M,K,i;
		graph g;
		fin>>N>>M>>K;
		for(i=0;i<N;i++)
			g.addvertex(i,"WHITE",inf,(vertex*)NULL,infi,false);
		for(i=0;i<M;i++){
			int x0,x1;
			fin>>x0>>x1;
			g.addedge(x0,x1,1);
			g.addedge(x1,x0,1);
		}
		vertex* s=g.Find_Node(0);
		g.obstruct(s,K);
		s=g.Find_Node(0);
		g.dijkstra(s);
		int ans=g.Find_Node(N-1)->weight;	
		cout<<"CASE #"<<iter+1<<":\t"<<ans<<endl;
	}
	return 0;
}