#include<bits/stdc++.h>

using namespace std;

class copy1{
	private:
		int a;
		char* name;	
	public:
		copy1(int b, char* str)
		{
			a = b;
			name = new char[strlen(str)];
			memcpy(name,str,strlen(str));
		}
		
		copy1(copy1& c)
		{
			a = c.a;
			name = c.name;
		}

		copy1 operator=(copy1 c)
		{
			this->a = c.a;
			this->name= c.name;
			return *this;
		}
		
		int get_a()
		{
			return a;
		}

		char* get_name()
		{
			return name;
		}

};


int main()
{
	copy1 c(10,"INDRA");
	copy1 c1(c);
	copy1 c2 = c;

	cout << "C:"<<c.get_a()<<"::ADDR:"<<&c<<endl;
	cout << "C1:"<<c1.get_a()<<"::ADDR:"<<&c1<<endl;
	cout << "C:"<<c2.get_a()<<"::ADDR:"<<&c2<<endl;
	cout << "C:"<<c.get_name()<<"::ADDR:"<<&(c)<<endl;
	cout << "C1:"<<c1.get_name()<<"::ADDR:"<<&(c1)<<endl;
	cout << "C:"<<c2.get_name()<<"::ADDR:"<<&(c2)<<endl;
	return 0;
}
