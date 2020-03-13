#include<bits/stdc++.h>

using namespace std;

class parent{
	private:
		int a,b;
		char c;
	public:

		parent(int i,int j,char k)
		{
			a = i;
			b = j;
			c = k;
			cout<<"Inside parent constructor:\n";
		}
		virtual void pure_func()=0;
		virtual void func()
		{
			cout<<"Inside parent func()\n";
		}
};


class base: public parent
{
	public:
		base(int i,int j,char k):parent(i,j,k)
		{
		}
		void pure_func()
		{
			cout<<"Inside base pure:\n";
		}

		void func()
		{
			cout<<"Inside base func:\n";
		}
};

int main()
{
	parent* p;
	base b(10,20,'A');
	p = dynamic_cast<parent*>(&b);

	p->func();


	return 0;
}
