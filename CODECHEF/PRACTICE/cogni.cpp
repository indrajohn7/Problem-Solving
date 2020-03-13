#include <iostream>
#include <vector>
#include <map>
#include <string>
#include<bits/stdc++.h>
//#define N 10
using namespace std;

#define inf  -99999999
#define infi  9999999999

//extern int global_cost=0;

struct vertex{
    typedef pair<int,vertex*> ve;
    vector<ve> adj; //cost of edge, destination vertex
    int name;
    string colour;
    int distance;
    vertex* parent;
	int weight;
	int ret;
    vertex(int s,string c,int d,vertex* v,int w,int b)
    {
        name=s;
        colour=c;
        parent=v;
        distance=d;
		weight=w;
		ret=b;
    }
};

class graph
{
    public:
        typedef map<int, vertex *> vmap;
        vmap work;
        void addvertex(int ,const string&,int , vertex*,int,int);
        void addedge(int from, int to, double cost);
              //  void display();
                vertex* Find_Node(int);
                void Print_Path(vertex*,vertex*);
				void prims(vertex*, int,int*,int*);
};


void graph::addvertex(int name,const string &colour,int distance,vertex* par,int weight,int block)
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


void graph::prims(vertex* Source, int Node_num,int* global_cost, int* num)
{
	Source->colour="GREY";
    Source->distance=0;
    Source->parent=NULL;
    list<vertex*> ver;
	list<vertex*> v;
	int index = 0, max=999,flag=0,node_index=0;
    ver.push_back(Source);
//	cout<<Source->name<<"\n";
	v=ver;
	while(ver.size() < Node_num){
               //  vertex* u=ver.front();
               //  ver.pop_front();     //DEQUEUE
				 max=999;
				  flag=0;
				// for(int k=0;k<ver.size();k++){
					 vertex* u=ver.back();;
					 // max=999;					 
                 for(int i=0;i<u->adj.size();i++){
						if(u->adj[i].first<max && u->adj[i].second->colour=="WHITE"){
							max=u->adj[i].first;
							index=i;
							node_index=ver.size()-1;
							flag=1;
						}
				 }
			//	}
			    if(flag==1){
				vertex* u=ver.back();
				if(u->adj[index].second->colour=="WHITE"){
                         u->adj[index].second->colour="GREY";
                         u->adj[index].second->distance=u->distance+1;
                         u->adj[index].second->parent=u;
					//	 u->adj[index].second->block==true;
						 *global_cost+=u->adj[index].first;
                         ver.push_back(u->adj[index].second);
						// cout<<u->adj[index].second->name<<endl;
                   }
                         u->colour="BLACK"; 
						 v=ver;
						 vertex* t=ver.back();
						 for(list<vertex*>::iterator it=ver.begin();it!=ver.end();it++){
							 if((*it)->name==ver.back()->name){
								 it=ver.erase(it);
								 --it;
							 }
						 }					 
						 ver.push_back(t);
			}
			else {
				if(u->ret==u->adj.size()-1){
					u->parent->ret+=1;
					for(int i=0;i<u->adj.size();i++){
						if(u->adj[i].second->name==u->parent->name){
							*global_cost+=u->adj[i].first;
							break;
						}
					}
					if(u->parent->name==1)
						*num+=1;
					ver.push_back(u->parent);
					v=ver;
					vertex* t=ver.back();
					for(list<vertex*>::iterator it=ver.begin();it!=ver.end();it++){
							 if((*it)->name==ver.back()->name){
								 it=ver.erase(it);
								 --it;
							 }
						 }						 
						 ver.push_back(t);
				}		
			}
	}
	vertex* t=ver.back();
	while(t->name!=1){
		for(int i=0;i<t->adj.size();i++){
			if(t->adj[i].second->name==t->parent->name){
				*global_cost+=t->adj[i].first;
				t=t->parent;
				break;
			}
		}
	}
}



int main()
{
	int N,L,K;
/*	cout<<"GIVE the number of nodes and the number of connections:\n";
	ifstream fin;
	fin.open("cogni.in");
	fin>>N;
	*/
	cin>>N;
	
//	cout<<"Give the connected path details:\n";
	int** vertices=new int*[N];
	for(int i=0;i<N;i++)
		vertices[i]=new int[N];
	for(int i=0;i<N;i++){
		cin>>L>>K;
		int** path=new int*[K];
	    for(int i=0;i<K;i++)
		     path[i]=new int[3];		
		for(int i=0;i<K;i++){
			path[i][0]=L;
			for(int j=1;j<3;j++)
				cin>>path[i][j];
			vertices[path[i][0]-1][path[i][1]-1]=path[i][2];
		}
	}
	graph g;
	for(int i=1;i<=N;i++)
        g.addvertex(i,"WHITE",inf,(vertex*)NULL,infi,0);
	for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                   if(vertices[i][j]>0){
                          g.addedge(i+1,j+1,vertices[i][j]);
                         }
                 }
    }
	int cost=0,num=1;
	vertex* S=g.Find_Node(1);
	g.prims(S,N,&cost,&num);
	cout<<num<<endl<<cost<<endl;
	return 0;
}