#include <iostream>
#include <vector>
#include <map>
#include <string>
#include<bits/stdc++.h>
#define N 10
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
    vertex(int s,string c,int d,vertex* v,int w)
    {
        name=s;
        colour=c;
        parent=v;
        distance=d;
		weight=w;
    }
};

// extern int global_cost=0;

class graph
{
    public:
        typedef map<int, vertex *> vmap;
        vmap work;
        void addvertex(int,const string&,int , vertex*,int);
        void addedge(int from, int to, double cost);
                void display();
                vertex* Find_Node(int);
          //      void BFS(vertex*,int);
                void Print_Path(vertex*,vertex*);
				int dijkstra(int, int);
				void init_all();
};

void graph::addvertex(int name,const string &colour,int distance,vertex* par,int weight)
{
    vmap::iterator itr=work.begin();
    itr=work.find(name);
    if(itr==work.end())
    {
        vertex *v;
        v= new vertex(name,colour,distance,par,weight);
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

 void graph::display()
 {
	    //NODE DETAILS
		 for(vmap::iterator itr=work.begin(); itr!=work.end();itr++){
                 cout<<itr->first <<"        :Node Details: \n";
                 cout<<"Node Name               Node Weight                 Node Colour        Node's Parent Name\n";
				 if(itr->second->parent==NULL)
					cout<<itr->second->name<<"      "<<itr->second->weight<<"      "<<itr->second->colour<<"      "<<"NULL \n";
				 else
					 cout<<itr->second->name<<"      "<<itr->second->weight<<"      "<<itr->second->colour<<"      "<<itr->second->parent->name<<"\n";
		 }
         for(vmap::iterator itr=work.begin(); itr!=work.end();itr++){
                 cout<<itr->first <<"   :Adjacency list is \n";
                 cout<<"Edge COST               Destination NODE                Destination Node Colour\n";


                 for(int i=0;i<itr->second->adj.size();i++){
                         cout<<itr->second->adj[i].first<<"             "<<itr->second->adj[i].second->name<<"          "<<itr->second->adj[i].second->colour<<"\n";
                        // itr->second++;
                 }
         }
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
void graph::init_all()
{
	for(vmap::iterator it=work.begin();it!=work.end();it++){
		it->second->colour="WHITE";
		it->second->weight=0;
	}
}

int  graph::dijkstra(int from , int to)
{
	 int min;
	 vmap::iterator it=work.find(from);
	 vertex* Source=it->second;
	 Source->colour="GREY";
     Source->distance=0;
	 Source->weight=0;
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
					if (u->adj[i].second->name == to)
						min = u->adj[i].second->weight;
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
	return min;
}


 int main()
 {
         ifstream fin;
         fin.open("wizard.in");
        // char* Node[N]={"ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE","TEN"};
         int i,j,Num,Test_case;
		 fin >> Test_case;
		 for(int iter = 0;iter < Test_case; iter++){
         	fin>>Num;
         	//char Node[Num][10];
			int Node [Num];
         	for(i=0;i<Num;i++)
                 Node[i] = i+1;
         	graph g;
         	int vertices[Num][Num];
         	for(i=0;i<Num;i++)
                 g.addvertex(Node[i],"WHITE",inf,(vertex*)NULL,infi);
         	for(i=0;i<Num;i++){
                 for(j=0;j<Num;j++)
                         fin>>vertices[i][j];
         	}
			
			int pos, rose, date;
			fin >> pos >> rose >> date;

         	for(i=0;i<Num;i++){
                 for(j=0;j<Num;j++){
                         if(vertices[i][j]>0){
                                 g.addedge(Node[i],Node[j],vertices[i][j]);
                         }
                 }
         	}
			int res = 0;
			res += g.dijkstra(pos, rose);
			g.init_all();
			res += g.dijkstra(rose,date);
		 	//g.display();
			cout<<res<<endl;
		}	
	
	return 0;
}
