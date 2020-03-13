#include<bits/stdc++.h>

typedef struct _node{
	int val;
}node;

int foo(int i){ return i + 1;}
node* g_port_db[2];

node* sptr_port_db(int n)
{
	return g_port_db[n];
}

node* (*p_sptr_port_db)(int)=&sptr_port_db;

#define SPTR(N) p_sptr_port_db(N)
//typedef int (*g)(int);  // Declare typedef
int main()
{
int (*func)(int) = &foo;          // Define function-pointer variable, and initialise
node* n=(node*)malloc(sizeof(node));
n->val=-99;
g_port_db[1]=n;
int hvar = func(3);
std::cout<<hvar<<"\t"<<SPTR(1)->val<<std::endl;
return 0;
}
