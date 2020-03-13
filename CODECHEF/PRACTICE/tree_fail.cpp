#include <iostream>
#include <vector>
#include <map>
#include <string>
#include<bits/stdc++.h>
#define N 10
using namespace std;

#define inf  -99999999

struct vertex{
    typedef pair<int,vertex*> ve;
    vector<ve> adj; //cost of edge, destination vertex
    int name;
    string colour;
    int distance;
    vertex* parent;
    vertex(int s,string c,int d,vertex* v)
    {
        name=s;
        colour=c;
        parent=v;
        distance=d;
    }
};

vector<int> vec;

class graph
{
    public:
        typedef map<int, vertex *> vmap;
        vmap work;
        void addvertex(int,const string&,int , vertex*);
        void addedge(int from, int to, double cost);
                void display();
                vertex* Find_Node(int);
                void BFS(vertex*);
                int  Print_Path(vertex*,vertex*,int*);
				void branching(int*);
};

void graph::addvertex(int name,const string &colour,int distance,vertex* par)
{
    vmap::iterator itr=work.begin();
    itr=work.find(name);
    if(itr==work.end())
    {
        vertex *v;
        v= new vertex(name,colour,distance,par);
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

 void graph::BFS(vertex* Source)
 {
         Source->colour="GREY";
         Source->distance=0;
         Source->parent=NULL;
         list<vertex*> ver;
         ver.push_back(Source);       //ENQUEUE
         while(ver.size()>0){
                 vertex* u=ver.front();
                 ver.pop_front();     //DEQUEUE
                 for(int i=0;i<u->adj.size();i++){
                         if(u->adj[i].second->colour=="WHITE"){
                                 u->adj[i].second->colour="GREY";
                                 u->adj[i].second->distance=u->distance+1;
                                 u->adj[i].second->parent=u;
                                 ver.push_back(u->adj[i].second);       //ENQUEUE
                         }
                         u->colour="BLACK";
                 }

         }
 }


/*Look here for infinite looping*/

void graph :: branching(int* arr)
{
	vmap clone;
	//clone.insert(work.begin(), work.end());
	
	for(vmap::iterator it = work.begin(); it != work.end(); it++){
		vertex* vex = new vertex(it->first,"WHITE",0,NULL);
		vertex* v = it->second;
		memcpy(vex, v, sizeof(vertex));
		clone[it->first] = vex;	
	}
	
	int val = 1;
	while(clone.size() != 0){
		for(vmap::iterator it = clone.begin(); it != clone.end(); it++){
			if(it->second->adj.size() == 0 || it->second->adj.size() == 1){
				arr[it->second->name-1] = val;
				clone.erase(it);
			}
		}
		//BFS(clone.begin());
		val++;
	}
}

int calculate_inversion(vector<int> v)
{
	int count = 0;
	for(int i = 0; i < v.size(); i++){
		for(int j = 0; j < i; j++){
			if(i > j && (vec[i] < vec[j]))
				count++;
		}
	}
	return count;
}

 int graph::Print_Path(vertex* Source,vertex* ver, int* arr)
 {
        if(ver==Source) {
				 vec.push_back(arr[Source->name]);
				 int res = calculate_inversion(vec);
				 vec.clear();
                 //cout<<Source->name<<"\n";
		} else if(ver->parent==NULL) {
                 cout<<"No Path from "<<Source->name<<" to destination: "<<ver->name;
        } else{
                 Print_Path(Source,ver->parent,arr);
				 vec.push_back(ver->name);
         }

}

 int main()
 {
         ifstream fin;
         fin.open("tree_fail.in");
         int i,j,Num_test;
         fin>>Num_test;
		 for(int iter = 0; iter < Num_test; iter++){
         	int nodes, queries;
			fin >> nodes >> queries;
			int Node[nodes];
         	for(i=0;i<nodes;i++)
                 Node[i] = i+1;
         	graph g;
         	int vertices[nodes-1][2];
         	
			/*Graph creation Started*/
         	for(i=0;i<nodes;i++)
                 g.addvertex(Node[i],"WHITE",inf,(vertex*)NULL);
         	for(i=0;i<nodes-1;i++){
                 for(j=0;j<2;j++)
                         fin>>vertices[i][j];
         	}
         	for(i=0;i<nodes-1;i++){
            	
				g.addedge(vertices[i][0],vertices[i][1],0);
         	}
        	int Source,Dest;
         	/*Graph creation completed*/
		
			/*Query init*/
			int query[queries][2];
			for(i = 0;i < queries; i++){
				fin >> query[i][0] >> query[i][1];
			}
			/*Query input end*/

			/*Branching of the graph assigning weight*/
			int* inversion = new int[nodes];
			g.branching(inversion);
			/*Branching end*/
			vertex* first_node = g.Find_Node(Node[0]);
			g.BFS(first_node);
         	int choice;

			/*Query init*/
         	cout<<"Printing Source to Destiation Nodes:\n";
         	for(i = 0; i<queries; i++){
                 Source = query[i][0];
                 Dest = query[i][1];
                 vertex* s=g.Find_Node(Source);
                 vertex* d=g.Find_Node(Dest);
                 int res = g.Print_Path(s, d, inversion);
				 cout << res << endl;
         	}
			/*Query end*/
		}

         return 0;
 }
