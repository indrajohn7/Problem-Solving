#include<bits/stdc++.h>

using namespace std;

class parent{
	int a;

	public:
		void parent_fun();
		int get_num();
		void set_num(int);

};

int parent::get_num()
{
	return a;
}

void parent::set_num(int i)
{
	a=i;
}

namespace A{
	class child{
		friend class parent;
		int b;
		parent p;
		public:
			child(int i)
			{
				b=i;
			}
			int get_num();
	};

	int child::get_num()
	{
		p.set_num(b);
		return p.get_num();
	}
}

int main()
{
	A::child c(10);
	cout<<c.get_num()<<endl;

	return 0;
}
