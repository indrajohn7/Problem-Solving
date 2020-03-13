#include <iostream>
#include <vector>
#include <map>
#include <string>
#include<bits/stdc++.h>
#define N 10
using namespace std;

#define inf  -99999999
#define infi  9999999999


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
              //  void display();
                vertex* Find_Node(int);
                void Print_Path(vertex*,vertex*);
				void dijkstra_all(vertex*,int**,int);
				void init_all();

};

void graph::init_all()
{
	for(vmap::iterator it=work.begin();it!=work.end();it++){
		it->second->colour="WHITE";
		it->second->weight=0;
	}
}

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

 
 void graph::Print_Path(vertex* Source,vertex* ver)
 {
        if(ver==Source)
                 cout<<Source->name<<"\n";
         else if(ver->parent==NULL)
                 cout<<"No Path from "<<Source->name<<" to destination: "<<ver->name;
         else{
                 Print_Path(Source,ver->parent);
                 cout<<ver->name;
         }

}

void graph::dijkstra_all(vertex* Source, int** shortest,int num)
{
	 Source->colour="GREY";
     Source->distance=0;
	 Source->weight=0;
     Source->parent=NULL;
     list<vertex*> ver;
     ver.push_back(Source);  //ENQUEUE
	 int k,l;	 
	 for(k=1;k<=num;k++){
		 if(k==Source->name)
			 break;
	 }
	 shortest[k-1][k-1]=0;
     while(ver.size()>0){
		vertex* u=ver.front();
        ver.pop_front();     //DEQUEUE
        for(int i=0;i<u->adj.size();i++){
                if(u->adj[i].second->colour=="WHITE" || ((u->weight+u->adj[i].first) < u->adj[i].second->weight)){
                    u->adj[i].second->colour="GREY";
                    u->adj[i].second->distance=u->distance+1;
                    u->adj[i].second->parent=u;
					u->adj[i].second->weight = u->weight+u->adj[i].first;
					for(l=1;l<=num;l++){
							if(l==u->adj[i].second->name)
								break;
					}
					shortest[k-1][l-1]=u->adj[i].second->weight;
                    ver.push_back(u->adj[i].second);       //ENQUEUE
                    }
                u->colour="BLACK";
        }

    }
}


int main()
{
	int C,F;
	cout<<"GIVE the number of nodes and the number of connections:\n";
	cin>>C>>F;
	int** path=new int*[F];
	for(int i=0;i<F;i++)
		path[i]=new int[3];
	cout<<"Give the connected path details:\n";
	for(int i=0;i<F;i++){
		for(int j=0;j<3;j++)
			cin>>path[i][j];
	}
	int** shortest=new int*[C];
	for(int i=0;i<C;i++)
		shortest[i]=new int[C];
	int** vertices=new int*[C];
	for(int i=0;i<C;i++)
		vertices[i]=new int[C];
	graph g;
	for(int i=0;i<F;i++){
		vertices[path[i][0]-1][path[i][1]-1]=path[i][2];
		vertices[path[i][1]-1][path[i][0]-1]=path[i][2];
	}
	for(int i=1;i<=C;i++)
        g.addvertex(i,"WHITE",inf,(vertex*)NULL,infi,false);
	for(int i=0;i<C;i++){
            for(int j=0;j<C;j++){
                   if(vertices[i][j]>0){
                          g.addedge(i+1,j+1,vertices[i][j]);
                         }
                 }
    }
	char Source[10];
		 for(int i=1;i<=C;i++){
			g.init_all();
			vertex* source=g.Find_Node(i);
			g.dijkstra_all(source,shortest,C);
		//	g.display();
	 }
	 int max=0;
	 
	 for(int i=0;i<C;i++){
			 for(int j=0;j<C;j++){
				 if(shortest[i][j]>max)
					 max=shortest[i][j];
				// cout<<shortest[i][j]<<"\t";
			 }
		//	 cout<<"\n";
		 }
		 
		// cout<<"MAX:: "<<max<<endl;
		cout<<max<<endl;
	return 0;
}