#include<bits/stdc++.h>

using namespace std;


class table{
	int height,breadth,width;
	public:
		table(int a,int b,int c)
		{
			height=a;
			breadth=b;
			width=c;
		}

};

int main()
{
	table* p=new table(1,2,3);
	table* q=new table(3,4,5);

	delete p;
	delete q;

	return 0;
}
