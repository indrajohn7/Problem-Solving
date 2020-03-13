#include<bits/stdc++.h>

using namespace std;

class construct{
	string name;
	public:
		construct()
		{
			cout<<"Pls provide a name: "<<endl;
			cin>>name;
		}
		string get_name();
};

string  construct::get_name()
{
	return name;
}

int main()
{
	construct cs[4];
	for(int i=0;i<4;i++)
		cout<<cs[i].get_name()<<endl;
	return 0;
}
