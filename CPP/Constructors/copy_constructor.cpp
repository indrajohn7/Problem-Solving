#include<bits/stdc++.h>

using namespace std;

class copy1{
	private:
		int a;
	
	public:
		copy1(int b)
		{
			a = b;	
		}
		
		copy1(copy1& c)
		{
			cout<<"Copy constructor is called:\n";
			a = c.a;
		}

		copy1 operator=(copy1 c)
		{
			cout<<"Assignment is called:\n";
			this->a = c.a;
			return *this;
		}
		
		int get_a()
		{
			return a;
		}

};


int main()
{
	copy1 c(10);
	copy1 c1(c);
	copy1 c2 = c;

	cout << "C:"<<c.get_a()<<"ADDR:"<<&c<<endl;
	cout << "C1:"<<c1.get_a()<<"ADDR:"<<&c1<<endl;
	cout << "C:"<<c2.get_a()<<"ADDR:"<<&c2<<endl;
	return 0;
}
